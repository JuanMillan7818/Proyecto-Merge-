
#ifndef PERSONALADMI_H_
#define PERSONALADMI_H_

#include "Persona.h"

using namespace std ;

class PersonalAdmi : public Persona {
	public :
		//Constructores
		PersonalAdmi () ;
		PersonalAdmi (string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) ; 
		
		//Otros metodos
		void CrearPersonal (PersonalAdmi* Personal) ;
		
		//Destructor
		~PersonalAdmi () ;
};
#endif
