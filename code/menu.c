/**
 * Cyriac & Edouard
 */

#include "menu.h"

void printMenu(int size, Person* table) {
    // Initialisation des nécéssaires pour le menu
    int choix = 0;
    int id = 0;
    char firstname[FIRSTNAME_SIZE];
    char lastname[LASTNAME_SIZE];
    Person* person = NULL;

    do {
        printf("\x1b[%dm", RED);
        printf("\n----- MENU -----\n");
        printf("\x1b[%dm", WHITE);
        printf("1. \x1b[%dmAfficher l'arbre d'une personne\x1b[%dm\n", CYAN, WHITE);
        printf("2. \x1b[%dmAfficher les informations d'une personne\x1b[%dm\n", CYAN, WHITE);
        printf("3. \x1b[%dmExporter les informations d'une personne dans un fichier html\x1b[%dm\n", CYAN, WHITE);
        printf("4. \x1b[%dmExporter l'arbre et les informations d'une personne dans un fichier html\x1b[%dm\n", CYAN, WHITE);
        printf("5. \x1b[%dmExporter les informations et les arbres de la population dans un fichier HTML\x1b[%dm\n", CYAN, WHITE);
        printf("0. \x1b[%dmQuitter\x1b[%dm\n", CYAN, WHITE);
        printf("\x1b[%dm", RED);
        printf("-----------------\n");
        printf("\x1b[%dm", GREEN);
        printf("Que voulez-vous faire ? ");
        printf("\x1b[%dm", WHITE);
        scanf("%d", &choix); // Récupération du choix de la personne

        if(choix == 0) { // Quit
            printf("\x1b[%dm", WHITE);
            return;
        }

        if(choix == 5) { // Export de la population
            printf("Vous avez choisi d'exporter les informations et l'arbre de toute la population dans un fichier HTML.\n");
            printf("\x1b[%dm", WHITE);

            cleanExportFolder(); // Nettoyage du fichier d'exportation

            printf("Exportation des arbres.\n");
            long initDate = time(NULL);
            for(int i = 0; i < size; i++) {
                createExportFile(&table[i]); // Création de l'arbre de la personne avec l'id i
            }
            long finalDate = time(NULL) - initDate;
            printf("\x1b[%dm", GREEN);
            printf("Exportation finie en \x1b[%dm%ld \x1b[%dmseconde(s).\x1b[%dm\n", YELLOW, finalDate, GREEN, WHITE);
            exportDepends(); // Exporter le css, js et les images
        } else {

            printf("\x1b[%dm", GREEN);
            printf("Quel est le nom et le prénom de la personne selectionnée ?\nNom: ");
            printf("\x1b[%dm", WHITE);

            // Récupération du Nom et Prénom de la personne à séléctionner
            fgetc(stdin);
            fgets(lastname, LASTNAME_SIZE, stdin);

            printf("\x1b[%dm", GREEN);
            printf("Prénom: ");
            printf("\x1b[%dm", WHITE);

            fgets(firstname, FIRSTNAME_SIZE, stdin);

            // Suppression des retour à la ligne à la fin des strings
            if(lastname[strlen(lastname)-1] == '\n') lastname[strlen(lastname)-1] = '\0';
            if(firstname[strlen(firstname)-1] == '\n') firstname[strlen(firstname)-1] = '\0';

            // Récupération de la personne
            Person p = getPersonByFullName(firstname, lastname, table, size);
            person = &p;

            long initDate = time(NULL);
            printf("\x1b[%dm", CYAN);
            switch (choix) {
                case 1:
                    printf("Vous avez choisi d'afficher l'arbre d'une personne.\n");
                    printf("\x1b[%dm", WHITE);
                    printfGeneration(person); // Affichage de l'arbre de la personne
                    break;
                case 4:
                    printf("Vous avez choisi d'exporter l'arbre et les informations d'une personne dans un fichier HTML.\n");
                    printf("\x1b[%dm", WHITE);
                    cleanExportFolder(); // Nettoyage du fichier d'exportation
                    printf("Exportation des arbres.\n");
                    createExportFile(person); // Créer l'arbre d'une personne en particulier
                    singleExportFile(person); // Créer les fiches des ancêtres de la personne
                    exportDepends(); // Exporter le css, js et les images
                    break;
                case 2:
                    printf("Vous avez choisi d'afficher les informations d'une personne.\n");
                    printf("\x1b[%dm", WHITE);
                    printInfos(person); // Afficher les informations de la personne

                    initSimbling(person, table, size); // Récupérer la fraterie de la personne

                    printf("\n----- FRATERIE -----\n\n");
                    for(int i = 0; i < person->simblingSize; i++) { // Affichage
                        printf("ID: %d Nom: %s Prénom: %s\n", person->simbling[i].id, person->simbling[i].lastname, person->simbling[i].firstname);
                    }
                    printf("\n----------------------------\n");
                    break;
                case 3:
                    printf("Vous avez choisi d'exporter les informations d'une personne dans un fichier HTML.\n");
                    printf("\x1b[%dm", WHITE);
                    cleanExportFolder(); // Nettoyage du fichier d'exportation
                    printf("Exportation des informations.\n");
                    createExportInfos(person); // Créer l'exportation des informations de la personne
                    exportDepends(); // Exporter le css, js et les images
                    break;
            }

            long finalDate = time(NULL) - initDate;
            printf("\x1b[%dm", GREEN);
            printf("Tache réalisée en \x1b[%dm%ld \x1b[%dmseconde(s).\x1b[%dm\n", YELLOW, finalDate, GREEN, WHITE);
        }
    } while (choix >= 0 && choix <= 6);
}