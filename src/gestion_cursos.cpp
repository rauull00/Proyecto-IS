// gestion_cursos.cpp: Author: Jesús Núñez de Arenas Llamas
// Classes for the management of courses

#ifndef GESTION_CURSOS_CPP
#define GESTION_CURSOS_CPP

#include <iostream>
#include <fstream>
#include <string>

#define MAX_LINEA 256

void get_lista_cursos();
bool add_curso();
bool delete_curso();
bool set_descripcion();

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
	inline std::string get_descripcion(){return descripcion;}

};

class listaCursos: public Curso {
	private:
	std::list<Curso> lcursos_;

	public:
	void get_lista_cursos();
	bool add_curso();
	bool delete_curso();
	bool set_descripcion();
};


void get_lista_cursos(){
	FILE *f;
	f=fopen("Lista_cursos.txt", r);
	std::string linea;
	for((fgets(linea, MAX_LINEA, f))!= NULL){
		cout << linea;
	}
}

bool add_curso(){
	std::string nombre;
	int idc;
	std::cout << "Introduzca el nombre del curso\n";
	std::cin >> nombre;
	std::cout << "Intoduzca el id del curso\n";
	std::cin >> idc;

	Curso c(idc, nombre);
	lcursos.push_back(c);
	return true;
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
	std::cin >> nombre;
	std::cout << "Intoduzca la nueva descripción\n";
	std::cin >> descripcion;
	for(auto it=lcursos_.begin(); it != lcursos_.end(); it++){
		if((*it).get_nombre()==nombre){
			(*it)->descripcion_curso_ = descripcion;
			return true;
		}
	}
	return false;

}

#endif
