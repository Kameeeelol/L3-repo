function saisirNombre(message) {
    let nombre;
    let valide = false;
    
    while (!valide) {
        let saisie = prompt(message);
        
        if (saisie === null) {
            return null;
        }
        
        nombre = parseFloat(saisie);

        if (isNaN(nombre)) {
            alert("Erreur : Veuillez entrer un nombre valide.");
        } else if (nombre < 0) {
            alert("Erreur : Veuillez entrer un nombre positif ou nul.");
        } else {
            valide = true;
        }
    }
    
    return nombre;
}

function somme(tableau) {
    let total = 0;
    for (let i = 0; i < tableau.length; i++) {
        total += tableau[i];
    }
    return total;
}

function moyenne(tableau) {
    if (tableau.length === 0) return 0;
    
    let somme = 0;
    tableau.forEach(element => somme += element);
    return somme / tableau.length;
}

function calculeMoyenne() {
    let n = saisirNombre("Combien d'entiers voulez-vous saisir ?");

    if (n === null) {
        document.write("<p>Opération annulée par l'utilisateur.</p>");
        return;
    }

    n = Math.floor(n);

    let nombres = [];

    for (let i = 0; i < n; i++) {
        let nombre = saisirNombre("Entrez l'entier n°" + (i + 1) + " :");
  
        if (nombre === null) {
            document.write("<p>Saisie interrompue.</p>");
            return;
        }
        
        nombres.push(nombre);
    }

    let moy = moyenne(nombres);

    document.open();
    document.write("<!DOCTYPE html><html><head><title>Résultat</title></head><body>");
    document.write("<h1>Résultat de la saisie</h1>");

    nombres.forEach(function(valeur, index) {
        document.write("<p>Entier " + (index + 1) + " = " + valeur + "</p>");
    });

    document.write("<p><strong>Moyenne = " + moy + "</strong></p>");
    
    document.write("<p><a href='calculeMoyenne.html'>Nouveau calcul</a></p>");
    
    document.write("</body></html>");
    document.close();
}

calculeMoyenne();