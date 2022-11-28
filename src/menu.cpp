#include <iostream>
#include <string>
#include "gestion_cursos.cpp"

void inscripcion();
void gestion();
void visualizar();

int main(){
	int opc=0;
	std::cout <<"Introduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir del programa \n";
	std::cout << "1. Inscribirse en un curso \n";
	std::cout << "2. Gestion de cursos \n";
	std::cout << "3. Visualizar cursos \n";
	std::cin >> opc;
	switch(opc){
		case 0:
			exit(EXIT_SUCCESS);
		break;
		case 1:
			inscripcion();
		break;
		case 2:
			gestion();
		break;
		case 3:
			visualizar();
		break;
	}
}

void inscripcion(){
	int opc1=0;
	std::cout << "0. Volver al menu principal \n";


	std::cin >> opc1;
	switch(opc2){
		case 0:
			exit(EXIT_SUCCESS);
		break;

		}
}

void gestion(){
	int opc2=0;
	std::cout << "0. Volver al menu principal \n";
	std::cout << "1. Añadir un curso \n";
	std::cout << "2. Borrar un curso \n";
	std::cout << "3. Cambiar descripción de un curso \n";
	std::cin >> opc2;
	switch(opc2){
	case 0:
		exit(EXIT_SUCCESS);
	break;
	case 1:
		if(add_curso()) std::cout << "Se ha añadido el curso correctamente";
		else std::cout << "No se ha podido añadir el curso";
	break;
	case 2:
		if(delete_curso()) std::cout << "Se ha borrado el curso correctamente";
		else std::cout << "No se ha podido borrar el curso";
	break;
	case 3:
		set_descripcion();
	break;
	}
}

void visualizar(){

}

