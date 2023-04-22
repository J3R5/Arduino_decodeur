# Arduino décodeur 74HC238

### Introduction :

Ce __répertoire__ va parler du [Décodeur 74HC238](https://github.com/J3R5/Arduino_decodeur/blob/main/datasheet/74HC238.PDF) c'est un décodeur 3 vers 8. Ce **Mardown** va expliqué la fonctionnement d'un décodeur pour en règle général et aussi du **décodeur** 3 vers 8 **74HC238**. Pour savoir comment marche le décodeur avec la bibliothèque arduino il faut aller voir se [Mardown]() ou se [document](). Sinon, vous pouvez allez directement voir le [Code]().

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

#### Entrée Binaire : 

Les entrées binaires définisse les nombres de sortie avec la formule 2^X avec X etant le nombre d'entrée. Les entrées binaire ont 2 état logique 0 et 1 elle fonctionne donc en binaire. Dans le cas du décodeur utilisé 0 correspond a du 0V et l'état 1 a du 5V. Dans le cas d'une tension qui serait compris entre 0 et 5V par exemple 3V l'etat logique serait indeterminer. Dans le cas du décodeur 3 vers 8 74HC238 il y a trois entrée binaire A0, A1 et A2. A0 est le bit de rang 0 (2^0 = 1) soit a l'état 1 ca valeur est 1 et a l'état 0 ca valeur est 0. A1 est le bit de rang 1 (2^1 = 2) donc a l'état 0 ca valeur est 0 et la l'etat 1 ca valeur est 2. A2 est le bit de rang 2 (2^2 = 4) soit a l'etat 1 ca valeur est 4 et a l'etat 0 la valeur est 0.

Le resultat de l'addition des valeurs des différent état détermine la sortie a activé et a passer a l'etat 1 soit 5V.

#### Entrée de Validation :


