
#include "ArticuloDePrestamo.h"

// CONSTRUCTOR
ArticuloDePrestamo::ArticuloDePrestamo() {
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// SETTERS 
void ArticuloDePrestamo::setIDMarca(string IDMarca) {
	this->IDMarca = IDMarca ;
}

void ArticuloDePrestamo::setCantidadDeTipoDeArticulo(int CantidadDeArticulos)  {
	this->CantidadDeTipoDeArticulo = CantidadDeArticulos ;
}

void ArticuloDePrestamo::AsignarAProfesor(Profesor* Profesor) {
	this->ProfesorAsignado = Profesor ; 
}

void ArticuloDePrestamo::setDespreciacion(float Despreciacion){
	this->ValorDespreciacionAnual = Despreciacion ;
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
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

bool ArticuloDePrestamo::Despreciacion(Fecha* Actual, Fecha* FechaArticulo) { 
	int DiferenciAnios, DiferenciaMes, DiferenciaAlAnio ; 
	
	DiferenciAnios = Actual->getAnio() - FechaArticulo->getAnio() ;
	DiferenciaMes = Actual->getMes() - FechaArticulo->getMes() ;
	
	if (DiferenciAnios >= 2) {
		this->ValorActualArticulo = 0 ;
		return true ; 				
	}else if (DiferenciAnios == 1) {
		if (FechaArticulo->getMes() >= Actual->getMes()) {
			DiferenciaAlAnio = FechaArticulo->getMes() - Actual->getMes() ; 
			DiferenciaMes = 12 - DiferenciaAlAnio ; 
			this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * DiferenciaMes) ;
			DiferenciaMes -= 18 ; 
			switch (DiferenciaMes) {
				case 1 : { // Un mes
					this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
					return false ;
					break;
				}
				
				case 2 : { // Dos meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
					return false ;
					break;
				}
				
				case 3 : { // Tres meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
					return false ;
					break;
				}
				
				case 4 : { // Cuatro meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
					return false ;
					break;
				}
				
				case 5 : { // Cinco meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
					return false ;
					break;
				}
				
				case 6 : { // Seis meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
					return false ;
					break;
				}
				
				case 7 : { // Siete meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
					return false ;
					break;
				}
				
				case 8 : { // Ocho meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
					return false ;
					break;
				}
				
				case 9 : { // Nueve meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
					return false ;
					break;
				}
				
				case 10 : { // Dies meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 10) ;
					return false ;
					break;
				}
				
				
				case 11 : { // Once meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 11) ;
					return false ;
					break;
				}
			}
		}else {			
			DiferenciaMes += 12 ;
			this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * DiferenciaMes) ;
			DiferenciaMes -= 18 ; 
			switch (DiferenciaMes) {
				case 1 : { // Un mes
					this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
					return false ;
					break;
				}
				
				case 2 : { // Dos meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
					return false ;
					break;
				}
				
				case 3 : { // Tres meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
					return false ;
					break;
				}
				
				case 4 : { // Cuatro meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
					return false ;
					break;
				}
				
				case 5 : { // Cinco meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
					return false ;
					break;
				}
				
				case 6 : { // Seis meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
					return false ;
					break;
				}
				
				case 7 : { // Siete meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
					return false ;
					break;
				}
				
				case 8 : { // Ocho meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
					return false ;
					break;
				}
				
				case 9 : { // Nueve meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
					return false ;
					break;
				}
				
				case 10 : { // Dies meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 10) ;
					return false ;
					break;
				}
				
				
				case 11 : { // Once meses
					this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 11) ;
					return false ;
					break;
				}
			}
		}
	}else if (DiferenciAnios == 0) {
		switch (DiferenciaMes) {
			case 1 : { // Un mes
				this->ValorActualArticulo -= this->ValorDespreciacionAnual ;  				
				return false ;
				break;
			}
			
			case 2 : { // Dos meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 2) ;
				return false ;
				break;
			}
			
			case 3 : { // Tres meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 3) ;
				return false ;
				break;
			}
			
			case 4 : { // Cuatro meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 4) ;
				return false ;
				break;
			}
			
			case 5 : { // Cinco meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 5) ;
				return false ;
				break;
			}
			
			case 6 : { // Seis meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 6) ;
				return false ;
				break;
			}
			
			case 7 : { // Siete meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 7) ;
				return false ;
				break;
			}
			
			case 8 : { // Ocho meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 8) ;
				return false ;
				break;
			}
			
			case 9 : { // Nueve meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 9) ;
				return false ;
				break;
			}
			
			case 10 : { // Dies meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 10) ;
				return false ;
				break;
			}
			
			
			case 11 : { // Once meses
				this->ValorActualArticulo = this->ValorActualArticulo - (this->ValorDespreciacionAnual * 11) ;
				return false ;
				break;
			}
		}
	}
	
	if (this->ValorActualArticulo == 0) {
		this->EstadoArticuloDeActivo == false ; 
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void ArticuloDePrestamo::CrearArticuloParaPrestamo(ArticuloDePrestamo* ArticuloParaCrear) {
	system("cls") ;
	string Nombre, Marca ;
	int Codigo, NroDeArticulos ; 
	float Valor ;
	bool EstadoArticulo = true, EstadoDeLimiteCantidad = true, Asignacion = true ;
	
	cout << "\n\tPor favor ingrese los datos correspondientes a articulos de prestamos \n\n" ;
	
	cout << "Ingrese el nombre del articulo: \n" ;
	fflush(stdin) ;
	cin  >> Nombre ;
	
	cout << "Ingrese la marca del articulo: \n"  ;
	fflush(stdin) ;
	cin  >> Marca ;
	
	Codigo = common::ValidarEntero("Ingrese el Codigo del articulo: \n" ) ;
	
	NroDeArticulos = common::ValidarEntero("Ingrese la cantidad de articulos que van a estar disponibles: \n" ) ;
		
	Valor = common::ValidarEntero("Ingrese el valor del articulo: \n" ) ;
		
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

}


/////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void ArticuloDePrestamo::AgregarFechaLim(Fecha* FechaLim) {
	this->FechaLimite = FechaLim ;	
}
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

Fecha* ArticuloDePrestamo::MostrarFecha() {
	return this->FechaLimite ; 
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
ArticuloDePrestamo::~ArticuloDePrestamo() {
}
