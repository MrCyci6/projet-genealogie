/**
 * Cyriac & Edouard
 */

#include "export.h"

void createExport(Person* root, Person* p, FILE* file, int generation) {
    if (p != NULL) {
        // Création de la personne p dans l'arbre
        fprintf(file, "        <!-- Génération %d -->\n", generation);
        fprintf(file, "        <li> <a href=\"fiche-%d.html\" id=\"%d\"><br/>%s %s</a>\n",
                p->id, p->id, p->lastname, p->firstname);

        // Si la personne p a des parents, ajout des parents dans l'arbre de la personne.
        if (p->p_father != NULL || p->p_mother != NULL) {
            fprintf(file, "            <ul>\n");
            createExport(root, p->p_father, file, generation + 1);
            createExport(root, p->p_mother, file, generation + 1);
            fprintf(file, "            </ul>\n");
        }

        fprintf(file, "        </li>\n");
    }
}

void singleExportFile(Person* root) {
    if(root->p_father != NULL) {
        createExportFile(root->p_father); // Création de la fiche du père
        singleExportFile(root->p_father);
    }
    if(root->p_mother != NULL) {
        createExportFile(root->p_mother); // Création de la fiche de la mère
        singleExportFile(root->p_mother);
    }
}

void createExportFile(Person* root) {
    // Initialisation du non du fichier en fonction de l'id de la personne
    char filename[150];
    sprintf(filename, "./exports/fiche-%d.html", root->id);
    FILE* file = fopen(filename, "w"); // Ouverture du fichier en mode écriture

    if(file == NULL) { // Erreur
        fprintf(stderr, "Une erreur s'est produite lors de l'ouverture de fiche-%d.html.\n", root->id);
    } else {

        // Ajout du header de l'arbre
        fprintf(file, "<!DOCTYPE html>\n"
                      "<html lang=\"fr\">\n"
                      "<head>\n"
                      "    <meta charset=\"utf-8\">\n"
                      "    <title>Généalogie de %s</title>\n"
                      "    <link rel=\"stylesheet\" href=\"./css/style.css\">\n"
                      "</head>\n"
                      "<body>\n"
                      "\n"
                      "<h1>ARBRE GENEALOGIQUE</h1>\n"
                      "\n", root->firstname);

        // Ajout des informations de la personne sous forme de carte
        fprintf(file, "\n"
                      "<div class=\"infos\">\n"
                      "    <div class=\"arrow\">\n"
                      "        <a href=\"fiche-%d.html\">back</a>\n"
                      "    </div>\n"
                      "    <div class=\"card\">\n"
                      "        <img src=\"./images/photo_0.jpg\" alt=\"photo\">\n"
                      "        <ul>\n"
                      "            <li><p>Prénom: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Nom: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Dob: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Région: <span class=\"color\">%s\n"
                      "</span></p></li>\n"
                      "            <li><p><a href=\"fiche-%d.html\">Père: <span class=\"color\">%s %s</span></a></p></li>\n"
                      "            <li><p><a href=\"fiche-%d.html\">Mère: <span class=\"color\">%s %s</span></a></p></li>\n"
                      "        </ul>\n"
                      "    </div>    \n"
                      "    <div class=\"arrow\">\n"
                      "        <a href=\"fiche-%d.html\">after</a>\n"
                      "    </div>\n"
                      "</div>\n",
                root->id <= 1 ? 1 : root->id-1,
                root->firstname,
                root->lastname,
                root->dob,
                root->zipcode,
                root->father_id, root->p_father == NULL ? "" : root->p_father->lastname, root->p_father == NULL ? "" : root->p_father->firstname,
                root->mother_id, root->p_mother == NULL ? "" : root->p_mother->lastname, root->p_mother == NULL ? "" : root->p_mother->firstname,
                root->id+1
        );

        // Ajout du header de l'arbre
        fprintf(file, "<div class=\"tree\">\n"
                      "    <ul>\n"
                      "        <!-- Génération 1 -->\n"
                      "        <li> <a href=\"fiche-%d.html\" id=\"%d\">%s %s</a>\n",
                      root->id, root->id, root->lastname, root->firstname);

        // Création et ajout des branches
        if (root->p_father != NULL || root->p_mother != NULL) {
            fprintf(file, "            <ul>\n");
            createExport(root, root->p_father, file, 2);
            createExport(root, root->p_mother, file, 2);
            fprintf(file, "            </ul>\n");
        }

        // Footer de l'arbre
        fprintf(file, "        </li>\n"
                      "    </ul>\n"
                      "</div>\n"
                      "\n"
                      "<script src=\"./js/index.js\"></script>\n"
                      "</body>\n"
                      "</html>");

        fclose(file);
    }
}

void createExportInfos(Person* root) {
    // Initialisation du non du fichier en fonction de l'id de la personne
    char filename[150];
    sprintf(filename, "./exports/fiche-%d.html", root->id);
    FILE* file = fopen(filename, "w"); // Ouverture du fichier en mode écriture

    if(file == NULL) { // Erreur
        fprintf(stderr, "Une erreur s'est produite lors de l'ouverture de fiche-%d.html.\n", root->id);
    } else {

        // Ajout du header de la page
        fprintf(file, "<!DOCTYPE html>\n"
                      "<html lang=\"fr\">\n"
                      "<head>\n"
                      "    <meta charset=\"utf-8\">\n"
                      "    <title>Généalogie de %s</title>\n"
                      "    <link rel=\"stylesheet\" href=\"./css/style.css\">\n"
                      "    <link rel=\"stylesheet\" href=\"./css/infos.css\">\n"
                      "</head>\n"
                      "<body>\n"
                      "\n"
                      "<h1>ARBRE GENEALOGIQUE</h1>\n"
                      "\n", root->firstname);

        // Ajout des informations d'une personne sous forme de carte
        fprintf(file, "\n"
                      "<div class=\"infos\">\n"
                      "    <div class=\"arrow\">\n"
                      "        <a href=\"fiche-%d.html\">back</a>\n"
                      "    </div>\n"
                      "    <div class=\"card\">\n"
                      "        <img src=\"./images/photo_0.jpg\" alt=\"photo\">\n"
                      "        <ul>\n"
                      "            <li><p>Prénom: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Nom: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Dob: <span class=\"color\">%s</span></p></li>\n"
                      "            <li><p>Région: <span class=\"color\">%s\n"
                      "</span></p></li>\n"
                      "            <li><p><a href=\"fiche-%d.html\">Père: <span class=\"color\">%s %s</span></a></p></li>\n"
                      "            <li><p><a href=\"fiche-%d.html\">Mère: <span class=\"color\">%s %s</span></a></p></li>\n"
                      "        </ul>\n"
                      "    </div>    \n"
                      "    <div class=\"arrow\">\n"
                      "        <a href=\"fiche-%d.html\">after</a>\n"
                      "    </div>\n"
                      "</div>\n",
                root->id <= 1 ? 1 : root->id-1,
                root->firstname,
                root->lastname,
                root->dob,
                root->zipcode,
                root->father_id, root->p_father == NULL ? "" : root->p_father->lastname, root->p_father == NULL ? "" : root->p_father->firstname,
                root->mother_id, root->p_mother == NULL ? "" : root->p_mother->lastname, root->p_mother == NULL ? "" : root->p_mother->firstname,
                root->id+1
        );

        // Footer de la page
        fprintf(file, "<script src=\"./js/index.js\"></script>\n"
                      "</body>\n"
                      "</html>");

        fclose(file);
    }
}

void cleanExportFolder() {
    printf("Nettoyage de l'ancienne exportation...\n");
    system("rm -rf ./exports; mkdir ./exports"); // Suppression récursive de exports, puis re-création de export
}

void exportDepends() {
    printf("Importation des dépendences...\n");
    system("cp -r ./template/css ./exports/css"); // Copie du dossier css dans l'export
    system("cp -r ./template/js ./exports/js"); // Copie du dossier js dans l'export
    system("cp -r ./template/images ./exports/images"); // Copie du dossier images dans l'export
}