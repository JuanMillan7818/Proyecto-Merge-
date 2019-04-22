#ifndef INFORMACION_H_
#define INFORMACION_H_
#include <iostream>
#include <string> 


using namespace std ;

class Informacion {
	private :
		string NombreDeInfo ;
		string ContenidoDeInfo ;
		
	public :	
		//Constructores
		Informacion () ;
		Informacion (string NombreDeInfo, string ContenidoDeInfo) ;
		
		//Otros metodos
		void setNombreDeInfo (string NombreDeInfo) ;
		void setContenidoDeInfo (string ContenidoDeInfo) ;
		string getNombreDeInfo () ;
		string getContenidoDeInfo () ;
		void DatosIniciales (Informacion* InfoInicial, int NroAuxiliar) ;
		void CrearInformacionLabotatorio (Informacion* InformacionParaCrear) ;
		
		//Destructor
		~Informacion () ;
};
#endif
