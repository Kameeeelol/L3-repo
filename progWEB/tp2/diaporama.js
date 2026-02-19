// diaporama.js

// Tableau des sources d'images
const sources = new Array(
    'images/diapo1.jpg', 
    'images/diapo2.jpg', 
    'images/diapo3.jpg', 
    'images/diapo4.jpg', 
    'images/diapo5.jpg', 
    'images/diapo6.jpg', 
    'images/diapo7.jpg', 
    'images/diapo8.jpg', 
    'images/diapo9.jpg', 
    'images/diapo10.jpg'
);

// Variable globale pour l'indice courant (initialisée après chargement)
let indiceCourant = 0;

window.addEventListener("load", () => {
    // Récupération de l'élément image
    const image = document.getElementById("photo");
    
    // Initialisation de l'image (au cas où)
    image.src = sources[indiceCourant];
    
    // Ajout de l'écouteur de clic sur l'image
    image.addEventListener("click", () => {
        // Passage à l'image suivante (circulaire)
        indiceCourant = (indiceCourant + 1) % sources.length;
        
        // Mise à jour de la source de l'image
        image.src = sources[indiceCourant];
    });
});