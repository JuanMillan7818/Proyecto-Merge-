
#ifndef LABORATORIO_H_
#define LABORATORIO_H_
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include "Profesor.h"
#include "Estudiante.h"
#include "Informacion.h"
#include "PersonalAdmi.h"
#include "ManejoDeArchivo.h"
#include "ArticuloDePrestamo.h"
#include "ArticuloComputo.h"
#include "ArticuloMueble.h"


using namespace std ;

class Laboratorio {
	private :
		Fecha* FechaInicio = new Fecha () ; 					// Fecha de creacion del Laboratorio.
		vector <Profesor> Profesores ; 							// Profesores del Laboratorio. 
		vector <Estudiante> Estudiantes ;						// Estudiantes del Laboratorio.
		vector <Informacion> Informaciones ;					// Informacio del Labboratorio.
		vector <PersonalAdmi> PersonalAdmin ;					// Personal Administrativo del Laboratorio.
		vector <ArticuloDePrestamo> ArticulosDisponibles ;  	// Articulos de Prestamo del Laboratorio.
		vector <ArticuloComputo> ArticulosComp ;				// Articulos de Computo del Laboratorio.
		vector <ArticuloMueble> ArticulosMuebles ;				// Articulos de Mueble del Laboratorio.
		vector <int*> CodigosDeEstudiantes ; 					// Detallar bien si es necesaria
		vector <Fecha> FechasAuxiliarComp ; 					// Auxiliares para Fecha de computo
		vector <Fecha> FechasAuxiliarMueb ; 					// Auxiliares para Fecha de muebles
		vector <Fecha> FechasAuxiliarPrest ; 					// Auxiliares para Fecha de prestamos

	public :
		Laboratorio () ;
		
		// Mostrar todo lo que tiene cada vector
		void getProfesores () ;
		void getEstudiantes () ;
		void getEstudianteYPrestados () ;
		void getPersonalAdmin () ;
		void getInformaciones () ;
		void getComputo () ;
		void getMuebles () ;
		void getPrestamos () ;
		void getFechaLaboratorio () ; 

		// Reglas
		void Reglas () ;
		void LimitePrestamos (int Articulo, Estudiante* EstudiantePrest, Fecha* FechaRegistro) ;  
		void AsociarLimite () ;
		void MostrarFechasLimites (int Posicion) ;
		
		// Cargar todos los archivos 
		void CargarTodoslosArchivos () ;

		// Mandar tamaño del vector y posicion del ultimo dato
		int MandarPosicionActual (int ClaseVector) ;
		
		//  Diligenciar Prestamo a estudiantes
		void ServicioPrestamo(int PosiEstudiante, int PosiArticulo) ;
		void VerMisPrestados (int Posicion) ; 
		
		// Diligenciar devolucion de prestamos 
		bool ServicioDevolucion (int PosiEstudiante) ; 
		
		// Diligenciar pago de multa 
		void RealizarPagoMulta(int Posicion) ;
		void Multa() ; 
		
		// Pedir datos y agregarlos al vector correspondiente
		bool AgregarAlVectorProfesores (int Cantidad) ;
		bool AgregarAlVectorEstudiantes (int Cantidad) ;
		void AgregarAlVectorInformaciones (int Cantidad) ;
		bool AgregarAlVectorPersonalAdmin (int Cantidad) ;
		bool AgregarAlVectorComputo (int Cantidad) ;
		bool AgregarAlVectorMueble (int Cantidad) ; 
		bool AgregarAlVectorPrestamo(int Cantidad );

		// Acceder a alguna posicion
		void AccederProfesor (int Codigo, int CodigoArticulo) ; // Para acceder mediante el codigo y agregarlo al articulo
		void AccederProfesorPosicion (int Posicion) ;
		void AccederArticulosProfe(int Posicion) ;
		void AccederAUnEstudiante (int Posicion) ;
		void AccederPersonalAdmi(int Posicion) ;
		Informacion* AccederAUnaInformacion (int Posicion) ;
		void AccederAComputo (int Posicion) ;
		void AccederAMueble (int Posicion) ;
		void AccederProfesorMueb (int Codigo , int CodigoArticulo) ;
		void AccederArticulosPrestamo(int Posicion) ;
		void AccederProfesorArtPrestamo (int Codigo , int CodigoArticulo) ;
		void AccederEstadoMultaEstudiante(int Posicion);

		// Modificar datos de los vectores
		void ModificarDatosDelVectorInformaciones() ;
		void ModificarDatosBasicosProfe(int Posicion) ;
		void ModificarDatosProfe(int Posicion) ;
		void ModificarDatosEstudiante(int Posicion) ;
		void ModificarDatosDelVectorComputo() ;
		void ModificarDatosMueble(int Posicion) ;
		void ModificarDatosArticulosPrestamos(int Posicion) ;

		// Eliminar datos de los vectores
		void EliminarDatosDelVectorInformaciones() ;
		void EliminarDatosDelVectorComputo() ;
		void EliminarDatosDelVectorProfesor(int Opcion) ;
		void EliminarDatosDelVectorEstudiante(int Opcion) ;
		void EliminarDatosDelVectorMueble() ;
		void EliminarDatosDelVectorArticuloPrestamos() ;


		// Asignar Profesor a Articulo
		void AsignarCodigosEstudiantes () ; 
		void AsignarProfesorComputo (int Posicion) ;
		void AsignarProfeMueble (int Posicion) ;
		void AsignarProfePrestamo (int Posicion) ;

		// Asignar Fechas 
		void AsignarFechaComputo (int Posicion) ;
		void AsignarFechaMueble (int Posicion) ;	
		void AsignarFechaPrestamo (int Posicion) ;
	
		// Consultas 
		void ConsultaProfeArticulos() ;
		void ConsultaAsignacionArt() ;
		void ConsultaMultaYEstado() ;
		void ConsultaVDEArticulo() ; 
		void ConsultaActiInac() ;
		
		// Funciones para los historiales
		void MostrarHistorialArticulo() ;
		void MostrarHistorialEstudiante() ; 
		void MostrarHistorialConFechas() ; 
		
		// Indicar fecha actual 
		bool IndicarFecha() ; 
		void Depreciar() ; 
		 
		// Para verificar si el vector esta vacio o no
		bool VerificarVectorProfesores () ;
		bool VerificarVectorAdmin () ;
		bool VerificarVectorEstudiantes () ;
		bool VerificarVectorInformaciones () ;
		bool VerificarArticulosCompu () ;
		bool VerificarArticulosMueble() ;
		bool VerificarArticulosPrestamo() ;

		~Laboratorio () ;
};
#endif
