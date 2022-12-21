// inscripcion.cpp Author: Jesús Núñez de Arenas Llamas
// Classes and functions for the inscription in courses

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

bool inicio_sesion(std::string email,  std::string contraseña);

class Usuario{
	private:
		std::string nombre_;
		int id_;
		std::string email_;
		std::string contraseña_;
		int privilegio_;

	public:
		Usuario(std::string nombre, int id, std::string email, std::string contraseña, int privilegio);

		inline std::string get_nombre(){return nombre_;}
		inline int get_id(){return id_;}
		inline std::string get_email(){return email_;}
		inline std::string get_contraseña(){return contraseña_;}

};

void inscribir_alumno(std::string curso);

Usuario::Usuario(std::string nombre, int id, std::string email, std::string contraseña, int privilegio){
	nombre_ = nombre;
	id_ = id;
	email_ = email;
	contraseña_ = contraseña;
	privilegio_ = privilegio;
}



class listaUsuario: public Usuario{
	private:
		std::list<Usuario> lista_users_;

	public:
		void get_lista_users();

};


void inscribir_alumno(std::string curso, std::string nombre, int id, std::string email, std::string contraseña, int privilegio){
	std::string src = "data/";
	std::ofstream curso_e;
	src = src + curso + ".txt";

	std::ofstream ini_sesion;

	ini_sesion.open("data/Inicio_sesion.txt", std::ios::app);
	curso_e.open(src, std::ios::app);



	curso_e << nombre << std::endl;
	ini_sesion << nombre << std::endl;
	ini_sesion << privilegio << std::endl;

	curso_e << id << std::endl;
	ini_sesion << id << std::endl;

	curso_e << email << std::endl;
	ini_sesion << email << std::endl;

	curso_e << contraseña << std::endl;
	ini_sesion << contraseña << std::endl;

	curso_e.close();
	ini_sesion.close();

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

bool inicio_sesion(std::string email,  std::string contraseña){

	std::string nombre;
	std::string id;
	std::string privilegio;
	int send_privilegio;
	std::string email1;
	std::string contraseña1;

	std::ifstream lista;
	lista.open("data/Inicio_sesion.txt");


	while(!lista.eof()){
		getline(lista, nombre);
		getline(lista, id);
		getline(lista, privilegio);
		getline(lista, email1);
		getline(lista, contraseña1);
		if((email1 == email) && (contraseña1 == contraseña)){
			send_privilegio = stoi(privilegio);
			return send_privilegio;
		}
	}
	return -1;
}

#endif
