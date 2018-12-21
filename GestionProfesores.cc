#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <cstring>
#include <stdio.h>
#include "Profesor.h"
#include "Agenda.h"

using namespace std;

bool BuscarProfesor(char ID[10], Profesor *Ptr_Profesores_);
void AnadirProfesor(Profesor *Ptr_Profesores_);
void MostrarTodos(Profesor *Ptr_Profesores_);
void GuardarFichero(Profesor *Ptr_Profesores_);

typedef struct profesor{
	
	char ID[10], Password[20];
	int Rol;
	
}profe;

int main(){

	int opcion;
	char ID[10], Password[20];
	Profesor p;
	
	//p.Profesores_.clear();
	
	while(true){

		cout << "\n\n";
        cout << "\t\t  ====== GESTIÓN DE PROFESORES ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Añadir un profesor";
		cout << "\n \t\t\t 2. Mostrar todos los profesores";
        cout << "\n \t\t\t 3. Salir";
        cout << "\n\n";
        cout << "\t\t\t Seleccione la opción que desee: ";
        cin>>opcion;

        if(opcion>3 || opcion<1){

            cout<<"\n \t\t\t¡Opción incorrecta!"<<endl;
            cout<<"\n \t\t\tIntroduzca otra opción: ";
            cin>>opcion;
        }

        switch(opcion){

        	case 1: 
         		AnadirProfesor(&p);
         		break;
	        case 2: 
	         	MostrarTodos(&p);
	         	break;
		    case 3: 
		        exit(-1);
		        break;
		}
	}
}

bool BuscarProfesor(char ID[10], Profesor *Ptr_Profesores_){
	
	list<Profesor>::iterator it;
	
	for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
		
		if((*it).getID()==ID){
			
			return true;
		}
	}
	
	return false;
}

void AnadirProfesor(Profesor *Ptr_Profesores_){
	
	char ID[10], Password[20];
	int Rol;
	Profesor p;
	ofstream fichero;
	list<Profesor>::iterator it;
	profe pro;
	//ifstream fichero2;

	cout<<"Introduzca el ID del nuevo profesor: ";
	cin>>ID;
	
	if(BuscarProfesor(ID, Ptr_Profesores_)==false){
		
		p.setID(ID);
		cout<<"Introduzca la contraseña del nuevo profesor: ";
		cin>>Password;
		p.setPassword(Password);
		cout<<"Introduzca el rol del nuevo profesor, Coordinador(1) ó Ayudante(0): ";
		cin>>Rol;
		p.setRol(Rol);
		
		Ptr_Profesores_->Profesores_.push_back(p);
		
	}else{
		
		cout<<"ERROR: Ya existe un profesor con ese ID."<<endl;
	}
	
	if(!Ptr_Profesores_->Profesores_.empty()){
		
		fichero.open("Profesores.bin", ios::out | ios::binary);
	
		if(fichero.is_open()){
			
			//MostrarTodos(Ptr_Profesores_);
		
			for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
				
				strcpy(pro.ID,(*it).getID().c_str());
				strcpy(pro.Password,(*it).getPassword().c_str());
				pro.Rol=((*it).getRol());
				
				fichero.write((const char *)&pro, sizeof(pro));
			}
		
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay profesores nuevos para guardar"<<endl;
	}
}

void MostrarTodos(Profesor *Ptr_Profesores_){

	list<Profesor>::iterator it;
	int cont=1;
	ifstream fichero;
	Profesor p;
	profe pro;
	string nombreFichero;
	
	nombreFichero="Profesores.bin";
	
	fichero.open(nombreFichero.c_str(), ios::in | ios::binary);
	
	if(fichero.is_open()){
		
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(pro)!=0){
			
			fichero.seekg((0)*sizeof(pro), ios::beg);
			
			Ptr_Profesores_->Profesores_.clear();
			
			while(!fichero.eof() && fichero.read((char *)&pro, sizeof(pro))){
				
				p.setID(pro.ID);
				p.setPassword(pro.Password);
				p.setRol(pro.Rol);
				
				Ptr_Profesores_->Profesores_.push_back(p);
			}
		
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
	
	for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
			
		cout<<cont<<".- ID: "<<(*it).getID()<<" - Contraseña: "<<(*it).getPassword()<<" - Rol: "<<(*it).getRol()<<endl;
		
		cont++;
	}
}
