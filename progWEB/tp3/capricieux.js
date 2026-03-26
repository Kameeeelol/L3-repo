$(document).ready(function() {

    // QUESTION 2
    // bouton NON qui fuit la souris

    $("#btn-non").mouseenter(function() {

        let largeur = $(window).width();

        let hauteur = $(window).height();

        let x = Math.random() * (largeur - 100);

        let y = Math.random() * (hauteur - 50);


        $(this).css({

            left: x + "px",
            top: y + "px"

        });

    });

    // QUESTION 3
    // bouton OUI qui grossit

    $("#btn-oui").mouseenter(function() {

        $(this).css({

            transform: "scale(1.3)",
            fontSize: "22px"

        });

    });


    $("#btn-oui").mouseleave(function() {

        $(this).css({

            transform: "scale(1)",
            fontSize: "18px"

        });

    });

    // QUESTION 4
    // clic sur OUI

    $("#btn-oui").click(function() {

        $("body").html(

            "<h1>Bravo ! Bonne réponse 😄</h1>" +

            "<img src='https://media.giphy.com/media/111ebonMs90YLu/giphy.gif'>"

        );

    });


});