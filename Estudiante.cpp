
#include "Estudiante.h"

// CONSTRUCTOR
Estudiante::Estudiante(){
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Estudiante::setCarrera(string Carrera) {
	this->Carrera = Carrera ;
}

void Estudiante::setCodigo(int Codigo) {
	this->Codigo = Codigo ;
}

void Estudiante::setSemestre(int Semestre) {
	this->Semestre = Semestre ;
}

void Estudiante::CorrerValorMulta(int ValorMultaAcomulada) {
	this->ValorMultaAcomulada = ValorMultaAcomulada ;
}

void Estudiante::setEstadoDeMulta(bool EstadoDeMulta) {
	this->EstadoDeMulta = EstadoDeMulta ;
}

void Estudiante::setEstadoDeEstudiante(bool EstadoDeEstudiante) {
	this->EstadoDeEstudiante = EstadoDeEstudiante ;
}

void Estudiante::ArticuloParaPrestar(ArticuloDePrestamo* Articulo) {
	this->ArticulosPrestados.push_back(Articulo) ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// GETTERS
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

vector <ArticuloDePrestamo*> Estudiante::MisArticulos() {
	return this->ArticulosPrestados ;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// Mostrar
void Estudiante::MostrarTodosLosArticulos() {
	cout << "\n\tMis Articulos Prestados \n\n" ;
	for (int i=0 ; i<this->ArticulosPrestados.size() ; i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
		cout << "\n\t Articulo #" << i+1 << "\n\n" ;
		cout << "1. Nombre: " << this->ArticulosPrestados[i]->getIDNombre() << "\n" ;
	 	cout << "2. Codigo: " << this->ArticulosPrestados[i]->getCodigoArticulo() << "\n" ;
	 	cout << "3. Marca: "  << this->ArticulosPrestados[i]->getIDMarca() << "\n" ;
	 	cout << "4. Cantidad: " << this->ArticulosPrestados[i]->getCantidadDeTipoDeArticulo() << "\n" ;
	 	cout << "5. Valor Articulo: " << this->ArticulosPrestados[i]->getValorArticuloInicial() << "\n" ;
	 	cout << "6. Valor Actual: " << this->ArticulosPrestados[i]->getValorActualArticulo() << "\n" ;
	 	cout << "7. Estado: " << this->ArticulosPrestados[i]->getEstadoArticuloDeActivo() << "\n" ;
	 	cout << "8. Estado Limite: " << this->ArticulosPrestados[i]->getEstadoDeLimiteDeArticulos() << "\n" ;
	 	cout << "9. Asignado al profesor: " << this->ArticulosPrestados[i]->getEstadoDeAsignadoAProfesor() << "\n" ;
	 	cout << "10.Valor de despreciacion: " << this->ArticulosPrestados[i]->getDespreciacion() << "\n" ;
	 	cout << "11. Asignado al Profesor: " << this->ArticulosPrestados[i]->getProfesor()->getNombre() << "\n" ;  
		cout << "    Codigo del Profesor: " << this->ArticulosPrestados[i]->getProfesor()->getCodigo() << "\n" ;  
 		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" ;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" ;
	}
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void Estudiante::MostrarArticulo(int Posicion) {
	
	
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

// OTROS METODOS 
void Estudiante::CrearDatosDeObjetoEstudiante(Estudiante* EstudianteParaCrear, int Cantidad) {
	system("cls") ;
	string Nombre, Apellido, Email, Carrera ; 
	int Edad, Codigo, Semestre, ValorMultaAcomulada = 0 ;
	long Cedula, Telefono ;
	bool EstadoDeMulta = false ;
	bool EstadoDeEstudiante = false ;

	for (int i=0 ; i<Cantidad ; i++) {
		cout << "\nIngresa los datos correspondiente de estudiante \n" ;
		cout << "Ingrese su nombre: \n" ;
		cin  >> Nombre ;
		EstudianteParaCrear->setNombre(Nombre) ;
		
		cout << "Ingrese su apellido: \n" ;
		cin  >> Apellido ;
		EstudianteParaCrear->setApellido(Apellido) ;
		
		cout << "Ingrese su email: \n" ;
		fflush(stdin) ;
		cin  >> Email ;
		EstudianteParaCrear->setEmail(Email) ;
		
		cout << "Ingrese su carrera: \n" ;
		fflush(stdin) ;
		cin  >> Carrera ;
		EstudianteParaCrear->setCarrera(Carrera) ;
		
		fflush(stdin) ;
		Edad = common::ValidarEntero("Ingrese su edad: \n") ;
		EstudianteParaCrear->setEdad(Edad) ;
		
		
		Cedula = common::ValidarEntero("Ingrese su numero de cedula: \n" ) ;
		EstudianteParaCrear->setCedula(Cedula) ;
		
		Telefono = common::ValidarEntero("Ingrese su numero de telefono: \n") ;
		EstudianteParaCrear->setTelefono(Telefono) ;
		
		Codigo = common::ValidarEntero("Ingrese su nuevo numero de codigo: \n") ;
		EstudianteParaCrear->setCodigo(Codigo) ;
		
		Semestre = common::ValidarEntero("Ingrese el semestre que cursa: \n") ;
		EstudianteParaCrear->setSemestre(Semestre) ;
		
		EstudianteParaCrear->setEstadoDeMulta(EstadoDeMulta) ;
		EstudianteParaCrear->setEstadoDeEstudiante(EstadoDeEstudiante) ;
		EstudianteParaCrear->CorrerValorMulta(ValorMultaAcomulada) ;
		cout << "\nPor favor espere ! \n" ;
		cout <<  "Estamos Revisando si los datos ingresados estan correctamente \n\n" ;
		system("pause") ; 
	}
}


////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


void Estudiante::Devolucion(int Posicion) {
	
	vector <ArticuloDePrestamo> Paso ; 
	for (int i=0 ; i<this->ArticulosPrestados.size() ; i++) {
		Paso.push_back(*this->ArticulosPrestados[i]) ; 
	}
	
	Paso.erase(Paso.begin()+Posicion, Paso.begin()+(Posicion+1)) ; 
	
	///////////////////////////////////////////////////////////////////////
	vector <ArticuloDePrestamo> PasoAOriginal ; 
	this->ArticulosPrestados.clear() ;
	for (int i=0 ; i<Paso.size() ; i++) {
		this->ArticulosPrestados.push_back(&Paso[i]) ; 
	}
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// DESTRUCTOR
Estudiante::~Estudiante() {
}
