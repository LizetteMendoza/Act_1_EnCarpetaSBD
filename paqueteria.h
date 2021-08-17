#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include"paquete.h"
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

template<class T>
class Paqueteria{
    vector<T> paquetes;

public:
    Paqueteria();
    void agregarPaquete(const T&p);
    void mostrar();
    void respaldar();
    void recuperar();
    void insertar_inicio(T &v);
    void eliminar_inicio();

    friend Paqueteria& operator <<(Paqueteria& p, const T&o){
        p.agregarPaquete(o);

        return p;
    }

};

template<class T>
Paqueteria<T>::Paqueteria(){}

template<class T>
void Paqueteria<T>::agregarPaquete(const T&p){
   paquetes.push_back(p);
}

template<class T>
void Paqueteria<T>::insertar_inicio(T &v){
    
    paquetes.insert(paquetes.begin(), v);
}

template<class T>
void Paqueteria<T>::eliminar_inicio(){
    paquetes.erase(paquetes.begin());
   
}

template<class T>
void Paqueteria<T>::mostrar(){
    cout<<left;
    cout<<setw(10)<<"ID";
    cout<<setw(15)<<"Origen";
    cout<<setw(15)<<"Destino";
    cout<<setw(15)<<"Peso";
    cout<<endl;
    for(size_t i=0; i<paquetes.size(); i++){
        T & p = paquetes[i];
        cout<<p;
    }

}

template<class T>
void Paqueteria<T>::respaldar(){

    ofstream archivo("paquete.txt");
    if (archivo.is_open()){
        for(size_t i=0; i<paquetes.size(); i++){
            Paquete &p = paquetes[i];
            archivo << p.getId()<<"|";
            archivo << p.getOrigen()<<"|";
            archivo << p.getDestino()<<"|";
            archivo << p.getPeso()<<"*";
            
        }
    }
    archivo.close();
}

template<class T>
void Paqueteria<T>::recuperar(){

    ifstream archivo("paquete.txt");
    if(archivo.is_open()){
        string temp;
        float peso;
        Paquete p;

        while(true){
           
            getline(archivo,temp,'|');
            if(archivo.eof()){
                break;
            }
            p.setId(temp);

            getline(archivo, temp,'|');
            p.setOrigen(temp);
            
            getline(archivo, temp,'|');
            p.setDestino(temp);
            
            getline(archivo, temp,'*');
            peso = stof(temp);
            p.setPeso(peso);

            agregarPaquete(p);
            
        }
    }
    archivo.close();
}

#endif