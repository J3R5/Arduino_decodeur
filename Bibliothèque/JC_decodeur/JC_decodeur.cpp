/*
 * Bibliothèque décodeur
 *
 *  Jérémy Clémente 02/04/2023
 */

#include "Arduino.h"
#include "JC_decodeur.h"

    
void JC_decodeur::Init_Validation(int e1_pin, int e2_pin, int e3_pin)
{
    /*
     * Fonction qui définie les entrée
     * de validation du décodeur
     *
     * Jérémy Clémente
    */

    //Début

    e1 = e1_pin;
    e2 = e2_pin;
    e3 = e3_pin;

    pinMode(e1, OUTPUT);
    pinMode(e2, OUTPUT);
    pinMode(e3, OUTPUT);

    //Fin
}

void JC_decodeur::Init_Validation_e3(int e3_pin)
{
    /*
     * Fonction qui définie l'entrée e3
     * de validation du décodeur
     *
     * Jérémy Clémente
    */

    //Début

    e3 = e3_pin;

    pinMode(e3, OUTPUT);

    //Fin
}

void JC_decodeur::Init_Validation_e2(int e2_pin)
{
    /*
     * Fonction qui définie l'entrée e2
     * de validation du décodeur
     *
     * Jérémy Clémente
    */

    //Début

    e2 = e2_pin;

    pinMode(e2, OUTPUT);

    //Fin
}

void JC_decodeur::Init_Validation_e1(int e1_pin)
{
    /*
     * Fonction qui définie l'entrée e1
     * de validation du décodeur
     *
     * Jérémy Clémente
    */

    //Début

    e1 = e1_pin;

    pinMode(e1, OUTPUT);

    //Fin
}

void JC_decodeur::Init_CodeBinaire(int a0_pin, int a1_pin, int a2_pin)
{
    /*
     * Fonction qui définie les entrées
     * du code binaire du décodeur
     * 
     * Jérémy Clémente
    */

    //Début

    a0 = a0_pin;
    a1 = a1_pin;
    a2 = a2_pin;

    pinMode(a0, OUTPUT);
    pinMode(a1, OUTPUT);
    pinMode(a2, OUTPUT);

    //Fin
}

void JC_decodeur::Validation_E1(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée e1   
     *
    */

   //Début

    digitalWrite(e1, etat);

   //Fin
}

void JC_decodeur::Validation_E2(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée e2   
     *
    */

   //Début

    digitalWrite(e2, etat);

   //Fin
}

void JC_decodeur::Validation_E3(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée e3   
     *
    */

   //Début

    digitalWrite(e3, etat);

   //Fin
}

void JC_decodeur::Validation(int etat_e1, int etat_e2, int etat_e3)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée e3   
     *
    */

   //Début
    
    digitalWrite(e1, etat_e1);
    digitalWrite(e2, etat_e2);
    digitalWrite(e3, etat_e3);

   //Fin
}

void JC_decodeur::Code_a0(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée a0   
     * qui représente le bit 0 (valeur : 1)
     *
    */

   //Début

    digitalWrite(a0, etat);

   //Fin
}

void JC_decodeur::Code_a1(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée a1   
     * qui représente le bit 1 (valeur : 2)
     *
    */

   //Début

    digitalWrite(a1, etat);

   //Fin
}

void JC_decodeur::Code_a2(int etat)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée a2   
     * qui représente le bit 2 (valeur : 4)
     *
    */

   //Début

    digitalWrite(a2, etat);

   //Fin
}

void JC_decodeur::Code_binaire(int etat_a2, int etat_a1, int etat_a0)
{
    /*
     * Fonction qui permet de changer
     * l'etat de la sortie de l'entrée des bits   
     * qui représente le code binaire 
     * 
    */

   //Début

    digitalWrite(a0, etat_a0);
    digitalWrite(a1, etat_a1);
    digitalWrite(a2, etat_a2);

   //Fin
}

void JC_decodeur::Code_decimal(int Nbre)
{
    /*
     * Cette Fonction converti
     * la valeur Decimal compris 
     * entre 0 et 7 inclu en code
     * binaire pour le decodeur
     *
    */

    //Début

    digitalWrite(a0, (Nbre%2));
    digitalWrite(a1, ((Nbre/2)%2));
    digitalWrite(a2, ((Nbre/4)%2));

    //Fin
}



