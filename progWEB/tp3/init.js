// Utilisation de la syntaxe jQuery pour attendre le chargement du DOM (html)
$(document).ready(function() {
    console.log("jQuery est prêt et chargé !");
    
    $('#btnStyle').click(function() { //actions a faire lors d'un click
        $('h1').css('color','darkblue');
        $('p').css('border','1px solid black');
        $('li:odd').css('background-color','lightgrey')

    });


    // Exemple 
    $('#message').text("jQuery est bien initialisé et prêt à l'emploi.");
    
    //style 
    $('#message').css('color', 'green');
});