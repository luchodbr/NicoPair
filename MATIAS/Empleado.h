#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char name[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);

Empleado* em_new(void);
Empleado* em_newParametros(char* strId,char* name, char* strHorasTrabajadas);
void em_delete(Empleado* this);

int em_setId(Empleado* this, int id);
int em_getId(Empleado* this, int* id);
int em_setName(Empleado* this, char* name);
int em_getName(Empleado* this, char* name);
int em_setHorasTrabajadas(Empleado* this, int horasTrabajadas);
int em_getHorasTrabajadas(Empleado* this, int* horasTrabajadas);
int em_setSueldo(Empleado* this, int sueldo);
int em_getSueldo(Empleado* this, int* sueldo);

#endif // EMPLEADO_H_INCLUDED
