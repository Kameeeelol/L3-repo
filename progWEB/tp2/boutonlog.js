
let compteurClics = 0;

function changeCouleur(e) {
    const r = Math.floor(Math.random() * 256);
    const g = Math.floor(Math.random() * 256);
    const b = Math.floor(Math.random() * 256);
    
    e.target.style.backgroundColor = `rgb(${r}, ${g}, ${b})`;
}


function ajouteElementListe(e) {
    compteurClics++;

    const maintenant = new Date();
    const heures = maintenant.getHours();
    const minutes = maintenant.getMinutes();
    const secondes = maintenant.getSeconds();
  
    const heureFormattee = `${heures}h${minutes}'${secondes}`;
    
    const texteElement = `clic bouton n°${compteurClics} à ${heureFormattee}`;

    const nouvelElement = document.createElement('li');
    nouvelElement.textContent = texteElement;

    const liste = document.getElementById('liste');
    liste.appendChild(nouvelElement);
}

function videListe(e) {
    const liste = document.getElementById('liste');
    liste.innerHTML = ''; 
}

document.addEventListener('DOMContentLoaded', function() {
    const boutonCliquer = document.getElementById('cliquer');
    const boutonEffacer = document.getElementById('effacer');
    
    boutonCliquer.addEventListener('click', changeCouleur);
    boutonCliquer.addEventListener('click', ajouteElementListe);
 
    boutonEffacer.addEventListener('click', videListe);
});