function min(a,b){
    return a < b ? a : b;
}

function max(a,b){
    return a > b ? a : b;
}

function iter(){
    let i = 1;
    for (i; i<=100; i++){
        if (i % 3 === 0){
            console.log(i);
            console.log("Divisible par 3");
        } else if (i % 5 === 0) {
            console.log(i);
            console.log("Divisible par 5");
        }else{
            console.log(i);
        }
        if (i === 93){
            console.log("Seine-Saint-Denis!");
        }
    }
}

function puissance(x, n){
    let i = 1
    let j = x;
    for (i; i<n; i++){
        j *= x;
    }
    return j;
}

function puissancerec(x, n){
    if (n===1) return x;
    if (n===0) return;
    return x * puissancerec(x, n-1);
}

console.log("Minimum entre 75 et 93 est : " + min(93,75))
console.log("Minimum entre 54 et 35 est : " + min(54,35))
console.log("Maximum entre 75 et 93 est : " + max(93,75))
iter();
console.log("2⁸ = " + puissance(2, 8));
console.log("2⁸ = " + puissancerec(2, 8));
