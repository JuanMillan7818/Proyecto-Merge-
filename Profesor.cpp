
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

	cout << "\nIngresa los datos correspondiente de Profesor \n" ;
	cout << "Ingrese su nombre: \n" ;
	cin  >> *Nombre ;
	Profesor->setNombre(*Nombre) ;
	
	cout << "Ingrese su apellido: \n" ;
	cin  >> *Apellido ;
	Profesor->setApellido(*Apellido) ;
	
	cout << "Ingrese su email: \n" ;
	cin  >> *Email ;
	Profesor->setEmail(*Email) ;

	cout << "Ingrese su Titulo de profesion: \n" ;
	fflush(stdin) ; // Liberar memoria para string
	cin  >> *TituloProfesional ;
	Profesor->setTituloProfesional(*TituloProfesional) ;
	
		
	*Edad = common::ValidarEntero("Ingrese su edad: \n") ;
	Profesor->setEdad(*Edad) ;
	
		
	*Cedula = common::ValidarEntero("Ingrese su numero de cedula: \n" ) ;
	Profesor->setCedula(*Cedula) ;
	
	*Telefono = common::ValidarEntero("Ingrese su numero de telefono: \n") ;
	Profesor->setTelefono(*Telefono) ;
	
	*Codigo = common::ValidarEntero("Ingrese su nuevo numero de codigo: \n") ;
	Profesor->setCodigo(*Codigo) ;
	
	cout << "\nPor favor espere ! \n" ;
	cout <<  "Estamos Revisando si los datos ingresados estan correctamente \n\n" ;
	system("pause") ;
	
   	delete Nombre, Apellido, Email, TituloProfesional ;
	delete Edad, Cedula, Telefono, Codigo ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Profesor::~Profesor(){
}


