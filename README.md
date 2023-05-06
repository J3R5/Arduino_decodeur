# Arduino décodeur 74HC238

### Introduction :

Ce __répertoire__ va parler du [Décodeur 74HC238](https://github.com/J3R5/Arduino_decodeur/blob/main/datasheet/74HC238.PDF) c'est un décodeur 3 vers 8. Ce **Mardown** va expliqué la fonctionnement d'un décodeur pour en règle général et aussi du **décodeur** 3 vers 8 **74HC238**. Pour savoir comment marche le décodeur avec la bibliothèque arduino il faut aller voir se [Mardown](https://github.com/J3R5/Arduino_decodeur/blob/main/Biblioth%C3%A8que/Explication.md) ou se [document](). Sinon, vous pouvez allez directement voir le [Code]().

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

  Les entrées binaires définisse **les nombres de sortie** avec la formule **2^X** avec **X** etant le nombre d'entrée. Les entrées binaire ont 2 état logique 0 et 1 elle fonctionne donc en binaire. Dans le cas du décodeur utilisé 0 correspond a du 0V et l'état **1** a du **5V**. Dans le cas d'une tension qui serait compris entre 0 et 5V par exemple **3V** l'etat logique serait indeterminer. Dans le cas du décodeur **3** vers **8** **74HC238** il y a trois entrée binaire **A0, A1 et A2**. **A0** est le bit de rang 0 _(2^0 = 1)_ soit a l'état 1 ca valeur est 1 et a l'état 0 ca valeur est 0. **A1** est le bit de rang 1 _(2^1 = 2)_ donc a l'état 0 ca valeur est 0 et la l'etat 1 ca valeur est 2. **A2** est le bit de rang 2 _(2^2 = 4)_ soit a l'etat 1 ca valeur est 4 et a l'etat 0 la valeur est 0.

Le resultat de l'addition des valeurs des différent état détermine la sortie a activé et a passer a l'etat 1 soit 5V.

#### Entrée de Validation :

  les entrées de validation sont important dans le fonctionnement du systeme en effet c'est elle qui permette de définir si le systeme est actif ou non. Le système est dit actif si la sortie correspondant au entrée binaire est a l'état 1. le système est dit inactif si toutes les sorties binaire sont a l'état 0. On peut donc résumer les entrées de validation comme des interrupteur qui permettent d'activer ou non le système. Pour activer le système il faut que toutes les entrée de validation soit a 1 c'est a dire qu'elle recoit un signal de 5V dans le cas du decodeur **74HC238**. Dans le cas ou une entrée du decodeur n'est pas a 1 le système n'est pas actif. Dans le cas ou une entrées se trouve entre l'etat 0 et 1 le système est dans un état indeterminées. Les entrées de validation peuvent etre inverser ou non c'est a dire que une entrée non inverser l'état d'entrée est l'état de la sortie par exemple si a l'entrée de validation on as 1 l'entrée est a 1. Dans le cas d'une entrée inversé l'etat a l'entrée est l'opposée de l'entrée c'est a dire que si on envoie du 5V a l'entrée donc l'état 1 l'entrée de validation sera a 0. Ces entrées inversé sont symbolisée par un rond sur leur entrée comme E2 et E1 du décodeur **74HC238**. En résumer pour que un décodeur fonctionne normalement il faut que toute ces entré de validation soit a l'état haut c'est a dire 1.

#### Sortie Binaire :

  Les sortie Binaires sont les sorties qui vont être activé en fonction du code en entrée. Les sorties sont suppérieurs au nombre d'entrées. Une seul sortie peux être activée a la fois car il dépend du code en entrée. Les sorties binaire tous comme les entrées binaire et de validation ont 2 été 0 ou 1 donc sois elle envoie 0V soit 5V pas entre les deux. Le resultats de toutes les sorties binaire sera 0V si le module n'est pas alimentée ou que toute les entrées de validation ne sont pas a l'état logique 1. Dans le cas ou le module est alimentée et que toutes les entrée de validation sont a 1 l'une des sorties du décodeurs sera activée.

### Décodeur 74HC238 3 vers 8 :

  Pour finir voici une petite explication du décodeur **74HC238** 3 vers 8. Ce décodeur possède 3 entrées de validation et donc 8 sortie Binaire. il possède aussi 3 entrées de validation 2 en entrée inverser et 1 en entrée non inverser. Il fonction en 5 que se soit le Vcc, les entrées ou les sorties.



