#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "string.h"
#include "ctype.h"
#define TAM 100
int main()
{
	setbuf(stdout,NULL);
    int idEmpleadoAbuscar;
    int indiceSort;
    int nextId=1;
    Employee lista[1000];
    Employee auxLista;
    char seguir='n';
    int flagInit=0;
    if(initEmployees(lista,TAM)==-1)
    {
        printf("Error al cargar empleados.\n");
    }
    do
    {
        switch(menu())
        {
        case 1:
            auxLista.id=nextId;
            getArraysS(auxLista.name,"Ingrese nombre\n","Error, ingrese nombre nuevamente.\n");
            getArraysS(auxLista.lastName,"Ingrese apellido\n","Error, ingrese apellido nuevamente\n");
            pedirFlotante(&auxLista.salary);
            pedirEntero(&auxLista.sector);
            auxLista.isEmpty=0;
            addEmployee(lista,TAM,auxLista.id,auxLista.name,auxLista.lastName,auxLista.salary,auxLista.sector);
            nextId++;
            flagInit++;
            printf("%d",flagInit);
            break;
        case 2:
            if(flagInit>0)
            {
                editEmployees(lista,TAM,10);
            }
            else
            {
                printf("primero debes ingresar datos\n");
            }
            break;
        case 3:
            if(flagInit>0)
            {
                printf("Ingrese id del empleado a dar de baja.\n");
                scanf("%d",&idEmpleadoAbuscar);
                removeEmployee(lista,TAM,idEmpleadoAbuscar);
                flagInit--;
                printf("%d",flagInit);
            }
            else
            {
                printf("primero debes ingresar datos\n");
            }
            break;
        case 4:
            if(flagInit>0 )
            {
                printf("Ingrese 1 para ordenar sector por forma ascendente o 2 para forma descendente.\n\n");
                scanf("%d",&indiceSort);
                sortEmployees(lista,TAM,indiceSort);
                printListas(lista,TAM);
            }
            else
            {
                printf("primero debes ingresar datos\n");
            }
            break;
        case 5:
            printf("Seguro que deseas salir? (s / n )\n");
            fflush(stdin);
            scanf("%c",&seguir);
            break;
        default:
            fflush(stdin);
            printf("Opcion invalida.\n");
        }
        system("pause");
    }
    while(seguir=='n');


    return 0;
}

