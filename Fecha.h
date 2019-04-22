
#ifndef FECHA_H_
#define FECHA_H_
#include <iostream>
#include <stdlib.h>

using namespace std ;

class Fecha {
	private :
		int Dia ;
		int Mes ;
		int Anio ;
	
	public :
		Fecha () ;
		Fecha (int Dia, int Mes, int Anio) ;
		void setDia (int Dia) ;
		void setMes (int Mes) ;
		void setAnio (int Anio) ;
		int getDia () ;
		int getMes () ;
		int getAnio () ;
		bool ValidarFormatoDeFecha (Fecha* FechaAValidar, Fecha* Actual) ;
		~Fecha () ;
};
#endif
