#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "iarray.h"

using namespace std;

void ShowMenu();
int *GetChain(int*,int);
bool isChainFormatCorrect(string,int);
int *GetIds(string,int*);
void ShowMenuOptions();
void ShowIndexes(int*);


void Menu(){
    int option;
    //char opcionAux;
    int* Indexes = createIntArray(7);
    do{
        ShowMenuOptions();
        //TODO manejar validacion que el usuario no ponga letras en la opcion del menu
        cin>>option;
        
        switch (option)
        {
        case 1:
            //TODO Ver informacion
            break;

        case 2:
            //TODO Agregar informacion
            GetChain(Indexes,option);
            break;

        case 3:
            //TODO Editar informacion
            GetChain(Indexes,option);
            break;

        case 4:
            //TODO Remover informacion
            //Indexes = GetChain();
            cout<<"HOla xd";
            break;

        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            break;
        }
    

        //TODO validar que el programa no truene si se ingresa una letra
    }while(option!=5);

}

int *GetChain(int* Indexes,int option){
    string Chain;
    cout<<"Ingrese la cadena de texto "<<endl;
    cin>>Chain;
    cin.ignore();

    if(isChainFormatCorrect(Chain,option)){
        Indexes=GetIds(Chain,Indexes);
    }
    else{
        Indexes[0] = 0;
        return Indexes;
    }

    return Indexes;

}

bool isChainFormatCorrect(string Chain,int option){
    int idN = Chain.find_first_of('N');
    if(idN != -1 && option == 3){
        cout<<"La cadena no tiene un formato correcto---"<<endl<<endl;
            return false;
    } 

    cout<<Chain.size()<<endl;

    if(Chain.size() == 12){
        if(((idN % 2 == 0 && idN >=2)|| idN == -1 ) && Chain.length()==12){
            cout<<"La cadena tiene un formato correcto"<<endl<<endl;
            return true;
        }
        else{
            return false;
        }
    }
    else{
        cout<<"La cadena no tiene un formato  XDDD"<<endl<<endl;
        return false;
    }
        
    
}

int *GetIds(string Chain, int *Indexes){
    int idN = Chain.find_first_of('N');
    if (idN == -1){
        Indexes[0] = 5;
        Indexes[1] = stoi(Chain.substr(0,2));
        Indexes[2] = stoi(Chain.substr(2,2));
        Indexes[3] = stoi(Chain.substr(4,2));
        Indexes[4] = stoi(Chain.substr(6,2));
        Indexes[5] = stoi(Chain.substr(8,2));
        Indexes[6] = stoi(Chain.substr(10,2));
    }

    else if(idN == 10){
        //no se si se va a modificar toda la matriz o solo una fila o columna
        Indexes[0] = 4;
        Indexes[1] = stoi(Chain.substr(0,2));
        Indexes[2] = stoi(Chain.substr(2,2));
        Indexes[3] = stoi(Chain.substr(4,2));
        Indexes[4] = stoi(Chain.substr(6,2));
        Indexes[5] = stoi(Chain.substr(8,2));
    }

    else if(idN == 8){
        //no se si se va a modificar toda la matriz o solo una fila o columna
        Indexes[0] = 4;
        Indexes[1] = stoi(Chain.substr(0,2));
        Indexes[2] = stoi(Chain.substr(2,2));
        Indexes[3] = stoi(Chain.substr(4,2));
        Indexes[4] = stoi(Chain.substr(6,2));
    }

    else if(idN == 6){
        Indexes[0] = 3;
        Indexes[1] = stoi(Chain.substr(0,2));
        Indexes[2] = stoi(Chain.substr(2,2));
        Indexes[3] = stoi(Chain.substr(4,2));
    }

    else if(idN == 4){
        Indexes[0] = 2;
        Indexes[1] = stoi(Chain.substr(0,2));
        Indexes[2] = stoi(Chain.substr(2,2));
    }

    else if(idN == 2){
        Indexes[0] = 1;
        Indexes[1] = stoi(Chain.substr(0,2));
    }


    return Indexes; 
}

void ShowMenuOptions(){
    cout<<"Menu"<<endl;
    cout<<"1. Visualizar informacion del sistema"<<endl;
    cout<<"2. Agregar informacion del sistema"<<endl;
    cout<<"3. Modificar informacion del sistema"<<endl;
    cout<<"4. Remover informacion del sistema"<<endl;
    cout<<"5. salir"<<endl<<endl;
}

void ShowIndexes(int* i){
    cout<<"Numero de nivel: "<<i[0]<<endl;
    cout<<"El nodo del grafo es: "<<i[1]<<endl;
    cout<<"El nodo del arbol es: "<<i[2]<<endl;
    cout<<"La fila de la matriz es: "<<i[3]<<endl;
    cout<<"La columna de la matriz es: "<<i[4]<<endl;
    cout<<"El nodo del arreglo es: "<<i[5]<<endl;
    return;
}
