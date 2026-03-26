$(document).ready(function() {

    $('#btn-envoyer').click(function() {
        let formulaireValide = true;

        //Quest 3:parcours de tous les champs input
        $('#mon-formulaire input').each(function() {
            // on verif si la valeur est vide
            if ($(this).val().trim() === "") {
                $(this).addClass('erreur');
                formulaireValide = false; // Une erreur a été trouvée
            } else {
                $(this).removeClass('erreur');
            }
        });

        //question 4 : Effet de tremblement si erreur
        if (!formulaireValide) {
            secouerFormulaire();
        } else {
            alert("Formulaire envoyé !");
        }
    });

    //faire trembler le formulaire
    function secouerFormulaire() {
        const form = $('#mon-formulaire');
        // On déplace a gauche puis a droite et retour a 0
        form.animate({ left: "-10px" }, 50)
            .animate({ left: "10px" }, 50)
            .animate({ left: "-10px" }, 50)
            .animate({ left: "10px" }, 50)
            .animate({ left: "0px" }, 50);
    }

});