#include "Menu.h"

// CONSTRUCTOR
Menu::Menu(){
	
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuIngreso() {
	bool* Salir = new bool (false) ;
	
	UsoDelLaboratorio->CargarTodoslosArchivos() ; // Cargar los archivos a los vecotres
	
	bool Estado = UsoDelLaboratorio->IndicarFecha() ;  // Dar la fecha actual
	
	if (Estado == true) {
		 
		UsoDelLaboratorio->Multa() ; 
		UsoDelLaboratorio->Depreciar() ;
		
		// Crear Informacion Inicial 
		if (UsoDelLaboratorio->VerificarVectorInformaciones() == true) {
			UsoDelLaboratorio->AgregarAlVectorInformaciones(3) ;
		}
 		
		 
		do {
			system("cls") ;
			cout << "\t\bBienvenido Al Laboratorio Budokai Taichi \n\n" ;
			cout << "1. Registrarse. \n" ;
			cout << "2. Ver informacion principal del Laboratorio. \n" ;
			cout << "3. Consultas. \n" ;
			cout << "4. Salir. \n\n " ;
			
			Opcion = common::ValidarEntero("Ingresa una opcion: \n" ) ;
			
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
				
				case 3 : { // Consultas
					MenuConsultas() ;
					break;
				}
				
				case 4 : { // Salir 
					cout << "Gracias Por su Visita \n\n" ;
					*Salir = true ;
					exit(1) ; // sale del ejecutable directamente
					break;
				}
							
				default : { // Opcion Incorrecta
					cout << "\nHas elegido una opcion incorrecta \n" ;
					cout << "Por favor intente de nuevo \n" ;
					system("pause") ;
					break;
				}
			} 
		}while (!*Salir) ;
	}else {
		system("cls") ;
		cout << "\n\t\tHas ingresado datos no validos \n" ;
		cout << "\t\tIntenta de nuevo \n\n" ;
		system("pause") ;
		MenuIngreso() ; 
	}
	
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
		cout << "1. Ingresar como estudiante \n" ;
		cout << "2. Ingresar como profesor \n" ;
		cout << "3. Ingresar como personal administrativo \n" ;
		cout << "4. Funciones relacionadas al manejo de la informacion del Laboratorio \n" ;
		cout << "5. Registrarse con datos ya existentes \n" ; 
		cout << "6. Atras \n\n" ;
		
		this->Opcion = common::ValidarEntero("Ingresa una opcion: \n" ) ;

		int Cantidad = 1 ; // Para referir que solo puede registrarse una persona a la vez
		
		switch (this->Opcion) { // Registrarse como estudiante
			case 1 : {
				bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaEstudiantes(UsoDelLaboratorio->MandarPosicionActual(0)) ;
				}
				break;
			}
			
			case 2 : { // Registrarse como Profesor
				bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaProfesores(UsoDelLaboratorio->MandarPosicionActual(1)) ;
				}
				break;
			}
			
			case 3 : { // Registrarse como Personal Administrativo
				bool Estado = UsoDelLaboratorio->AgregarAlVectorPersonalAdmin(Cantidad) ;
				
				if (Estado == true) {
					*Salir = true ;
					MenuParaPersonalAdmi(UsoDelLaboratorio->MandarPosicionActual(3)) ;
				}
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
				MenuIngreso () ;
				*Salir = true ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tIngresar con Datos Existentes \n\n" ;
		cout << "1. Ingresar con datos de un estudiantes \n" ;
		cout << "2. Ingresar con datos de un profesor \n" ;
		cout << "3. Ingresar con datos de un personal administrativo \n" ;
		cout << "4. Atras \n" ;
		cout << "5. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ; 
		
		switch(this->Opcion) {
			case 1 : { // Ingresar con datos de estudiantes
				if(UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					UsoDelLaboratorio->getEstudiantes() ;
				
					this->Opcion = common::ValidarEntero("\n\nElija con que informacion desea ingresar \n") ; 
				
					MenuParaEstudiantes(this->Opcion) ;	
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}
				break;
			}
			
			case 2 : { // Ingresar con datos de profesores
				if(UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					UsoDelLaboratorio->getProfesores() ;
				
					this->Opcion = common::ValidarEntero("Elija con que informacion desea ingresar \n") ; 
				
					MenuParaProfesores(this->Opcion) ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					RegistroIDPersona() ; 
				}		
				break;
			}
			
			case 3 : { // Ingresar con Datos de Personal Administrativo
				if(UsoDelLaboratorio->VerificarVectorAdmin() == false) {
					UsoDelLaboratorio->getPersonalAdmin() ;
				
					this->Opcion = common::ValidarEntero("Elija con que informacion desea ingresar \n") ; 
				
					MenuParaPersonalAdmi(this->Opcion) ;	
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
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
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tFunciones disponibles para profesores \n\n" ;
		cout << "1. Ver mi informacion disponible \n" ;
		cout << "2. Ver Articulos encargados \n" ;
		cout << "3. Ver todos profesores del Laboratorio \n" ;
		cout << "4. Modificar datos basicos \n" ;
		cout << "5. Atras \n" ;
		cout << "6. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ; 
		
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
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ; // Sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
	this->Opcion = common::ValidarEntero("Elija un Profesor\n") ;
	
	UsoDelLaboratorio->AccederProfesorPosicion(Opcion) ;
	do{
		system("cls") ;
		
		cout << "1. Modificar informacion \t\n" ;
		cout << "2. Eliminar un profesor del sistema \t\n" ;
		cout << "3. Ver datos existentes \t\n" ;
		cout << "4. Ver articulos asignados \t\n" ;
		cout << "5. Atras\n" ;
		cout << "6. Salir \n\n" ;
		
		Eleccion = common::ValidarEntero("Elija una Opcion: \n") ;
		
		
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
				cout << "\nREGRESA PRONTO \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
    	
    	cout << "\n\tFunciones permitidas para articulos de prestamos \n\n" ;
    	cout << "1. Ver todos los articulos prestados\n" ;
    	cout << "2. Ver un articulo en especifico\n" ;
    	cout << "3. Registrar un articulo de prestamo\n" ;
    	cout << "4. Modificar un articulo\n" ;
    	cout << "5. Eliminar un articulo\n" ;
    	cout << "6. Atras \n" ;
    	cout << "7. Salir \n\n" ;
    	
    	this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ;
    	
    	switch(this->Opcion){
    		case 1 :{ // Ver todos los articulos
    			if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
    				system("pause");
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
    			
				break;
			}
			
			case 2 :{ // Ver un articulo en especifico
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
					this->Opcion = common::ValidarEntero("Elija ucual desea ver especificamente? \n") ;					
					
					UsoDelLaboratorio->AccederArticulosPrestamo(Opcion);
					system("pause");
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				
				break;
			}
			
			case 3 :{ // Registrar nuevos articulos de prestamos
				
				cout << "\nPor favor ingrese la cantidad de articulos que desea registrar \n\n" ;
				
				this->Opcion = common::ValidarEntero("Ingrese la cantidad: \n") ;
				
				bool Estado = UsoDelLaboratorio->AgregarAlVectorPrestamo(this->Opcion) ; 
				system("pause") ;
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDePrestamo() ;
				}
				
				break;
			}
			
			case 4 :{  // Modificar 
				
				UsoDelLaboratorio->getPrestamos() ;
				
				this->Opcion = common::ValidarEntero("\nQue articulo desea modificar ? \n") ;
					
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
				cout << "\nREGRESA PRONTO \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default :{ // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\t\tMenu Exclusivo para estudiantes \n\n" ;
		cout << "1. Ver mi informacion personal \n" ;
		cout << "2. Ver estudiantes registrados en el Laboratorio \n" ;
		cout << "3. Ver articulos de prestamo disponibles para prestamos \n" ;
		cout << "4. Ver mis articulos prestados \n" ; 
		cout << "5. Diligenciar prestamos \n" ;
		cout << "6. Diligenciar devolucion \n" ;
		cout << "7. Diligenciar Pago de multa \n" ; 
		cout << "8. Consultar mi estado y valor de multa \n" ;
		cout << "9. Atras \n" ;
		cout << "10. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
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
			
			case 4 : { // Ver mis articulos prestados
				system("cls") ; 
				UsoDelLaboratorio->VerMisPrestados(Posicion) ;
				system("pause") ; 
				break;
			}
			
			case 5 : { //diligenciar prestamos
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					UsoDelLaboratorio->getPrestamos() ;
					
					cout << "\n\tEsta Opcion esclusiva del estudiante perrmite acceder a un prestamo de un articulo \n\n" ;
					this->Opcion = common::ValidarEntero("Por favor seleccione que articulo desea prestar \n") ;
					
					UsoDelLaboratorio->ServicioPrestamo(Posicion, this->Opcion) ;	
				}else {
					cout << "\n\tNo han registrados articulos de tipo prestamo \n" ;
					cout << "Por este motivo seras devuelto al menu principal \n\n" ;
					system("pause") ;
					*Salir = true ; 
					RegistroIDPersona() ; 
				}
				system("pause") ;
				break;
			}
			
			case 6 : { // diligenciar devolucion
				bool Estado ; 
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					
					Estado = UsoDelLaboratorio->ServicioDevolucion(Posicion) ;
					
				}else {
					cout << "\n\tERROR !!! \n" ;
					cout << "\tNo puedes ejecutar la funcion de devolucion por razones de no haber registro de articulos de Prestamo \n\n" ;
				}				
				system("pause") ; 	
				
				if (Estado == true) {
					cout << "\n\tTe redigiriendo al menu anterios para que se conserven los cambios \n\n" ; 
					system("pause") ; 
					*Salir = true ;
					RegistroIDPersona() ; 
				}
				break;
			}
			
			case 7 : { // Diligenciar pago de multa	
				UsoDelLaboratorio->RealizarPagoMulta(Posicion) ; 
				system("pause") ;
				break;
			}
			
			case 8 : { //consultar estado y valor de multa					
				UsoDelLaboratorio->AccederEstadoMultaEstudiante(Posicion) ;
				system("pause") ;
				break;
			}
			
			case 9 : { // Atras
				*Salir = true ;
				RegistroIDPersona () ;
				
				break;
			}
			
			case 10 : { // Salir
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
						
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		Eleccion = common::ValidarEntero("Elija una Opcion: \n") ;
		
		switch(Eleccion){
			case 1 : { // Ver todos los estudiantes
				cout << "Todos los estudiantes registrados son: ";
				UsoDelLaboratorio->getEstudiantes();
				system("pause");
				break;
			}
			
			case 2 : { // Ver un estudiante en especifico 
				UsoDelLaboratorio->getEstudiantes();
				
				this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ; 
				
				cout<< "El estudiante que eligio es:";
				UsoDelLaboratorio->AccederAUnEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 3 : { // Registrar estudiantes
				cout << "Cuantos estudiantes quiere registrar \n";
				this->Opcion = common::ValidarEntero("Elija una Opcion: \n") ;
				
				bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion);
				
				if (Estado == false) {
					*Salir = true ;
					MenuExclusivoEstudiante() ; 
				}
				break;
			}
			
			case 4 : { // Modificar estudiantes
				cout << "Modificacion de estudiante";
				UsoDelLaboratorio->getEstudiantes() ;
				this->Opcion = common::ValidarEntero("Elija el estudiante que desea modificar: ") ;
				UsoDelLaboratorio->ModificarDatosEstudiante(this->Opcion) ;
				system("pause");
				break;
			}
			
			case 5 : { // Eliminar algun estudiante
				UsoDelLaboratorio->AccederAUnEstudiante(this->Opcion);
				
				UsoDelLaboratorio->getEstudiantes() ;
			
				this->Opcion = common::ValidarEntero("Elija el estudiante que desea eliminar: ") ;
				
				UsoDelLaboratorio->EliminarDatosDelVectorEstudiante(this->Opcion);
				system("pause");
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ;
				break;
			}
			
			case 7 : { // Salir
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ; // sale del ejecutable directamente
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tFunciones Disponibles \n\n" ;
		cout << "1. Ver articulos de mueble registrados \n" ;
		cout << "2. Ver un articulo en especifico \n" ; 
		cout << "3. Registrar nuevos articulos de mueble \n" ;
		cout << "4. Modificar articulos de mueble \n" ;
		cout << "5. Eliminar articulos de mueble \n" ;
		cout << "6. Atras \n" ;
		cout << "7. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion \n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
	
					system("pause") ; 
					
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					UsoDelLaboratorio->getMuebles() ;
					
					cout << "\nIngrese el articulo que desea ver su informacion \n\n" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAMueble(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCuantos articulos desea requistar ? \n") ;
					
				bool Estado = UsoDelLaboratorio->AgregarAlVectorMueble(Cantidad) ;
				system("pause") ; 
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDeMueble() ;
				}

				break;
			}
				
			case 4 : { // Modificar Articulos
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false){
					UsoDelLaboratorio->getMuebles() ;
					
					this->Opcion = common::ValidarEntero("\nQue articulo desea modificar ? \n") ;
					
					UsoDelLaboratorio->ModificarDatosMueble(this->Opcion) ;
					 
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
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
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tFunciones Disponibles \n\n" ;
		cout << "1. Ver articulos de computo registrados \n" ;
		cout << "2. Ver un articulo en especifico \n" ; 
		cout << "3. Registrar nuevos articulos de computo \n" ;
		cout << "4. Modificar articulos de computo \n" ;
		cout << "5. Eliminar articulos de computo \n" ;
		cout << "6. Atras \n" ;
		cout << "7. Salir \n\n" ; 
		
		this->Opcion = common::ValidarEntero("Elija una opcion \n") ;
		
		switch(this->Opcion) {
			case 1 : { // Ver articulos registrados
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					UsoDelLaboratorio->getComputo() ;
				
					system("pause") ; 
					
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					 
				}
				break;
			}
			
			case 2 : { // Ver articulo en especifico
				system("cls") ; 
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					cout << "\nIngrese el articulo que desea ver su informacion \n\n" ;
					cin  >> this->Opcion ;
					UsoDelLaboratorio->AccederAComputo(this->Opcion) ;
					
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}  
				
				break;
			}
				
			case 3 : { // Registrar Articulos
				system("cls") ;
				
				Cantidad = common::ValidarEntero("\nCuantos articulos desea requistar ? \n") ;
					
				bool Estado = UsoDelLaboratorio->AgregarAlVectorComputo(Cantidad) ;
				system("pause") ; 
				
				if (Estado == false) {
					*Salir = true ;
					MenuParaArticulosDeComputo() ;
				}
				break;
			}
				
			case 4 : { // Modificar Articulos
				system("cls") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false){
					UsoDelLaboratorio->ModificarDatosDelVectorComputo() ; 
					system("pause") ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
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
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
				}
				break;
			}
			
			case 6 : { // Atras
				*Salir = true ; 
				break;
			}
				
			case 7 : { // Salir
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
				
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tFunciones Disponibles \n\n" ;
		cout << "1. Ver mi informacion disponible \n" ; 
		cout << "2. Funciones: Para Informacion del Laboratorio \n" ;
		cout << "3. Funciones: Para Estudiantes del Laboratorio \n" ;
		cout << "4. Funciones: Para Profesores del Laboratorio \n" ;
		cout << "5. Funciones: Para Articulos de Computo del Laboratorio \n" ;
		cout << "6. Funciones: Para Articulos de Mueble del Laboratorio \n" ;
		cout << "7. Funciones: Para Articulos de Prestamo del Laboratorio \n" ;
		cout << "8. Ir a Menu Principal \n" ;
		cout << "9. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver mi informacion
				
				UsoDelLaboratorio->AccederPersonalAdmi(Posicion) ;
				system("pause") ;
				
				break;
			}
			
			case 2 : { // Funciones para informaciones
				cout << "\nEn Cualquier momento sera dirigido \n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorInformaciones() == false) {
					MenuInformacionLaboratorio() ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					system("pause") ;
					MenuInformacionLaboratorio() ;
				}
				break;
			}
			
			case 3 : { // Menu exclusivo de estudiantes
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorEstudiantes() == false) {
					MenuExclusivoEstudiante() ;
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre Al menos un estudiante \n\n" ;
					system("pause") ;
					system("cls") ;
					
					cout << "\nPor favor registre algun estudiante \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCuantos Estudiantes desea registrar? \n") ;
					
					bool Estado = UsoDelLaboratorio->AgregarAlVectorEstudiantes(this->Opcion) ;
					
					if (Estado == false) {
						*Salir = true ;
						MenuParaPersonalAdmi(Posicion) ;
					}
				}
				break;
			}
			
			case 4 : { //Menu para funciones exclusivas de profesor desde administrador				
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {
					MenuExclusivoProfe();
				}else {
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre Al menos un Profesor \n\n" ;
					system("pause") ;
					system("cls") ;
					
					cout << "\nPor favor registre algun profesor \n\n" ;				
					this->Opcion = common::ValidarEntero("\n\nCuantos Profesores desea registrar? \n") ;
					bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
					
					if (Estado == false) {
						*Salir = true ;
						MenuParaPersonalAdmi(Posicion) ;
					}
				}
				break;
			}
			
			case 5 : { // Funciones para articulos de computo
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosCompu() == false) {
					MenuParaArticulosDeComputo() ;
					
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n\n" ;
					cout << "\nPor favor registre articulos de computo \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorComputo(this->Opcion) ;
						if(Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
						
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}					
				}
				
				break;
			}
			
			case 6 : { // Funciones para articulos de Mueble
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosMueble() == false) {
					MenuParaArticulosDeMueble() ; 
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n" ;
					cout << "Registre articulos de muebles \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorMueble(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false) {
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
					}
				}
				break;
			}
			
			case 7 : { // Funciones para articulos de Prestamo
				cout << "\nEn Cualquier momento sera dirigido \n\n" ;
				system("pause") ;
				
				if (UsoDelLaboratorio->VerificarArticulosPrestamo() == false) {
					MenuParaArticulosDePrestamo() ;
				}else {
					system("cls") ;
					cout << "\nNo existen datos de registro \n" ;
					cout << "Registre articulos de prestamo \n\n" ;
					system("pause") ;
					system("cls") ;
					
					if (UsoDelLaboratorio->VerificarVectorProfesores() == false) {				
						this->Opcion = common::ValidarEntero("\n\nCuantos articulos desea registrar? \n") ;
						
						bool Estado = UsoDelLaboratorio->AgregarAlVectorPrestamo(this->Opcion) ;
						
						if (Estado == false) {
							MenuParaPersonalAdmi(Posicion) ;
						}
					}else {
						cout << "\nPor favor registre al menos un profesor para poder proceder al registro de articulos \n\n" ;				
						this->Opcion = common::ValidarEntero("Cuantos Profesores desea registrar? \n") ;
						bool Estado = UsoDelLaboratorio->AgregarAlVectorProfesores(this->Opcion) ;
						
						if (Estado == false ){
							*Salir = true ;
							MenuParaPersonalAdmi(Posicion) ;
						}
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
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
		
		cout << "\n\tFunciones Disponibles  \n\n" ;
		cout << "1. Ver informacion principal del Laboratorio. \n" ;
		cout << "2. Agregar informacion al Laboratorio. \n" ;
		cout << "3. Modificar informacion al Laboratorio. \n" ;
		cout << "4. Eliminar datos agregados al Laboratorio. \n" ;
		cout << "5. Atras. \n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch (this->Opcion) {
			case 1 : { // Ver toda la informacion del Laboratorio disponible
				UsoDelLaboratorio->getInformaciones() ;
				cout << "\n" ; 
				system("pause") ;
				break;
			}
			
			case 2 : { // Agregar informacion al Laboratorio
				system("cls") ;
				cout << "Ingrese la cantidad de datos que desea agregar \n" ;
				Cantidad = common::ValidarEntero("Digete la cantidad de informacion que desea registrar \n") ;
				
				UsoDelLaboratorio->AgregarAlVectorInformaciones(Cantidad) ; 
				break;
			}
			
			case 3 : { // Modificar datos del Laboratorio
				system("cls") ;
				
				cout << "\nEs hora modificar !!! \n" ;
				system("pause") ;
				UsoDelLaboratorio->ModificarDatosDelVectorInformaciones() ;
				break;
			}
			
			case 4 : { // Eliminar datos del Laboratorio Exclusivo para personal Adiministrativo
				system("cls") ;
				
				cout << "\nA continuacion podras eliminar informacion del Laboratorio \n" ;
				cout << "Solo podras eliminar informacion agregada \n\n" ;
				system("pause") ;
				UsoDelLaboratorio->EliminarDatosDelVectorInformaciones() ;
								
				break;
			}
			
			case 5 : { // Atras 
				*Salir = true ; 
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
				system("pause") ;
				system("cls") ;
				break;
			}
		}
	}while(!*Salir) ;
}

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

void Menu::MenuConsultas() {
	bool* Salir = new bool (false) ;
	
	do {
		system("cls") ;
		
		cout << "\n\tFunciones disponibles para consultas \n\n" ;
		cout << "1. Consultar articulos asigados a un profesor. \n" ;
		cout << "2. Consultar asignacion de articulo. \n" ;
		cout << "3. Consultar historial de prestamo de un articulo. \n" ;
		cout << "4. Consultar historial de prestamo de un estudiante. \n" ;
		cout << "5. Consultar multa y estado de prestamo de un estudiante. \n" ;
		cout << "6. Consultar prestamos realizados en fechas determinadas. \n" ;
		cout << "7. Consultar valor , despreciacion y estado de un articulo. \n" ; 
		cout << "8. Consultar los articulos activos e inactivos. \n" ;
		cout << "9. Atras. \n" ;
		cout << "10. Salir \n\n" ;
		
		this->Opcion = common::ValidarEntero("Elija una opcion\n") ;
		
		switch(this->Opcion) {
			case 1 : { // Consultar Articulos de profesor
				UsoDelLaboratorio->ConsultaProfeArticulos() ;
				system("pause") ; 
				break;
			}
			
			case 2 : { // Consultar asignacion del articulo
				UsoDelLaboratorio->ConsultaAsignacionArt() ; 
				system("pause") ; 
				break;
			}
			
			case 3 : { // Consultar Historial de articulo Prestamo
				system("cls") ;
				UsoDelLaboratorio->MostrarHistorialArticulo() ; 
				system("pause") ; 
				break;
			}
			
			case 4 : { // Consultar Historial de prestamo estudiante
				UsoDelLaboratorio->MostrarHistorialEstudiante() ;
				system("pause") ; 
				break;
			}
			
			case 5 : { // Multa y Estado de estudiante
				UsoDelLaboratorio->ConsultaMultaYEstado() ;
				system("pause") ; 
				break;
			}
			
			case 6 : { // Consultar Prestamos en fechas
				UsoDelLaboratorio->MostrarHistorialConFechas() ;
				system("pause") ;
				break;
			}
			
			case 7 : { // Valor, Despreciacion Y estado de articulo
				UsoDelLaboratorio->ConsultaVDEArticulo() ;
				system("pause") ;
				break;
			}
			
			case 8 : { // Estados de activos o inactivos
				UsoDelLaboratorio->ConsultaActiInac() ;
				system("pause") ; 
				break;
			}
			
			case 9 : { // Atras
				*Salir = true ; 
				break;
			}
			
			case 10 : { // Salir
				cout << "\nEsperamos su regreso \n\n" ;
				system("pause") ;
				exit(1) ;
				break;
			}
			
			default : { // Opcion Incorrecta
				cout << "\nHas elegido una opcion incorrecta \n" ;
				cout << "Por favor intente de nuevo \n" ;
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
