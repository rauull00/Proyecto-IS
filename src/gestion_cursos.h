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

	std::ifstream lista("src/data/Lista_cursos.txt");
	std::string linea;

	while( getline(lista, linea) ){ // Coge el nombre del curso
		std::cout << linea;			// Imprime por pantalla el nombre del curso
		getline(lista, linea);	//Linea del id del curso
		getline(lista, linea);	//Linea de la descripcion
	}

	lista.close();
}

void add_curso(){

	std::list<Curso> lcursos;
	lcursos = cargar_cursos();

	std::ofstream lista;
	lista.open("src/data/Lista_cursos.txt");
	std::string nombre;
	std::string descripcion;
	int idc;

	std::cout << "Introduzca el nombre del curso\n";
	std::getline(std::cin, nombre);
	std::cin.ignore();

	std::cout << "Intoduzca el id del curso\n";
	std::cin >> idc;
	std::cin.ignore();

	std::cout << "Intoduzca la nueva descripción\n";
	std::getline(std::cin, descripcion);
	std::cin.ignore();

	Curso c(idc, nombre, descripcion);

	lista << c.get_nombre() << std::endl;
	lista << c.get_idc() << std::endl;
	lista << c.get_descripcion() << std::endl;


	lista.close();
}



void delete_curso(){

	std::list<Curso> lcursos;
	lcursos = cargar_cursos();
	int idc;

	std::cout << "Intoduzca el id del curso a eliminar\n";
	std::cin >> idc;

	for(auto it=lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_idc()==idc){
			lcursos.erase(it);
		}
	}
}

bool set_descripcion(){
	std::string descripcion;
	std::string nombre;
	std::list<Curso> lcursos;
	lcursos = cargar_cursos();

	std::cout << "Introduzca el nombre del curso\n";
	std::getline(std::cin, nombre);
	std::cin.ignore();

	std::cout << "Intoduzca la nueva descripción\n";
	std::getline(std::cin, descripcion);
	std::cin.ignore();

	for(auto it=lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_nombre()== nombre){
			(*it).set_description(descripcion);
			return true;
		}
	}

	return false;

}

std::list<Curso> cargar_cursos(){

	std::list<Curso> listac;
	std::string linea1;
	int linea1a;
	std::string linea2;
	std::string linea3;

	std::ifstream lista("src/data/Lista_cursos.txt");
	while(getline(lista, linea1)){
		linea1a = stoi(linea1);
		getline(lista, linea2);
		getline(lista, linea3);
		Curso c(linea1a, linea2, linea3);
		listac.push_back(c);
	}

	return listac;
}

#endif
