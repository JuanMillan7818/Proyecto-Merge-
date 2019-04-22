
#ifndef PERSONA_H_
#define PERSONA_H_
#include <iostream>
#include <string>
#include "common.h" 
#include <limits>

using namespace std ;

class Persona {
	protected :
		string Nombre ;
		string Apellido ;
		string Email ;
		int Edad ;
		long Cedula ;
		long Telefono ;
	
	public :
		
		//Constructores
		Persona () ;
		Persona (string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) ;
		
		//Otros metodos
		void setNombre (string Nombre) ;
		void setApellido (string Apellido) ;
		void setEmail (string Email) ;
		void setEdad (int Edad) ;
		void setCedula (long Cedula) ; 
		void setTelefono (long Telefono) ; 
		string getNombre () ;
		string getApellido () ;
		string getEmail () ;
		int getEdad () ;
		long getCedula () ;
		long getTelefono () ;
		
		//Destructor
		~Persona () ;
};
#endif
