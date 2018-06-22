#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int retorno = -1;
    //tener donde dejar lo que voy a leer (buffers)
    //buffers gigantes
    char bId[4096];
    char bName[4096];
    char bLastName[4096];
    char bIsEmpty[4096];

    Employee* auxiliarempleado;

    if(pFile != NULL){

        retorno = 0;
        //para descartar la primera linea, se hace un fscanf sin agregarla al array list
        //ni guardarla en un auxEmpleado
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",bId, bName, bLastName,bIsEmpty);
        while(!feof(pFile)){

            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
                   bId, bName, bLastName,bIsEmpty);
            //el auxiliar no es necesario, podria ir dentro de la funcion al_add
            auxiliarempleado = employee_newParametros(bId, bName, bLastName, bIsEmpty);
            al_add(pArrayListEmployee, auxiliarempleado);
        }
    }
    return retorno;
}




