
#ifndef ARTICULOMUEBLE_H_
#define ARTICULOMUEBLE_H_
#include "Articulo.h"
#include "Profesor.h"

using namespace std ;

class ArticuloMueble : public Articulo {
	private :
		string Material ;
		int CantidadMueble ;
		float ValorDespreciacionAnual ;
		
		Profesor* ProfesorAsignado ;
						
	public :
		ArticuloMueble () ;
		void setMaterial (string Material) ;
		void setDespreciacion (float Despreciacion) ;
		void setCantidad (int Cantidad) ;
		void AsignarAlArticulo (Profesor* Profesor) ;  
		string getMaterial () ;
		float getDespreciacion() ;
		int getCantidad () ; 
		Profesor* getProfesorAsignado () ;
		bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo)  ; // Polimorfismo
		void CrearMueble (ArticuloMueble* ArticuloACrear) ; 
		~ArticuloMueble () ;
};
#endif 
