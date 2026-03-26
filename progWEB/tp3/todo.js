$(document).ready(function(){

    $('#add').click(function(){
        //recuperer le texte
       const message = $('#tache').val();
        if (message.trim() !== ""){ 
            //creer l'element
            $('#liste-taches').append('<li>' + message + '</li>') ;

            //vider le champ texte
            $('#tache').val("");

            //focus sur linput
            $('#tache').focus();

        }
        else{
            alert("veuillez saisir du texte a ajouter SVP")
        }

    });
    //supprimer une tache
    //demander a liste-taches d'ecouter les clics de ses futurs enfants
    $('#liste-taches').on('click','li',function(){
        $(this).remove(); //represente le truc qui a ete cliqué

    });
// vider toute la liste 
$('#btn-vider').click(function() {
    $('#liste-taches').empty(); //vide tout le contenu interieur du UL
});

//Effet de fondu sur la liste
$('#btn-toggle').click(function() {
    $('#liste-taches').fadeToggle(400); //400ms pour l'effet de fondu
});

});