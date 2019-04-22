
#ifndef ARTICULODEPRESTAMO_H_
#define ARTICULODEPRESTAMO_H_
#include "Articulo.h"
#include "Profesor.h"
#include <vector>

class ArticuloDePrestamo : public Articulo { 
	private :
		string IDMarca ;
		int CantidadDeTipoDeArticulo ;
		float ValorDespreciacionAnual ;

		//Puntero
		Profesor* ProfesorAsignado ;
			
	public :
		//Constructor
		ArticuloDePrestamo () ;
		
		//Puntero
		Profesor* getProfesor () ;
		ArticuloDePrestamo* ArticulosDePrestamoIniciales (ArticuloDePrestamo* ArticulosIniciales, int NroDeArticulo) ; 
				
		//Otros metodos		
		void setIDMarca (string IDMarca) ;
		void setCantidadDeTipoDeArticulo (int CantidadDeArticulos) ;
		void setDespreciacion (float Despreciacion) ;
		string getIDMarca () ;
		int getCantidadDeTipoDeArticulo () ;
		float getDespreciacion() ;
		void AsignarAProfesor (Profesor* Profesor) ;
		void CrearArticuloParaPrestamo (ArticuloDePrestamo* ArticuloParaCrear) ; 
		//Polimorfismo
		float Despreciacion ()  ;
		
		//Destructor
		~ArticuloDePrestamo () ;
};
#endif 
