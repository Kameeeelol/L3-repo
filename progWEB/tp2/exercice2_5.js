class Eleve {
    constructor(numero, nom, prenom, ddn, courriel) {
        this.numero = numero;
        this.nom = nom;
        this.prenom = prenom;
        this.ddn = new Date(ddn);
        this.courriel = courriel;
        this.notes = [];
    }

    age() {
        let aujourdhui = new Date();
        let anneeNaissance = this.ddn.getFullYear();
        let moisNaissance = this.ddn.getMonth();
        let jourNaissance = this.ddn.getDate();
        
        let age = aujourdhui.getFullYear() - anneeNaissance;
        
        if (aujourdhui.getMonth() < moisNaissance || 
            (aujourdhui.getMonth() === moisNaissance && aujourdhui.getDate() < jourNaissance)) {
            age--;
        }
        
        return age;
    }
    formatDate() {
        let jour = this.ddn.getDate().toString().padStart(2, '0');
        let mois = (this.ddn.getMonth() + 1).toString().padStart(2, '0');
        let annee = this.ddn.getFullYear();
        
        return `${jour}/${mois}/${annee}`;
    }
    
    affiche() {
        console.log(`${this.nom.toUpperCase()} ${this.prenom} - Né(e) le ${this.formatDate()}`);
    }
        ajoutNote(matiere, note) {
            if (note < 0 || note > 20) {
                console.error("La note doit être comprise entre 0 et 20");
                return;
            }
            let noteExistante = this.notes.find(n => n.matiere === matiere);
            if (noteExistante) {
                console.log(`Mise à jour de la note de ${matiere} (ancienne: ${noteExistante.note}, nouvelle: ${note})`);
                noteExistante.note = note;
            } else {
                this.notes.push({ matiere: matiere, note: note });
            }
        }
 
        moyenne() {
            if (this.notes.length === 0) {
                return 0;
            }
            
            let somme = 0;
            for (let i = 0; i < this.notes.length; i++) {
                somme += this.notes[i].note;
            }
            
            return somme / this.notes.length;
        }
        
        static annivMois(tableauEleves, mois) {

            if (mois < 1 || mois > 12) {
                console.error("Le mois doit être compris entre 1 et 12");
                return [];
            }
            
            let moisIndex = mois - 1;
            
            return tableauEleves.filter(eleve => eleve.ddn.getMonth() === moisIndex);
        }
}


console.log("=== Création des élèves ===");
let eleve1 = new Eleve(1, "Dupont", "Jean", "2005-03-15", "jean@email.com");
let eleve2 = new Eleve(2, "Martin", "Sophie", "2006-07-22", "sophie@email.com");
let eleve3 = new Eleve(3, "Bernard", "Lucas", "2005-03-03", "lucas@email.com");
let eleve4 = new Eleve(4, "Petit", "Emma", "2006-11-30", "emma@email.com");

console.log("\n=== Test de ajoutNote (Question 3) ===");
eleve1.ajoutNote("Maths", 15);
eleve1.ajoutNote("Français", 12);
eleve1.ajoutNote("Anglais", 18);
console.log("Notes de Jean :", eleve1.notes);

eleve1.ajoutNote("Maths", 17);
console.log("Notes après mise à jour Maths :", eleve1.notes);

eleve2.ajoutNote("Maths", 14);
eleve2.ajoutNote("Histoire", 16);

console.log("\n=== Test de moyenne (Question 4) ===");
console.log("Moyenne de Jean :", eleve1.moyenne()); 
console.log("Moyenne de Sophie :", eleve2.moyenne()); 
console.log("Moyenne de Lucas (sans notes) :", eleve3.moyenne());

console.log("\n=== Test de annivMois (Question 5) ===");
let tousLesEleves = [eleve1, eleve2, eleve3, eleve4];

let anniversairesMars = Eleve.annivMois(tousLesEleves, 3);
console.log("Anniversaires en mars :");
anniversairesMars.forEach(e => console.log(`- ${e.prenom} ${e.nom} (${e.formatDate()})`));

let anniversairesJuillet = Eleve.annivMois(tousLesEleves, 7);
console.log("\nAnniversaires en juillet :");
anniversairesJuillet.forEach(e => console.log(`- ${e.prenom} ${e.nom} (${e.formatDate()})`));

let anniversairesNovembre = Eleve.annivMois(tousLesEleves, 11);
console.log("\nAnniversaires en novembre :");
anniversairesNovembre.forEach(e => console.log(`- ${e.prenom} ${e.nom} (${e.formatDate()})`));
