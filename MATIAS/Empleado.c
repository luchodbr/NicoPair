#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Empleado.h"

void em_calcularSueldo(void* p)
{
    int horasTrabajadasP;
    int sueldoP = 0;

    Empleado* pEm = (Empleado*)p;

    em_getHorasTrabajadas(pEm, &horasTrabajadasP);

    if(horasTrabajadasP <= 120 && horasTrabajadasP >= 80)
    {
        sueldoP = 180 * horasTrabajadasP;
    }
    else if(horasTrabajadasP <= 160)
    {
        sueldoP = (180 * 120) + (240 *(horasTrabajadasP - 120));
    }
    else if(horasTrabajadasP <= 240)
    {
        sueldoP = (180 * 120) + (240 *40) + (350 *(horasTrabajadasP - 160));
    }

    em_setSueldo(pEm, sueldoP);
}


static int isValidName(char* name);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);


Empleado* em_new(void)
{

    Empleado* returnAux = (Empleado*) malloc(sizeof(Empleado));
    return returnAux;

}


Empleado* em_newParametros(char* strId,char* name, char* strHorasTrabajadas)
{
    int id;
    int horasTrabajadas;
    Empleado* this = em_new();

    id = atoi(strId);
    horasTrabajadas = atoi(strHorasTrabajadas);

    if( !em_setId(this,id) &&
        !em_setName(this,name) &&
        !em_setHorasTrabajadas(this,horasTrabajadas))
    {
        return this;
    }
    em_delete(this);
    return NULL;
}


void em_delete(Empleado* this)
{
    if(this != NULL)
        free(this);
}


//---------------------------------------------------------------


int em_setId(Empleado* this, int id)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        if(id == -1)
        {
            ultimoId++;
            this->id = ultimoId;
            retorno = 0;
        }
        if(id > ultimoId)
        {
            this->id = id;
            ultimoId = id;
            retorno = 0;
        }
    }
    return retorno;
}


int em_getId(Empleado* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}


int em_setName(Empleado* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}


int em_getName(Empleado* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}


int em_setHorasTrabajadas(Empleado* this, int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas))
    {
        retorno = 0;
        this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}


int em_getHorasTrabajadas(Empleado* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        retorno = 0;
        *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}


int em_setSueldo(Empleado* this, int sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo))
    {
        retorno = 0;
        this->sueldo = sueldo;
    }
    return retorno;
}


int em_getSueldo(Empleado* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        retorno = 0;
        *sueldo = this->sueldo;
    }
    return retorno;
}


//---------------------------------------------------------------


static int isValidName(char* name)
{
    return 1;
}


static int isValidHorasTrabajadas(int horasTrabajadas)
{
    return 1;
}


static int isValidSueldo(int sueldo)
{
    return 1;
}

//---------------------------------------------------------------


/*void destinatario_print(EDestinatario* this)
{
    char name[51];
    char email[101];
    if(this != NULL)
    {
        destinatario_getName(this,name);
        destinatario_getEmail(this,email);
        fprintf(stdout,"\nNombre: %s - Email: %s",name,email);
    }

}*/
