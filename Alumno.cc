#include "Alumno.h"

using namespace std;

Alumno::Alumno(string DNI, string Nombre,string Apellidos, string Email, string Direccion, int Telefono,
 int CursoAlto, int Grupo, bool Lider=false, float Nota=0)
{
	DNI_=DNI;
	Nombre_=Nombre;
	Apellidos_=Apellidos;
	Email_=Email;
	Direccion_=Direccion;
	Telefono_=Telefono;
	CursoAlto_=CursoAlto;
	Grupo_=Grupo;
	Lider_=Lider;
	Nota_=Nota;
}