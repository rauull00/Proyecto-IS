// inscripcion.cpp
// Classes and functions for the inscription in courses

#ifndef INSCRIPCION_CPP
#define INSCRIPCION_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <list>

class Usuario{
	private:
		std::string nombre_;
		int id_;
		std::string email_;
		std::string contraseña_;

	public:
		Usuario(
				std::string nombre;
				int id;
				std::string email;
				std::string contraseña;
		){}
		void inscribir_alumno(std::string curso);

};

class listaUsuario: public Usuario{
	private:
		std::list<Usuario> lista_users_;

	public:
		void get_lista_users();

};

void inscribir_alumno(std::string curso){
	std::string src = "src/data/";
	ofstream curso_e;
	src = src + curso + ".txt";
	curso_e.open(src);
	std::string linea;
	int id;

	std::cout << "Introduzca su nombre" << endl;
	std::cin >> linea;
	curso_e << linea << endl;

	std::cout << "Introduzca su id" << endl;
	std::cin >> linea;
	curso_e << id << endl;

	std::cout << "Introduzca su email" << endl;
	std::cin >> linea;
	curso_e << linea << endl;

	std::cout << "Introduzca su contraseña" << endl;
	std::cin >> linea;
	curso_e << linea << endl;
}


void get_lista_users(){

	std::string nombre;
	std::string src = "src/data/";

	std::cout << "Introduzca el nombre del curso sustituyendo los espacios por _" << endl;
	std::cin >> nombre;
	std::cin.ignore();

	src = src + nombre + ".txt";

	ifstream lista(src);
	std::string linea;

	while( getline(lista, linea) ){ //Coge la linea del nombre
		std::cout << linea;			// Imprime por pantalla el nombre de los usuarios
		getline(lista, linea); //Linea del id
		getline(lista, linea); //Linea del email
		getline(lista, linea); //Linea de la contraseña
	}

	lista.close();
}

#endif
