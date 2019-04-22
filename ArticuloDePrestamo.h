
#ifndef ARTICULODEPRESTAMO_H_
#define ARTICULODEPRESTAMO_H_
#include "Articulo.h"
#include "Profesor.h"
#include "Fecha.h"
#include <vector>

class ArticuloDePrestamo : public Articulo { 
	private :
		string IDMarca ;
		int CantidadDeTipoDeArticulo ;
		float ValorDespreciacionAnual ;

		
		Profesor* ProfesorAsignado ;
		Fecha* FechaLimite ; 
		
	public :
		ArticuloDePrestamo () ;
		void setIDMarca (string IDMarca) ;
		void setCantidadDeTipoDeArticulo (int CantidadDeArticulos) ;
		void setDespreciacion (float Despreciacion) ;
		string getIDMarca () ;
		int getCantidadDeTipoDeArticulo () ;
		float getDespreciacion() ;
		Profesor* getProfesor () ;
		void AsignarAProfesor (Profesor* Profesor) ;
		void CrearArticuloParaPrestamo (ArticuloDePrestamo* ArticuloParaCrear) ; 
		bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo)  ;  // Polimorfismo
		void AgregarFechaLim (Fecha* FechaLim) ; 
		Fecha* MostrarFecha () ; 
		~ArticuloDePrestamo () ;
};
#endif 
