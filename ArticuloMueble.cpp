
#include "ArticuloMueble.h"

// CONSTRUCTOR 
ArticuloMueble::ArticuloMueble() {
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void ArticuloMueble::setMaterial(string Material) {
	this->Material = Material ;
}

void ArticuloMueble::AsignarAlArticulo(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ;
}

void ArticuloMueble::setCantidad(int Cantidad) {
	this->CantidadMueble = Cantidad ;
}

void ArticuloMueble::setDespreciacion(float Despreciacion) {
	this->ValorDespreciacionAnual = Despreciacion ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
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

bool ArticuloMueble::Despreciacion(Fecha* Actual, Fecha* FechaArticulo) {
	int DiferenciAnios ; 
	DiferenciAnios = Actual->getAnio() - FechaArticulo->getAnio() ;
	
	if (DiferenciAnios >= 10) {
		this->ValorActualArticulo = 0 ;
		return true ; 				
	}else  {
		switch (DiferenciAnios) {
			case 0 : { // 0 A�os
				this->ValorActualArticulo = this->ValorActualArticulo ;  				
				return false ;
				break;
			}
			
			case 1 : { // Un a�o 
				this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
				return false ;
				break;
			}
			
			case 2 : { // Dos a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
				return false ;
				break;
			}
			
			case 3 : { // Tres a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
				return false ;
				break;
			}
			
			case 4 : { // Cuatro a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
				return false ;
				break;
			}
			
			case 5 : { // Cinco a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
				return false ;
				break;
			}
			
			case 6 : { // Seis a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
				return false ;
				break;
			}
			
			case 7 : { // Siete a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
				return false ;
				break;
			}
			
			case 8 : { // Ocho a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
				return false ;
				break;
			}
			
			case 9 : { // Nueve a�os
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
				return false ;
				break;
			}
			
			default : { // Datos incorrecto
				cout << "\nDato Incorrecto \n\n" ;
				system("pause") ; 
				return false ;
				break;
			}
		}
	}
	
	if (this->ValorActualArticulo == 0) {
		this->EstadoArticuloDeActivo == false ; 
	}
}


void ArticuloMueble::CrearMueble(ArticuloMueble* ArticuloACrear) {
	string Nombre, Material ;
	int Codigo, Cantidad ;
	float ValorArticulo ;
	
	system("cls") ;

	cout << "\n\tA Continuacion digite la informacion correspondiente \n\n" ;

	cout << "\nIngrese el nombre del articulo: \n" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	
	cout << "\nIngrese el material del articulo: \n" ;
	fflush(stdin) ;
	cin  >> Material ;
	
	Codigo = common::ValidarEntero("\nIngrese el codigo del articulo \n") ;

	ValorArticulo = common::ValidarEntero("\nIngrese el valor del articulo \n") ;
	
	Cantidad = common::ValidarEntero("\nIngrese la cantidad del articulo que van a estar disponibles \n") ;
	
	ArticuloACrear->setIDNombre(Nombre) ;
	ArticuloACrear->setMaterial(Material) ; 
	ArticuloACrear->setCodigoArticulo(Codigo) ;
	ArticuloACrear->setCantidad(Cantidad) ; 
	ArticuloACrear->setValorArticuloInicial(ValorArticulo) ;
	ArticuloACrear->setValorActualArticulo(ValorArticulo) ;
	ArticuloACrear->setDespreciacion(this->ValorArticulo/10) ; 
	ArticuloACrear->setEstadoArticuloDeActivo(true) ;
	ArticuloACrear->setEstadoDeLimiteDeArticulos(true) ;
	ArticuloACrear->setEstadoDeAsignadoAProfesor(true) ;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ArticuloMueble::~ArticuloMueble() {
}
