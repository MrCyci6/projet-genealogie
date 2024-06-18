document.addEventListener('DOMContentLoaded', () => {
    // Récupérer l'image de la personne
    let img = document.querySelector('.card img');
    // Changer l'image aléatoirement dans le fichier images
    img.setAttribute('src', `./images/photo_${getRandomInt(0, 10)}.jpg`);
});

// Retourne un entier aléatoire
function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min;
}