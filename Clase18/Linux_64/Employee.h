#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
//agregar el nextId

int Employee_setId(Employee* this,int id);
int Employee_getId(Employee* this,int* id);
int Employee_setNombre(Employee* this,char* nombre,int lenNombre);
int Employee_getNombre(Employee* this,char* nombre);
int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int Employee_setSueldo(Employee* this,int sueldo);
int Employee_getSueldo(Employee* this,int* sueldo);
Employee* Employee_new();
void Employee_delete(Employee* this);
Employee* Employee_newConParametros(char* idString,char* nombre,int lenNombre,
                                    char* horasTrabajadasString,char* sueldoString);

int Employee_criterioSortNombre(void* thisA, void* thisB);

#endif // EMPLOYEE_H_INCLUDED
