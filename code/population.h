/**
 * Cyriac & Edouard
 */

#ifndef POPULATION_H
#define POPULATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LASTNAME_SIZE 500
#define FIRSTNAME_SIZE 500
#define ZIPCODE_SIZE 500
#define LINE_SIZE 300
#define DOB_SIZE 11
#define ITEMS 7

#define FILENAME 40

/**
 * Structure d'une personne de la population
 */
typedef struct person {
    int id;
    int father_id;
    int mother_id;

    char lastname[LASTNAME_SIZE];
    char firstname[FIRSTNAME_SIZE];
    char dob[DOB_SIZE];
    char zipcode[ZIPCODE_SIZE];

    struct person* p_father;
    struct person* p_mother;

    struct person* simbling;
    int simblingSize;
} Person;

/**
 * Récupérer la structure d'une personne depuis une ligne du fichier excel
 * @param line -> Ligne selectionnée
 * @param length -> Longueur de la ligne
 * @return
 */
Person getPerson(char* line, int length);

/**
 * Récupérer la structure d'une personne depuis son Nom et Prénom
 * @param firstname -> Prénom de la personne à chercher
 * @param lastname -> Nom de la personne à chercher
 * @param people -> Population
 * @param size -> Taille de la population
 * @return
 */
Person getPersonByFullName(char* firstname, char* lastname, Person* people, int size);

/**
 * Récupérer les frères et soeurs d'une personne.
 * Cette fonctionnalité n'est pas dans les exports HTML car elle augmenterait la compléxité grandement
 * Mais elle est là lorsque l'on cherche les informations d'une personne en particulier
 * @param person -> Personne à chercher la fraterie
 * @param people -> Population
 * @param size -> Taille de la population
 */
void initSimbling(Person* person, Person* people, int size);

/**
 * Insérer dans un tableau le paramètre d'une ligne du tableau
 * Cette fonction fait office de "split"
 * @param line -> String à récupérer
 * @param string -> Tableau des paramètres
 * @param index -> L'indice où s'arrêter pour obtenir le paramètre sans coupure
 * @param wordCount -> L'indice du mot récupéré
 */
void copyToIndex(char line[LINE_SIZE], char string[ITEMS][ZIPCODE_SIZE], int index, int wordCount);

/**
 * Récupérer le nombre de personne dans un fichier excel
 * @param file -> Fichier excel choisi
 * @return nombre de personne dans la population
 */
int sizeOfFile(char file[FILENAME]);

/**
 * Insérer une personne dans la population
 * @param file -> Fichier excel de la population
 * @param people -> Population
 */
void pushOnTableFromFile(char file[FILENAME], Person* people);

/**
 * Affichage des informations d'une personne de la population
 * @param people -> Personne selectionnée
 */
void printInfos(Person* people);

/**
 * Création de l'arbre d'une personne en récursivité
 * @param person -> Personne à définir en racine
 * @param people -> Population
 */
void createTree(Person* person, Person* people);

/**
 * Affichage en postfixe de l'arbre d'une personne
 * @param person -> Personne selectionnée
 */
void postfixe(Person* person);

/**
 * Affichage en prefixe de l'arbre d'une personne
 * @param person -> Personne selectionnée
 */
void prefixe(Person* person);

/**
 * Affichage en infixe de l'arbre d'une personne
 * @param person -> Personne selectionnée
 */
void infixe(Person* person);

/**
 * Savoir si deux strings sont égaux
 * @param str1 -> String 1
 * @param str2 -> String 2
 * @return 0 pour faux et 1 pour vrai
 */
int isEqual(char* str1, char* str2);

#endif