#include "Profesor.h"

// CONSTRUCTOR
Profesor::Profesor(){
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Profesor::setCodigo(int Codigo) {
	this->Codigo = Codigo ;
}

void Profesor::setTituloProfesional(string TituloProfesional) {
	this->TituloProfesional = TituloProfesional ;
}


// GETTERS
int Profesor::getCodigo() {
	return this->Codigo ;
}

string Profesor::getTituloProfesional() {
	return this->TituloProfesional ;
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// OTROS METODOS
void Profesor::CrearDatosDeProfesor(Profesor* Profesor) {
	system("cls") ;
	string* Nombre = new string ;
	string* Apellido = new string ;
	string* Email = new string ;
	int* Edad = new int ;
	long* Cedula = new long ;
	int* Telefono = new int ;
	int* Codigo = new int ;
	string* TituloProfesional = new string ;

	cout << "\nLLENA EL SIGUIENTE FORMULARIO PARA CREAR U NUEVO PERFIL \n" ;
	cout << "NOMBRE:" ;
	cin  >> *Nombre ;
	Profesor->setNombre(*Nombre) ;
	
	cout << "APELLIDO:" ;
	cin  >> *Apellido ;
	Profesor->setApellido(*Apellido) ;
	
	cout << "E-MAIL:" ;
	cin  >> *Email ;
	Profesor->setEmail(*Email) ;

	cout << "TITULO PROFESIONAL:" ;
	fflush(stdin) ; // Liberar memoria para string
	cin  >> *TituloProfesional ;
	Profesor->setTituloProfesional(*TituloProfesional) ;
	
		
	*Edad = common::ValidarEntero("EDAD:") ;
	Profesor->setEdad(*Edad) ;
	
		
	*Cedula = common::ValidarEntero("# DE IDENTIFICACION:" ) ;
	Profesor->setCedula(*Cedula) ;
	
	*Telefono = common::ValidarEntero("# TELEFONICO:") ;
	Profesor->setTelefono(*Telefono) ;
	
	*Codigo = common::ValidarEntero("CODIGO:") ;
	Profesor->setCodigo(*Codigo) ;
	
	cout << "\nEL NUEVO PERFIL PROFESOR SE HA CREADO CON EXITO \n\n" ;
	system("pause") ;
	
   	delete Nombre, Apellido, Email, TituloProfesional ;
	delete Edad, Cedula, Telefono, Codigo ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Profesor::~Profesor(){
}


