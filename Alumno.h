#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Alumno{
	
	private:
		string DNI_,Nombre_,Apellidos_,Email_,Direccion_;
		int Telefono_,CursoAlto_,Grupo_;
		bool Lider_;
		float Nota_;

	public:	

		Alumno(string DNI, string Nombre,string Apellidos, string Email, string Direccion, int Telefono,
		int CursoAlto, int Grupo,bool Lider, float Nota);
		
		Alumno(){};

		

//----OBSERVADORES-----

		inline string getDNI() const
		{
			return DNI_;
		}

		inline string getNombre() const
		{
			return Nombre_;
		}

		inline string getApellidos() const
		{
			return Apellidos_;
		}

		inline string getEmail() const
		{
			return Email_;
		}

		inline string getDireccion() const
		{
			return Direccion_;
		}

		inline int getTelefono() const
		{
			return Telefono_;
		}

		inline int getCursoAlto() const
		{
			return CursoAlto_;
		}

		inline int getGrupo() const
		{
			return Grupo_;
		}

		inline bool getLider() const
		{
			return Lider_;
		}

		inline float getNota() const
		{
			return Nota_;
		}

//------MODIFICADORES-----

		inline void setDNI(string DNI)
		{
			DNI_=DNI;
		}
		inline void setNombre(string Nombre)
		{
			Nombre_=Nombre;
		}
		inline void setApellidos(string Apellidos)
		{
			Apellidos_=Apellidos;
		}
		inline void setEmail(string Email)
		{
			Email_=Email;
		}
		inline void setDireccion(string Direccion)
		{
			Direccion_=Direccion;
		}
		inline void setTelefono(int Telefono)
		{
			Telefono_=Telefono;
		}
		inline void setCursoAlto(int CursoAlto)
		{
			CursoAlto_=CursoAlto;
		}
		inline void setGrupo(int Grupo)
		{
			Grupo_=Grupo;
		}
		inline void setLider(bool Lider)
		{
			Lider_=Lider;
		}
		inline void setNota(float Nota)
		{
			Nota_=Nota;
		}

};

#endif
