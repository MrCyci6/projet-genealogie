/**
 * Cyriac & Edouard
 */

#include "queue.h"

queue* emptyqueue(){
    // Initialisation d'une file vide
    queue *file = malloc(sizeof(queue));
    file->head=NULL;
    file->tail=NULL;
    return file;
}

void enqueue(queue* file, Person* person){
    // Création d'une nouvelle personne dans la file
    element* nouveau = malloc(sizeof(element));
    nouveau->person = person;
    nouveau->next = NULL;

    // Ajout de cette personne dans la file
    if(file->head == NULL){
        file->head = nouveau;
        file->tail = nouveau;
    }
    else {
        (file->tail)->next = nouveau;
        file->tail = nouveau;
    }
}

Person* dequeue(queue* file){
    element *p = file->head; // Récupérer la personne à supprimer
    file->head = p->next; // Redéfinir le début de la file
    Person* n = p->person;
    free(p); // Libérer la personne de la file en mémoire
    return n; // Retourner la structure de la personne
}

int max(int v1, int v2) {
    return v1 > v2 ? v1 : v2;
}

int heightBetween(Person* person, Person* to, int height) {
    if(person == NULL || to == NULL) {
        return 0;
    }

    if(person->id == to->id) {
        // Si la personne est égale à son objectif, retourner la hauteur qui les séparent
        return height;
    }

    int leftHeight = heightBetween(person->p_father, to, height + 1); // Récupérer la hauteur du père
    if (leftHeight != 0) { // Si la hauteur n'est pas nulle
        return leftHeight;
    }

    return heightBetween(person->p_mother, to, height + 1); // Récupérer la hauteur de la mère
}

void printfGeneration(Person *p) {
    // Initialisation de la file
    queue *f = emptyqueue();
    // Ajout du descendant dans la file
    enqueue(f, p);

    int height = 0;

    while(f->head != NULL) {
        Person* person = dequeue(f);

        if (person->p_father != NULL) {
            enqueue(f, person->p_father);
        }
        if (person->p_mother != NULL) {
            enqueue(f, person->p_mother);
        }

        int h = heightBetween(p, person, 1); // Hauteur entre la racine et la personne selectionnée
        // Affichage de son arbre
        if (h != -1 && h > height) {
            printf("\n\x1b[%dmGénération %d:\n", RED, h);
            printf("    \x1b[%dmID: \x1b[%dm%d \x1b[%dmNom: \x1b[%dm%s \x1b[%dmPrénom: \x1b[%dm%s\n",
                   GREEN, YELLOW,
                   person->id,
                   GREEN, YELLOW,
                   person->lastname,
                   GREEN, YELLOW,
                   person->firstname);
            height = h;
        } else {
            printf("    \x1b[%dmID: \x1b[%dm%d \x1b[%dmNom: \x1b[%dm%s \x1b[%dmPrénom: \x1b[%dm%s\n",
                   GREEN, YELLOW,
                   person->id,
                   GREEN, YELLOW,
                   person->lastname,
                   GREEN, YELLOW,
                   person->firstname);
        }

    }

    printf("\n");
}