let premiereImage = null;
let premierClic = true;


function auditeur_clic(evenement) {
    const imageCliquee = evenement.target;
    
    if (premierClic) {
        premiereImage = imageCliquee;
        premierClic = false;
        imageCliquee.style.opacity = '0.7';
    } else {
        if (premiereImage) {
            premiereImage.style.opacity = '1';
        }
        
        const srcTemp = imageCliquee.src;
        imageCliquee.src = premiereImage.src;
        premiereImage.src = srcTemp;
        
        premiereImage = null;
        premierClic = true;
    }
}

document.addEventListener('DOMContentLoaded', function() {
    const imagesPuzzle = document.querySelectorAll('#images img');
    
    imagesPuzzle.forEach(function(image) {
        image.addEventListener('click', auditeur_clic);
    });
});