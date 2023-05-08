### Bibliothèque JC_Decodeur :

Ce document va expliqué comment fonctionne et utilisé la **bibliothèque** *JC_decodeur.* Dans un **premier temps** pour utiliser la *bibliothèque* il faut télécharger la bibliothèque **(JC_decodeur.zip)** et l'ajouter au autre bibliothèque. Voici un [tuto](https://fablabutc.fr/wp-content/uploads/2021/01/Tutoriel_Installer-une-bibliotheque-pour-Arduino.pdf).

Important la bibliothèque s'appelle JC_decodeur pour eviter d'éventuelle conflit avec une autre bibliothèque de decodeur si elle portait un nom similaire a juste décodeur.

### Ajout de la bibliothèque :

Une fois la bibliothèque ajouter il faut l'inclure dans le programme ou l'on veux s'en servir.

On le fait via un #include :

~~~C++

#include <JC_decodeur.h>

~~~

Une fois cette ligne mis dans un programme on peut l'utilisée.

### Créeation du décodeur :

Cette **bibliothèque** permet de se servir de **plusieurs décodeur** en même temps pour cela chaque *décodeur* a ces propres fonctions.

Pour créer *un décodeur* on doit effectuer **la ligne suivante :**

~~~C++

JC_decodeur decodeur_exemple;

~~~

Dans se cas on n'as créer un decodeur de nommer *decodeur_exemple*. **JC_decodeur** est la class des décodeurs. Toutes les *commandes* de ce decodeur commenceront par **decodeur_exemple.XXXX** (**XXXX** étant la fonction).

### Fonction d'initialisation :

Pour se servir de la **bibliothèque** il y a des fonctions d'initialisation. Ces différentes fonctions permettent d'initialisées les différentes broche du *decodeur*.

#### Initialisation broche de validation :

Pour initialiser les broches de **valisation** il existe *2 méthodes* :

1) Dans le cas ou toutes **les broches du décodeurs** sont utilisé par **l'arduino** on peut utilisé cette commande :

~~~C++

  decodeur_exemple.Init_Validation(5,6,7);

~~~

Dans ce cas on attribue **les 3 pins** des 3 **entrées de validation** dans l'ordre suivant **E1**, **E2** et **E3**. Il est **très important** que si cette ligne est utilisée il faut que toute **les entrées** ai un **numéro** et que **leurs numéros** sois **différent** sinon il risque d'y avoir **des problèmes** par la suite. La fonction va déclarer chaque ces 3 numéros comme sortie.

2) Dans le cas ou l'on utilise **1 ou 2 entrées** de validation :

Si toutes **les entrées de validation** ne sont pas **utilisée** il est possible de déclarer les entrées séparement via ces commandes :

~~~C++

  //Pour e1
  decodeur_exemple.Init_Validation_e1(5);

  //Pour e2
  decodeur_exemple.Init_Validation_e2(6);

  //Pour e3
  decodeur_exemple.Init_Validation_e3(7);
  
~~~

Ici on déclare **E1**, **E2** et **E3** séparrement. Cela donne **exactement le même résulat** que la ligne au dessus mais ces commandes **permettent de ne pas en déclarer une par exemple.**

#### Initialisation Code binaire :

Une autre partie a initialisée hormis les entrées binaires sont *les entrées de validation*. Pour **initialiser** ces entrées **il n'existe qu'une seul commande.** La **raison est que les trois entrées de validation** sont *utilisé* pour déterminer la sortie a activé.

~~~C++

  decodeur_exemple.Init_CodeBinaire(2, 3, 4);  

~~~

Cette *commande* prend les différents **Pin** dans l'ordre suivant **A0, A1, A2** et va les **déclarer** en temps que **sortie.** 

#### Erreur a ne pas faire :

Il est **important** de ne pas faire certaine chose dans **l'initialisation.** Par exemple il ne faut pas que les différentes broche initialisée ont les mêmes Pin sinon les commande ne marche pas. Il ne faut non plus utilisé les mêmes pin pour le code binaire ou **les entrées analogique.**

Il **ne faut pas utilisé** la commande pour initialisé **les 3 pins des entrées** en même temps puis utilisé un commande qui n'en **initialise 1 pin.**

Il ne faut pas changer **ces Pins** en cours de route.

### Fonction Sortie :

Après avoir initialisée les Pin on peut utilisé les différentes commande pour piloté les sortie.

#### Pilotage Entrée de validation :

Pour **piloté les entrées de validations** on peut utilisé différente **commande.**

1) Pilotage global

On peut **utilisé une commande** qui permet de **piloté toutes les entrées de validation** en même temps.

~~~C++

  decodeur_exemple.Validation(1, 0, 1);

~~~

Cette comande va envoyer du **5V** pour **1** et **0V** pour **0.** **Les sorties sont pilotées dans l'ordre suivant E1, E2 et E3.** Cela ne veux pas dire que si l'on envoie du 5V la sortie sera a l'état 1, comme dans le cas ou la sortie est inversée.

2) pilotage selectif :

Dans le cas ou l'on veut changer l'état que de 1 seul entrée de validation on peut utilisé ces commandes :

~~~C++

  //E1
  decodeur_exemple.Validation_E1(1);

  //E2
  decodeur_exemple.Validation_E2(0);

  //E3
  decodeur_exemple.Validation_E3(1);

~~~

Voici **les 3 commandes** pour initialiser **E1**, **E2** et **E3** séparrement. On peut utiliser ces commandes si l'on change l'état de que l'une **des entrées.*

#### Pilotage Entrée Binaire :

Il existe **2 façons** de **piloté les entrées binaire** qui vont affecté **les sorties binaire.** On peut sois utilisé **le code binaire** a envoyer sois décider d'allumer une **sortie binaire spécifique.**

##### Pilotage via Code Binaire

Le pilotage via code binaire se fait de 2 façons sois global sois spécifique.

1) Pilotage global :

Pour Piloté globalement il existe 1 commande :

~~~C++

  decodeur_exemple.Code_binaire(0, 1, 1);

~~~

Dans ce cas **la commande** pilote **les trois sorties** en une commande. **L'ordre de pilotage** est le suivant **A0**, **A1** et **A2**. 1 envoie du 5V et 0 envoie du 0V.

2) Pilotage Séparée :

On peut faire **la même chose** avec **trois commandes** :

~~~C++

  //A0
  decodeur_exemple.Code_a0(0);

  //A1
  decodeur_exemple.Code_a1(1);

  //A2
  decodeur_exemple.Code_a2(1);

~~~

Ici on fait **la même chose** mais avec **une commande** qui pilote une sortie différente.

3) Pilotage Décimal :

La dernière méthode de **pilotage** est de choisir **la sortie a allumé.**

~~~C++

  decodeur_exemple.Code_decimal(5);

~~~

Dans ce cas c'est **la sortie 5** qui va être activée. On peut choisir **un nombre entre 0 et 7** pour utilisé cette commande.

### Fin 

Ceci est toutes les commandes de la bibliothèque. Pour voir comment marche le programme exemple il faut aller voir le [Document]() sinon pour savoir comment marche un décodeur il faut aller voir le premier [markdown](https://github.com/J3R5/Arduino_decodeur/blob/main/README.md).



