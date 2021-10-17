#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int menu()
{
    int opcion;
    //test
    system("cls");
    printf("    ******** Employees ********\n");
    printf("---------------------------------\n");
    printf("    1-Altas\n");
    printf("    2-Modificar\n");
    printf("    3-Baja \n");
    printf("    4-Informar\n");
    printf("    5-Salir\n");
    printf("Ingrese opcion :\n ");
    scanf("%d",&opcion);

    return opcion;
}
int subMenu()
{
    int opcion;
    printf("1.-Modificar nombre\n");
    printf("2.-Modificar apellido\n");
    printf("3.-Modificar salario\n");
    printf("4.-Modificar sector\n");
    scanf("%d",&opcion);

    return opcion;
}

int initEmployees(Employee* list, int len)
{
    int todoOk=-1;

    if(list!=NULL&&len>0)
    {
        for(int i =0; i < len; i++)
        {
            list[i].isEmpty=1;
        }
        todoOk=0;
    }
    return todoOk;
}

int findFreeSlot(Employee list[], int len)
{
    int indice=-1;
    if(list!=NULL&&len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int todoOk=0;
    int index;
    if(list!=NULL&&len>0&&id>0&&name!=NULL&&lastName!=NULL&&salary>0&&sector>0)
    {
        index=findFreeSlot(list,len);
        list[index].id=id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName,lastName);
        list[index].salary=salary;
        list[index].sector=sector;
        list[index].isEmpty=0;
        todoOk=1;
    }
    return todoOk;
}

int getArraysS(char* list,char mensaje1[],char mensaje2[])
{
    int todoOk=0;
    char auxCadena[51];
    if(list!=NULL)
    {
        printf("%s",mensaje1);
        fflush(stdin);
        gets(auxCadena);
        strlwr(auxCadena);
        while(strlen(auxCadena)<2||strlen(auxCadena)>51)
        {
            printf("%s",mensaje2);
            fflush(stdin);
            gets(auxCadena);
        }
        auxCadena[0]=toupper(auxCadena[0]);
        strcpy(list,auxCadena);
        todoOk=1;
    }
    return todoOk;
}

int pedirFlotante(float* flotante)
{
    float auxF;
    int todoOk=0;
    if(flotante!=NULL)
    {
        printf("Ingrese salario.\n");
        scanf("%f",&auxF);
        while(auxF<1 || auxF>150000)
        {
            printf("Error,ingrese salario.\n");
            scanf("%f",&auxF);
        }
        *flotante=auxF;
        todoOk=1;
    }
    return todoOk;
}

int pedirEntero(int* entero)
{
    int auxInt;
    int todoOk;
    if(entero!=NULL)
    {
        printf("Ingrese sector.\n");
        scanf("%d",&auxInt);
        while(auxInt<1 || auxInt>150000)
        {
            printf("Error, ingrese sector nuevamente.\n");
            scanf("%d",&auxInt);
        }
        *entero=auxInt;
        todoOk=1;
    }
    return todoOk;
}

void printLista(Employee list)
{
    printf("      %3d    %10s    %10s          %10.3f             %2d\n",
           list.id,
           list.name,
           list.lastName,
           list.salary,
           list.sector);
}


int printListas(Employee list[],int len)
{
    system("cls");
    printf("                   ********** Employees **********       \n");
    printf("      --------------------------------------------------------------\n");
    printf("        Id      Nombre         Apellido          Salario            Sector\n\n");

    int flag=1;
    int todoOk=0;
    int contador=0;
    int contadorReGanados=0;
    float acumulador=0;
    float promedio;
    if(list!=NULL&&len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {

                printLista(list[i]);
                acumulador+=list[i].salary;
                contador++;
                flag=0;
            }
        }
        if(flag)
        {
            printf("No existen datos ingresados\n");
        }
        if(contador!=0)
        {
            promedio=(float)acumulador/contador;
        }
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0&&list[i].salary>promedio)
            {
                contadorReGanados++;
            }
        }
        todoOk=1;
    }
    if(contador!=0)
    {
        printf("\nSueldo acumulado : %f\n",acumulador);
        printf("Promedio de sueldos general : %.2f\n",promedio);
        printf("Cantidad de empleados con sueldo mayor al promedio : %d\n",contadorReGanados);
    }
    else
    {
        printf("Sueldo acumulado : No se han ingresado datos.\n");
        printf("Promedio de sueldos general : No se han ingresado datos.\n");
        printf("Cantidad de empleados con sueldo mayor al promedio : No se han ingresado datos. \n");
    }

    return todoOk;
}


int findEmployeeById(Employee* list,int len,int id)
{
    int indice=-1;
    if(list!=NULL&&len>0&&id>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0&&list[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int removeEmployee(Employee list[],int len,int id)
{
    int todoOk=0;
    char confirmacion;
    int indice;
    if(list!=NULL&&len>0&&id>0)
    {
        system("cls");
        printf("        ******** baja de empleados ********\n");
        indice=findEmployeeById(list,len,id);
        if(indice==-1)
        {
            printf("No se encuentra el id para hacer la baja.\n");
        }
        else
        {
            printLista(list[indice]);
            printf("Seguro que desea dar de baja los siguientes datos? ( s / n )\n");
            fflush(stdin);
            scanf("%c",&confirmacion);
            while(confirmacion !='s'&& confirmacion!='n')
            {
                system("cls");
                printf("        ******** baja de empleados ********\n\n");
                printf("Error, debe confirmar que desea dar de baja los siguientes datos \n\n");
                printLista(list[indice]);
                printf("\n");
                printf("Digite una opcion para continuar o cancelar la operacion. ( s / n )\n");
                fflush(stdin);
                scanf("%c",&confirmacion);
            }
            if(confirmacion=='s')
            {
                list[indice].isEmpty=1;
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Se ha cancelado la operacion.\n");
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int sortEmployees(Employee list[],int len,int order)
{
    Employee auxEmploy;
    int todoOk=0;
    if(list!=NULL&&len>0&&order>0&&order<3)
    {

        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if((order==1&&
                        strcmp(list[i].lastName,list[j].lastName)>0) ||
                        (  strcmp ( list[i].lastName,list[j].lastName ) ==0 &&
                           list[i].sector>list[j].sector  ) )
                {
                    auxEmploy=list[i];
                    list[i]=list[j];
                    list[j]=auxEmploy;
                }
                else if((order==2&&
                         strcmp(list[i].lastName,list[j].lastName)<0) ||
                        (  strcmp ( list[i].lastName,list[j].lastName ) ==0 &&
                           list[i].sector<list[j].sector  ) )
                {
                    auxEmploy=list[i];
                    list[i]=list[j];
                    list[j]=auxEmploy;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int editEmployees(Employee list[],int len,int id)
{
    int indice;
    int idPersona;
    int todoOk=0;
    char confirma;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    if(list!=NULL&&len>0)
    {
        system("cls");
        printf("****Modificar persona****\n\n");
        printf("Ingrese id \n");
        scanf("%d",&idPersona);
        indice=findEmployeeById(list,len,idPersona);
        if(indice==-1)
        {
            printf("Error, ID no encontrado.");
        }
        else
        {
            printLista(list[indice]);
            printf("Confirma modificacion?  (s / n)\n");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                switch(subMenu())
                {
                case 1:
                    getArraysS(auxNombre,"Ingrese nombre\n","Error, ingrese nombre nuevamente.\n");
                    strcpy(list[indice].name,auxNombre);
                    break;
                case 2:
                    getArraysS(auxApellido,"Ingrese apellido\n","Error, ingrese apellido nuevamente.\n");
                    strcpy(list[indice].lastName,auxApellido);
                    break;
                case 3:
                    pedirFlotante(&auxSalario);
                    list[indice].salary=auxSalario;
                    break;
                case 4:
                    pedirEntero(&auxSector);
                    list[indice].sector=auxSector;
                    break;
                default:
                    printf("Opcion invalida\n");
                }
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la operacion\n");
            }
        }
    }
    return todoOk;
}
