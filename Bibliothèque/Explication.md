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

Cette bibliothèque permet de se servir de plusieurs décodeur en même temps pour cela chaque décodeur a ces propres fonction.

Pour créer un décodeur on doit effectuer la ligne suivante :

~~~C++

JC_decodeur decodeur_exemple;

~~~

Dans se cas on n'as créer un decodeur de nommer decodeur_exemple. JC_decodeur est la class des décodeurs.

### Fonction d'initialisation :

Pour se servir de la bibliothèque il y a des fonctions d'initialisation.




