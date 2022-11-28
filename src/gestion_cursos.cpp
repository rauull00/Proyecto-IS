#include <iostream>
#include <fstream>
#include <string>

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
	){};
	inline std::string get_nombre(){return nombre_curso_;}
	inline std::string get_descripcion(){return descripcion;}

};
