// inscripcion.cpp
// Classes and functions for the inscription in courses

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

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
		Usuario();

		inline std::string get_nombre(){return nombre_;}
		inline int get_id(){return id_;}
		inline std::string get_email(){return email_;}
		inline std::string get_contraseña(){return contraseña_;}
};

void inscribir_alumno(std::string curso);

Usuario::Usuario(){
	std::string nombre;
	int id;
	std::string email;
	std::string contraseña;

	std::cout << "Introduzca su nombre" << std::endl;
	std::getline(std::cin, nombre);
	nombre_ = nombre;

	std::cout << "Introduzca su id" << std::endl;
	std::cin >> id;
	std::cin.ignore();
	id_ = id;

	std::cout << "Introduzca su email" << std::endl;
	std::getline(std::cin, email);
	email_ = email;

	std::cout << "Introduzca su contraseña" << std::endl;
	std::getline(std::cin, contraseña);
	contraseña_ = contraseña;
}



class listaUsuario: public Usuario{
	private:
		std::list<Usuario> lista_users_;

	public:
		void get_lista_users();

};


void inscribir_alumno(std::string curso){
	std::string src = "data/";
	std::ofstream curso_e;
	src = src + curso + ".txt";

	Usuario user;

	curso_e.open(src);


	std::string linea;
	int id;

	curso_e << user.get_nombre() << std::endl;

	curso_e << user.get_id() << std::endl;

	curso_e << user.get_email() << std::endl;

	curso_e << user.get_contraseña() << std::endl;

	curso_e.close();


}


void get_lista_users(){

	std::string nombre;

	std::cout << "Introduzca el nombre del curso sustituyendo los espacios por _" << std::endl;
	std::getline(std::cin, nombre);
	std::cin.ignore();

	nombre = "data/" + nombre + ".txt";

	std::ifstream lista;
	lista.open(nombre);

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
