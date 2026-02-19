function semaine() {
    let date = new Date();
    let jour = date.getDay();
    
    if (jour === 1) {
        return "Dur le lundi !";
    } else if (jour === 5) {
        return "Bientôt le week-end";
    } else if (jour === 0 || jour === 6) {
        return "Youhou, c'est le week-end !";
    } else {
        return "Au boulot !";
    }
}
console.log(semaine());

function moyenne(tableau) {
    if (tableau.length === 0) return 0;
    
    let somme = 0;
    tableau.forEach(element => somme += element);
    return somme / tableau.length;
}

function somme(tableau) {
    let total = 0;
    for (let i = 0; i < tableau.length; i++) {
        total += tableau[i];
    }
    return total;
}

function statsTableau(tableau) {
    return {
        nombre: tableau.length,
        somme: somme(tableau),
        moyenne: moyenne(tableau)
    };
}
let tableau = [12, 11, 15, 9, 10, 15];
console.log(statsTableau(tableau));
