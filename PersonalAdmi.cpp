
#include "PersonalAdmi.h"

// Constructor
PersonalAdmi::PersonalAdmi() {
}

PersonalAdmi::PersonalAdmi(string Nombre, string Apellido, string Email, int Edad, int Cedula, long Telefono) : Persona (Nombre,Apellido,Email,Edad,Cedula,Telefono) {	
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

void PersonalAdmi::CrearPersonal(PersonalAdmi* Personal) {
	system("cls") ;
	string Nombre, Apellido, Email ;
	int Edad ;
	long Cedula, Telefono ;
	
	cout << "\nLLENA EL FORMULARIO PARA LA CREACION DE UN NUEVO PERFIL \n" ;
	cout << "NOMBRE:" ;
	cin  >> Nombre ;
	Personal->setNombre(Nombre) ;
	
	cout << "APELLIDO:" ;
	cin  >> Apellido ;
	Personal->setApellido(Apellido) ;
	
	cout << "E-MAIL:" ;
	cin  >> Email ;
	Personal->setEmail(Email) ;
	
	Edad = common::ValidarEntero("EDAD:") ;
	Personal->setEdad(Edad) ;
		
		
	Cedula = common::ValidarEntero("# DE IDENTIFICACION:" ) ;
	Personal->setCedula(Cedula) ;
	
	Telefono = common::ValidarEntero("# TELEFONICO:") ;
	Personal->setTelefono(Telefono) ;
	
	cout << "\n\nPERFIL CREADO CON EXITO !! \n\n" ;
	system("pause") ;
}
 
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// Destructor
PersonalAdmi::~PersonalAdmi(){
}
