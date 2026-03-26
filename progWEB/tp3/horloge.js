const TAILLE = 500;

let canvas;
let ctx;

// angles
let theta_aiguille_secondes;
let theta_aiguille_minutes;
let theta_aiguille_heures;

let refreshIntervalId;

// dessin de l horloge
function dessine() {

    ctx.clearRect(0, 0, TAILLE, TAILLE);

    // fond noir
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, TAILLE, TAILLE);


    // losange jaune
    ctx.fillStyle = "yellow";

    ctx.beginPath();

    ctx.moveTo(TAILLE/2, 0);
    ctx.lineTo(TAILLE, TAILLE/2);
    ctx.lineTo(TAILLE/2, TAILLE);
    ctx.lineTo(0, TAILLE/2);

    ctx.closePath();
    ctx.fill();


    // carré rouge
    const tailleCarre = 250;
    const debut = (TAILLE - tailleCarre)/2;

    ctx.fillStyle = "red";
    ctx.fillRect(debut, debut, tailleCarre, tailleCarre);


    // cercle vert
    const centre = TAILLE/2;
    const rayon = tailleCarre/2;

    ctx.fillStyle = "lime";

    ctx.beginPath();
    ctx.arc(centre, centre, rayon, 0, 2*Math.PI);
    ctx.fill();


    // aiguille secondes en red

    ctx.strokeStyle = "red";
    ctx.lineWidth = 2;

    ctx.beginPath();

    ctx.moveTo(centre, centre);

    ctx.arc(
        centre,
        centre,
        rayon,
        theta_aiguille_secondes,
        theta_aiguille_secondes + Math.PI/100
    );

    ctx.stroke();


    // aiguille minutes en noir
    ctx.strokeStyle = "black";
    ctx.lineWidth = 4;

    ctx.beginPath();

    ctx.moveTo(centre, centre);

    ctx.arc(
        centre,
        centre,
        rayon,
        theta_aiguille_minutes,
        theta_aiguille_minutes + Math.PI/75
    );

    ctx.stroke();


    // aiguille heures
    ctx.strokeStyle = "black";
    ctx.lineWidth = 6;

    ctx.beginPath();

    ctx.moveTo(centre, centre);

    ctx.arc(
        centre,
        centre,
        rayon * (2/3),
        theta_aiguille_heures,
        theta_aiguille_heures + Math.PI/50
    );

    ctx.stroke();

}


// actualiser l heure   /Q4 et 6
function actualiseHeure() {

    let now = new Date();

    let secondes = now.getSeconds();
    let minutes = now.getMinutes();
    let heures = now.getHours();


    // calcul angles précis

    theta_aiguille_secondes =
        -Math.PI/2 + (2*Math.PI)*(secondes/60);

    theta_aiguille_minutes =
        -Math.PI/2 + (2*Math.PI)*((minutes + secondes/60)/60);

    theta_aiguille_heures =
        -Math.PI/2 + (2*Math.PI)*((heures%12 + minutes/60 + secondes/3600)/12);


    dessine();

}


// chargement
window.addEventListener("load", () => {

    canvas = document.getElementById("canvas");
    ctx = canvas.getContext("2d");


    // question 5
    actualiseHeure();


    // questionn 4
    refreshIntervalId = setInterval(actualiseHeure, 1000);

});