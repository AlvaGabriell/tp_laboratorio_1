#ifndef MBIBLIOTECA_H_INCLUDED
#define MBIBLIOTECA_H_INCLUDED



#endif // MBIBLIOTECA_H_INCLUDED


/** \brief me brinda un menu en el main
 *
 * \param banderaNum1 int  pido bandera por parametro para segun la ocasion mostrar un mensaje u otro
 * \param numero1 int   pido los numeros a operar segun la opcion elegida por el usario
 * \param numero2 int   pido los numeros a operar segun la opcion elegida por el usario
 * \param banderaNum2 int  pido bandera por parametro para segun la ocasion mostrar un mensaje u otro
 * \return int retorna el numero del menu que escogio el usuario
 *
 */
int mostrarMenu(int banderaNum1, int numero1,int numero2, int banderaNum2);
/** \brief ingresar un numero entero que elija el usuario
 *
 * \param mensaje[] char indico por parametro lo que deseo que salga en el printf de la funcion
 * \return int retorna el valor elegido por el usuario
 *
 */
int ingresarEntero(char mensaje[]);

/** \brief pregunta si realmente desea salir y en base a la respuesta la cambio una por otra para que no interfiera en el bucle
 *
 * \return char opcion elegida por el usuario
 *
 */
char preguntarSalir();
 /** \brief suma los numeros ingresados por el usuario
  *
  * \param numero ingresado por el usuario para sumar
  * \param numero ingresado por el usuario para sumar
  * \return
  *
  */
 int sumar (int numero1,int numero2);
/** \brief saca factorial segun el numero ingresado
 *
 * \param numero int numero ingresado por el usuario
 * \return int retorna el factorial del numero ingresado
 *
 */
/** \brief sacar factorial
 *
 * \param numero int numero ingresadoi
 * \param int*resultadoFactorial retorno por puntero
 * \return int retorna si hubo error
 *
 */
int sacarFactorial(int numero,int*resultadoFactorial);
 int restar (int numero1,int numero2);
 /** \brief multiplica los numeros ingresados por el usuario
  *
  * \param numero ingresado por el usuario para multiplicar
  * \param numero ingresado por el usuario para multiplicar
  * \return resultado de la multiplicacion
  *
  */
 int multiplicar (int numero1,int numero2);
 /** \brief divide entre 2 numeros
  *
  * \param numero1 int numero a ingresar para dividir
  * \param numero2 int numero a ingresar para dividir
  * \param resultadoDividir float* manda el resultado por parametro
  * \return int retorna si hubo error o no para contemplar que el segundo numero no sea 0
  *
  */
 int dividir(int numero1, int numero2,float* resultadoDividir);
 /** \brief llama a todos los resultados retornados por las funciones aritmeticas y los muestra por printf
  *
  * \param numero1 int  muestra el numero por printf
  * \param numero2 int  muestra el numero por printf
  * \param resultadoSuma int    muestra el resultado por printf
  * \param resultadoResta int   muestra el resultado por printf
  * \param resultadoMulti int   muestra el resultado por printf
  * \param factorial int        muestra el resultado por printf
  * \param resultadoFactorial2 int  muestra el factorial por printf
  * \param errorDiv int         necesario para mostrar el mensaje dividir en caso de haber o no error.
  * \param resultadoDivision float*  muestra el resultado de la division
  * \return void
  *
  */
void llamarValores(int numero1, int numero2,int resultadoSuma,int resultadoResta,int resultadoMulti,int huboErrorFactorial1,int* resultadoPunteroFactorial1,int huboErrorFactorial2,int* resultadoPunteroFactorial2,int errorDiv,float* resultadoDivision);
