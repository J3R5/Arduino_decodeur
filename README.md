# Arduino décodeur 74HC238

### Introduction :

Ce __répertoire__ va parler du [Décodeur 74HC238](https://github.com/J3R5/Arduino_decodeur/blob/main/datasheet/74HC238.PDF) c'est un décodeur 3 vers 8. Ce **Mardown** va expliquer le fonctionnement d'un décodeur en règle générale et aussi du **décodeur** 3 vers 8 **74HC238**. Pour savoir comment marche le décodeur avec la bibliothèque arduino, il faut aller voir ce [Mardown](https://github.com/J3R5/Arduino_decodeur/blob/main/Biblioth%C3%A8que/Explication.md) ou ce [document](https://github.com/J3R5/Arduino_decodeur/blob/main/Documentation/Decodeur_74HC238.pdf) pour le code exemple. Sinon, vous pouvez aller directement voir le [Code](https://github.com/J3R5/Arduino_decodeur/blob/main/Biblioth%C3%A8que/JC_decodeur/JC_decodeur.cpp).

### Principe d'un Décodeur :

Le principe d'un **decodeur** est le suivant : avec un nombre de sorties, on peut activer un nombre de sorties plus grand. **Le nombre de sorties que l'on peut activer dépend de la fomule suivante 2^X avec X étant le nombre d'entrées.** Dans le cas du décodeur 74HC238, c'est un décodeur 3 vers 8 donc il y a 3 entrées et 2^3 = 8, donc c'est bien un décodeur 3 vers 8. Le code se fait en binaire, on converti le code binaire des entrées pour activer la bonne sortie.

### Différentes parties d'un décodeur :

Un décodeur contient plusieurs parties :

* Les entrées binaires.
* Les entrées de validation.
* Les sorties binaires.

### Binaire :

Le décodeur fonctionne en **Binaire** c'est à dire en état logique 0-1 donc par exemple un décodeur qui fonctionne en 0/5V il envoit soit du 0V, soit du 5V. 

Voici un lien vers un [cours](https://lehollandaisvolant.net/tuto/bin/) qui permet d'en apprendre plus sur le binaire.

Sinon ce tableau suffira :

![Tableau binaire 3 bits](https://github.com/J3R5/Arduino_decodeur/blob/main/datasheet/photo_tableau_binaire.png)

#### Entrée Binaire : 

  Les entrées binaires définissent **les nombres de sorties** avec la formule **2^X** avec **X** étant le nombre d'entrées. Les entrées binaires ont 2 états logiques 0 et 1, elles fonctionnent donc en binaire. Dans le cas du décodeur utilisé, 0 correspond à du 0V et l'état **1** à du **5V**. Dans le cas d'une tension qui serait comprise entre 0 et 5V par exemple **3V** l'état logique serait indeterminé. Dans le cas du décodeur **3** vers **8** **74HC238** il y a trois entrées binaires **A0, A1 et A2**. **A0** est le bit de rang 0 _(2^0 = 1)_ soit à l'état 1 sa valeur est 1 et à l'état 0 sa valeur est 0. **A1** est le bit de rang 1 _(2^1 = 2)_ donc à l'état 0 sa valeur est 0 et à l'état 1 sa valeur est 2. **A2** est le bit de rang 2 _(2^2 = 4)_ soit à l'état 1 sa valeur est 4 et à l'état 0 la valeur est 0.

Le résultat de l'addition des valeurs des différents états détermine la sortie à activer et à passer à l'état 1 soit 5V.

#### Entrée de Validation :

  les entrées de validation sont importantes dans le fonctionnement du systeme ; en effet, c'est elle qui permet de définir si le systeme est actif ou non. Le système est dit actif si la sortie correspondant aux entrées binaires est à l'état 1. le système est dit inactif si toutes les sorties binaires sont à l'état 0. On peut donc résumer les entrées de validation comme des interrupteurs qui permettent d'activer ou non le système. Pour activer le système, il faut que toutes les entrées de validation soient à 1 c'est à dire qu'elle reçoit un signal de 5V dans le cas du decodeur **74HC238**. Dans le cas où une entrée du décodeur n'est pas à 1 le système n'est pas actif. Dans le cas où une entrée se trouve entre l'état 0 et 1 le système est dans un état indeterminé. Les entrées de validation peuvent être inversées ou non,  c'est à dire qu'une entrée non inversée, son entrée est égale à la sortie. Dans le cas d'une entrée inversée, l'état à l'entrée est l'opposé de l'entrée,  c'est à dire que si on envoit du 5V à l'entrée donc l'état 1 l'entrée de validation sera à 0. Ces entrées inversées sont symbolisées par un rond sur leur entrée comme E2 et E1 du décodeur **74HC238**. En résumé, pour qu'un décodeur fonctionne normalement, il faut que toutes ses entrées de validation soient à l'état haut c'est à dire 1.

#### Sortie Binaire :

  Les sorties Binaires sont les sorties qui vont être activées en fonction du code en entrée. Les sorties sont suppérieures au nombre d'entrées. Une seule sortie peut être activée à la fois car il dépend du code en entrée. Les sorties binaires tout comme les entrées binaires et de validation ont 2 états 0 ou 1 donc soit elles envoient 0V soit 5V, pas entre les deux. Le résultat de toutes les sorties binaires sera 0V si le module n'est pas alimenté ou que toutes les entrées de validation ne sont pas à l'état logique 1. Dans le cas ou le module est alimenté et que toutes les entrées de validation sont à 1 l'une des sorties du décodeur sera activée.

### Décodeur 74HC238 3 vers 8 :

  Pour finir, voici une petite explication du décodeur **74HC238** 3 vers 8. Ce décodeur possède 3 entrées de validation et donc 8 sorties Binaires. il possède aussi 3 entrées de validation, 2 en entrée inversée et 1 en entrée non inversée. Il fonctionne en 5 V que se soit le Vcc, les entrées ou les sorties.



