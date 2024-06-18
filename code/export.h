/**
 * Cyriac & Edouard
 */

#ifndef EXPORT_H
#define EXPORT_H

#include "population.h"
#include "queue.h"

/**
 * Fonction récursive pour ajouter une branche à l'arbre de la personne racine
 * @param root -> Personne racine de l'export
 * @param p -> Personne dans l'arbre de la racine
 * @param file -> Fichier dans lequel l'export doit se créer
 * @param generation -> Numéro de la génération actuelle
 */
void createExport(Person* root, Person* p, FILE* file, int generation);

/**
 * Créer un export HTML de l'arbre et des informations d'une personne.
 * @param root -> Personne concernée par l'export
 */
void createExportFile(Person* root);

/**
 * Créer un export HTML avec la dépendence de seulement une personne
 * @param root -> Personne choisie
 */
void singleExportFile(Person* root);

/**
 * Créer un export HTML des informations d'une personne.
 * @param root -> Personne concernée par l'export
 */
void createExportInfos(Person* root);

/**
 * Supprimer tous les fichiers du dossier exports pour le remettre à 0.
 */
void cleanExportFolder();

/**
 * Copier les fichiers css, js et les images dans le dossier de l'exportation.
 */
void exportDepends();

#endif