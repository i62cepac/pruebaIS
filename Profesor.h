#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include "Agenda.h"
#include "Alumno.h"

using namespace std;

class Profesor{

	private:
		
		string ID_, Password_;
		int Rol_;
		Agenda *Ptr_Agenda_;

	public:

		list<Profesor> Profesores_;
		
		void CargarCopia(Agenda *Ptr_Agenda_);
		void GuardarCopia(Agenda *Ptr_Agenda_);
		void CargarBD(Agenda *Ptr_Agenda_);
		void GuardarBD(Agenda *Ptr_Agenda_);

//------OBSERVADORES----

		inline string getID() const
		{
			return ID_;
		}
		
		inline string getPassword() const
		{
			return Password_;
		}

		inline int getRol() const
		{
			return Rol_;
		}

//--------MODIFICADORES------

		inline void setID(string ID)
		{
			ID_=ID;
		}
		
		inline void setPassword(string Password)
		{
			Password_=Password;
		}

		inline void setRol(int Rol)
		{
			Rol_=Rol;
		}

};

#endif
