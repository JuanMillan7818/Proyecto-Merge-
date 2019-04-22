
#ifndef ARTICULOCOMPUTO_H_
#define ARTICULOCOMPUTO_H_
#include "Articulo.h"
#include "Profesor.h" 

using namespace std ;

class ArticuloComputo : public Articulo {
	private :
		string IDMarca ;
		int CantidadDisponibles ;
		float ValorDespreciacionAnual ;
		
		//Puntero
		Profesor* ProfesorAsignado ;		

	public :
		// Constructor
		ArticuloComputo () ;
		
		//Puntero
		Profesor* getProfesor () ;
		
		//Otros metodos
		void AsignarAlArticulo (Profesor* Profesor) ;
		void setIDMarca (string IDMarca) ;
		void setDespreciacion (float Despreciacion) ;
		void setCantidad (int Cantidad) ;
		string getIDMarca () ;
		float getDespreciacion() ;
		int getCantidad () ; 
		
		// Polimorfismo
		float Despreciacion ()  ; 
		void CrearComputo (ArticuloComputo* ComputoACrear) ; 
		void CrearArchivoInventario () ;
		
		//Destructor
		~ArticuloComputo () ;
};
#endif
