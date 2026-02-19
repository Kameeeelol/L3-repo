function calculeAge(annee) {
    let anneeCourante = new Date().getFullYear();
    return anneeCourante - annee;
}

function demandeEtCalculeAge() {
    let anneeNaissance = prompt("Entrez votre année de naissance :");
    let age = calculeAge(parseInt(anneeNaissance));
    
    document.write("<h1>Calcul de l'âge</h1>");
    document.write("<p>Vous avez " + age + " ans.</p>");
}

function demandeEtCalculeAgeAmelioree() {
    let anneeCourante = new Date().getFullYear();
    let anneeNaissance;
    let valide = false;
    
    while (!valide) {
        anneeNaissance = prompt("Entrez votre année de naissance (ex: 1990) :");
        
        // Vérification si l'utilisateur a annulé
        if (anneeNaissance === null) {
            document.write("<p>Opération annulée par l'utilisateur.</p>");
            return;
        }
        
        anneeNaissance = parseInt(anneeNaissance);
        
        if (isNaN(anneeNaissance)) {
            alert("Erreur : Veuillez entrer un nombre valide.");
        } else if (anneeNaissance > anneeCourante) {
            alert("Erreur : L'année ne peut pas être dans le futur.");
        } else {
            valide = true;
        }
    }
    
    let age = calculeAge(anneeNaissance);
    
    // Efface le document et écrit le résultat
    document.open();
    document.write("<!DOCTYPE html><html><head><title>Résultat</title></head><body>");
    document.write("<h1>Votre âge</h1>");
    document.write("<p>Né(e) en " + anneeNaissance + ", vous avez " + age + " ans.</p>");
    document.write("<p><a href='calculeAge.html'>Retour</a></p>");
    document.write("</body></html>");
    document.close();
}

console.log("Né en 2000 -> âge :", calculeAge(2000));
console.log("Né en 1995 -> âge :", calculeAge(1995));
console.log("Né en 2020 -> âge :", calculeAge(2020));
demandeEtCalculeAgeAmelioree();
    