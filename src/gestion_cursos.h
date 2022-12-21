// gestion_cursos.cpp: Author: Jesús Núñez de Arenas Llamas
// Classes and functions for the management of courses

#ifndef GESTION_CURSOS_H
#define GESTION_CURSOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#define MAX_LINEA 256

void get_lista_cursos();
void add_curso();
void delete_curso();

class Curso{

	private:
	int idc_;
	std::string nombre_curso_;
	std::string descripcion_curso_;

	public:
	Curso(int idc, std::string nombre_curso, std::string descripcion_curso);

	inline int get_idc(){return idc_;}
	inline std::string get_nombre(){return nombre_curso_;}
	inline void set_nombre(std::string nombre){nombre_curso_ = nombre;}
	inline std::string get_descripcion(){return descripcion_curso_;}
	inline void set_description(std::string descripcion){descripcion_curso_ = descripcion;}

	bool set_descripcion();

};

std::list<Curso> cargar_cursos();

/*
	Se necesita crear una funcion para borrar los cursos de los ficheros
*/
Curso::Curso(int idc, std::string nombre_curso, std::string descripcion_curso){
	idc_ = idc;
	nombre_curso_ = nombre_curso;
	descripcion_curso_ = descripcion_curso;
}


void get_lista_cursos(){

	std::ifstream lista;
	lista.open("data/Lista_cursos.txt");
	std::string linea;

	while( getline(lista, linea) ){ // Coge el nombre del curso
		std::cout << linea;			// Imprime por pantalla el nombre del curso
		getline(lista, linea);	//Linea del id del curso
		getline(lista, linea);	//Linea de la descripcion
	}

	lista.close();
}

void add_curso(){


	std::ofstream lista("data/Lista_cursos.txt", std::ios::app);

	std::string linea;
	std::string nombre;
	std::string descripcion;
	int idc;

	std::cout << "Introduzca el nombre del curso\n";
	std::getline(std::cin, nombre);


	std::cout << "Introduzca el id del curso\n";
	std::cin >> idc;
	std::cin.ignore(100, '\n');

	std::cout << "Introduzca la nueva descripción\n";
	std::getline(std::cin, descripcion);

	Curso c(idc, nombre, descripcion);

	lista << c.get_idc() << std::endl;
	lista << c.get_nombre() << std::endl;

	lista << c.get_descripcion() << std::endl;


	lista.close();
}



void delete_curso(){

	std::list<Curso> lcursos;
	lcursos = cargar_cursos();
	int idc;

	std::cout << "Intoduzca el id del curso a eliminar\n";
	std::cin >> idc;
	std::cin.ignore(100, '\n');

	for(auto it=lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_idc() == idc){
			(*it).set_nombre("-1");
		}
	}
	std::ofstream lista2;
	lista2.open("data/Lista_cursos_aux.txt");
	for (auto it= lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_nombre() != "-1"){
			lista2 << (*it).get_nombre() << std::endl;
			lista2 << (*it).get_idc() << std::endl;
			lista2 << (*it).get_descripcion() << std::endl;
		}
	}
	lista2.close();

	remove("data/Lista_cursos.txt");
	rename("data/Lista_cursos_aux.txt", "data/Lista_cursos.txt");

}

bool set_descripcion(){
	std::string descripcion;
	std::string nombre;
	std::list<Curso> lcursos;
	lcursos = cargar_cursos();

	std::cout << "Introduzca el nombre del curso\n";
	std::getline(std::cin, nombre);


	std::cout << "Intoduzca la nueva descripción\n";
	std::getline(std::cin, descripcion);


	for(auto it=lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_nombre()== nombre){
			(*it).set_description(descripcion);

			std::ofstream lista2;
			lista2.open("data/Lista_cursos_aux.txt");
			for (auto it1= lcursos.begin(); it1 != lcursos.end(); it1++){

				lista2 << (*it1).get_idc() << std::endl;
				lista2 << (*it1).get_nombre() << std::endl;
				lista2 << (*it1).get_descripcion() << std::endl;

			}
			lista2.close();

			remove("data/Lista_cursos.txt");
			rename("data/Lista_cursos_aux.txt", "data/Lista_cursos.txt");

			return true;
		}
	}

	return false;

}

std::list<Curso> cargar_cursos(){

	std::list<Curso> listac;
	std::string id;
	int id1;
	std::string nombre;
	std::string descripcion;

	std::ifstream lista;
	lista.open("data/Lista_cursos.txt");


	while(!lista.eof()){
		getline(lista, nombre);
		getline(lista, id);
		id1 = stoi(id);
		getline(lista, descripcion);
		Curso c(id1, nombre, descripcion);
		listac.push_back(c);
	}

	return listac;
}

#endif
