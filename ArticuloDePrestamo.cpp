#include "ArticuloDePrestamo.h"

// CONSTRUCTOR
ArticuloDePrestamo::ArticuloDePrestamo() {
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Setters
void ArticuloDePrestamo::setIDMarca(string IDMarca) {
	this->IDMarca = IDMarca ;
}

void ArticuloDePrestamo::setCantidadDeTipoDeArticulo(int CantidadDeArticulos)  {
	this->CantidadDeTipoDeArticulo = CantidadDeArticulos ;
}

void ArticuloDePrestamo::setDespreciacion(float Despreciacion){
	this->ValorDespreciacionAnual = Despreciacion ;	
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Asignacion de profesor al articulo
void ArticuloDePrestamo::AsignarAProfesor(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ; 
}	

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Getters
string ArticuloDePrestamo::getIDMarca() {
	return this->IDMarca ; 
}

int ArticuloDePrestamo::getCantidadDeTipoDeArticulo() {
	return this->CantidadDeTipoDeArticulo ;
}

Profesor* ArticuloDePrestamo::getProfesor() {
	return this->ProfesorAsignado ; 
}

float ArticuloDePrestamo::getDespreciacion(){
	return this->ValorDespreciacionAnual ;
} 

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//Otros metodos
float ArticuloDePrestamo::Despreciacion() { 
	float ValorDeArticulo, DespreciacionXMes ; 
	//ValorDeArticulo = ArticuloADespreciar.getValorArticuloInicial() ;
	DespreciacionXMes = ValorDeArticulo / 18 ; 
//	for (int i=1 ; )
//	ValorDeArticulo -=
//	ArticuloADespreciar.setValorActualArticulo()
	float a = 1.2 ;
	
	return a ; 
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ArticuloDePrestamo* ArticuloDePrestamo::ArticulosDePrestamoIniciales(ArticuloDePrestamo* ArticulosIniciales, int NroDeArticulo ) {
	string Nombre, Marca ;
	int Codigo, Cantidad ; 
	float Valor ;
	bool EstadoArticulo = false, EstadoDeLimiteCantidad = false, Asignacion = false ;
	
	if (NroDeArticulo == 0) {
		Nombre = "Control" ;
		Marca = "Samsumng" ;
		Codigo = 7818 ;
		Cantidad = 3 ;
		Valor = 2500 ;
		ArticulosIniciales->setIDNombre(Nombre) ;
		ArticulosIniciales->setIDMarca(Marca) ;
		ArticulosIniciales->setCodigoArticulo(Codigo) ;
		ArticulosIniciales->setCantidadDeTipoDeArticulo(Cantidad) ;
		ArticulosIniciales->setValorArticuloInicial(Valor) ;
		ArticulosIniciales->setEstadoArticuloDeActivo(EstadoArticulo) ;
		ArticulosIniciales->setEstadoDeLimiteDeArticulos(EstadoDeLimiteCantidad) ;
		ArticulosIniciales->setEstadoDeAsignadoAProfesor(Asignacion) ;
	}else {
		Nombre = "Guitarra" ;
		Marca = "Yamaha" ;
		Codigo = 1304 ;
		Cantidad = 2 ;
		Valor = 5000 ;
		ArticulosIniciales->setIDNombre(Nombre) ;
		ArticulosIniciales->setIDMarca(Marca) ;
		ArticulosIniciales->setCodigoArticulo(Codigo) ;
		ArticulosIniciales->setCantidadDeTipoDeArticulo(Cantidad) ;
		ArticulosIniciales->setValorArticuloInicial(Valor) ;
		ArticulosIniciales->setEstadoArticuloDeActivo(EstadoArticulo) ;
		ArticulosIniciales->setEstadoDeLimiteDeArticulos(EstadoDeLimiteCantidad) ;
		ArticulosIniciales->setEstadoDeAsignadoAProfesor(Asignacion) ;
	}
	return ArticulosIniciales ;
}

//////////////////////////////////////////////////////////////////////////////////////////

void ArticuloDePrestamo::CrearArticuloParaPrestamo(ArticuloDePrestamo* ArticuloParaCrear) {
	system("cls") ;
	string Nombre, Marca ;
	int Codigo, NroDeArticulos ; 
	float Valor ;
	bool EstadoArticulo = false, EstadoDeLimiteCantidad = false, Asignacion = false ;
	
	cout << "\n\tINGRESE LOS SIGUIENTES DATOS PARA CREAR ARTICULOS DE PRESTAMO \n\n" ;
	
	cout << "-INGRESE NOMBRE DEL ARTICULO:		" ;
	cin  >> Nombre ;
	
	cout << "-INGRESE LA MARCA DEL ARTICULO:		"  ;
	cin  >> Marca ;
	
	Codigo = common::ValidarEntero("-INGRESE EL CODIGO DEL ARTICULO:	" ) ;
	
	NroDeArticulos = common::ValidarEntero("-INGRESE UNA CANTIDAD DE DISPONIBLES:	" ) ;
		
	Valor = common::ValidarEntero("-INGRESE UN VALOR AL ARTICULO:		" ) ;
		
	ArticuloParaCrear->setIDNombre(Nombre) ;
	ArticuloParaCrear->setIDMarca(Marca) ;
	ArticuloParaCrear->setCodigoArticulo(Codigo) ;
	ArticuloParaCrear->setCantidadDeTipoDeArticulo(NroDeArticulos) ;
	ArticuloParaCrear->setValorArticuloInicial(Valor) ;
	ArticuloParaCrear->setValorActualArticulo(Valor) ;
	ArticuloParaCrear->setDespreciacion(Valor/18) ;
	ArticuloParaCrear->setEstadoArticuloDeActivo(EstadoArticulo) ;
	ArticuloParaCrear->setEstadoDeLimiteDeArticulos(EstadoDeLimiteCantidad) ;
	ArticuloParaCrear->setEstadoDeAsignadoAProfesor(Asignacion) ;
	
	cout << "\n\n\tSU ARTICULO DE PRESTAMO SE REGISTRO CON EXITO... \n\n" ;
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// Destructor
ArticuloDePrestamo::~ArticuloDePrestamo() {
}
