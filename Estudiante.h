
#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_
#include <iostream>
#include <vector>
#include "Persona.h"
#include "ArticuloDePrestamo.h"
//#include "Prestamo.h" 


class Estudiante : public Persona {
	private :
		string Carrera ;  
		int Codigo ;
		int Semestre ;
		int ValorMultaAcomulada ;
		bool EstadoDeMulta ;
		bool EstadoDeEstudiante ;
		
		vector <ArticuloDePrestamo*> ArticulosPrestados ; 	// Articulos prestamos Por estudiante 

	public :
		Estudiante () ;
		Estudiante (string Nombre, string Apellido, string Email, int Edad, long Cedula, int Telefono,
					string Carrera, int Codigo, int Semestre, int ValorMultaAcomulada, bool EstadoDeMulta, bool EstadoDeEstudiante) ;					
		void setCarrera (string Carrera) ;
		void setCodigo (int Codigo) ;
		void setSemestre (int Semestre) ;
		void CorrerValorMulta (int ValorMultaAcomulada) ;
		void setEstadoDeMulta (bool EstadoDeMulta) ;
		void setEstadoDeEstudiante (bool EstadoDeEstudiante) ;
		void ArticuloParaPrestar (ArticuloDePrestamo* Articulo) ;
		string getCarrera () ;
		int getCodigo () ;
		int getSemestre ()  ;
		int getValorMultaAcomulada () ;
		bool getEstadoDeMulta () ;
		bool getEstadoDeEstudiante () ;
		vector <ArticuloDePrestamo*> MisArticulos () ;
		void MostrarTodosLosArticulos () ;
		void MostrarArticulo (int Posicion) ;
		void CrearDatosDeObjetoEstudiante (Estudiante* EstudianteParaCrear, int Cantidad) ;
		void Devolucion (int Posicion) ;
		~Estudiante () ;
};
#endif
