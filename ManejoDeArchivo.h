
#ifndef MANEJODEARCHIVO_H_
#define MANEJODEARCHIVO_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include "Laboratorio.h"
#include "ArticuloComputo.h"
#include "ArticuloMueble.h"


using namespace std ;

class ManejoDeArchivo {
	private :
		int PosicionDelVector ;  

	public :
		ManejoDeArchivo () ;
		
		// Manejo de Archivos Para Informacion del laboratorio
		void CrearArchivoInformacionCSV (vector <Informacion> Informaciones) ;
		void CargarArchivoInformacionCSV (vector <Informacion>* Informaciones) ;

		// Manejo de Archivos Para Estudiante del laboratorio
		void CrearArchivoEstudianteCSV (vector <Estudiante> Estudiantes) ;
		void ActualizarArchivoEstudianteCSV (vector <Estudiante> Estudiantes) ;
		void CargarArchivoEstudianteCSV (vector <Estudiante>& Estudiantes) ;
		
		// Manejo De Archivos Para Los Articulos Prestados Por Un Estudiante
		void CrearArchivoPrestados (vector <Estudiante> Prestamos) ;
		void ActualizarPrestados (vector <Estudiante> Prestamos) ;
		void CargarPrestados (vector <Estudiante*> Prestamos, vector <ArticuloDePrestamo*> Articulos) ; 

		// Manejo de Archivos Para Profesor del laboratorio
		void CrearArchivoProfesorCSV (vector <Profesor> Profesores) ;
		void ActualizarArchivoProfesorCSV (vector <Profesor> Profesores) ;
		void CargarArchivoProfesorCSV (vector <Profesor>* Profesores) ;
		
		// Manejo de Archivos Para Articulo de Personal Administrativo del laboratorio
		void CrearArchivoAdminisCSV (vector <PersonalAdmi> PersonalAdm) ;
		void CargarArchivoAdminisCSV (vector <PersonalAdmi>* PersonalAdm) ;
		
		// Manejo de Archivos para Articulos de Computo del Laboratorio 
		void CrearArchivoArticuloComputoCSV (vector <ArticuloComputo> ArticulosParaComputo) ; 
		void ActualizarComputoCSV (vector <ArticuloComputo> ArticulosParaComputo) ;
		vector <int> CargarArchivoArticuloComputoCSV (vector <ArticuloComputo>* ArticulosParaComputo) ;
		void CargarArticuloComputoCSV (vector <Fecha>* FechasRegistradas) ;
		
		
		// Manejo de Archivos Para Articulo de prestamo del laboratorio
		void CrearArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo> ArticulosParaPrestar) ;
		void ActualizarArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo> ArticulosParaPrestar) ;
		vector <int> CargarArchivoArticuloDePrestamoCSV (vector <ArticuloDePrestamo>* ArticulosParaPrestar) ;
		void CargarArticuloDePrestamoCSV (vector <Fecha>* FechasRegistradas) ;

		// Manejo de Archivos para Articulos de Mueble del Laboratorio
		void CrearArchivoArticuloMuebleCSV (vector <ArticuloMueble> ArticulosParaMueble) ; 
		void ActualizarMuebleCSV (vector <ArticuloMueble> ArticulosParaMueble) ;
		vector <int> CargarArchivoArticuloMuebleCSV (vector <ArticuloMueble>* ArticulosParaMueble) ;
		void CargarArticuloMuebleCSV (vector <Fecha>* FechasRegistradas) ;
	
		// Crear historiales
		void HistorialPrestamoCSV (vector <Estudiante> EstudiantePrestamo) ; 
		void ActualizarHistorial (vector <Estudiante> EstudiantePrestamo) ; 
		void CargarHistorialPrestamo (vector <Estudiante>* Estudiantes) ;
		void CargarHistorialPrestamo (vector <ArticuloDePrestamo>* Prestamos) ;
		void CargarHistorialPrestamo (vector <Fecha>* FechaHistorial) ; 
				
		// Crear Plazo de entrega
		void CrearPlazoEntrega (vector <Estudiante> EstudiantePlazo) ;
		void ActualizarPlazos (vector <Estudiante> EstudiantePlazo) ;
		void CargarPlazos (vector <Estudiante>* EstudianteAux) ;
		void CargarPlazos (vector <Fecha>* FechasRegistradas) ;
		
		// Funcion para Cambiar de string -> int
		float CambioStringALong (string Temporal) ;
		
		~ManejoDeArchivo () ;
};
#endif
