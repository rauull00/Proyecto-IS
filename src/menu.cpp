// menu.cpp Author: Jesús Núñez de Arenas Llamas
// A menu to inscribe to courses

#include <iostream>
#include <string>
#include "gestion_cursos.h"
#include "inscripcion.h"

void menu_general();
void menu_usuario();
void menu_visitante();
void inscripcion();
void gestion();
void visualizar();

int main(){

	menu_general();

}

void menu_general(){

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
/*
void menu_usuario(){

	int opc=0;

	std::cout <<"Introduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir del programa \n";
	std::cout << "1. Inscribirse en un curso \n";
	std::cout << "2. Visualizar cursos \n";
	std::cin >> opc;
	std::cin.ignore(1000, '\n');

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
	std::cout << "";
	std::cin >> opc;
	std::cin.ignore(1000, '\n');
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

*/
void inscripcion(){

	int opc1=0;

	std::cout << "0. Terminar operaciones \n";
	std::cout << "1. Comenzar la inscripcion \n";

	std::cin >> opc1;
	std::cin.ignore(1000, '\n');
	switch(opc1){

		case 0:
			exit(EXIT_SUCCESS);
		break;

		case 1:
			std::string curso;
			std::cout << "Escriba el nombre de alguno de los siguientes cursos cambiando los espacios por _ \n";
			get_lista_cursos();
			std::cin >> curso;
			std::cin.ignore();
			inscribir_alumno(curso);
		break;

		}
}

void gestion(){

	int opc2=0;

	std::cout << "0. Terminar operaciones \n";
	std::cout << "1. Añadir un curso \n";
	std::cout << "2. Borrar un curso \n";
	std::cin >> opc2;
	std::cin.ignore(1000, '\n');

	switch(opc2){

		case 0:
			exit(EXIT_SUCCESS);
			break;

		case 1:
			add_curso();
			std::cout << "Se ha añadido el curso \n\n";
			break;

		case 2:
			delete_curso();
			std::cout << "Se ha borrado el curso \n\n";
		break;

	}
}

void visualizar(){

	int opc;
	std::string curso;
	std::list<Curso> C;
	C = cargar_cursos();

	get_lista_cursos();

	std::cout << "0. Terminar operaciones \n";
	std::cout << "1. Visualizar la descripcion de un curso \n";

	std::cin >> opc;
	std::cin.ignore(1000, '\n');
	switch(opc){

		case 0:
			exit(EXIT_SUCCESS);
		break;

		case 1:
			std::cout << "Escriba el nombre del curso del que desea visualizar la descripcion sustituyendo los espacios por _\n";
			std::cin >> curso;
			for (auto it1 = C.begin(); it1 != C.end(); it1++){
				if ((*it1).get_nombre()== curso){
					(*it1).get_descripcion();
				}
			}
		break;

	}
}

