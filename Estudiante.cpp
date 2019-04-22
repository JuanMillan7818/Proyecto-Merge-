#include "Estudiante.h"

// Constructor
Estudiante::Estudiante(){
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Setters
void Estudiante::setCarrera(string Carrera) {
	this->Carrera = Carrera ;
}

void Estudiante::setCodigo(int Codigo) {
	this->Codigo = Codigo ;
}

void Estudiante::setSemestre(int Semestre) {
	this->Semestre = Semestre ;
}

void Estudiante::setEstadoDeMulta(bool EstadoDeMulta) {
	this->EstadoDeMulta = EstadoDeMulta ;
}

void Estudiante::setEstadoDeEstudiante(bool EstadoDeEstudiante) {
	this->EstadoDeEstudiante = EstadoDeEstudiante ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

//Funcion correr valor de multa del estudiante
void Estudiante::CorrerValorMulta(int ValorMultaAcomulada) {
	this->ValorMultaAcomulada = ValorMultaAcomulada ;
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Getters
string Estudiante::getCarrera() {
	return this->Carrera ; 
}

int Estudiante::getCodigo() {
	return this->Codigo ;
}

int Estudiante::getSemestre() {
	return this->Semestre ;
}

int Estudiante::getValorMultaAcomulada() {
	return this->ValorMultaAcomulada ;
}

bool Estudiante::getEstadoDeMulta() {
	return this->EstadoDeMulta ;
}

bool Estudiante::getEstadoDeEstudiante() {
	return this->EstadoDeEstudiante ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Mostrar todo
void Estudiante::MostrarTodosLosArticulos() {	
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Otros metodos
void Estudiante::CrearDatosDeObjetoEstudiante(Estudiante* EstudianteParaCrear, int Cantidad) {
	system("cls") ;
	string Nombre, Apellido, Email, Carrera ; 
	int Edad, Codigo, Semestre, ValorMultaAcomulada = 0 ;
	long Cedula, Telefono ;
	bool EstadoDeMulta = false ;
	bool EstadoDeEstudiante = false ;

	for (int i=0 ; i<Cantidad ; i++) {
		cout << "\n\tCOMPLETE EL SIGUIENTE FORMULARIO \n\n" ;
		cout << "-NOMBRE:		" ;
		cin  >> Nombre ;
		EstudianteParaCrear->setNombre(Nombre) ;
		
		cout << "-APELLIDO:		" ;
		cin  >> Apellido ;
		EstudianteParaCrear->setApellido(Apellido) ;
		
		cout << "-EMAIL:			" ;
		fflush(stdin) ;
		cin  >> Email ;
		EstudianteParaCrear->setEmail(Email) ;
		
		cout << "-CARRERA:		" ;
		fflush(stdin) ;
		cin  >> Carrera ;
		EstudianteParaCrear->setCarrera(Carrera) ;
		
		fflush(stdin) ;
		Edad = common::ValidarEntero("-EDAD:			") ;
		EstudianteParaCrear->setEdad(Edad) ;
		
		
		Cedula = common::ValidarEntero("-# DOC. IDENTIDAD:	") ;
		EstudianteParaCrear->setCedula(Cedula) ;
		
		Telefono = common::ValidarEntero("-# TELEFONICO:		") ;
		EstudianteParaCrear->setTelefono(Telefono) ;
		
		Codigo = common::ValidarEntero("-CODIGO:		") ;
		EstudianteParaCrear->setCodigo(Codigo) ;
		
		Semestre = common::ValidarEntero("-SEMESTRE QUE CURSA:	") ;
		EstudianteParaCrear->setSemestre(Semestre) ;
		
		EstudianteParaCrear->setEstadoDeMulta(EstadoDeMulta) ;
		EstudianteParaCrear->setEstadoDeEstudiante(EstadoDeEstudiante) ;
		EstudianteParaCrear->CorrerValorMulta(ValorMultaAcomulada) ;
		cout << "\n\nSUS DATOS SE HAN REGISTRADO EXITOSAMENTE... \n\n" ;
		system("pause") ; 
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Asignar Al vector
void Estudiante::AsignarAlVector(ArticuloDePrestamo* ArticuloParaPrestar) {
	this->ArticulosPrestados.push_back(ArticuloParaPrestar) ;
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR
Estudiante::~Estudiante() {
}
