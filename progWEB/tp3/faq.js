$(document).ready(function() {

    // question 3 :afficher ou masquer la réponse

    $(".question").click(function() {

        $(this).next(".reponse").slideToggle();

    });


    // question 4 
    $(".question").click(function() {

        let reponseCliquee = $(this).next(".reponse");

        // fermer toutes les autres réponses
        $(".reponse").not(reponseCliquee).slideUp();

    });

});
