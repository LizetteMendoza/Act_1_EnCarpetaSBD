#include <iostream>
#include<limits>
#include"paquete.h"
#include"paqueteria.h"

using namespace std;

int main() {
	
	Paqueteria <Paquete> p;

	int opc=100;
	
	while (opc!=0){
		cout<<endl<<endl<<"MENU DE OPCIONES"<<endl<<endl;
		cout<<"1.-Agregar paquete"<<endl;
		cout<<"2.-Eliminar paquete"<<endl;
		cout<<"3.-Mostrar"<<endl;
		cout<<"4.-Guardar"<<endl;
		cout<<"5.-Recuperar"<<endl;
		cout<<"0.-Salir"<<endl;
		cin>>opc; cin.ignore();
	
		switch (opc){
		case 1:{
			Paquete p2;
			cin>>p2;
			p.insertar_inicio(p2);
			break;}
		
		case 2:
			p.eliminar_inicio();
			break;
		case 3:
			p.mostrar();
			break;
		case 4:
			p.respaldar();
			break;
		case 5:
			p.recuperar();
			break;
		case 0:
			cout<<"Saliendo..."<<endl;
			break;
		
		default:
			cout<<"Opcion no valida"<<endl;
			break;
		}

	}
	
    return 0;

}
