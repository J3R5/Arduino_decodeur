//ajout bibliothèque
#include <JC_decodeur.h>

JC_decodeur decodeur1;

void setup() {
  
  //Initialisation des entrées de validations
  decodeur1.Init_Validation(5,6,7);
  //Initialisation des entrées du code binaire
  decodeur1.Init_CodeBinaire(2,3,4);

}

void loop() {

  //activation de l'entrée 3 pour activé les sorties du decodeur
  decodeur1.Validation_E3(1);
  //allume les sortie du decodeur une a une
  for (int i = 0; i < 8; i ++) {
  decodeur1.Code_decimal(i);
  delay(1000);
  }

}
