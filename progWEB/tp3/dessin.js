const TAILLE=500;
let theta = 0; // Angle initial (0 radian)
const PAS = Math.PI / 8; //  La valeur du décalage demandée

function dessine(){

    //récuperer l'element canva en 2D
    const canvas = document.querySelector('canvas');
    if(!canvas) return ;
    const dessin = canvas.getContext('2d');

    // le carré noir 
    dessin.fillStyle = "black" ;
    dessin.fillRect(0,0,500,500); //fillRect : Dessine un rectangle rempli

    // losange jaune
 dessin.fillStyle="yellow";
 dessin.beginPath();
// notes CM : moveTo(x,y) : déplacement en (x,y) sans trace
//lineTo(x,y) : trace une ligne depuis la position courante jusqu’au point (x,y)
 dessin.moveTo(250,0); //haut milieu
 dessin.lineTo(500,250); //droite milieu
 dessin.lineTo(250,500); //bas milieu
 dessin.lineTo(0,250); //gauche milieu
 dessin.closePath();
 dessin.fill();

 //Carré rouge central
 //Un carré de 250px centré 
    const tailleRouge = 250;
    const offsetRouge = (500 - 250) / 2; //125 125 les cotés
    dessin.fillStyle = "red";
    dessin.fillRect(offsetRouge, offsetRouge, tailleRouge, tailleRouge);

    const centreX = TAILLE / 2;
    const centreY = TAILLE / 2;
    const rayon = TAILLE / 4;

    //cercle vert
    dessin.fillStyle="lime";
    dessin.beginPath();
    dessin.beginPath();
    dessin.arc(centreX, centreY, rayon, 0, 2 * Math.PI);
    dessin.fill();

    //secteur bleu
    dessin.fillStyle = "blue";
    dessin.beginPath();
    dessin.moveTo(centreX, centreY); //on part du centre pour créer la pointe
    //arc de 0 à environ 45 degrés (PI / 4)
    dessin.arc(centreX, centreY, rayon, theta,theta + Math.PI / 4);
    dessin.closePath(); //referme le tracé vers le centre
    dessin.fill();






}

function decaleTrigo() {
    theta -= PAS; 
    dessine();
}

function decaleAntiTrigo() {
    theta += PAS;
    dessine();
}


window.addEventListener("load", () => {
 dessine();
 });

//clic de souris
 document.addEventListener("click", () => {
    decaleTrigo();
});

//touches du clavier
document.addEventListener("keypress",(e) =>{
if (e.key === 'g'){
    decaleTrigo(); //sens
}
else if (e.key=== 'd'){
    decaleAntiTrigo(); //sens horaire
}
})





 
