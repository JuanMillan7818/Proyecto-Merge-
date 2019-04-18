
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
		vector <Profesor> Profesores ;
		vector <Estudiante> Estudiantes ;
		vector <Informacion> Informaciones ;
		vector <PersonalAdmi> PersonalAdmin ;
		vector <ArticuloDePrestamo> ArticulosDisponibles ;
		vector <ArticuloComputo> ArticulosComp ;
		vector <ArticuloMueble> ArticulosMuebles ;
		vector <int> AsignarFecha  ; // desde 1-4 es CodigoDelArticulo, Anio, Mes, Dia
		vector <int*> CodigosDeEstudiantes ;

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
		//void getArticulosPrestamo() ;

		// Reglas
		void Reglas () ;
		void CargarTodoslosArchivos () ;

		// Mandar tamaño del vector y posicion del ultimo dato
		int MandarPosicionActual (int ClaseVector) ;
		
		//  Diligenciar Prestamo a estudiantes
		void ServicioPrestamo(int PosiEstudiante, int PosiArticulo) ;
		void VerMisPrestados (int Posicion) ; 
		
		// Diligenciar devolucion de prestamos 
		void ServicioDevolucion (int PosiEstudiante) ; 
		
		// Diligenciar pago de multa 
		void RealizarPagoMulta(int Posicion) ;
		
		// Pedir datos y agregarlos al vector correspondiente
		bool AgregarAlVectorProfesores (int Cantidad) ;
		bool AgregarAlVectorEstudiantes (int Cantidad) ;
		void AgregarAlVectorInformaciones (int Cantidad) ;
		bool AgregarAlVectorPersonalAdmin (int Cantidad) ;
		void AgregarAlVectorComputo (int Cantidad) ;
		void AgregarAlVectorMueble (int Cantidad) ;
		void AgregarAlVectorDisponibles (int Cantidad) ;
		void AgregarFecha(int Posicion, int Dia, int Mes, int Anio) ;
		void AgregarAlVectorPrestamo(int Catindad );

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
		void AccederEStadoMultaEstudiante(int Posicion);
//		void AccederArticulosprestamo (int Posicion);

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
		void AsignarAlCargarFecha (vector <Fecha*> FechasAux3) ;
	
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
