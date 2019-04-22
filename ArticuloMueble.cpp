#include "ArticuloMueble.h"

// Constructor
ArticuloMueble::ArticuloMueble() {
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Setters
void ArticuloMueble::setMaterial(string Material) {
	this->Material = Material ;
}

void ArticuloMueble::setCantidad(int Cantidad) {
	this->CantidadMueble = Cantidad ;
}

void ArticuloMueble::setDespreciacion(float Despreciacion) {
	this->ValorDespreciacionAnual = Despreciacion ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

//ASIGNACION 

void ArticuloMueble::AsignarAlArticulo(Profesor* Profesor) { // FUNCION DONDE SE ASIGNA UN PROFESOR 
	this->ProfesorAsignado = Profesor ;						 // RESPONSABLE DEL ARTICULO...
}
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Getters
string ArticuloMueble::getMaterial() {
	return this->Material ;
}

Profesor* ArticuloMueble::getProfesorAsignado() {
	return this->ProfesorAsignado ;
}

int ArticuloMueble::getCantidad() {
	return this->CantidadMueble ;
}

float ArticuloMueble::getDespreciacion() {
	return this->ValorDespreciacionAnual ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// DESPRECIACION 

float ArticuloMueble::Despreciacion() {
											// -> DESPRECIACION ANUAL...
	return 1.3 ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void ArticuloMueble::CrearMueble(ArticuloMueble* ArticuloACrear) {
	string Nombre, Material ;
	int Codigo, Cantidad ;
	float ValorArticulo ;

	system("cls") ;

	cout << "\n\tINGRESE LOS SIGUIENTES DATOS PARA CREACION DE MUEBLE \n\n" ;
	
	cout << "-INGRESE EL NOMBRE DEL ARTICULO:		" ;	
	cin  >> Nombre ;
	
	cout << "-INGRESE EL MATERIAL DEL ARTICULO		" ;
	cin  >> Material ;
	
	Codigo = common::ValidarEntero("-INGRESE EL CODIGO DEL ARTICULO:		") ;

	ValorArticulo = common::ValidarEntero("-INGRESE UN VALOR AL ARTICULO:			") ;
	
	Cantidad = common::ValidarEntero("-INGRESE UNA CANTIDAD DE DISPONIBLES:		") ;
	
	ArticuloACrear->setIDNombre(Nombre) ;
	ArticuloACrear->setMaterial(Material) ; 
	ArticuloACrear->setCodigoArticulo(Codigo) ;
	ArticuloACrear->setCantidad(Cantidad) ; 
	ArticuloACrear->setValorArticuloInicial(ValorArticulo) ;
	ArticuloACrear->setValorActualArticulo(ValorArticulo) ;
	ArticuloACrear->setDespreciacion(this->ValorArticulo/10) ; 
	ArticuloACrear->setEstadoArticuloDeActivo(0) ;
	ArticuloACrear->setEstadoDeLimiteDeArticulos(0) ;
	ArticuloACrear->setEstadoDeAsignadoAProfesor(0) ;
	
	
	cout << "\n\n SU ARTICULO MUEBLE SE REGISTRO CON EXITO... \n\n" ;
	system("pause") ;
}

//////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ArticuloMueble::~ArticuloMueble() {
}
