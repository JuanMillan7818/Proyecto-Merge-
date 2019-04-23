#include "Articulo.h"

// Constructores
Articulo::Articulo(){
}

Articulo::Articulo(string IDNombre, int CodigoArticulo, int ValorArticuloInicial, int ValorActualArticulo, 
				  bool EstadoArticulo, bool EstadoDeLimiteDeArticulos, bool EstadoDeAsignadoAProfesor) {
				  	
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Setters

void Articulo::setIDNombre(string IDNombre) {
	this->IDNombre = IDNombre ;
}


void Articulo::setCodigoArticulo(int CodigoArticulo) {
	this->CodigoArticulo = CodigoArticulo ;
}

void Articulo::setValorArticuloInicial(float ValorArticuloInicial) {
	this->ValorArticulo = ValorArticuloInicial ;
}

void Articulo::setValorActualArticulo(float ValorActualArticulo) {
	this->ValorActualArticulo = ValorActualArticulo ;
}

void Articulo::setEstadoArticuloDeActivo(bool EstadoArticulo) {
	this->EstadoArticuloDeActivo = EstadoArticulo ;
}

void Articulo::setEstadoDeLimiteDeArticulos(bool EstadoDeLimiteDeArticulos) {
	this->EstadoDeLimiteDeArticulos = EstadoDeLimiteDeArticulos ;
}

void Articulo::setEstadoDeAsignadoAProfesor(bool EstadoAsignadoAProfesor) {
	this->EstadoDeAsignadoAProfesor = EstadoAsignadoAProfesor ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Getters

string Articulo::getIDNombre() {
	return this->IDNombre ;
}

int Articulo::getCodigoArticulo() {
	return this->CodigoArticulo ;
}

float Articulo::getValorArticuloInicial() {
	return this->ValorArticulo ;
}

float  Articulo::getValorActualArticulo() {
	return this->ValorActualArticulo ;
}


bool Articulo::getEstadoArticuloDeActivo() {
	return this->EstadoArticuloDeActivo ;
}

bool Articulo::getEstadoDeLimiteDeArticulos() {
	return this->EstadoDeLimiteDeArticulos ;
}

bool Articulo::getEstadoDeAsignadoAProfesor() {
	return this->EstadoDeAsignadoAProfesor ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Estructura fecha

struct tm* Articulo::getFecha() {
	return this->Fecha ; 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Asignacion fecha al articulo

void Articulo::AsignarFecha(struct tm* AgregarFecha) {
	this->Fecha = AgregarFecha ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Destructor

Articulo::~Articulo() {
}
