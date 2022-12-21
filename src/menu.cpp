// menu.cpp Author: Jesús Núñez de Arenas Llamas
// A menu to inscribe to courses

#include <iostream>
#include <string>
#include "gestion_cursos.h"
#include "inscripcion.h"

void menu_inicio_sesion();
void menu_admin();
void menu_gestor();
void menu_usuario();
void menu_visitante();
void inscripcion();
void gestion();
void visualizar();

/*
Privilegios

	0 = Administrador
	3 = Coordinador
	5 = Participante

*/

int main(){

	menu_inicio_sesion();

}

void menu_inicio_sesion(){
	int op;
	std::cout << "\nIntroduzca el numero de la opción elegida \n\n";
	std::cout << "0. Salir\n";
	std::cout << "1. Iniciar sesion\n";
	std::cout << "2. Entrar como visitante\n";
	std::cout << "3. Crear cuenta de usuario\n";
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
				if(priv == 1){
					std::cout << "Su email o contraseña no son correctos\n";
					count++;
					std::cout << "Le quedan " << 3-count << " intentos\n";
				}else {
					count=3;
				}
			}

			if(priv == 0){
				menu_admin();
			}else if(priv == 3){
				menu_gestor();
			}else if(priv == 5){
				menu_usuario();
			}else if(priv == 1){
				std::cout << "Se ha quedado sin intentos de inicio de sesion, vuelva mas tarde\n";
				exit(EXIT_FAILURE);
			}

		break;
		case 2:
			menu_visitante();
		break;
		case 3:
			std::string nombre;
			int id=0;
			std::string email;
			std::string contraseña;

			std::cout << "Introduzca su nombre\n" << std::endl;
			std::getline(std::cin, nombre);

			while(existe_id(id)){
				std::cout << "Introduzca su id\n" << std::endl;
				std::cin >> id;
				std::cin.ignore();
				if(existe_id(id)){
					std::cout << "Escriba otro id, el id escogido ya esta en uso\n";
				}
			}

			std::cout << "Introduzca su email\n" << std::endl;
			std::getline(std::cin, email);

			std::cout << "Introduzca su contraseña\n" << std::endl;
			std::getline(std::cin, contraseña);

			crear_usuario(nombre, id, email, contraseña, 5);
		break;
	}

}


void menu_admin(){

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

void menu_gestor(){

	int opc=0;

	std::cout << "Introduzca el numero de la opción elegida \n\n";
	std::cout << "1. Gestion de cursos \n";
	std::cout << "2. Visualizar cursos \n";
	std::cout << "3. Salir del programa \n";
	std::cin >> opc;
	std::cin.ignore(1000, '\n');

	while(opc != 3){
		switch(opc){
			case 1:
				gestion();
			break;
			case 2:
				visualizar();
			break;
			case 3:
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
			std::cout << "Escriba el nombre de alguno de los siguientes cursos\n";
			get_lista_cursos();
			std::cout << '\n';
			std::cin >> curso;
			std::cin.ignore();
			if(!existe_curso(curso)){
				std::cout << "El curso introducido no existe";
				exit(EXIT_FAILURE);
			}


			std::list<Usuario> users = cargar_usuarios();
			std::string nombre;
			int id;
			std::string email;
			std::string contraseña;

			for(auto it = users.begin(); it != users.end(); it++){
				if((*it).get_id()==idg){
					nombre = (*it).get_nombre();
					id = (*it).get_id();
					email = (*it).get_email();
					contraseña = (*it).get_contraseña();
				}
			}
			inscribir_alumno(curso, nombre, id, email, contraseña, 5);

			std::cout << "Se ha inscrito al curso seleccionado\n";
		break;

		}
}

void gestion(){

	int opc2=0;
	std::list<Curso> C;
	C = cargar_cursos();

	std::cout << "\n0. Terminar operaciones \n";
	std::cout << "1. Añadir un curso \n";
	std::cout << "2. Borrar un curso \n";
	std::cout << "3. Ver alumnos en un curso\n";
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
		case 3:
			get_lista_users();
			std::cout << '\n';
		break;
	}
}

void visualizar(){

	int opc;
	std::string curso;
	std::list<Curso> C;
	C = cargar_cursos();

	get_lista_cursos();
	std::cout << '\n';
	std::cout << "\n0. Terminar operaciones \n";
	std::cout << "1. Visualizar la descripcion de un curso \n";

	std::cin >> opc;
	std::cin.ignore(1000, '\n');
	switch(opc){

		case 0:
			exit(EXIT_SUCCESS);
		break;

		case 1:
			std::cout << "Escriba el nombre del curso del que desea visualizar la descripcion\n";
			std::getline(std::cin, curso);
			if(!existe_curso(curso)){
				std::cout << "El curso introducido no existe";
				exit(EXIT_FAILURE);
			}
			for (auto it1 = C.begin(); it1 != C.end(); it1++){
				if ((*it1).get_nombre()== curso){
					std::cout << (*it1).get_descripcion() << std::endl;
				}
			}
		break;

	}
}


