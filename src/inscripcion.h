// inscripcion.cpp Author: Jesús Núñez de Arenas Llamas
// Classes and functions for the inscription in courses

#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "gestion_cursos.h"

int inicio_sesion(std::string email,  std::string contraseña);
void get_lista_users();
bool existe_curso(std::string curso);
bool existe_id(int id);
void crear_usuario(std::string nombre, int id, std::string email, std::string contraseña, int privilegio);
bool esta_inscrito(std::string src, int id);
int idg = 2;

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
std::list<Usuario> cargar_usuarios();

Usuario::Usuario(std::string nombre, int id, std::string email, std::string contraseña, int privilegio){
	nombre_ = nombre;
	id_ = id;
	email_ = email;
	contraseña_ = contraseña;
	privilegio_ = privilegio;
}


void inscribir_alumno(std::string curso, std::string nombre, int id, std::string email, std::string contraseña, int privilegio){

	std::string linea;
	int id1;
	std::string src = "data/";
	src = src + curso + ".txt";

	if(esta_inscrito(src, id)){
		exit(EXIT_FAILURE);
	}

	std::ofstream curso_e;
	curso_e.open(src, std::ios::app);

	curso_e << nombre << std::endl;
	curso_e << id << std::endl;
	curso_e << email << std::endl;
	curso_e << contraseña << '\n';


	curso_e.close();


}


void get_lista_users(){

	std::string nombre;

	std::cout << "Introduzca el nombre del curso" << std::endl;
	get_lista_cursos();
	std::cout << '\n';
	std::getline(std::cin, nombre);
	if(!existe_curso(nombre)){
		std::cout << "El curso introducido no existe";
	exit(EXIT_FAILURE);
	}

	nombre = "data/" + nombre + ".txt";

	std::ifstream lista;
	lista.open(nombre);

	std::string linea;

	while( getline(lista, linea) ){ //Coge la linea del nombre
		std::cout << linea;			// Imprime por pantalla el nombre de los usuarios
		std::cout << '\n';
		getline(lista, linea); //Linea del id
		getline(lista, linea); //Linea del email
		getline(lista, linea); //Linea de la contraseña
	}

	lista.close();

}

int inicio_sesion(std::string email,  std::string contraseña){

	std::string nombre;
	std::string id;
	int id1;
	std::string privilegio;
	int send_privilegio = 1;
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

		if((email == email1) && (contraseña == contraseña1)){
			send_privilegio = stoi(privilegio);
			id1 = stoi(id);
			if(send_privilegio == 5){
				idg = id1;
			}
			return (send_privilegio);
		}
	}
	return 1;
}

std::list<Usuario> cargar_usuarios(){

	std::ifstream lista;
	lista.open("data/Inicio_sesion.txt");

	std::list<Usuario> users;
	std::string nombre;
	std::string id;
	int id1;
	std::string privilegio;
	int privilegio1;
	std::string email;
	std::string contraseña;

	while(!lista.eof()){
		getline(lista, nombre);
		getline(lista, id);
		id1 = stoi(id);
		getline(lista, privilegio);
		privilegio1 = stoi(privilegio);
		getline(lista, email);
		getline(lista, contraseña);
		Usuario user(nombre, id1, email, contraseña, privilegio1);
		users.push_back(user);
	}
	lista.close();

	return users;
}

void crear_usuario(std::string nombre, int id, std::string email, std::string contraseña, int privilegio){

	std::ofstream ini_sesion;
	ini_sesion.open("data/Inicio_sesion.txt", std::ios::app);

	ini_sesion << nombre << std::endl;
	ini_sesion << id << std::endl;
	ini_sesion << privilegio << std::endl;
	ini_sesion << email << std::endl;
	ini_sesion << contraseña << '\n';

	ini_sesion.close();
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

bool existe_id(int id){
	std::list<Usuario> listac = cargar_usuarios();
	for(auto it = listac.begin(); it != listac.end(); it++){
		if((*it).get_id() == id){
			return true;
		}
	}
	return false;
}

bool esta_inscrito(std::string src, int id){

	std::string linea;
	int id1;
	std::ifstream curso_e(src);
	while(getline(curso_e, linea)){
		getline(curso_e, linea);
		id1 = stoi(linea);
		if (id1 == id){
			std::cout << "Ya esta inscrito a este curso\n";
			return true;
		}
		getline(curso_e, linea);
		getline(curso_e, linea);
	}
	curso_e.close();
	return false;

}

#endif
