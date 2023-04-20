# Arduino décodeur 74HC238

### Introduction :

Ce __répertoire__ va parler du [Décodeur 74HC238]() c'est un décodeur 3 vers 8. Ce **Mardown** va expliqué la fonctionnement d'un décodeur pour en règle général et aussi du **décodeur** 3 vers 8 **74HC238**. Pour savoir comment marche le décodeur avec la bibliothèque arduino il faut aller voir se [Mardown]() ou se [document](). Sinon, vous pouvez allez directement voir le [Code]().

### Principe d'un Décodeur :

Le principe d'un **decodeur** est le suivant, avec un nombre de sortie on peut activer une nombre de sortie plus grand. **Le nombre de sortie que l'on peut activée dépend de la fomule suivante 2^X avec X etant le nombre d'entrée.** Dans le cas du décodeur 74HC238 c'est un décodeur 3 vers 8 donc il y a 3 entrée et 2^3 = 8 donc c'est bien un décodeur 3 vers 8. Le code se fait en binaire on convertir le code binaire des entrées pour activé la bonne sortie.

### Différente partie d'un décodeur :

Un décodeur contient plusieurs partie :

* Les entrées binaires.
* Les entrées de validations.
* Les sorties binaires.

### Binaire :

Le decodeur fonctionne en **Binaire** c'est a dire en état logique 0-1 donc par exemple un décodeur qui fonctionne en 0/5V il envoie soit du 0V soit du 5V. 

Voici un lien vers un [cours](https://lehollandaisvolant.net/tuto/bin/) qui permet d'en apprendre plus sur le binaire.

Sinon se tableau suffira :

![Tableau binaire 3 bits](https://github.com/J3R5/Arduino_decodeur/blob/main/datasheet/photo_tableau_binaire.png)
