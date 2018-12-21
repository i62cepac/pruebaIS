#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <cstdlib>
#include <list>
#include "Alumno.h"

using namespace std;

class Agenda {
	
	private:

	public:
		
		list<Alumno> Alumnos_;
		
		bool BuscarAlumno(string DNI);
		int BuscarAlumnoAp(string Apellidos);
		bool BuscarAlumnoEm(string Email);
		void AnadirAlumno();
		void ModificarAlumno(string DNI);
		void EliminarAlumno(string DNI);
		void EliminarTodos();
		void MostrarAlumno(string DNI);
		void MostrarTodos();
		void MostrarGrupo(int Grupo);
};

#endif
