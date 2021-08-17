#ifndef PAQUETE_H
#define PAQUETE_H

#include<iostream>
#include<iomanip>

using namespace std;


class Paquete{
    string id;
    string origen;
    string destino;
    float peso;
    public:
        Paquete();
        Paquete(const string &id, const string &origen, const string &destino, float peso);
        void setId(const string&v);
        string getId();
        void setOrigen(const string&v);
        string getOrigen();
        void setDestino(const string&v);
        string getDestino();
        void setPeso(float p);
        float getPeso();
        
        friend ostream& operator<<(ostream&out, const Paquete&p){
            
            out<<left;
            out<<setw(10)<<p.id;
            out<<setw(15)<<p.origen;
            out<<setw(15)<<p.destino;
            out<<setw(15)<<p.peso;
            out<<endl;
            
            return out;
        }

        friend istream& operator>>(istream&in, Paquete&p){

            string temp;
            float peso;

            cout<<"Id: ";
            getline(cin,temp);
            p.setId(temp);

            cout<<"Origen: ";
            getline(cin,temp);
            p.setOrigen(temp);

            cout<<"Destino: ";
            getline(cin,temp);
            p.setDestino(temp);

            cout<<"Peso: ";
            cin>>p.peso; //cin.ignore();

            return in;
        }
    
    };


#endif