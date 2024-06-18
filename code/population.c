/**
 * Cyriac & Edouard
 */

#include "population.h"

Person getPerson(char* line, int length) {

    // Initialisation du tableau final des paramètres
    char string[ITEMS][ZIPCODE_SIZE];
    int wordCount = 0;
    int stop = 0;

    // Si la ligne ne respecte pas les critères 0,0,0,-,-,-,-
    // Créer un utilisateur vide
    if(length < 13) {
        Person person;

        person.id = 0;
        person.father_id = 0;
        person.mother_id = 0;

        strcpy(person.lastname, "-");
        strcpy(person.firstname, "-");
        strcpy(person.dob, "-");
        strcpy(person.zipcode, "-");

        person.p_father = NULL;
        person.p_mother = NULL;

        return person;
    }

    for(int i = 0; i < length; i++) {
        // Pour chaque caractère de la ligne, s'arrêter à la virgule ou à la fin
        if(line[i-stop] == ',' || line[i-stop] == '\0') {
            copyToIndex(line, string, i-stop, wordCount); // Récupérer le paramètre
            line = line+(i-stop)+1; // Redéfinir le début de la ligne après la virgule
            stop = i; // Récupérer l'indice d'arrêt
            wordCount++; // Incrémenter le nombre de mot dans le splitter
        }
    }

    // Définir la personne avec les paramètres récupérés
    Person person;

    person.id = atoi(string[0]);
    person.father_id = atoi(string[1]);
    person.mother_id = atoi(string[2]);

    strcpy(person.lastname, string[3]);
    strcpy(person.firstname, string[4]);
    strcpy(person.dob, string[5]);
    strcpy(person.zipcode, string[6]);

    person.p_father = NULL;
    person.p_mother = NULL;

    return person;
}

Person getPersonByFullName(char* firstname, char* lastname, Person* people, int size) {
    for(int i = 0; i < size; i++) {
        // Verifier si les nom et prénoms correspondent dans le fichier
        if(isEqual(firstname, people[i].firstname) && isEqual(lastname, people[i].lastname)) {
            return people[i]; // Personne correspondante
        }
    }
    return getPerson("", 0); // Personne vide
}

void initSimbling(Person* person, Person* people, int size) {
    // Initialiser le tableau de la fraterie
    person->simblingSize = 0;
    person->simbling = malloc(person->simblingSize*sizeof(Person));

    for(int i = 0; i < size; i++) {
        // Si les deux parents sont égaux
        if(person->father_id == people[i].father_id && person->mother_id == people[i].mother_id) {
            // Agrandir le tableau de la fraterie pour qu'une personne en plus puisse s'y insérer
            person->simblingSize++;
            person->simbling = realloc(person->simbling, person->simblingSize*sizeof(Person));
            person->simbling[person->simblingSize-1] = people[i]; // Ajout de frère ou de la soeur
        }
    }
}

void copyToIndex(char line[LINE_SIZE], char string[ITEMS][ZIPCODE_SIZE], int index, int wordCount) {
    for(int i = 0; i < index; i++) {
        // Copie du paramètre dans le splitter
        string[wordCount][i] = line[i];
    }
    string[wordCount][index] = '\0'; // Mettre fin à la chaine de caractère
}

int sizeOfFile(char file[FILENAME]) {
    FILE* data;
    data = fopen(file, "r"); // Ouverture du fichier en mode lecture

    if(data == NULL) { // Erreur
        fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", file);
    } else {
        int length = 0;

        while(!feof(data)) {
            char* line = NULL;
            size_t len = 0;

            getline(&line, &len, data);
            length++; // Incrémenter la population à chaque nouvelle ligne
            free(line);
        }

        fclose(data);
        return length;
    }
}

void pushOnTableFromFile(char file[FILENAME], Person* people) {
    FILE* data;
    data = fopen(file, "r"); // Ouvrir le fichier en mode lecture

    if(data == NULL) { // Erreur
        fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", file);
    } else {

        while(!feof(data)) {
            char* line = NULL;
            size_t len = 0;

            getline(&line, &len, data); // Récupérer une ligne

            int length = strlen(line); // Longueur de la ligne
            Person person = getPerson(line, length); // Initialisation de la personne associée
            people[person.id] = person; // Insérer la personne dans le tableau

            free(line);
        }

        fclose(data);
    }
}

void printInfos(Person* person) {

    // Affichage des informations de la personne person
    printf("\n----- INFORMATIONS -----\n\n");

    printf("Prénom : %s\n",person->firstname);
    printf("Nom : %s\n",person->lastname);
    printf("Date de naissance : %s\n",person->dob);
    printf("Région de naissance : %s",person->zipcode);

    // Affichage de ses parents s'ils ne sont pas nuls
    if(person->p_father != NULL) printf("Père : %s %s\n",person->p_father->lastname, person->p_father->firstname);
    if(person->p_mother != NULL) printf("Mère : %s %s\n",person->p_mother->firstname, person->p_mother->lastname);
}

void createTree(Person* person, Person* people) {
    if(person != NULL) {
        // Si le père n'est pas vide, le lier à son enfant et recommencer
        if(person->father_id != 0) {
            person->p_father = &people[person->father_id];
            createTree(person->p_father, people);
        }
        // Si la mère n'est pas vide, la lier à son enfant et recommencer
        if(person->mother_id != 0) {
            person->p_mother = &people[person->mother_id];
            createTree(person->p_mother, people);
        }
    }
}

void postfixe(Person* person) {
    if(person != NULL) {
        postfixe(person->p_father);
        postfixe(person->p_mother);
        printf("ID: %d Nom: %s Prénom: %s\n", person->id, person->lastname, person->firstname);
    }
}

void prefixe(Person* person) {
    if(person != NULL) {
        printf("ID: %d Nom: %s Prénom: %s\n", person->id, person->lastname, person->firstname);
        prefixe(person->p_father);
        prefixe(person->p_mother);
    }
}

void infixe(Person* person) {
    if(person != NULL) {
        infixe(person->p_father);
        printf("ID: %d Nom: %s Prénom: %s\n", person->id, person->lastname, person->firstname);
        infixe(person->p_mother);
    }
}

int isEqual(char* str1, char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    if(length1 != length2) return 0;
    for(int i = 0; i < length1; i++) {
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}