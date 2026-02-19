function creerMultiplicateur(n) {
    return function(x) {
        return x * n;
    };
}

let multipli4 = creerMultiplicateur(4);

console.log("Test : creerMultiplicateur(4)(3) = " + multipli4(3)); 
console.log("Test : creerMultiplicateur(93)(22) = " + creerMultiplicateur(93)(22)); 

function creerSequence(init, step) {
    let valeur = init; 
    return function() {
        let resultat = valeur;
        valeur += step;
        return resultat;
    };
}

let seq43 = creerSequence(4, 3);
let seq21 = creerSequence(2, 1);

console.log("Test : creerSequence(4, 3)");
console.log(seq43());
console.log(seq43());
console.log(seq43()); 

console.log("Test : creerSequence(2, 1)");
console.log(seq21()); 
console.log(seq21()); 
console.log(seq21()); 

function fibonacci(u0, u1) {
    let a = u0;
    let b = u1;
    let premierAppel = true;
    return function() {
        if (premierAppel) {
            premierAppel = false;
            return a + b;
        }
        let suivant = a + b;
        a = b;
        b = suivant;
        return suivant;
    };
}

let fibolapins = fibonacci(1, 1);
console.log("fibolapins appel 1 : " + fibolapins());
console.log("fibolapins appel 2 : " + fibolapins());
console.log("fibolapins appel 3 : " + fibolapins());
console.log("fibolapins appel 4 : " + fibolapins());

function creerMultiplicateur2(n, x) {
    if (x !== undefined) {
        return n * x;
    } else {
        return function(y) {
            return y * n;
        };
    }
}

let multipli5 = creerMultiplicateur2(5);
console.log("creerMultiplicateur2(5)(2) = " + multipli5(2));
console.log("creerMultiplicateur2(3,4) = " + creerMultiplicateur2(3,4));

function formatter(numero_initial) {
    let compteur = numero_initial;
    
    return function(message) {
        let resultat = compteur + ": " + message;
        compteur++;
        return resultat;
    };
}

let f = formatter(10);
console.log(f('il fait beau'));
console.log(f('il fait chaud'));
console.log(f('il fait froid'));

function logger(format, ecriture) {
    return function(message) {
        let messageFormate = format(message);
        ecriture(messageFormate);
    };
}

let nb = 1;
let monlogger = logger(
    (chaine) => "message " + nb++ + " : " + chaine,
    console.log
);

monlogger('coucou');
monlogger('ça va ?');