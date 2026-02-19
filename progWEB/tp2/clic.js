window.addEventListener("load", () => {
    const articleDescription = document.getElementById("description");
    const image = document.getElementById("imagefilm");
    const titreGeneral = document.querySelector("header h1");
    
    articleDescription.addEventListener("click", () => {
        image.classList.toggle("arrondi");
    });
    
    titreGeneral.addEventListener("mouseover", () => {
        image.src = "images/brighter2.png";
    });
    
    titreGeneral.addEventListener("mouseout", () => {
        image.src = "images/brighter1.png";
    });
});