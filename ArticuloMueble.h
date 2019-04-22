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
		
		//Puntero
		Profesor* ProfesorAsignado ;
						
	public :
		//Constructor
		ArticuloMueble () ;
		
		//Otros metodos
		void setMaterial (string Material) ;
		void setDespreciacion (float Despreciacion) ;
		void setCantidad (int Cantidad) ;
		void AsignarAlArticulo (Profesor* Profesor) ;  
		string getMaterial () ;
		float getDespreciacion() ;
		int getCantidad () ;
		void CrearMueble (ArticuloMueble* ArticuloACrear) ; 
		 
		//Polimorfismo
		float Despreciacion ()  ; 
		
		//Puntero
		Profesor* getProfesorAsignado () ;
		
		//Destructor
		~ArticuloMueble () ;
};
#endif 
