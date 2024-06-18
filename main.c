/**
 * Cyriac & Edouard
 */

#include <time.h>

#include "code/population.h"
#include "code/export.h"
#include "code/menu.h"

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

int main(int argc, char *argv[]) {

    printf("\x1b[2J"); // Clear le terminal
    printf("\x1b[%d;%dH", 0, 0); // Définir la position d'écriture en haut du terminal
    printf("\x1b[%dm", YELLOW); // Couleur en jaune
    printf("  ___________________ _______  ___________   _____    ___________________________________________\n"
           " /  _____/\\_   _____/ \\      \\ \\_   _____/  /  _  \\   \\__    ___/\\______   \\_   _____/\\_   _____/\n"
           "/   \\  ___ |    __)_  /   |   \\ |    __)_  /  /_\\  \\    |    |    |       _/|    __)_  |    __)_ \n"
           "\\    \\_\\  \\|        \\/    |    \\|        \\/    |    \\   |    |    |    |   \\|        \\ |        \\\n"
           " \\______  /_______  /\\____|__  /_______  /\\____|__  /   |____|    |____|_  /_______  //_______  /\n"
           "        \\/        \\/         \\/        \\/         \\/                     \\/        \\/         \\/ \n");
    printf("\x1b[%dm", WHITE); // Couleur en blanc

    long initDate = time(NULL); // Récupérer le timestamp de départ

    int numberOfPeople = sizeOfFile(argv[1]); // Récupérer le nombre de personne dans le fichier choisi
    Person* table = malloc(numberOfPeople * sizeof(Person)); // Initialiser le tableau des structures

    printf("\x1b[%dm", GREEN);
    printf("\nInitialisation de %d personnes...\n", numberOfPeople-2);

    pushOnTableFromFile(argv[1], table); // Insérer toutes les structures dans le tableau

    for(int i = 0; i < numberOfPeople; i++) {
        createTree(&table[i], table); // Créer l'arbre de chaque personne du tableau
    }


    long finalDate = time(NULL) - initDate; // Récupérer le temps d'éxecution du programme avec le timestamp de fin
    printf("Toutes les personnes ont été chargées avec succès en \x1b[%dm%ld \x1b[%dmseconde(s).\n", YELLOW, finalDate, GREEN);
    printf("\x1b[%dm", WHITE);

    printMenu(numberOfPeople, table); // Afficher le menu

    finalDate = time(NULL) - initDate;
    printf("\n\x1b[%dmVotre utilisation sur \x1b[%dmGENEA TREE \x1b[%dma durée \x1b[%dm%ld \x1b[%dmseconde(s).\x1b[%dm\n",
           GREEN, RED, GREEN, YELLOW, finalDate, GREEN, WHITE);

    free(table); // Libérer le tableau des personnes en mémoire
    return 0;
}
