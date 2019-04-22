#include "common.h"

int common::ValidarEntero(string Mensaje) { // Esta funcion solicta un enetro por consola y valida que sea correcto
	float* Validar = new float ;
	
	cout << Mensaje ;
	cin >> *Validar ;

	while(true) {
		if(cin.fail()) {
			cin.clear() ; 
			cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
			cout << "VALOR INVALIDO, DIGITE UN NUMERO \n" ;
			cout << "INTENTALO DE NUEVO \n" ;
			system("pause") ;
			cout << "\n" ;
			cout << Mensaje ;
			cin >> *Validar ;
		}
		if(!cin.fail())
			break;
	}
	
	return *Validar;	
	delete Validar ;
}
