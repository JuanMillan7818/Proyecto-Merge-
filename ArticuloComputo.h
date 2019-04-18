
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
		
		Profesor* ProfesorAsignado ;
		Fecha* FechaDeRegistro ;		

	public :
		ArticuloComputo () ;
		Profesor* getProfesor () ;
		void AsignarAlArticulo (Profesor* Profesor) ;
		void setIDMarca (string IDMarca) ;
		void setDespreciacion (float Despreciacion) ;
		void setCantidad (int Cantidad) ;
		string getIDMarca () ;
		float getDespreciacion() ;
		int getCantidad () ; 
		float Despreciacion ()  ; // Polimorfismo
		Fecha* getFecha () ; 
		void AsignarFecha (Fecha* FechaRegistro) ; 
		void RegistrarFecha (int Dia, int Mes, int Anio) ;
		void CrearComputo (ArticuloComputo* ComputoACrear) ; 
		void CrearArchivoInventario () ;
		~ArticuloComputo () ;
};
#endif
