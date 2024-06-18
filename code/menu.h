/**
 * Cyriac & Edouard
 */

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "population.h"
#include "queue.h"
#include "export.h"

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

/**
 * Affichage et gestion du menu
 * @param size -> Taille de la population
 * @param table -> Population
 */
void printMenu(int size, Person* table);

#endif