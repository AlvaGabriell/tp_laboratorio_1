#include "miBiblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//////////////////////////// Matematicas.

int promediar(int x, int y)
{
    int reslt;
    reslt = (int)(x+y)/2;
    return reslt;
}

///////////////////////// Menu
int mostrarMenu(int banderaNum1, int numero1,int numero2, int banderaNum2)
{
    int opcion;
    system("cls");
    printf("Menu de opciones : \n\n");
    if(banderaNum1==0)
    {
        printf("1. Ingresar primer numero :\n");
    }
    else
    {
        printf("1. Ingresar primer numero : (A=%d) \n",numero1);
    }
    if(banderaNum2==0)
    {
        printf("2. Ingresar segundo numero :\n");
    }
    else
    {
        printf("2. Ingresar segundo numero : (B=%d) \n",numero2);
    }
    printf("3. Calcular todas las operaciones :\n");
    printf("4. Informar resultados :\n");
    printf("5. Salir :\n");
    scanf("%d",&opcion);
    return opcion;
}

int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}
char preguntarSalir()
{
    char salir='s';
        printf("Seguro que desea salir ? : ( S / N )\n");
        fflush(stdin);
        scanf("%c",&salir);
        salir=tolower(salir);
        if(salir=='n')
        {
            salir='s';
        }
        else if(salir=='s')
        {
            salir='n';
        }
    return salir;
}
////////////////////////parte Matematica.
int sumar (int numero1,int numero2)
{
    int resultadoSuma=numero1+numero2;
    return resultadoSuma;
}

int sacarFactorial(int numero,int*resultadoFactorial)
{
    int rta;
    int todoOk=0;
    int i;
    rta=1;
    if(numero>0)
    {
        for(i=1;i<=numero;i++)
        {
            rta=rta*i;
        }
        todoOk=1;
        *resultadoFactorial=rta;
    }
    return todoOk;
}

int restar (int numero1,int numero2)
{
    int resultadoResta=numero1-numero2;
    return resultadoResta;
}

int multiplicar (int numero1,int numero2)
{
    int resultadoMulti=numero1*numero2;
    return resultadoMulti;
}

int dividir(int numero1, int numero2,float* resultadoDividir)
{
    int huboError;
    if(numero2==0)
    {
        huboError=1;
    }
    else
    {
        huboError=0;
        *resultadoDividir=(float)numero1/numero2;
    }
    return huboError;
}
 void llamarValores(int numero1, int numero2,int resultadoSuma,int resultadoResta,int resultadoMulti,int huboErrorFactorial1,int* resultadoPunteroFactorial1,int huboErrorFactorial2,int* resultadoPunteroFactorial2,int errorDiv,float* resultadoDivision)
{

    printf("El resultado de %d + %d es : %d\n",numero1,numero2,resultadoSuma);
    printf("El resultado de %d - %d es : %d\n",numero1,numero2,resultadoResta);
    printf("El resultado de %d * %d es : %d\n",numero1,numero2,resultadoMulti);
    printf("El factorial de %d es : %d\n",numero2,*resultadoPunteroFactorial2);
    if(errorDiv==0)
    {
        printf("El resultado de %d / %d es : %.2f\n",numero1,numero2,*resultadoDivision);
    }
    else
    {
        printf("No se puede dividir por 0.\n");
    }
    if(huboErrorFactorial1==1)
    {
        printf("El factorial de %d es : %d\n",numero1,*resultadoPunteroFactorial1);
    }
    else
    {
        printf("No se puede calcular el factorial.\n");
    }
        if(huboErrorFactorial2==1)
    {
        printf("El factorial de %d es : %d\n",numero1,*resultadoPunteroFactorial2);
    }
    else
    {
        printf("No se puede calcular el factorial.\n");
    }



}
