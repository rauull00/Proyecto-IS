// menu.cpp Author: Jesús Núñez de Arenas Llamas
// A menu to inscribe to courses

#include <iostream>
#include <string>
#include "gestion_cursos.h"
#include "inscripcion.h"

void menu_inicio_sesion();
void menu_general();
void menu_usuario();
void menu_visitante();
void inscripcion();
void gestion();
void visualizar();
bool existe_curso(std::string curso);

/*
Privilegios

	0 = Administrador
	1 = Gestor de curso
	2 = Participante

*/

int main(){

	menu_inicio_sesion();

}

void menu_inicio_sesion(){
	int op;
	std::cout << "\nIntroduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir";
	std::cout << "1. Iniciar sesion\n";
	std::cout << "2. Entrar como visitante\n";
	std::cin >> op;
	std::cin.ignore(1000, '\n');

	std::string email;
	std::string contraseña;
	int priv;
	int count = 0;

	switch(op){
		case 0:
			exit(EXIT_SUCCESS);
		break;
		case 1:

			while(count < 3){
				std::cout << "\nEscriba su email\n";
				std::getline(std::cin, email);
				std::cout << "Escriba su contraseña\n";
				std::getline(std::cin, contraseña);
				priv = inicio_sesion(email, contraseña);
				if(priv > -1){
				count=3;
				}else {
					std::cout << "Su email o contraseña no son correctos\n";
					count++;
				}
			}

			if(priv == 0){
				menu_general();
			}else if(priv == 1){
				menu_general();
			}else if(priv == 2){
				menu_usuario();
			}else if(priv == -1){
				std::cout << "Se ha quedado sin intentos de inicio de sesion, vuelva mas tarde\n";
				exit(EXIT_FAILURE);
			}

		break;
		case 2:
			menu_visitante();
		break;
	}

}


void menu_general(){

	int opc=0;

	std::cout << "Introduzca el numero de la opción elegida \n\n";
	std::cout << "1. Inscribirse en un curso \n";
	std::cout << "2. Gestion de cursos \n";
	std::cout << "3. Visualizar cursos \n";
	std::cout << "4. Salir del programa \n";
	std::cin >> opc;
	std::cin.ignore(1000, '\n');

	while(opc != 4){
		switch(opc){
			case 1:
				inscripcion();
			break;
			case 2:
				gestion();
			break;
			case 3:
				visualizar();
			break;
			case 4:
				exit(EXIT_SUCCESS);
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
			if(!existe_curso(curso)){
				std::cout << "El curso introducido no existe";
				exit(EXIT_FAILURE);
			}

			std::string nombre;
			int id;
			std::string email;
			std::string contraseña;

			std::cout << "Introduzca su nombre" << std::endl;
			std::getline(std::cin, nombre);

			std::cout << "Introduzca su id" << std::endl;
			std::cin >> id;
			std::cin.ignore();

			std::cout << "Introduzca su email" << std::endl;
			std::getline(std::cin, email);

			std::cout << "Introduzca su contraseña" << std::endl;
			std::getline(std::cin, contraseña);

			inscribir_alumno(curso, nombre, id, email, contraseña, 2);
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
			std::cin.ignore(1000, '\n');
			if(!existe_curso(curso)){
				std::cout << "El curso introducido no existe";
				exit(EXIT_FAILURE);
			}
			for (auto it1 = C.begin(); it1 != C.end(); it1++){
				if ((*it1).get_nombre()== curso){
					(*it1).get_descripcion();
				}
			}
		break;

	}
}

bool existe_curso(std::string curso){
	std::list<Curso> listac = cargar_cursos();
	for(auto it = listac.begin(); it != listac.end(); it++){
		if((*it).get_nombre() == curso){
			return true;
		}
	}
	return false;
}
