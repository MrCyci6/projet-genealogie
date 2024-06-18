# GENEA TREE

## Projet

Le but de ce projet est de réaliser l'arbre généalogique d'une population importée dans un fichier.csv.
Chaque ligne du fichier doit se composer de cette façon:

*ID,ID_père,ID_mère,Nom,Prénom,Date de naissance,Lieu de naissance*

## Compléxité

- n = nombre de personnes

>> Avec AMD Ryzen 3 3250U

- n = 40 -> 0 seconde
- n = 200 -> 2 secondes
- n = 1000 -> 6 secondes
- n = 2500 -> 23 secondes
- n = 5000 -> 55 secondes
- n = 10000 -> 101 secondes

`C(n) ~= n/112`

>> Avec AMD Ryzen 7 5700X

- n = 40 -> 0 seconde
- n = 200 -> 0 secondes
- n = 1000 -> 0 secondes
- n = 2500 -> 0 secondes
- n = 5000 -> 0 secondes
- n = 10000 -> 1 secondes

`C(n) = n/10000`

## Utilisation

**Genea Tree** doit être utilisé sous un OS **Unix**.
>> Prérequis

```sh
sudo apt install gcc
```
```sh
sudo apt install cmake
```

>> Lancement

Une fois les outils de compilation installés, passons au lancement du logiciel
```sh
git clone https://github.com/MrCyci6/projet-genealogie.git; cd projet-a1-cyriac-edouard; chmod u+x ./script.sh
```
```sh
./script.sh
```
Lors du lancement de **Genea Tree** vous devrez choisir quel **fichier.csv** de population voulez vous utiliser.
Vous n'avez qu'à le renseigner et **c'est parti** !

## Crédits

***Toutes les images utilisées** dans ce code sont **générées** par de l'intelligence artificielle et sont **libres de droit***

*Par Cyriac LENOIR & Edouard JOUHRI*
