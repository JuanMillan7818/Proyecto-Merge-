#include "ArticuloComputo.h"

// Constructor
ArticuloComputo::ArticuloComputo() {
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Setters
void ArticuloComputo::setIDMarca(string IDMarca) {
	this->IDMarca = IDMarca ;
}

void ArticuloComputo::setDespreciacion(float Despreciacion) {
	this->ValorDespreciacionAnual = Despreciacion ;
}

void ArticuloComputo::setCantidad(int Cantidad) {
	this->CantidadDisponibles = Cantidad ;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//Metodo de asignacion
void ArticuloComputo::AsignarAlArticulo(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// GETTERS
string ArticuloComputo::getIDMarca() {
	return this->IDMarca ;
}

Profesor* ArticuloComputo::getProfesor() {
	return this->ProfesorAsignado ;
}

int ArticuloComputo::getCantidad() {
	return this->CantidadDisponibles ;
}

float ArticuloComputo::getDespreciacion() {
	return this->ValorDespreciacionAnual ; 
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

//Otros metodos...

float ArticuloComputo::Despreciacion () {
//	int Hoy = 2019 ; 
//	int AnioActual = this->FechaActual()->tm_year+1900 ; 
//	for (int i=AnioActual ; i<=AnioActual+10 ; i++) {
//		if (this->ValorArticulo != 0) {
//			this->ValorDespreciacionAnual = this->ValorArticulo / 10 ;
//			this->ValorArticulo -= this->ValorDespreciacionAnual ;
//		}
//	} 
//	
//	return this->ValorDespreciacionAnual ;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

void ArticuloComputo::CrearComputo(ArticuloComputo* ComputoACrear) {

	time_t FechaActual ; 
	time(&FechaActual) ;
	ctime(&FechaActual) ;
	
	struct tm* MiFecha = localtime(&FechaActual) ;
	
	string Nombre, Marca ;
	int Codigo, Cantidad ;
	float ValorArticulo ;

	system("cls") ;

	cout << "\n\tINGRESE LOS SIGUIENTES DATOS PARA CREACION DE COMPUTO \n\n" ;

	cout << "-INGRESE NOMBRE DEL ARTICULO:		" ;
	cin  >> Nombre ;
	
	cout << "-INGRESE MARCA DEL ARTICULO:		" ;
	cin  >> Marca ;
	
	Codigo = common::ValidarEntero("-INGRESE CODIGO DEL ARTICULO:		") ;

	ValorArticulo = common::ValidarEntero("-INGRESE UN VALOR AL ARTICULO:		") ;
	
	Cantidad = common::ValidarEntero("-INGRESE UNA CANTIDAD DE DISPONIBLES:	") ;
	
	ComputoACrear->setIDNombre(Nombre) ;
	ComputoACrear->setIDMarca(Marca) ; 
	ComputoACrear->setCodigoArticulo(Codigo) ;
	ComputoACrear->setCantidad(Cantidad) ; 
	ComputoACrear->setValorArticuloInicial(ValorArticulo) ;
	ComputoACrear->setValorActualArticulo(ValorArticulo) ;
	ComputoACrear->setDespreciacion(this->ValorArticulo/10) ; 
	ComputoACrear->setEstadoArticuloDeActivo(0) ;
	ComputoACrear->setEstadoDeLimiteDeArticulos(0) ;
	ComputoACrear->setEstadoDeAsignadoAProfesor(0) ;
	MiFecha->tm_year += 1900 ;
	ComputoACrear->AsignarFecha(MiFecha) ; 
	
	cout << "\n\n\tSU ARTICULO SE REGISTRO CON EXITO ...\n\n" ;
	system("pause") ;

}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

// Destructor
ArticuloComputo::~ArticuloComputo() {
}
