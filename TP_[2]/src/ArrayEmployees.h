#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED
/** \brief menu principal
 *
 * \return retorna la opcion numerica elegida.
 *
 */
int menu();




/** \brief menu para la funcion modificar datos.
 *
 * \return int retorna la opcion numerica elegida.
 *
 */
int subMenu();




/** \brief  inicializa el campo isempty en 1
 *
 * \param list Employee* array a recorrer
 * \param len int       tamaño de la lista a inicializar
 * \return int retorna 0 si estuvo bien, -1 si hubo error.
 *
 */
int initEmployees(Employee* list, int len);



/** \brief recorre array buscando el primer lugar que este libre para usar.
 *
 * \param list[] Employee array a recorrer
 * \param len int tamñao a recorrer.
 * \return int retorna el indice del espacio vacio que encontro, de lo contrario retorna -1 como error.
 *
 */
int findFreeSlot(Employee list[], int len);



/** \brief junta todos los auxiliares pedidos previamente y los almacena en el arreglo principal
 *
 * \param list Employee* arreglo principal donde se almacenan los datos
 * \param len int tamaño del arreglo
 * \param id int  id de la persona
 * \param name[] char nombre de la persona
 * \param lastName[] char apellido de la persona
 * \param salary float salario de la persona
 * \param sector int sector de la persona
 * \return int retorna 1 si la operacion se dio correctamente, 0 de lo contrario.
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);



/** \brief pide flotante al usuario
 *
 * \param flotante float* devuelve por puntero el valor a pedir por el usuario
 * \return int retorna 0 si hubo error, 1 si se dio bien.
 *
 */
int pedirFlotante(float* flotante);


/** \brief pide un entero que seria el sector.
 *
 * \param entero int* devuelve por puntero el valor a pedir por el usuario
 * \return int retorna 0 si hubo error, 1 si se dio bien.
 *
 */
int pedirEntero(int* entero);



/** \brief muestra por print una sola estructura
 *
 * \param list Employee la estructura por la cual se muestra
 * \return void
 *
 */
void printLista(Employee list);



/** \brief muestra por print la estructura y el tamaño de la misma segun se configure como tambien el promedio, acumulador y contador
 *         de personal con excedente de sueldo en base al promedio general
 *
 * \param list[] Employee estructura por la cual se muestra
 * \param len int tamaño de la estructura a mostrar
 * \return int retorna 1 si estuvo todo bien, 0 si fallo algo.
 *
 */
int printListas(Employee list[],int len);


/** \brief pido una cadena por array
 *
 * \param list char* el array donde almaceno la cadena pedida
 * \param mensaje1[] char primer mensaje a mostrar
 * \param mensaje2[] char segundo si hubo error
 * \return int retorna 0 si hubo error, 1 de lo contrario
 *
 */
int getArraysS(char* list,char mensaje1[],char mensaje2[]);



/** \brief funcion para remover en base al id obtenido una estructura de datos.
 *
 * \param list[] Employee lugar a buscar los datos
 * \param len int tamaño del lugar
 * \param id int id por el cual se ingresa a buscar los datos
 * \return int retorna 1 si funciono, 2 de lo contrario
 *
 */
int removeEmployee(Employee list[],int len,int id);



/** \brief ordena los arreglos como primer criterio el sector y segundo el orden alfabetico.
 *
 * \param list[] Employee estructura a recorrer
 * \param len int tamaño del mismo
 * \param order int  criterio de busqueda, 1 si es ascendente, 2 si es descendente
 * \return int retorna 1 si se dio todo bien, 2 de lo contrario.
 *
 */
int sortEmployees(Employee list[],int len,int order);



/** \brief  edita los campos creados en la estructura
 *
 * \param list[] Employee   list[] Employee estructura mediante la cual se editan los datos ingresados.
 * \param len int   tamaño de la escturica
 * \param id int    id como referencia para encontrar los datos de la busqueda.
 * \return int retorna 0 si hubo error, 1 si se dio todo bien.
 *
 */
int editEmployees(Employee list[],int len,int id);

