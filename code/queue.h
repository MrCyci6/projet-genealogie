/**
 * Cyriac & Edouard
 */

#ifndef QUEUE_H
#define QUEUE_H

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

#include "population.h"

/**
 * Personne de la file et son suivant
 */
typedef struct _element {
    Person* person;
    struct _element* next;
} element;

/**
 * File
 */
typedef struct _queue {
    element* head;
    element* tail;
} queue;

/**
 * Création d'une file vide
 * @return file
 */
queue* emptyqueue();

/**
 * Retirer la première personne de la file
 * @param file -> File selectionnée
 * @return personne retirée de la file
 */
Person* dequeue(queue* file);

/**
 * Ajouter une personne à la fin de la file
 * @param file -> File selectionée
 * @param noeud -> Personne à ajouter
 */
void enqueue(queue* file, Person* noeud);

/**
 * Affichage de l'arbre d'une personne grâce au parcours en largeur
 * @param person -> Personne selectionnée
 */
void printfGeneration(Person *person);

/**
 * Hauteur entre la racine d'un arbre et une de ses branches
 * @param person -> Racine de l'arbre
 * @param to -> Branche
 * @param height -> Variable temporaire qui sauvegarde la hauteur
 * @return hauteur entre une personne et son déscendant
 */
int heightBetween(Person* person, Person* to, int height);

/**
 *
 * @param v1 -> Entier 1
 * @param v2 -> Entier 2
 * @return entier le plus grand entre v1 et v2
 */
int max(int v1, int v2);

#endif