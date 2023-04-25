#ifndef JC_DECODEUR_H
#define JC_DECODEUR_H

class JC_decodeur {
	public:
		void Init_Validation(int e1_pin, int e2_pin, int e3_pin);
		void Init_CodeBinaire(int a0_pin, int a1_pin, int a2_pin);
		void Init_Validation_e1(int e1_pin);
		void Init_Validation_e2(int e2_pin);
		void Init_Validation_e3(int e3_pin);
		void Validation_E1(int etat);
		void Validation_E2(int etat);
		void Validation_E3(int etat);
		void Validation(int etat_e1, int etat_e2, int etat_e3);
		void Code_a0(int etat);
		void Code_a1(int etat);
		void Code_a2(int etat);
		void Code_binaire(int etat_a0, int etat_a1, int etat_a2);
		void Code_decimal(int Nbre);
	private:
		int a0, a1, a2;
		int e1, e2, e3;
};

#endif