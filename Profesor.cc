#include "Profesor.h"

using namespace std;

typedef struct alumno{
	
	char DNI[20], Nombre[20], Apellidos[50], Email[20], Direccion[50];
	int Telefono, CursoAlto, Grupo;
	bool Lider;
	float Nota;
	
}alu;

void Profesor::CargarCopia(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	char nombreFichero[20];
	alu al;
	Alumno a;
	Agenda agenda;
	
	cout<<"Introduzca el nombre del fichero que quiere cargar: ";
	cin>>nombreFichero;
	strcat(nombreFichero, ".bin");
	
	fichero.open(nombreFichero, ios::in | ios::binary);
	
	if(fichero.is_open()){
		
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(al)!=0){
			
			fichero.seekg((0)*sizeof(al), ios::beg);
			
			Ptr_Agenda_->Alumnos_.clear();
			
			while(!fichero.eof() && fichero.read((char *)&al, sizeof(al))){
				
				a.setDNI(al.DNI);
				a.setNombre(al.Nombre);
				a.setApellidos(al.Apellidos);
				a.setEmail(al.Email);
				a.setDireccion(al.Direccion);
				a.setTelefono(al.Telefono);
				a.setCursoAlto(al.CursoAlto);
				a.setGrupo(al.Grupo);
				a.setLider(al.Lider);
				a.setNota(al.Nota);
				
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
}

void Profesor::GuardarCopia(Agenda *Ptr_Agenda_){
	
	ofstream fichero;
	Alumno a;
	list<Alumno>::iterator it;
	string nomb, nombreFichero;
	alu al;
	
	if(!Ptr_Agenda_->Alumnos_.empty()){
		
		cout<<"Introduzca el nombre del fichero donde quiere guardar: ";
		cin>>nomb;
		
		nombreFichero=nomb+".bin";
	
		fichero.open(nombreFichero.c_str(), ios::out | ios::binary);
	
		if(fichero.is_open()){
		
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end();it++){
				
				strcpy(al.DNI,(*it).getDNI().c_str());
				strcpy(al.Nombre,(*it).getNombre().c_str());
				strcpy(al.Apellidos,(*it).getApellidos().c_str());
				strcpy(al.Email,(*it).getEmail().c_str());
				strcpy(al.Direccion,(*it).getDireccion().c_str());
				al.Telefono=((*it).getTelefono());
				al.CursoAlto=((*it).getCursoAlto());
				al.Grupo=((*it).getGrupo());
				al.Lider=((*it).getLider());
				al.Nota=((*it).getNota());
			
				fichero.write((const char *)&al, sizeof(al));
			}
		
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}

void Profesor::CargarBD(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	alu al;
	Alumno a;
	Agenda agenda;
	
	fichero.open("BaseDatos.bin", ios::in | ios::binary);
	
	if(fichero.is_open()){
		
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(al)!=0){
			
			fichero.seekg((0)*sizeof(al), ios::beg);
			
			Ptr_Agenda_->Alumnos_.clear();
			
			while(!fichero.eof() && fichero.read((char *)&al, sizeof(al))){
				
				a.setDNI(al.DNI);
				a.setNombre(al.Nombre);
				a.setApellidos(al.Apellidos);
				a.setEmail(al.Email);
				a.setDireccion(al.Direccion);
				a.setTelefono(al.Telefono);
				a.setCursoAlto(al.CursoAlto);
				a.setGrupo(al.Grupo);
				a.setLider(al.Lider);
				a.setNota(al.Nota);
				
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
}

void Profesor::GuardarBD(Agenda *Ptr_Agenda_){
	
	ofstream fichero;
	Alumno a;
	list<Alumno>::iterator it;
	alu al;
	
	if(!Ptr_Agenda_->Alumnos_.empty()){
	
		fichero.open("BaseDatos.bin", ios::out | ios::binary);
	
		if(fichero.is_open()){
		
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end();it++){
				
				strcpy(al.DNI,(*it).getDNI().c_str());
				strcpy(al.Nombre,(*it).getNombre().c_str());
				strcpy(al.Apellidos,(*it).getApellidos().c_str());
				strcpy(al.Email,(*it).getEmail().c_str());
				strcpy(al.Direccion,(*it).getDireccion().c_str());
				al.Telefono=((*it).getTelefono());
				al.CursoAlto=((*it).getCursoAlto());
				al.Grupo=((*it).getGrupo());
				al.Lider=((*it).getLider());
				al.Nota=((*it).getNota());
			
				fichero.write((const char *)&al, sizeof(al));
			}
		
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}
