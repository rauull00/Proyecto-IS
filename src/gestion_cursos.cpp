// gestion_cursos.cpp: Author: Jesús Núñez de Arenas Llamas
// Classes and functions for the management of courses

#ifndef GESTION_CURSOS_CPP
#define GESTION_CURSOS_CPP

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#define MAX_LINEA 256


class Curso {

	private:
	int idc_;
	std::string nombre_curso_;
	std::string descripcion_curso_;

	public:
	Curso(
		int idc;
		std::string nombre_curso;
		std::string descripcion_curso= "empty";

	){}

	inline int get_idc(){return idc_;}
	inline std::string get_nombre(){return nombre_curso_;}
	inline std::string get_descripcion(){return descripcion_curso_;}
	inline void set_description(std::string descripcion){descripcion_curso_ = descripcion;}

};

/*
	Se necesita crear una funcion para borrar los cursos de los ficheros
*/

class listaCursos: public Curso {
	private:
	std::list<Curso> lcursos_;

	public:


	void get_lista_cursos();
	void add_curso();
	bool delete_curso();
	bool set_descripcion();

};


void get_lista_cursos(){



	ifstream lista("src/data/Lista_cursos.txt");
	std::string linea;

	while( getline(lista, linea) ){ // Coge el nombre del curso
		cout << linea;			// Imprime por pantalla el nombre del curso
		getline(lista, linea);	//Linea del id del curso
		getline(lista, linea);	//Linea de la descripcion
	}

	lista.close();
}

void add_curso(){

	ofstream lista;
	lista.open("src/data/Lista_cursos.txt");
	std::string nombre;
	int idc;

	std::cout << "Introduzca el nombre del curso\n";
	std::cin >> nombre;
	std::cin.ignore();

	std::cout << "Intoduzca el id del curso\n";
	std::cin >> idc;
	std::cin.ignore();

	Curso c(idc, nombre);

	lista << c.get_nombre() << endl;
	lista << c.get_idc() << endl;
	lista << c.get_descripcion() << endl;

	lcursos.push_back(c);
	lista.close();

}



bool delete_curso(){

	int idc;

	std::cout << "Intoduzca el id del curso a eliminar\n";
	std::cin >> idc;

	for(auto it=lcursos.begin(); it != lcursos.end(); it++){
		if((*it).get_idc()==idc){
			lcursos.erase(it);
			return true;
		}
	}
	return false;
}

bool set_descripcion(){
	std::string descripcion;
	std::string nombre;

	std::cout << "Introduzca el nombre del curso\n";
	std::cin.getline(nombre, MAX_LINEA);
	std::cin >> nombre;
	std::cin.ignore();

	std::cout << "Intoduzca la nueva descripción\n";
	std::cin.getline(nombre, MAX_LINEA);
	std::cin >> descripcion;
	std::cin.ignore();

	for(auto it=lcursos_.begin(); it != lcursos_.end(); it++){
		if((*it).get_nombre()== nombre){
			(*it).set_description(descripcion);
			return true;
		}
	}

	return false;

}


#endif
