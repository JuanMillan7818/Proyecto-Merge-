
#include "Fecha.h"


// CONSTRUCTORES
Fecha::Fecha() {

}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

Fecha::Fecha(int Dia, int Mes, int Anio) {
	this->Dia = Dia ;
	this->Mes = Mes ;
	this->Anio = Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// SETTERS
void Fecha::setDia(int Dia) {
	this->Dia = Dia ;
}

void Fecha::setMes(int Mes) {
	this->Mes = Mes ;
}

void Fecha::setAnio(int Anio) {
	this->Anio = Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// GETTERS
int Fecha::getDia() {
	return this->Dia ;
}

int Fecha::getMes() {
	return this->Mes ;
}

int Fecha::getAnio() {
	return this->Anio ;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////


bool Fecha::ValidarFormatoDeFecha(Fecha* FechaAValidar, Fecha* Actual) {
	if (FechaAValidar->getAnio() < Actual->getAnio()) {
		cout << "\n\tError del formato de fecha ingresada !!  \n" ;
		cout << "El anio debe ser mayor a la fecha del Laboratorio \n\n" ;
		system("pause") ; 
		return false ;
	} else if (FechaAValidar->getMes() > 12) {
		cout << "\n\tError del formato de fecha ingresada !!  \n" ;
		cout << "El Mes es incorrecto debe ser de 0-12 \n\n" ;
		system("pause") ; 
		return  false ;
	} else if (FechaAValidar->getMes() == 2) {
		if (FechaAValidar->getDia() > 29) {
			cout << "\n\tError del formato de fecha ingresada !!  \n" ;
			cout << "El dia es incorrecto debe ser de 0-29 \n\n" ;
			system("pause") ; 
			return false ;
		}
	} else if (FechaAValidar->getDia() > 31) {
		cout << "\n\tError del formato de fecha ingresada !!  \n" ;
		cout << "El dia es incorrecto debe ser de 0-29 \n\n" ;
		system("pause") ; 
		return false ;
	}

	return true ;
	system("pause") ;
}


///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Fecha::~Fecha() {
}
