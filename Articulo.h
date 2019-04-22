
#ifndef ARTICULO_H_
#define ARTICULO_H_
#include <iostream>
#include <string>
#include "common.h"
#include "Fecha.h"

using namespace std ; 

class Articulo  {
	protected :
		string IDNombre ;
		int CodigoArticulo ;
		float ValorArticulo ;
		float ValorActualArticulo ;
		bool EstadoArticuloDeActivo ;
		bool EstadoDeLimiteDeArticulos ;
		bool EstadoDeAsignadoAProfesor ; 
		
		Fecha* FechaDeRegistro ;
		
	public :
		Articulo () ;
		Articulo (string IDNombre, int CodigoArticulo, int ValorArticuloInicial, int ValorActualArticulo, 
				  bool EstadoArticulo, bool EstadoDeLimiteDeArticulos, bool EstadoDeAsignadoAProfesor) ;
		void setIDNombre (string IDNombre) ;
		void setCodigoArticulo (int CodigoArticulo) ;
		void setValorArticuloInicial (float ValorArticuloInicial) ;
		void setValorActualArticulo (float ValorActualArticulo) ;
		void setEstadoArticuloDeActivo (bool EstadoArticulo) ;
		void setEstadoDeLimiteDeArticulos (bool EstadoDeLimiteDeArticulos) ;
		void setEstadoDeAsignadoAProfesor (bool EstadoDeAsignadoAProfesor) ;
		string getIDNombre () ;
		int getCodigoArticulo () ;
		float getValorArticuloInicial () ;
		float getValorActualArticulo () ;
		bool getEstadoArticuloDeActivo () ;
		bool getEstadoDeLimiteDeArticulos () ;
		bool getEstadoDeAsignadoAProfesor () ;
		Fecha* getFecha () ; 
		void AsignarFecha (Fecha* FechaArticulo) ;
		virtual bool Despreciacion (Fecha* Actual, Fecha* FechaArticulo) = 0 ;
		~Articulo () ; 
};
#endif
