/* Ex1 Q3 */
var grille = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];
var score = 0;
var nbVide = 16;

/* Ex1 Q3 */
function construitGrille() {
  var html = "<table>";
  for (var i = 0; i < 4; i++) {
    html += "<tr>";
    for (var j = 0; j < 4; j++) {
      if (grille[i][j] === 0) {
        html += "<td></td>";
      } else {
        html += "<td>" + grille[i][j] + "</td>";
      }
    }
    html += "</tr>";
  }
  html += "</table>";
  $("#grille").html(html);
}

/* Ex2 Q1 */
function afficheScore() {
  $("#score").html(score);
}

/* Ex2 Q2 */
function caseVide(i, x) {
  var compteur = 0;
  for (var r = 0; r < 4; r++) {
    for (var c = 0; c < 4; c++) {
      if (grille[r][c] === 0) {
        if (compteur === i) {
          grille[r][c] = x;
          nbVide--;
          return;
        }
        compteur++;
      }
    }
  }
}

/* Ex2 Q3 */
function nouvelle() {
  score = 0;
  afficheScore();
  grille = [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]];
  nbVide = 16;
  var i1 = Math.floor(Math.random() * nbVide);
  caseVide(i1, 2);
  var i2 = Math.floor(Math.random() * nbVide);
  caseVide(i2, 2);
  construitGrille();
  $("#gameover").hide();
}

/* Ex2 Q4 */
function glisse(dir) {
  var moved = false;

  for (var k = 0; k < 4; k++) {

    /* Extraire la ligne ou colonne selon la direction */
    var ligne = [];
    for (var l = 0; l < 4; l++) {
      if (dir === 'g') ligne.push(grille[k][l]);
      if (dir === 'd') ligne.push(grille[k][3 - l]);
      if (dir === 'h') ligne.push(grille[l][k]);
      if (dir === 'b') ligne.push(grille[3 - l][k]);
    }

    var avant = ligne.slice();

    /* Compacter : enlever les zéros */
    var tiles = [];
    for (var l = 0; l < 4; l++) {
      if (ligne[l] !== 0) tiles.push(ligne[l]);
    }

    /* Fusionner les paires identiques adjacentes */
    for (var l = 0; l < tiles.length - 1; l++) {
      if (tiles[l] === tiles[l + 1]) {
        tiles[l] *= 2;
        score += tiles[l];
        nbVide++;
        tiles.splice(l + 1, 1);
        l++;
      }
    }

    /* Rembourrer avec des zéros */
    while (tiles.length < 4) tiles.push(0);

    /* Remettre dans la grille */
    for (var l = 0; l < 4; l++) {
      if (dir === 'g') grille[k][l]     = tiles[l];
      if (dir === 'd') grille[k][3 - l] = tiles[l];
      if (dir === 'h') grille[l][k]     = tiles[l];
      if (dir === 'b') grille[3 - l][k] = tiles[l];
      if (tiles[l] !== avant[l]) moved = true;
    }
  }

  return moved;
}

/* Ex2 Q5 */
function gameOver() {
  $("#gameover").show();
}

/* Ex2 Q3 & Q6 */
$(document).ready(function() {

  nouvelle();

  /* Ex2 Q3 */
  $("#btn-nouvelle").click(function() {
    nouvelle();
  });

  /* Ex2 Q6 */
  $(document).keydown(function(k) {

    if (nbVide === 0) {
      gameOver();
      return;
    }

    var dir = null;
    if (k.which === 37) dir = 'g';
    if (k.which === 39) dir = 'd';
    if (k.which === 38) dir = 'h';
    if (k.which === 40) dir = 'b';

    if (dir !== null) {
      k.preventDefault();
      var moved = glisse(dir);
      if (moved) {
        var i = Math.floor(Math.random() * nbVide);
        caseVide(i, 2);
      }
      construitGrille();
      afficheScore();
      if (nbVide === 0) {
        gameOver();
      }
    }
  });

});
