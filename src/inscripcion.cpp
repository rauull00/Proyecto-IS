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

};

class listaUsuario: public Usuario{
	private:
		std::list<Usuario> lista_users_;

	public:
		void get_lista_users();

};

void get_lista_users(){

	std::string nombre;
	std::string src = "src/data/";

	std::cout << "Introduzca el nombre del curso sustituyendo los espacios por _" << endl;
	std::cin >> nombre;
	std::cin.ignore();

	src = src + nombre;

	ifstream lista(src);
	std::string linea;

	while( getline(lista, linea) ){ //Coge la linea del nombre
		cout << linea;			// Imprime por pantalla el nombre de los usuarios
		getline(lista, linea); //Linea del id
		getline(lista, linea); //Linea del email
		getline(lista, linea); //Linea de la contraseña
	}

	lista.close();
}

#endif
