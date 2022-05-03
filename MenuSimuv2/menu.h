#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "iarray.h"

using namespace std;

void Menu();
bool IsValidChain(int,int*);
void GetIds(string,int*,bool);
void ShowMenu();
void ShowArray(int*);

enum options {Visualizar = 1, Agregar, Modificar, Remover, Salir};

void Menu(){
    int option = 0;
    string optionAux = "";

    do
    {   
        int* Indexes = createIntArray(7);
        ShowMenu();
        cin>>option;
        cin.clear();
        cin.ignore(10000, '\n');
        
        switch (option)
        {
            case Visualizar:
                /* code */
                

                break;
            case Agregar:
                /* code */
                if(IsValidChain(option,Indexes)){
                    ShowArray(Indexes);

                } else{

                }

                break;
            case Modificar:
                /* code */
                if(IsValidChain(option,Indexes)){
                    ShowArray(Indexes);
                } else{

                }

                break;
            case Remover:
                /* code */
                if(IsValidChain(option,Indexes)){
                    ShowArray(Indexes);
                } else{

                }

                break;
            case Salir:
                cout<<"Saliendo......"<<endl<<endl;
                
                break;
            
            default:
                break;
        }
        destroyArray(Indexes);
    } while (option != 5);
    return;
}

bool IsValidChain(int option, int* Indexes){
    int CounterCharsValid = 0;
    bool hasN = false;
    string Chain = "";
    cout<<"Ingrese la cadena de texto"<<endl;
    cin>>Chain;
    cin.clear();
    cin.ignore(10000, '\n');
    cout<<endl;


    //Valida si la cadena tiene 12 caracteres
    if(Chain.size() == 12){
        //Se mira si la cadena tiene datos validos
        if(option == 3){
            for (int i = 0; i < 12; i++){
                if((Chain.at(i) >= 48 && Chain.at(i) <= 57)){
                    if(Chain.at(i) == 78){
                        hasN = true;
                        CounterCharsValid--;
                    }
                    CounterCharsValid++;
                }
            }
        } else {
            for (int i = 0; i < 12; i++){
                if((Chain.at(i) >= 48 && Chain.at(i) <= 57) || Chain.at(i) == 78){
                    if(Chain.at(i) == 78)
                        hasN = true;
                    CounterCharsValid++;

                }
            }
        }

        if(CounterCharsValid == 12){
            if(option == 3 ){
                if(hasN){
                    cout<<"Solo se puede editar la informacion del ultimo nivel "<<endl;
                    return false;
                }
                if(hasN == false){
                    cout<<"Opcion 3 valida"<<endl;
                    GetIds(Chain,Indexes,hasN);
                    return true;
                }
            }

            if (option != 3){
                if(hasN == true && Chain.find_first_of('N')>=2 && Chain.find_first_of('N')%2 == 0){
                    cout<<"Cadena correcta para NN"<<endl;
                    GetIds(Chain,Indexes,hasN);
                    return true;
                }
                if(hasN == false){
                    cout<<"Cadena correcta para modificar ultimo nivel "<<endl;
                    GetIds(Chain,Indexes,hasN);
                    return true;
                }
            }
        }
        else{
            cout<<"Ingrese un formato correcto"<<endl;
            return false;
        }
        
    } else {
        cout<<"Ingrese un formato correcto"<<endl;
        return false;
    }

    Chain="";
    CounterCharsValid=0;
    cout<<"INGRESE UN FORMATO CORRECTO "<<endl;
    return false;
}

void GetIds(string Chain, int *Indexes,bool hasN){
    int idN = Chain.find_first_of('N');
    if (hasN == false){
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
    return; 
}

void ShowMenu(){
    cout<<"Menu"<<endl;
    cout<<"1. Visualizar informacion del sistema"<<endl;
    cout<<"2. Agregar informacion del sistema"<<endl;
    cout<<"3. Modificar informacion del sistema"<<endl;
    cout<<"4. Remover informacion del sistema"<<endl;
    cout<<"5. salir"<<endl<<endl;
    return;
}

void ShowArray(int* Indexes){
    cout<<endl;
    for (int i = 0; i < 7 ; i++)
    {
        cout<<"Indice "<<i<<" es "<<Indexes[i]<<endl;
    }
    
}