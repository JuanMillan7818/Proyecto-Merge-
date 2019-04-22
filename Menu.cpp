#include "Menu.h"

// CONSTRUCTOR
Menu::Menu(){
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuIngreso() {
	bool* Salir = new bool (false) ;
	
	UsoDelLaboratorio->CargarTodoslosArchivos() ; // Cargar los archivos a los vecotres
	
//	UsoDelLaboratorio->getProfesores() ;
//	system("pause") ; 

//	UsoDelLaboratorio->getPrestamos() ;
//	system("pause") ; 
	
	
	// Crear Informacion Inicial 
	if (UsoDelLaboratorio->VerificarVectorInformaciones() == true) {
		UsoDelLaboratorio->AgregarAlVectorInformaciones(3) ;
	}
	
	 
	do {
		system("cls") ;
		cout << "\t\bBIENVENIDO AL LABORATORIO \n\n" ;
		cout << "1. REGISTRARSE. \n" ;
		cout << "2. VER INFORMACION PRINCIPAL \n" ;
		cout << "3. SALIR \n\n " ;
		
		Opcion = common::ValidarEntero("ELIGE UNA OPCION: \n" ) ;
		
		switch (this->Opcion) {
			case 1 : { // Ingreso al sistema
				RegistroIDPersona () ;
				break;  
			}
			
			case 2 : { // Ver informacion principal
				UsoDelLaboratorio->getInformaciones() ;
				system("pause") ;
				MenuParaArticulosDeComputo() ; 
				break;
			}
			
			case 3 : { // Salir 
				cout << "GRACIAS POR VISITARNOS, ESPERAMOS TU REGRESO... \n\n" ;
				*Salir = true ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
						
			default : { // Opcion Incorrecta
				cout << "\nOPCION NO VALIDA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		} 
	}while (!*Salir) ;
	
	delete Salir ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::RegistroIDPersona() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		cout << "\t\nRegistro De Usuario \n" ;
		cout << "Elige la opcion correspendiente... \n\n" ;
		cout << "1. INGRESAR COMO ESTUDIANTE \n" ;
		cout << "2. INGRESAR COMO PROFESOR \n" ;
		cout << "3. INGRESAR COMO PERSONAL ADMINISTRATIVO \n" ;
		cout << "4. FUNCIONES AL MANEJO DE INFORMACION DEL LABORATORIO \n" ;
		cout << "5. INGRESAR CON DATOS EXISTENTES \n" ; 
		cout << "6. Atras \n\n" ;
		
		this->Opcion = common::ValidarEntero("ELIGE UNA OPCION:\n" ) ;

		int Cantidad = 1 ; // Para referir que solo puede registrarse una persona a la vez
		
		switch (this->Opcion) { // Registrarse como estudiante
			case 1 : {
				UsoDelLaboratorio->AgregarAlVectorEstudiantes(Cantidad) ;
		
				MenuParaEstudiantes (UsoDelLaboratorio->MandarPosicionActual(0)) ;
				break;
			}
			
			case 2 : { // Registrarse como Profesor
				UsoDelLaboratorio->AgregarAlVectorProfesores(Cantidad) ;
				UsoDelLaboratorio->getProfesores() ;
				
				system("pause") ;
				MenuParaProfesores(UsoDelLaboratorio->MandarPosicionActual(1)) ;
				break;
			}
			
			case 3 : { // Registrarse como Personal Administrativo
				UsoDelLaboratorio->AgregarAlVectorPersonalAdmin(Cantidad) ;
				
				UsoDelLaboratorio->getPersonalAdmin() ;
				
				system("pause") ;
				MenuParaPersonalAdmi(UsoDelLaboratorio->MandarPosicionActual(3)) ;
				
				break;
			}
			
			case 4 : { // Manejo de informacion del Laboratorio
				MenuInformacionLaboratorio() ; 
				break;
			}
			
			case 5 : { // Ingresar con datos ya existentes
				system("cls") ;
				MenuDatosExistentes() ;
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ;
				MenuIngreso () ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INVALIDA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while (!*Salir) ;
	
	delete Salir ; 
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuDatosExistentes() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\tDATOS EXISTENTES \n\n" ;
		cout << "1. INGRESAR COMO ESTUDIANTE \n" ;
		cout << "2. INGRESAR COMO PROFESOR \n" ;
		cout << "3. INGRESAR COMO PERSONAL ADMINISTRATIVO \n" ;
		cout << "4. Atras \n" ;
		cout << "5. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("SELECCIONE UNA OPCION:\n") ; 
		
		switch(this->Opcion) {
			case 1 : { // Ingresar con datos de estudiantes
			
				if(UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					UsoDelLaboratorio->getEstudiantes() ;
				
					this->Opcion = common::ValidarEntero("SELECCIONE SUS DATOS \n") ; 
				
					MenuParaEstudiantes(this->Opcion) ;	
				}else {
					cout << "\nDATOS NO EXISTENTES \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}
				break;
			}
			
			case 2 : { // Ingresar con datos de profesores
				if(UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					UsoDelLaboratorio->getProfesores() ;
				
					this->Opcion = common::ValidarEntero("SELECCIONE SUS DATOS \n") ; 
				
					MenuParaProfesores(this->Opcion) ;
				}else {
					cout << "\nDATOS NO EXISTENTES \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}		
				break;
			}
			
			case 3 : { // Ingresar con Datos de Personal Administrativo
				if(UsoDelLaboratorio->VerificarVectorAdmin() == false) {
					UsoDelLaboratorio->getPersonalAdmin() ;
				
					this->Opcion = common::ValidarEntero("SELECCIONE SUS DATOS \n") ; 
				
					MenuParaPersonalAdmi(this->Opcion) ;	
				}else {
					cout << "\nDATOS NO EXISTENTES \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}				
				break;
			}
			
			case 4 : { // Atras
				*Salir = true ;
				RegistroIDPersona() ;
				break;
			}
			
			case 5 : { // Salir
				cout << "\nESPERAMOS SU REGRESO \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;
	
	
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



void Menu::MenuParaProfesores(int Posicion) {
	
	bool* Salir = new bool ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES PARA PROFESORES \n\n" ;
		cout << "1. VER MI INFORMACION DISPONIBLE \n" ;
		cout << "2. VER ARTICULOS ENCARGADOS \n" ;
		cout << "3. VER PROFESORES REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "4. MODIFICAR DATOS BASICOS \n" ;
		cout << "5. Atras \n" ;
		cout << "6. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("SELECCIONA UNA OPCION:\n") ; 
		
		switch(this->Opcion) {
			case 1 : { // Ver mi informacion disponible
				
				UsoDelLaboratorio->AccederProfesorPosicion(Posicion) ;
				system("pause") ; 
				
				break;
			}
			
			case 2 : { // Ver informacion de los articulos 
			
				UsoDelLaboratorio->AccederArticulosProfe(Posicion) ;
				system("pause") ;
				
				break;
			}
			
			case 3 : { // Ver todos los profesores 
			
				UsoDelLaboratorio->getProfesores() ;
				
				system("pause") ;
				break;
			}
			
			case 4 : { // Modificar datos basicos
			
				UsoDelLaboratorio->ModificarDatosBasicosProfe(Posicion) ;
								
				break;
			}
			
			case 5 : { // Atras
			
				RegistroIDPersona() ;
				break;
			}
			
			case 6 : { // Salir
			
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
			
				cout << "\nHOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
		
	}while(!*Salir) ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuExclusivoProfe(){
	 
	
	
	cout << "\t\tPROFESORES REGISTRADOS EN EL SISTEMA\n" ;

	bool* Salir = new bool (false) ;
	
	UsoDelLaboratorio->getProfesores() ;
	
	int Eleccion ;
		
	this->Opcion = common::ValidarEntero("SELECCIONA UN PROFESOR\n") ;
	
	UsoDelLaboratorio->AccederProfesorPosicion(Opcion) ;
	do{
		system("cls") ;
		
		cout << "1. MODIFICAR INFORMACION \t\n" ;
		cout << "2. ELIMINAR PROFESOR DEL SISTEMA \t\n" ;
		cout << "3. VER SUS DATOS EXISTENTES \t\n" ;
		cout << "4. VER ARTICULOS ASIGNADOS \t\n" ;
		cout << "5. Atras\n" ;
		cout << "6. Salir \n\n" ;
		
		Eleccion = common::ValidarEntero("SELECCIONE UNA OPCION: \n") ;
		
		
		switch(Eleccion) {
			
			case 1 : {//Modifica los datos personales de un profesor
			
				UsoDelLaboratorio->ModificarDatosProfe(Eleccion) ;
				system("pause") ;
				break;
			}
			
			case 2 : {//Eliminar un profesor
			
				UsoDelLaboratorio->EliminarDatosDelVectorProfesor(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 3 : {//Acceder a un profesor
			
				UsoDelLaboratorio->AccederProfesorPosicion(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 4 : {//Ver articulos Asignados
			
				UsoDelLaboratorio->AccederArticulosProfe(this->Opcion) ;
				break;
			}
			
			case 5 : {//Atras
			
				*Salir = true ; 
				break;
			}
			
			case 6 : {//Salir
			
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
			
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTALO DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}  
	}while(!*Salir) ;
	
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuParaArticulosDePrestamo(){
	
	bool* Salir = new bool (false) ;
		    
    do{
    	system("cls");
    	
    	cout << "\n\tFUNCIONES PERMITIDAS PARA ARTICULOS DE PRESTAMO \n\n" ;
    	cout << "1. ARTICULOS PRESTADOS\n" ;
    	cout << "2. CONSULTAR UN ARTICULO EN ESPECIFICO\n" ;
    	cout << "3. REGISTRAR UN NUEVO ARTICULO DE PRESTAMO\n" ;
    	cout << "4. MODIFICAR UN ARTICULO\n" ;
    	cout << "5. ELIMINAR ARTICULO\n" ;
    	cout << "6. Atras \n" ;
    	cout << "7. Salir \n\n" ;
    	
    	this->Opcion = common::ValidarEntero("SELECCIONE UNA OPCION:\n") ;
    	
    	switch(this->Opcion){
    		case 1 :{
    			if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
    				system("pause");
				}else {
					cout << "\nDATOS DE REGISTRO NO EXISTENTE \n\n" ;
					system("pause") ;
				}
    			
				break;
			}
			
			case 2 :{ 
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
					this->Opcion = common::ValidarEntero("SELECCIONA UN ARTICULO EN ESPECIFICO \n") ;					
					
					UsoDelLaboratorio->AccederArticulosPrestamo(Opcion);
					system("pause");
				}else {
					cout << "\nDATOS DE REGISTRO NO EXISTENTES \n\n" ;
					system("pause") ;
				}
				
				break;
			}
			
			case 3 :{ // Registrar nuevos articulos de prestamos
				
				cout << "\nCANTIDAD DE ARTICULOS QUE DESEA REGISTRAR: " ;
				
				this->Opcion = common::ValidarEntero("\nCANTIDAD: ") ;
				
				UsoDelLaboratorio->AgregarAlVectorPrestamo(this->Opcion) ; 
				
				system("pause");
				
				break;
			}
			
			case 4 :{  // Modificar 
				
				UsoDelLaboratorio->getPrestamos() ;
				
				this->Opcion = common::ValidarEntero("\nSELECCIONE EL ARTICULO QUE DESEA MODIFICAR \n") ;
					
				UsoDelLaboratorio->ModificarDatosArticulosPrestamos(this->Opcion) ; 
					
				system("pause") ; 
				
				break;
			}
			
			case 5 :{ // Eliminar
				
				UsoDelLaboratorio->EliminarDatosDelVectorArticuloPrestamos() ;
				
				system("pause") ; 
				break;
			}
			
			case 6 :{ // Salir
				*Salir = true ; 
				break;
			}
			
			case 7 :{ // Salir
				cout << "\nESPERAMOS TU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default :{ // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTALO DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while (!*Salir) ;
		
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaEstudiantes(int Posicion) {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\t\tMENU EXCLUSIVO PARA ESTUDIANTES \n\n" ;
		cout << "1. VER MI INFORMACION PERSONAL \n" ;
		cout << "2. VER ESTUDIANTES REGISRADOS EN EL SISTEMA \n" ;
		cout << "3. VER ARTICULOS DE PRESTAMO DISPONIBLE \n" ;
		cout << "4. DILIGENCIAR PRESTAMO  \n" ;
		cout << "5. DILIGENCIAR DEVOLUCION \n" ;
		cout << "6. CONSULTAR MI ESTADO DE MULTA \n" ;
		cout << "7. Atras \n" ;
		cout << "8. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("SELECCION UNA OPCION: \n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver mi informacion es decir el de registrado
			
				// Nota : 0 = Al vector de estudiantes, y lo utilizamos para sacar la ultima posicion del vector que es donde se encuentra mis datos
				UsoDelLaboratorio->AccederAUnEstudiante(Posicion) ; 
				
				system("Pause") ;
				break;
			}
			
			case 2 : { // Ver todos los estudiantes registrados en el Laboratorio
			
				UsoDelLaboratorio->getEstudiantes() ; 
				system("pause") ;
				break;
			}
			
			case 3 : { // Ver articulos de prestamo disponible
			
				UsoDelLaboratorio->getPrestamos() ;
				system("pause") ;
				break;
			}
			
			case 4 : {//diligenciar prestamos
			
				UsoDelLaboratorio->AccederArticulosPrestamo(this->Opcion) ;
				//cout << "HOla";
				system("pause") ;
				break;
			}
			
			case 5 : {// diligenciar devolucion
			
				break;
			}
			
			case 6 : {//consultar estado y valor de multa
			
				UsoDelLaboratorio->AccederEStadoMultaEstudiante(this->Opcion) ;
				system("pause") ;
				break;
			}
			
			case 7 : {// Atras
			
				*Salir = true ;
				RegistroIDPersona () ;
				
				break;
			}
			
			case 8 : { // Salir
			
				cout << "\nESPERAMOS TU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
			
			
			default : {
				
				cout << "\nOPCION INCORRECTA\n" ;
				cout << "INTENTALO DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while (!*Salir) ;
	
	delete Salir ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuExclusivoEstudiante(){

	bool* Salir = new bool (false) ;
	
	int Eleccion ;
	
	do {
	
		system("cls");
		
		cout << "\n\t FUNCIONES PARA ESTUDIANTES \n\n\n";
		
		cout << "1. Ver todos los estudiantes. \n" ;
		cout << "2. Ver un estudiante en especifico. \n";
		cout << "3. Registrar un estudiante. \n";
		cout << "4. Modificar un estudiante. \n";
		cout << "5. Eliminar un estudiante. \n" ;
		cout << "6. Atras. \n" ;
		cout << "7. Salir. \n";
		
		Eleccion = common::ValidarEntero("SELECCIONA UNA OPCION: \n") ;
		
		switch(Eleccion){
			case 1 : { // Ver todos los estudiantes
			
				cout << "LOS ESTUDIANTES REGISTRADOS EN EK SISTEMA SON: ";
				UsoDelLaboratorio->getEstudiantes();
				system("pause");
				break;
			}
			
			case 2 : { // Ver un estudiante en especifico 
			
				UsoDelLaboratorio->getEstudiantes();
				
				this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ; 
				
				cout<< "EEL ESTUDIANTE SELECCIONADO ES:";
				UsoDelLaboratorio->AccederAUnEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 3 : { // Registrar estudiantes
			
				cout << "CANTIDAD DE ESTUDIANTES A REGISTRAR \n";
				this->Opcion = common::ValidarEntero("SELECCIONA UNA OPCION: \n") ;
				
				UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion);
				break;
			}
			
			case 4 : { // Modificar estudiantes
			
				cout << "\tMODIFICACION DE LOS DATOS DE UN ESTUDIANTE\n";
				UsoDelLaboratorio->getEstudiantes() ;
				this->Opcion = common::ValidarEntero("SELECCIONE EL CAMPO QUE DESEA MODIFICAR: ") ;
				UsoDelLaboratorio->ModificarDatosEstudiante(this->Opcion) ;
				system("pause");
				break;
			}
			
			case 5 : { // Eliminar algun estudiante
			
				UsoDelLaboratorio->AccederAUnEstudiante(this->Opcion);
				
				UsoDelLaboratorio->getEstudiantes() ;
			
				this->Opcion = common::ValidarEntero("SELECCIONE EL ESTUDIANTE QUE DESEA ELIMINAR: ") ;
				
				UsoDelLaboratorio->EliminarDatosDelVectorEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 6 : { // Atras
			
				*Salir = true ;
				break;
			}
			
			case 7 : { // Salir
			
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTE DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir);
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaArticulosDeMueble() {
	
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES \n\n" ;
		cout << "1. ARTICULOS DE MUEBLES REGISTRADOS \n" ;
		cout << "2. VER UN ARTICULO EN ESPECIFICO \n" ; 
		cout << "3. REGISTRAR UN NUEVO MUEBLE \n" ;
		cout << "4. MODIFICAR ARTICULO MUEBLE  \n" ;
		cout << "5. ELIMINAR ARTICULO MUEBLE \n" ;
		cout << "6. Atras \n" ;
		cout << "7. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("SELECCIONE UNA OPCION: \n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
	
					system("pause") ; 
					
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
			
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
					
					cout << "\nSELECCION EL ARTICULO QUE DESEA VER:	" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAMueble(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
			
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCANTIDAD DE ARTICULOS A REGISTRAR \n") ;
					
				UsoDelLaboratorio->AgregarAlVectorMueble(Cantidad) ;

				break;
			}
				
			case 4 : { // Modificar Articulos
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false){
					UsoDelLaboratorio->getMuebles() ;
					
					this->Opcion = common::ValidarEntero("\nARTICULO A MODIFICAR:") ;
					
					UsoDelLaboratorio->ModificarDatosMueble(this->Opcion) ;
					 
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}
				break;
			} 
				
			case 5 : { // Eliminar Articulos 
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false){
					UsoDelLaboratorio->EliminarDatosDelVectorMueble() ;
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
			
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
			
				cout << "\nREGRESA PRONTO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
			
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuParaArticulosDeComputo() {
	
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES \n\n" ;
		cout << "1. ARTICULOS DE COMPUTO DISPONIBLES \n" ;
		cout << "2. VER ARTICULO ESPECIFICO \n" ; 
		cout << "3. REGISTRAR UN NUEVO COMPUTO \n" ;
		cout << "4. MODIFICAR UN ARTICULO DE COMPUTO \n" ;
		cout << "5. Eliminar articulos de computo \n" ;
		cout << "6. Atras \n" ;
		cout << "7. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("SELECCIONA UNA OPCION:\n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					UsoDelLaboratorio->getComputo() ;
				
					system("pause") ; 
					
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
			
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					cout << "\nSELECCIONE UN ARTICULO EN ESPECIFICO A CONSULTAR \n\n" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAComputo(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
			
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCANTIDAD DE ARTICULOS A REGISTRAR  \n") ;
					
				UsoDelLaboratorio->AgregarAlVectorComputo(Cantidad) ;
				system("pause") ; 
				break;
			}
				
			case 4 : { // Modificar Articulos
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false){
					UsoDelLaboratorio->ModificarDatosDelVectorComputo() ; 
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}
				break;
			} 
				
			case 5 : { // Eliminar Articulos 
			
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false){
					UsoDelLaboratorio->EliminarDatosDelVectorComputo() ;
					system("pause") ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
			
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
			
				cout << "\nESPERAMOS SU REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		}
	}while(!*Salir) ;
	
	
}



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuParaPersonalAdmi(int Posicion) {
	bool* Salir = new bool (false) ;
	
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES \n\n" ;
		cout << "1. VER MI INFORMACION PERSONAL \n" ; 
		cout << "2. FUNCIONES PARA INFORMACION DE LABORATORIO \n" ;
		cout << "3. FUNCIONES PARA ESTUDIANTES REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "4. FUNCIONES PARA PROFESORES REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "5. FUNCIONES PARA ARTICULOS DE COMPUTO REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "6. FUNCIONES PARA ARTICULOS MUEBLE REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "7. FUNCIONES PARA ARTICULOS DE PRESTAMO REGISTRADOS EN EL LABORATORIO \n" ;
		cout << "8. MENU PRINCIPAL \n" ;
		cout << "9. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("SELECCIONA UNA OPCION: \n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver mi informacion
				
				UsoDelLaboratorio->AccederPersonalAdmi(Posicion) ;
				system("pause") ;
				
				break;
			}
			
			case 2 : { // Funciones para informaciones
			
				cout << "\nPRESIONA UNA TECLA PARA SER DIRIGIDO \n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorInformaciones() == false) {
					MenuInformacionLaboratorio() ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					system("pause") ;
					MenuInformacionLaboratorio() ;
				}
				break;
			}
			
			case 3 : { // Menu exclusivo de estudiantes
			
				cout << "\nPRESIONA UNA TECLA PARA SER DIRIGIDO \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					MenuExclusivoEstudiante() ;
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					cout << "\nREGISTRE AL MENOS UN ESTUDIANTE \n\n" ;
					
					system("pause") ;
					system("cls") ;
					
					cout << "\nREGISTRE UN ESTUDIANTE \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCANTIDAD DE ESTUDIANTES A REGISTRAR \n") ;
					UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion) ;
				}
				break;
			}
			
			case 4 : { //Menu para funciones exclusivas de profesor desde administrador		
					
				cout << "\nPRESIONA UNA TECLA PARA SER DIRIGIDO \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					MenuExclusivoProfe();
				}else {
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					cout << "\nREGISTRE AL MENOS UN PROFESOR \n\n" ;
					system("pause") ;
					system("cls") ;
					
					cout << "\nREGISTRE UN PROFESOR \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCANTIDAD DE PROFESORES A REGISTRAR \n") ;
					UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
				}
				break;
			}
			
			case 5 : { // Funciones para articulos de computo
			
			
				cout << "\nPRESIONA UNA TECLA PARA SER DIRIGIDO \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					MenuParaArticulosDeComputo() ;
					
				}else {
					system("cls") ;
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n\n" ;
					cout << "\nREGISTRE UN ARTICULO DE COMPUTO \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCANTIDAD DE ARTICULOS A REGISTRAR \n") ;
						
						UsoDelLaboratorio->AgregarAlVectorComputo(this->Opcion) ;
					}else {
						cout << "\nREGISTRE AL MENOS UN PROFESOR PARA DILIGENCIAR EL REGISTRO DE ARTICULO \n\n" ;				
						this->Opcion = common::ValidarEntero("CANTIDAD DE PROFESORES A REGISTRAR \n") ;
						UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
					}
					
				}
				
				break;
			}
			
			case 6 : { // Funciones para articulos de Mueble
			
				cout << "\nPRESIONA UNA TECLA PARA SER DIRIGIDO \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					MenuParaArticulosDeMueble() ; 
				}else {
					system("cls") ;
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n" ;
					cout << "REGISTRE UN ARTICULO DE MUEBLE \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCANTIDAD DE ARTICULOS A REGISTRAR \n") ;
						
						UsoDelLaboratorio->AgregarAlVectorMueble(this->Opcion) ;
					}else {
						cout << "\nREGISTRE AL MENOS UN PROFESOR PARA DILIGENCIAR EL REGISTRO DE ARTICULO \n\n" ;				
						this->Opcion = common::ValidarEntero("CANTIDAD DE PROFESORES A REGISTRAR \n") ;
						UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
					}
				}
				break;
			}
			
			case 7 : { // Funciones para articulos de Prestamo
			
				cout << "\nPRESIONE UNA TECLA PARA SER DIRIGIDO \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					MenuParaArticulosDePrestamo() ;
				}else {
					system("cls") ;
					cout << "\nNO EXISTEN DATOS DE REGISTRO \n" ;
					cout << "REGISTRE UN ARTICULO DE PRESTAMO \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCANTIDAD DE ARTICULOS A REGISTRAR \n") ;
						
						UsoDelLaboratorio->AgregarAlVectorDisponibles(this->Opcion) ;
					}else {
						cout << "\nREGISTRE AL MENOS UN PROFESOR PARA DILIGENCIAR EL REGISTRO DE ARTICULO\n\n" ;				
						this->Opcion = common::ValidarEntero("CANTIDAD DE PROFESORES A REGISTRAR\n") ;
						UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
					}
				}
				break;
			}
			
			case 8 : { // Atras
			
				MenuIngreso() ;
				*Salir = true ;
				break;
			}
			
			case 9 : { // Salir 
			
				cout << "\nESPERAMOS SU PRONTO REGRESO, ADIOS... \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
			
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTALO DE NUEVO \n" ;
				system("pause") ;
				break;
			}
		} 	
	}while(!*Salir) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


void Menu::MenuInformacionLaboratorio() {
	bool* Salir = new bool (false) ;
	int Cantidad ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFUNCIONES DISPONIBLES  \n\n" ;
		cout << "1. VER INFORMACION PRINCIPAL DEL LABORATORIO \n" ;
		cout << "2. AGREGAR INFORMACION AL LABORATORIO \n" ;
		cout << "3. MODIFICIAR INFORMACION AL LABORATORIO \n" ;
		cout << "4. ELIMINAR DATOS AGREGADOS  \n" ;
		cout << "5. Atras. \n" ;
		
		this->Opcion = common::ValidarEntero("SELECCIONA UNA OPCION\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver toda la informacion del Laboratorio disponible
			
				UsoDelLaboratorio->getInformaciones() ;
				cout << "\n" ; 
				system("pause") ;
				break;
			}
			
			case 2 : { // Agregar informacion al Laboratorio
			
				system("cls") ;
				cout << "CANTIDAD DE DATOS A INGRESAR \n" ;
				Cantidad = common::ValidarEntero("CANTIDAD DE DATOS QUE DESEA AGREGAR \n") ;
				
				UsoDelLaboratorio->AgregarAlVectorInformaciones(Cantidad) ; 
				break;
			}
			
			case 3 : { // Modificar datos del Laboratorio
			
				system("cls") ;
				
				cout << "\nMOODIFICACION DE DATOS BASICOS DEL LABORATORIO !!! \n" ;
				system("pause") ;
				UsoDelLaboratorio->ModificarDatosDelVectorInformaciones() ;
				break;
			}
			
			case 4 : { // Eliminar datos del Laboratorio Exclusivo para personal Adiministrativo
			
				system("cls") ;
				
				cout << "\nELIMINAR DATOS DEL LABORATORIO \n" ;
				cout << "ATENCION <SOLO PODRAS ELIMINAR LA INFORMACION AGREGADA" ;
				system("pause") ;
				UsoDelLaboratorio->EliminarDatosDelVectorInformaciones() ;
								
				break;
			}
			
			case 5 : { // Atras 
			
				*Salir = true ; 
				break;
			}
			
			default : { // Opcion Incorrecta
			
				cout << "\nOPCION INCORRECTA \n" ;
				cout << "INTENTA DE NUEVO \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while(!*Salir) ;
}


/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

// DESTRUCTOR
Menu::~Menu() {
}
