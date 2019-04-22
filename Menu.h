
#ifndef MENU_H_
#define MENU_H_
#include <string>
#include "Laboratorio.h"

using namespace std ;

class Menu {
	private :
		int Opcion ; // Este Atributo es para utilizar solo en el menu 
					 // para que me vaya almacenando la opciones ingresadas
		Laboratorio* UsoDelLaboratorio = new Laboratorio () ;   
		 
	public :
		Menu () ; 
		void MenuIngreso () ;
		void RegistroIDPersona () ;
		void MenuDatosExistentes() ;
		void MenuOpcionesPosibles () ;
		void MenuParaEstudiantes(int Posicion) ;
		void MenuExclusivoEstudiante();
		void MenuParaProfesores (int Posicion) ;
		void MenuExclusivoProfe() ;
		void MenuParaArticulosDePrestamo () ;
		void MenuParaArticulosDeMueble   () ;
		void MenuParaArticulosDeComputo  () ;
		void MenuParaPersonalAdmi(int Posicion) ;
		void MenuInformacionLaboratorio () ;
		void MenuParaEstadosDeArticulo () ;
		void MenuConsultas () ;
		~Menu () ;
};
#endif 
