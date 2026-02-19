function range(a, b) {
    let debut;
    let fin;
    if (a<=b){
        debut = a;
        fin = b;
    }else{
        debut = b;
        fin = a;
    }
    let resultat = [];
    
    for (let i = debut; i <= fin; i++) {
        resultat.push(i);
    }
    
    return resultat;
}

console.log(range(3, 8));
console.log(range(10, 5));
console.log(range(-2, 2));


function range2(a, b) {
    let debut = Math.min(a, b);
    let fin = Math.max(a, b);
    let resultat = [];
    
    for (let i = debut; i <= fin; i++) {
        resultat.push(i);
    }
    
    return resultat;
}
console.log(range2(3, 8));
console.log(range2(10, 5));
console.log(range2(-2, 2));

// Version avec boucle for
function sommeFor(tableau) {
    let total = 0;
    for (let i = 0; i < tableau.length; i++) {
        total += tableau[i];
    }
    return total;
}

// Version avec boucle while
function sommeWhile(tableau) {
    let total = 0;
    let i = 0;
    while (i < tableau.length) {
        total += tableau[i];
        i++;
    }
    return total;
}

// Version avec forEach
function sommeForEach(tableau) {
    let total = 0;
    tableau.forEach(function(element) {
        total += element;
    });
    return total;
}

let nombres = range(1, 5);
console.log("Somme (for) : " + sommeFor(nombres));      
console.log("Somme (while) : " + sommeWhile(nombres));  
console.log("Somme (forEach) : " + sommeForEach(nombres)); 

function moyenne(tableau) {
    if (tableau.length === 0) return 0;
    
    let somme = 0;
    tableau.forEach(element => somme += element);
    return somme / tableau.length;
}

console.log("Moyenne [1,2,3,4,5] = " + moyenne(range(1, 5)));
console.log("Moyenne [10,20,30] = " + moyenne([10, 20, 30]));
console.log("Moyenne [] = " + moyenne([]));

function selectionne(t, pattern) {
    let resultat = [];
    
    t.forEach(function(chaine) {
        if (chaine.includes(pattern)) {
            resultat.push(chaine.toUpperCase());
        }
    });
    
    return resultat;
}

console.log(selectionne(["ile-de-france", "galilee", "universite"], "ile"));