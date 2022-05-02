#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "iarray.h"

using namespace std;

bool isChainFormatCorrect();
int *GetIds();
void ShowMenuOptions();
int *GetChain();
void ShowMenu();

void ShowMenu(){
    int opcion;
    int* Indexes;
    do{
        ShowMenuOptions();
        //TODO manejar validacion que el usuario no ponga letras en la opcion del menu
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            //TODO Ver informacion
            break;

        case 2:
            //TODO Agregar informacion
            Indexes = GetChain();
            break;

        case 3:
            //TODO Editar informacion
            break;

        case 4:
            //TODO Remover informacion
            Indexes = GetChain();
            break;

        case 5:

            break;
        default:
            cout<<"Ingrese una opcion correcta"<<endl;
            break;
        }
        //TODO validar que el programa no truene si se ingresa una letra
    }while(opcion!=5);

}

bool isChainFormatCorrect(string Chain){
    int idN = Chain.find_first_of('N');

    if((idN % 2 == 0 || idN == -1 ||idN >= 2) && Chain.length()==12){
        cout<<"La cadena tiene un formato correcto"<<endl<<endl;
        return true;
    }
    
    else
        return false;
}

int *GetIds(string Chain){
    int idGraph;
    int idTree;
    int idList;
    int NumberRow;
    int NumberColumn;
    int indexArray;
    int idN = Chain.find_first_of('N');
    int* ArrayOfIndexes;
    
    ArrayOfIndexes = createIntArray(7);

    if(isChainFormatCorrect(Chain)){

        if (idN == -1){
            ArrayOfIndexes[0] = 5;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
            ArrayOfIndexes[2] = stoi(Chain.substr(2,2));
            ArrayOfIndexes[3] = stoi(Chain.substr(4,2));
            ArrayOfIndexes[4] = stoi(Chain.substr(6,2));
            ArrayOfIndexes[5] = stoi(Chain.substr(8,2));
            ArrayOfIndexes[6] = stoi(Chain.substr(10,2));
        }

        else if(idN == 10){
            //no se si se va a modificar toda la matriz o solo una fila o columna
            ArrayOfIndexes[0] = 4;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
            ArrayOfIndexes[2] = stoi(Chain.substr(2,2));
            ArrayOfIndexes[3] = stoi(Chain.substr(4,2));
            ArrayOfIndexes[4] = stoi(Chain.substr(6,2));
            ArrayOfIndexes[5] = stoi(Chain.substr(8,2));
        }

        else if(idN == 8){
            //no se si se va a modificar toda la matriz o solo una fila o columna
            ArrayOfIndexes[0] = 3;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
            ArrayOfIndexes[2] = stoi(Chain.substr(2,2));
            ArrayOfIndexes[3] = stoi(Chain.substr(4,2));
            ArrayOfIndexes[4] = stoi(Chain.substr(6,2));
        }

        else if(idN == 6){
            ArrayOfIndexes[0] = 2;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
            ArrayOfIndexes[2] = stoi(Chain.substr(2,2));
            ArrayOfIndexes[3] = stoi(Chain.substr(4,2));
        }

        else if(idN == 4){
            ArrayOfIndexes[0] = 1;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
            ArrayOfIndexes[2] = stoi(Chain.substr(2,2));
        }

        else if(idN == 2){
            ArrayOfIndexes[0] = 0;
            ArrayOfIndexes[1] = stoi(Chain.substr(0,2));
        }
                
    }
    else{
        cout<<"Ingrese una cadena valida"<<endl;
    }

    return ArrayOfIndexes; 
}

void ShowMenuOptions(){
    cout<<"Menu"<<endl;
    cout<<"1. Visualizar informacion del sistema"<<endl;
    cout<<"2. Agregar informacion del sistema"<<endl;
    cout<<"3. Modificar informacion del sistema"<<endl;
    cout<<"4. Remover informacion del sistema"<<endl;
    cout<<"5. salir"<<endl<<endl;
    
}

