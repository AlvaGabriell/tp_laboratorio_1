#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include <ctype.h>
#define INGRESONUMERO 1
#define NOINGRESONUMERO 0
int main()
{
	setbuf(stdout,NULL);
    char seguir='s';
    int numero1;
    int numero2;
    int banderaFunIngresoNum1=NOINGRESONUMERO;
    int banderaFunIngresoNum2=NOINGRESONUMERO;
    int banderaCalcularRes=NOINGRESONUMERO;
    char reescribir='n';
    int resultadoSumar;
    int resultadoRestar;
    int resultadoMultiplicar;
    int huboErrorFactorial1;
    int resultadoPunteroFactorial1;
    int huboErrorFactorial12;
    int resultadoPunteroFactorial2;
    int errorDivision;
    float resultadoDivision;
    do
    {
        switch(mostrarMenu(banderaFunIngresoNum1,numero1,numero2,banderaFunIngresoNum2))
        {
        case 1:
            if(banderaFunIngresoNum1==NOINGRESONUMERO)
            {
                numero1=ingresarEntero("Ingresa primer operador :\n");
                banderaFunIngresoNum1=INGRESONUMERO;
            }
            else if (banderaFunIngresoNum1==INGRESONUMERO)
            {
                printf("Ya has ingresado el primer operador, deseas reescribir ? ( S / N ) :\n");
                fflush(stdin);
                reescribir=tolower(reescribir);
                scanf("%c",&reescribir);
                if(reescribir == 's' )
                {
                    numero1=ingresarEntero("Ingresa primer operador :\n");
                }
            }
            break;
        case 2:
            if(banderaFunIngresoNum1==NOINGRESONUMERO)
            {
                printf("Debes ingresar el primer numero!\n");
            }
            else if(banderaFunIngresoNum2==NOINGRESONUMERO)
            {
                numero2=ingresarEntero("Ingresa segundo operador :\n");
                banderaFunIngresoNum2=INGRESONUMERO;
                banderaFunIngresoNum2=INGRESONUMERO;
            }
            else if (banderaFunIngresoNum2==INGRESONUMERO)
            {
                printf("Ya has ingresado el segundo operador, deseas reescribir ? ( S / N ) :\n");
                fflush(stdin);
                reescribir=tolower(reescribir);
                scanf("%c",&reescribir);
                if(reescribir == 's' )
                {
                    numero2=ingresarEntero("Ingresa segundo operador :\n");
                    banderaFunIngresoNum2=INGRESONUMERO;
                }
            }
            break;
        case 3:
            if(banderaFunIngresoNum1==NOINGRESONUMERO && banderaFunIngresoNum2==NOINGRESONUMERO)
            {
                printf("Debes ingresar el primer y segundo numero antes de realizar la operacion.\n");
            }
            else if (banderaFunIngresoNum2==NOINGRESONUMERO)
            {
                printf("Debes ingresar el segundo numero para realizar la operacion.\n");
            }
            else
            {
                banderaCalcularRes=INGRESONUMERO;
                resultadoSumar=sumar(numero1,numero2);
                resultadoRestar=restar(numero1,numero2);
                resultadoMultiplicar=multiplicar(numero1,numero2);
                huboErrorFactorial1=sacarFactorial(numero1,&resultadoPunteroFactorial1);
                huboErrorFactorial12=sacarFactorial(numero2,&resultadoPunteroFactorial2);
                errorDivision=dividir(numero1,numero2,&resultadoDivision);
            }
            break;
        case 4:
            if(banderaFunIngresoNum1==NOINGRESONUMERO&&banderaFunIngresoNum2==NOINGRESONUMERO)
            {
                printf("Debes ingresar los numeros y operarlos para mostrar los resultados .\n");
            }
            else if(banderaFunIngresoNum2==0)
            {
                printf("Debes ingresar el segundo numero y operarlos para mostrar los resultados.\n ");
            }
            else if (banderaCalcularRes==NOINGRESONUMERO)
            {
                printf("Debes realizar el calculo previamente para mostrar los resultados.\n");
            }
            else
            {
                llamarValores(numero1,numero2,resultadoSumar,resultadoRestar,resultadoMultiplicar,huboErrorFactorial1,&resultadoPunteroFactorial1,huboErrorFactorial12,&resultadoPunteroFactorial2,errorDivision,&resultadoDivision);
                banderaFunIngresoNum1=NOINGRESONUMERO;
                banderaFunIngresoNum2=NOINGRESONUMERO;
            }
            break;
        case 5:
            seguir=preguntarSalir();
            break;
        default:
            printf("Opcion invalida.\n");
            fflush(stdin);
            break;
        }
        system("pause");
    }
    while(seguir=='s');

    return 0;
}
