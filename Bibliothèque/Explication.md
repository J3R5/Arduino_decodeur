### Bibliothèque JC_Decodeur :

Ce document va expliquer comment fonctionne et on utilise la **bibliothèque** *JC_decodeur.* Dans un **premier temps** pour utiliser la *bibliothèque*, il faut télécharger la bibliothèque **(JC_decodeur.zip)** et l'ajouter aux bibliothèques. Voici un [tuto](https://fablabutc.fr/wp-content/uploads/2021/01/Tutoriel_Installer-une-bibliotheque-pour-Arduino.pdf).

Important la bibliothèque s'appelle JC_decodeur pour éviter d'éventuel conflit avec une autre bibliothèque de décodeur si elle s'appelait juste décodeur.

### Ajout de la bibliothèque :

Une fois la bibliothèque ajoutée,  il faut l'inclure dans le programme où l'on veut s'en servir.

On le fait via un #include :

~~~C++

#include <JC_decodeur.h>

~~~

Une fois cette ligne mis dans un programme on peut l'utiliser.

### Création du décodeur :

Cette **bibliothèque** permet de se servir de **plusieurs décodeurs** en même temps, pour cela chaque *décodeur* a ses propres fonctions.

Pour créer *un décodeur*, on doit effectuer **la ligne suivante :**

~~~C++

JC_decodeur decodeur_exemple;

~~~

Dans ce cas, on a crée un décodeur nommé *decodeur_exemple*. **JC_decodeur** est la class des décodeurs. Toutes les *commandes* de ce décodeur commenceront par **decodeur_exemple.XXXX** (**XXXX** étant la fonction).

### Fonction d'initialisation :

Pour se servir de la **bibliothèque**, il y a des fonctions d'initialisation. Ces différentes fonctions permettent d'initialiser les différentes broches du *décodeur*.

#### Initialisation broche de validation :

Pour initialiser les broches de **validation** il existe *2 méthodes* :

1) Dans le cas où toutes **les broches du décodeur** sont utilisées par **l'arduino** on peut utiliser cette commande :

~~~C++

  decodeur_exemple.Init_Validation(5,6,7);

~~~

Dans ce cas, on attribue **les 3 pins** des 3 **entrées de validation** dans l'ordre suivant **E1**, **E2** et **E3**. Il est **très important** que si cette ligne est utilisée, il faut que toutes **les entrées** aient un **numéro** et que **leurs numéros** soient **différents** sinon il risque d'y avoir **des problèmes** par la suite. La fonction va déclarée chacun de ses 3 numéros comme sortie.

2) Dans le cas où l'on utilise **1 ou 2 entrées** de validation :

Si toutes **les entrées de validation** ne sont pas **utilisées**, il est possible de déclarer les entrées séparement via ces commandes :

~~~C++

  //Pour e1
  decodeur_exemple.Init_Validation_e1(5);

  //Pour e2
  decodeur_exemple.Init_Validation_e2(6);

  //Pour e3
  decodeur_exemple.Init_Validation_e3(7);
  
~~~

Ici, on déclare **E1**, **E2** et **E3** séparément. Cela donne **exactement le même résulat** que la ligne au dessus mais ces commandes **permettent de ne pas en déclarer une par exemple.**

#### Initialisation Code binaire :

Une autre partie à initialisée hormis les entrées binaires sont *les entrées de validation*. Pour **initialiser** ces entrées **il n'existe qu'une seule commande.** La **raison est que les trois entrées de validation** sont *utilisé* pour déterminer la sortie à activée.

~~~C++

  decodeur_exemple.Init_CodeBinaire(2, 3, 4);  

~~~

Cette *commande* prend les différents **Pins** dans l'ordre suivant **A0, A1, A2** et va les **déclarer** en temps que **sortie.** 

#### Erreur à ne pas faire :

Il est **important** de ne pas faire certaines choses dans **l'initialisation.** Par exemple, il ne faut pas que les différentes broches initialisées aient les mêmes Pins, sinon les commandes ne marchent pas. Il ne faut non plus utiliser les mêmes pins pour le code binaire ou **les entrées analogiques.**

Il **ne faut pas utiliser** la commande pour initialiser **les 3 pins des entrées** en même temps, puis utiliser une commande qui **n'initialise qu'un pin.**

Il ne faut pas changer **ces Pins** en cours de route.

### Fonction Sortie :

Après avoir initialisé les Pins, on peut utiliser les différentes commandes pour piloter les sorties.

#### Pilotage Entrée de validation :

Pour **piloter les entrées de validations**, on peut utiliser différentes **commandes.**

1) Pilotage global

On peut **utiliser une commande** qui permet de **piloter toutes les entrées de validation** en même temps.

~~~C++

  decodeur_exemple.Validation(1, 0, 1);

~~~

Cette comande va envoyer du **5V** pour **1** et **0V** pour **0.** **Les sorties sont pilotées dans l'ordre suivant E1, E2 et E3.** Cela ne veut pas dire que si l'on envoit du 5V la sortie sera à l'état 1, comme dans le cas où la sortie est inversée.

2) pilotage selectif :

Dans le cas où l'on veut changer l'état que d'une seule entrée de validation on peut utiliser ces commandes :

~~~C++

  //E1
  decodeur_exemple.Validation_E1(1);

  //E2
  decodeur_exemple.Validation_E2(0);

  //E3
  decodeur_exemple.Validation_E3(1);

~~~

Voici **les 3 commandes** pour initialiser **E1**, **E2** et **E3** séparément. On peut utiliser ces commandes si l'on change l'état de qu'une **des entrées.*

#### Pilotage Entrée Binaire :

Il existe **2 façons** de **piloter les entrées binaires** qui vont affectées **les sorties binaires.** On peut soit utiliser **le code binaire** à envoyer, soit décider d'allumer une **sortie binaire spécifique.**

##### Pilotage via Code Binaire

Le pilotage via code binaire se fait de 2 façons soit global soit spécifique.

1) Pilotage global :

Pour Piloter globalement, il existe 1 commande :

~~~C++

  decodeur_exemple.Code_binaire(0, 1, 1);

~~~

Dans ce cas, **la commande** pilote **les trois sorties** en une commande. **L'ordre de pilotage** est le suivant **A0**, **A1** et **A2**. 1 envoit du 5V et 0 envoit du 0V.

2) Pilotage Séparé :

On peut faire **la même chose** avec **trois commandes** :

~~~C++

  //A0
  decodeur_exemple.Code_a0(0);

  //A1
  decodeur_exemple.Code_a1(1);

  //A2
  decodeur_exemple.Code_a2(1);

~~~

Ici on fait **la même chose**, mais avec **une commande** qui pilote une sortie différente.

3) Pilotage Décimal :

La dernière méthode de **pilotage** est de choisir **la sortie à allumer.**

~~~C++

  decodeur_exemple.Code_decimal(5);

~~~

Dans ce cas, c'est **la sortie 5** qui va être activée. On peut choisir **un nombre entre 0 et 7** pour utiliser cette commande.

### Fin 

Ce document montre toutes les commandes de la bibliothèque. Pour voir comment marche le programme exemple, il faut aller voir le [Document](https://github.com/J3R5/Arduino_decodeur/blob/main/Documentation/Decodeur_74HC238.pdf) sinon pour savoir comment marche un décodeur, il faut aller voir le premier [markdown](https://github.com/J3R5/Arduino_decodeur/blob/main/README.md).



