#include <iostream>
#include <string>
#include "gestion_cursos.cpp"

void menu_admin();
void menu_usuario();
void menu_visitante();
void inscripcion();
void gestion();
void visualizar();

int main(){

	menu_admin();

}

void menu_admin(){

	int opc=0;

	std::cout <<"Introduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir del programa \n";
	std::cout << "1. Inscribirse en un curso \n";
	std::cout << "2. Gestion de cursos \n";
	std::cout << "3. Visualizar cursos \n";
	std::cin >> opc;
	while(opc != 0){
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
}

void menu_usuario(){

	int opc=0;

	std::cout <<"Introduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir del programa \n";
	std::cout << "1. Inscribirse en un curso \n";
	std::cout << "2. Visualizar cursos \n";
	std::cin >> opc;
	while(opc != 0){
		switch(opc){
			case 0:
				exit(EXIT_SUCCESS);
				break;
			case 1:
				inscripcion();
				break;
			case 2:
				visualizar();
				break;
		}
	}
}

void menu_visitante(){

	int opc=0;

	std::cout <<"Introduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir del programa \n";
	std::cout << "1. Visualizar cursos \n";
	std::cin >> opc;
	while(opc != 0){
		switch(opc){
			case 0:
				exit(EXIT_SUCCESS);
				break;
			case 1:
				visualizar();
				break;
		}
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
	listaCursos C();
	switch(opc2){
	case 0:
		exit(EXIT_SUCCESS);
	break;
	case 1:
		if(C.add_curso()) std::cout << "Se ha añadido el curso correctamente";
		else std::cout << "No se ha podido añadir el curso";
	break;
	case 2:
		if(C.delete_curso()) std::cout << "Se ha borrado el curso correctamente";
		else std::cout << "No se ha podido borrar el curso";
	break;
	case 3:
		C.set_descripcion();
	break;
	}
}

void visualizar(){

	listaCursos C();
	int opc;
	std::string curso;

	C.get_lista_cursos();
	for (auto it = C.begin(); it =! C.end(); it++){
		std::cout << (*it).get_nombre();
	}
	std::cout << "0. Volver al menu principal \n";
	std::cout << "1. Visualizar la descripcion de un curso \n";
	cin >> opc;
	switch(opc){
		case 0:
			exit(EXIT_SUCCESS);
		break;
		case 1:
			cout << "Escriba el nombre del curso del que desea visualizar la descripcion";
			cin >> curso;
			for (auto it1 = C.begin(); it1 != C.end(); it1++){
				if ((*it1).get_nombre()== curso){
					(*it1).get_descripcion();
				}
			}
		break;
	}
}

