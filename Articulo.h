
#ifndef ARTICULO_H_
#define ARTICULO_H_
#include <iostream>
#include <string>
#include <time.h>
#include "common.h"

using namespace std ; 

class Articulo {
	protected :
		string IDNombre ;
		int CodigoArticulo ;
		float ValorArticulo ;
		float ValorActualArticulo ;
		bool EstadoArticuloDeActivo ;
		bool EstadoDeLimiteDeArticulos ;
		bool EstadoDeAsignadoAProfesor ;
		
		// Estructuras
		struct tm* Fecha ;
		
	public :
		
		//Constructores
		Articulo () ;
		Articulo (string IDNombre, int CodigoArticulo, int ValorArticuloInicial, int ValorActualArticulo, 
				  bool EstadoArticulo, bool EstadoDeLimiteDeArticulos, bool EstadoDeAsignadoAProfesor) ;
				  
		//Otros metodos...		  
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
		void AsignarFecha (struct tm* AgregarFecha) ;
		
		//Estructura
		struct tm* getFecha () ; 
		
		//Funcion virtual...
		virtual float Despreciacion () = 0 ; //Funcion implementada por sus hijos.
		
		//Destructor...
		~Articulo () ; 
};
#endif
