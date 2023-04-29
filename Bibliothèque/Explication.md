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



