#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<cstdio>
#include<sys\timeb.h> 

#define reservar_memoria_cola (NodoCola *)malloc(sizeof(NodoCola))
#define reservar_memoria_pila (NodoPila *)malloc(sizeof(NodoPila))

using namespace std;

struct NodoCola{
	int dato;
	NodoCola * siguiente;
};

struct NodoPila{
	int dato;
	NodoPila * siguiente;
};

//
struct timeb start, end;
int tiempo = 0;

void iniciarReloj()
{	
	ftime(&start);
}

void detenerReloj()
{
	ftime(&end);
	
	tiempo = (int) (1000.0 * (end.time - start.time)
					+ (end.millitm - start.millitm));	
}


//FUNCIONES PILA
//************************************************************//
bool pilaVacia(NodoPila *pilita){
	return (pilita == NULL) ? true:false;
}

void vaciarPila(NodoPila *&inicio){
	
	while(inicio != NULL){
		
		NodoPila *aux = inicio;
		inicio = aux->siguiente;
		free(aux);
	}
	
}

int pedirDatosPila(){
	int dato;
	printf("Ingrese un dato\n");
	scanf("%d", &dato);
	return dato;
}

int imprimirDatosPila(NodoPila *pilita){
	int resultado = 0;
	NodoPila *aux = pilita;
	if(pilaVacia(pilita)){
		printf("La pila esta vacia\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux->dato);
			aux = aux->siguiente;
		}
		printf("\n");
	}
	
	return resultado;
}

int insertarDatosPila(NodoPila *&pilita, int n){
	
	int resultado = 0;
	NodoPila * nuevo_nodo = reservar_memoria_pila;
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pilita;
	pilita = nuevo_nodo;
	
	return resultado;
}

int generarDatosPila(NodoPila *&inicio, int cantDatos){
	
	int resultado = 0;
	int i, aleatorio;
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosPila(inicio, aleatorio);
	}
	
	return resultado;
}

int editarDatosPila(NodoPila *&pilita, int dato){
	int resultado = 0;
	NodoPila *aux = pilita;
	int contador = 0, nuevo_dato;
	if(pilaVacia(pilita)){
		printf("Pila vacia\n");
	}else{
		while(aux != NULL){
			if(aux->dato == dato){
				nuevo_dato = pedirDatosPila();
				contador += 1;
				aux->dato = nuevo_dato;
				break;
			}
			aux = aux->siguiente;
		}
		if(contador == 0){
			printf(":( lo siento no encontre el dato\n");
		}else{
			printf("iuuuuuju el dato fue editado\n");
			imprimirDatosPila(pilita);
		}
	}
	
	return resultado;
}
int eliminarDatosPila(NodoPila *&pilita){
	int resultado = 0;
	NodoPila *aux = pilita;
	if(pilaVacia(pilita)){
		printf("Pila vacia\n");
	}else{
		pilita = aux->siguiente;
		free(aux);
	}
	
	return resultado;
}

int eliminarPila(NodoPila *&pilita){
	
	int resultado = 0;
	if(pilaVacia(pilita)){
		printf("Pila vacia\n");
	}else{
		while(pilita != NULL){
			NodoPila *aux = pilita;
			pilita = aux->siguiente;
			free(aux);
		}
	}
	
	return resultado;
}

int buscarDatosPila(NodoPila *pilita, int dato){
	int resultado = 0;
	NodoPila *aux = pilita;
	int contador = 0;
	if(pilaVacia(pilita)){
		printf("Pila vacia\n");
	}else{
		while(aux != NULL){
			if(aux->dato == dato){
				contador += 1;
				break;
			}
			aux = aux->siguiente;
		}
		if(contador == 0){
			printf(":( lo siento no encontre el dato\n");
		}else{
			printf("iuuuuuju el dato fue encontrado\n");
		}
	}
	
	return resultado;
}
//FUNCIONES DE COLA
//*****************************************************************//

//funcion para dividir el array y hacer los intercambios
int dividir(int *array, int inicio, int fin)
{
	int izq;
	int der;
	int pivote;
	int temp;
	
	pivote = array[inicio];
	izq = inicio;
	der = fin;
	
	//Mientras no se cruzen los Ã­ndices
	while (izq < der){
		while (array[der] > pivote){
			der--;
		}
		
		while ((izq < der) && (array[izq] <= pivote)){
			izq++;
		}
		
		// Si todavia no se cruzan los indices seguimos intercambiando
		if(izq < der){
			temp= array[izq];
			array[izq] = array[der];
			array[der] = temp;
		}
	}
	
	//Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
	temp = array[der];
	array[der] = array[inicio];
	array[inicio] = temp;
	
	//La nueva posiciÃ³n del pivote
	return der;
}

//      Funcion Quicksort
//======================================================================
//funcion recursiva para hacer el ordenamiento
void quicksort(int *array, int inicio, int fin)
{
	int pivote;
	if(inicio < fin)
	{
		pivote = dividir(array, inicio, fin );
		quicksort( array, inicio, pivote - 1 );//ordeno la lista de los menores
		quicksort( array, pivote + 1, fin );//ordeno la lista de los mayores
	}
}


bool colaVacia(NodoCola *inicio){
	return (inicio == NULL) ? true:false;
}

void vaciarCola(NodoCola *&inicio, NodoCola *&fin){
	
	while(inicio != NULL){
		
		NodoCola *aux = inicio;
		inicio = aux->siguiente;
		free(aux);
	}
	
	fin = NULL;
}

int insertarDatosCola(int n, NodoCola *&inicio, NodoCola *&fin){
	int resultado = 0;
	
	NodoCola * nuevo_nodo = reservar_memoria_cola;
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo_nodo;
	}else{
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	
	return resultado;
}

int generarDatosCola(NodoCola *&inicio, NodoCola *&fin, int cantDatos){
	
	int resultado = 0;
	int i, aleatorio;
	
	for(i = 1; i <= cantDatos; i++){
		aleatorio = (rand() % (1999999 + 1)- 1000000);
		insertarDatosCola(aleatorio, inicio, fin);
	}
	
	return resultado;
}


int imprimirDatosCola(NodoCola *&inicio){
	
	int resultado = 0;
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			printf("%d ", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	return resultado;
}

//CODIGO DE PILA//
//************************************************************//
int generar1MillonPila(NodoPila *&inicio)
{
	int cantDatos = 1000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosPila(inicio, cantDatos);
	detenerReloj();
	 
	return resultado;
}

int generar2MillonesPila(NodoPila *&inicio)
{
	int cantDatos = 2000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosPila(inicio, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar5MillonesPila(NodoPila *&inicio)
{
	int cantDatos = 5000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosPila(inicio, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar10MillonesPila(NodoPila *&inicio)
{
	int cantDatos = 10000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosPila(inicio, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar20MillonesPila(NodoPila *&inicio)
{
	int cantDatos = 20000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosPila(inicio, cantDatos);
	detenerReloj();
	
	return resultado;
}

//** MENU GENERAR DATOS PILA**//
int generarDatosPila(NodoPila *&inicio)
{
	int resultado = 0;
	
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				vaciarPila(inicio);
				
				resultado = generar1MillonPila(inicio);
				
				
				break;
			}          
			case 2: 
			{
				vaciarPila(inicio);
				resultado = generar2MillonesPila(inicio);
				
				break;
			}        
			
			case 3: 
			{
				vaciarPila(inicio);
				resultado = generar5MillonesPila(inicio);
				
				break;
			}        
			
			
			case 4: 
			{
				vaciarPila(inicio);
				resultado = generar10MillonesPila(inicio);
				
				break;
			}        
			
			
			case 5: 
			{
				vaciarPila(inicio);
				resultado = generar20MillonesPila(inicio);
				
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	
	return resultado;
}


//***********************************************************////
int leer1MillonPila()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoPila *inicio = NULL;
	
	iniciarReloj();
	archivo = fopen("un_millonPila.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosPila(inicio,dato); 
	}
	detenerReloj();
	
	imprimirDatosPila(inicio);
	
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarPila(inicio);
	
	return resultado;
}

int leer2MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoPila *inicio = NULL;
	
	iniciarReloj();
	archivo = fopen("dos_millonesPila.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosPila(inicio,dato); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarPila(inicio);
	
	return resultado;
}

int leer5MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoPila *inicio = NULL;
	
	iniciarReloj();
	archivo = fopen("cinco_millonesPila.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosPila(inicio,dato); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarPila(inicio);
	
	return resultado;
}

int leer10MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoPila *inicio = NULL;
	
	iniciarReloj();
	archivo = fopen("diez_millonesPila.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosPila(inicio,dato); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarPila(inicio);
	
	return resultado;
}

int leer20MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoPila *inicio = NULL;
	
	iniciarReloj();
	archivo = fopen("veinte_millonesPila.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosPila(inicio,dato); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarPila(inicio);
	
	return resultado;
}

//MENU PARA LEER ARCHIVO

int leerArchivoPila()
{
	int resultado = 0;
	
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = leer1MillonPila();
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = leer2MillonesPila();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = leer5MillonesPila();
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = leer10MillonesPila();
				
				break;
			}        
			
			
			case 5: 
			{
				
				resultado = leer20MillonesPila();
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return resultado;
}
//***********************************************************///
int escribir1MillonPila()
{
	int resultado = 0;
	FILE *archivo;
	NodoPila * inicio = NULL;
	
	int cantDatos = 1000000;
	
	iniciarReloj();
	archivo = fopen("un_millonPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("un_millonPila.txt ", "w+t");
	}
	
	resultado = generarDatosPila(inicio, cantDatos);
	
	NodoPila * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	rewind(archivo);
	fclose(archivo);
	
	detenerReloj();
	// Eliminando la pila pues ya no la necesito
	vaciarPila(inicio);
	return resultado;
}

int escribir2MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	NodoPila * inicio = NULL;
	
	int cantDatos = 2000000;
	
	iniciarReloj();
	archivo = fopen("dos_millonesPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("dos_millonesPila.txt ", "w+t");
	}
	
	resultado = generarDatosPila(inicio, cantDatos);
	
	NodoPila * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	rewind(archivo);
	fclose(archivo);
	
	detenerReloj();
	// Eliminando la pila pues ya no la necesito
	vaciarPila(inicio);
	return resultado;
}

int escribir5MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	NodoPila * inicio = NULL;
	
	int cantDatos = 5000000;
	
	iniciarReloj();
	archivo = fopen("cinco_millonesPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("cinco_millonesPila.txt ", "w+t");
	}
	
	resultado = generarDatosPila(inicio, cantDatos);
	
	NodoPila * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	rewind(archivo);
	fclose(archivo);
	
	detenerReloj();
	// Eliminando la pila pues ya no la necesito
	vaciarPila(inicio);
	return resultado;
}

int escribir10MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	NodoPila * inicio = NULL;
	
	int cantDatos = 10000000;
	
	iniciarReloj();
	archivo = fopen("diez_millonesPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("diez_millonesPila.txt ", "w+t");
	}
	
	resultado = generarDatosPila(inicio, cantDatos);
	
	NodoPila * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la pila pues ya no la necesito
	vaciarPila(inicio);
	return resultado;
}

int escribir20MillonesPila()
{
	int resultado = 0;
	FILE *archivo;
	NodoPila * inicio = NULL;
	
	int cantDatos = 20000000;
	
	iniciarReloj();
	archivo = fopen("veinte_millonesPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("veinte_millonesPila.txt ", "w+t");
	}
	
	resultado = generarDatosPila(inicio, cantDatos);
	
	NodoPila * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la pila pues ya no la necesito
	vaciarPila(inicio);
	return resultado;
}

//MENU ESCRIBIR ARCHIVOS

int escribirArchivoPila()
{
	int resultado = 0;
	
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = escribir1MillonPila();
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = escribir2MillonesPila();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = escribir5MillonesPila();
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = escribir10MillonesPila();
				
				break;
			}        
			
			
			case 5: 
			{
				
				resultado = escribir20MillonesPila();
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return resultado;
}

//ORDENAMIENTO PILA
//******************************************************************//
int burbujaPila(NodoPila *&inicio)
{
	iniciarReloj();
	int resultado = 0;
	int aux;
	NodoPila * x = inicio;
	NodoPila * y = NULL;
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
	detenerReloj();
	
	return resultado;
}

void ordenarPorQuicksortPila(NodoPila *inicio)
{
	iniciarReloj();
	NodoPila *aux = inicio;
	// Creando un vector del tamano maximo de 20000000
	int *vector = (int*)malloc(sizeof(int) * 20000000);
	int tamanoCola = 0;
	while(aux != NULL)
	{
		vector[tamanoCola] = aux->dato;
		aux = aux->siguiente;
		tamanoCola++;
	}
	
	quicksort(vector, 0, tamanoCola - 1);
	
	// vuelvo a colocar los valores ya ordenados en la cola
	aux = inicio;
	for (int i = 0; i < tamanoCola; i++)
	{
		aux->dato = vector[i];
		aux = aux->siguiente;
	}
	
	free(vector);
	detenerReloj();
}
//**********************************************************///
int ordenamientoPila(NodoPila *&inicio)
{
	int resultado = 0;
	
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Metodo de Ordenamiento Directo:\n");
		printf("2.Metodo de Ordenamiento Rapido:\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				resultado = burbujaPila(inicio);
				
				
				break;
			}          
			
			case 2: 
			{
				ordenarPorQuicksortPila(inicio);
				
				break;
			}        
			
			default:{
				system("CLS");
				
				break;
			}          
		}
	}
	return resultado;
}
//*********************************************************///
int imprimirResultadoPila()
{
	int resultado = 0;
	
	printf("Duro %d milisegundos\n", tiempo);
	printf("Presione cualquier tecla para continuar\n");
	getch();
	return resultado;
}
//**********************************************************//

int busquedaSecuencialPila(NodoPila *&inicio)
{
	int resultado = 0;
	NodoPila *aux = inicio;
	int contador = 0;
	int n = 0;
	
	printf("ingrese un numero entre -999999 y 999999\n");
	scanf("%d",&n);
	
	iniciarReloj();
	if(pilaVacia(inicio)){
		printf("Pila vacia\n");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				contador += 1;
				break;
			}
			aux = aux->siguiente;
		}
		if(contador == 0){
			printf(":( lo siento no encontre el dato\n");
		}else{
			printf("iuuuuuju el dato fue encontrado\n");
		}
	}
	detenerReloj();
	
	return resultado;
}

int busquedaPila(NodoPila *&inicio)
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: Busqueda Secuencial\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = busquedaSecuencialPila(inicio);
				
				
				break;
			}          
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return resultado;
}
//************************************************************//
int guardarResultadosPila()
{
	int resultado = 0;
	FILE *archivo;
	
	archivo = fopen("resultadoPila.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("resultadoPila.txt ", "w+t");//w+t leer texto legible
	}	
	
	fprintf(archivo,"Duro %d milisegundos", tiempo);
	
	rewind(archivo);
	fclose(archivo);
	return resultado;
}
//************************************************************//

int menuPila(NodoPila *&inicio)
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: Generar Datos Pila\n");
		printf("2.: Leer desde un archivo Pila\n");
		printf("3.: Escribir en un archivo\n");
		printf("4.: Ordenamiento(2 metodos)\n");
		printf("5.: Imprimir Resultados\n");
		printf("6.: Busqueda\n");
		printf("7.: Guardar Resultados\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				resultado = generarDatosPila(inicio);
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = leerArchivoPila();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = escribirArchivoPila();		
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = ordenamientoPila(inicio);
				
				break;
			}        
			
			
			case 5: 
			{
				
				resultado = imprimirResultadoPila();
				
				break;
			}        
			
			
			case 6: 
			{
				
				resultado = busquedaPila(inicio);
				
				break;
			}        
			
			
			case 7: 
			{
				
				resultado = guardarResultadosPila();
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return resultado;
}

//**************************************************************///
//CODIGO COLA//

int generar1MillonCola(NodoCola *&inicio, NodoCola *&fin)
{
	int cantDatos = 1000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosCola(inicio, fin, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar2MillonesCola(NodoCola *&inicio, NodoCola *&fin)
{
	int cantDatos = 2000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosCola(inicio, fin, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar5MillonesCola(NodoCola *&inicio, NodoCola *&fin)
{
	int cantDatos = 5000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosCola(inicio, fin, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar10MillonesCola(NodoCola *&inicio, NodoCola *&fin)
{
	int cantDatos = 10000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosCola(inicio, fin, cantDatos);
	detenerReloj();
	
	return resultado;
}

int generar20MillonesCola(NodoCola *&inicio, NodoCola *&fin)
{
	int cantDatos = 20000000;
	int resultado = 0;
	
	iniciarReloj();
	resultado = generarDatosCola(inicio, fin, cantDatos);
	detenerReloj();
	
	return resultado;
}
//**MENU DE GENERAR DATOS COLA**//

int mostrarMenuGenerarDatosCola(NodoCola *&inicio, NodoCola *&fin)
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		
		
		switch(opcion)
		{
			case 1: 
			{
				vaciarCola(inicio, fin);
				resultado = generar1MillonCola(inicio, fin);
				
				
				break;
			}          
			case 2: 
			{
				vaciarCola(inicio, fin);
				resultado = generar2MillonesCola(inicio, fin);
				
				break;
			}        
			
			case 3: 
			{
				vaciarCola(inicio, fin);
				resultado = generar5MillonesCola(inicio, fin);
				
				break;
			}        
			
			case 4: 
			{
				vaciarCola(inicio, fin);
				resultado = generar10MillonesCola(inicio, fin);
				
				break;
			}        
			
			
			case 5: 
			{
				vaciarCola(inicio, fin);
				resultado = generar20MillonesCola(inicio, fin);
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	return resultado;
}
//*****************************************************************//
int leer1MillonCola()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoCola *inicio = NULL;
	NodoCola *fin = NULL;
	
	iniciarReloj();
	archivo = fopen("un_millonCola.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosCola(dato, inicio, fin); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarCola(inicio, fin);
	
	return resultado;
}

int leer2MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoCola *inicio = NULL;
	NodoCola *fin = NULL;
	
	iniciarReloj();
	archivo = fopen("dos_millonesCola.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosCola(dato, inicio, fin); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarCola(inicio, fin);
	return resultado;
}

int leer5MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoCola *inicio = NULL;
	NodoCola *fin = NULL;
	
	iniciarReloj();
	archivo = fopen("cinco_millonesCola.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosCola(dato, inicio, fin); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarCola(inicio, fin);
	return resultado;
}

int leer10MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoCola *inicio = NULL;
	NodoCola *fin = NULL;
	
	iniciarReloj();
	archivo = fopen("diez_millonesCola.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosCola(dato, inicio, fin); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarCola(inicio, fin);
	return resultado;
}

int leer20MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	int dato = 0;
	NodoCola *inicio = NULL;
	NodoCola *fin = NULL;
	
	iniciarReloj();
	archivo = fopen("veinte_millonesCola.txt", "rt"); //proceso para visualizar
	rewind(archivo);
	
	// Leyendo número por número insertado en el archivo
	while (EOF != fscanf(archivo,"%d\n", &dato))
	{
		// Guardándolo en la cola temporal
		resultado = insertarDatosCola(dato, inicio, fin); 
	}
	detenerReloj();
	// Cuando ya no se ocupa la cola entoncse la borro
	vaciarCola(inicio, fin);
	return resultado;
}

//MENU PARA LEER ARCHIVO COLA

int leerArchivoCola()
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = leer1MillonCola();
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = leer2MillonesCola();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = leer5MillonesCola();
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = leer10MillonesCola();
				
				break;
			}        
			
			
			case 5: 
			{
				
				resultado = leer20MillonesCola();
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	return resultado;
}

//****************************************************************//
int escribir1MillonCola()
{
	int resultado = 0;
	FILE *archivo;
	NodoCola * inicio = NULL;
	NodoCola * fin = NULL;
	int cantDatos = 1000000;
	
	archivo = fopen("un_millonCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("un_millonCola.txt ", "w+t");
	}
	
	resultado = generarDatosCola(inicio, fin, cantDatos);
	
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	
	// Eliminando la cola pues ya no la necesito
	vaciarCola(inicio, fin);
	return resultado;
}

int escribir2MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	NodoCola * inicio = NULL;
	NodoCola * fin = NULL;
	int cantDatos = 2000000;
	
	iniciarReloj();
	archivo = fopen("dos_millonesCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("dos_millonesCola.txt ", "w+t");
	}
	
	resultado = generarDatosCola(inicio, fin, cantDatos);
	
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la cola pues ya no la necesito
	vaciarCola(inicio, fin);
	return resultado;
}

int escribir5MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	NodoCola * inicio = NULL;
	NodoCola * fin = NULL;
	int cantDatos = 5000000;
	
	iniciarReloj();
	archivo = fopen("cinco_millonesCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("cinco_millonesCola.txt ", "w+t");
	}
	
	resultado = generarDatosCola(inicio, fin, cantDatos);
	
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la cola pues ya no la necesito
	vaciarCola(inicio, fin);
	return resultado;
}

int escribir10MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	NodoCola * inicio = NULL;
	NodoCola * fin = NULL;
	int cantDatos = 10000000;
	
	iniciarReloj();
	archivo = fopen("diez_millonesCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("diez_millonesCola.txt ", "w+t");
	}
	
	resultado = generarDatosCola(inicio, fin, cantDatos);
	
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la cola pues ya no la necesito
	vaciarCola(inicio, fin);
	return resultado;
}

int escribir20MillonesCola()
{
	int resultado = 0;
	FILE *archivo;
	NodoCola * inicio = NULL;
	NodoCola * fin = NULL;
	int cantDatos = 20000000;
	
	iniciarReloj();
	archivo = fopen("veinte_millonesCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("veinte_millonesCola.txt ", "w+t");
	}
	
	resultado = generarDatosCola(inicio, fin, cantDatos);
	
	NodoCola * aux = inicio;
	if(inicio == NULL){
		printf("Esta vacio\n");
	}else{
		while(aux != NULL){
			fprintf(archivo,"%d\n", aux -> dato);
			aux = aux -> siguiente;
		}
	}
	
	rewind(archivo);
	fclose(archivo);
	detenerReloj();
	// Eliminando la cola pues ya no la necesito
	vaciarCola(inicio, fin);
	return resultado;
}

//MENU ESCRIBIR ARCHIVOS
int escribirArchivoCola()
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.: 1 Millon\n");
		printf("2.: 2 Millones\n");
		printf("3.: 5 Millones\n");
		printf("4.: 10 Millones\n");
		printf("5.: 20 Millones\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = escribir1MillonCola();
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = escribir2MillonesCola();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = escribir5MillonesCola();
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = escribir10MillonesCola();
				
				break;
			}        
			
			
			case 5: 
			{
				
				resultado = escribir20MillonesCola();
				
				break;
			}        
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
	}
	
	return resultado;
}
//ORDENAMIENTO COLA 
//******************************************************************//
int burbujaCola(NodoCola *&inicio)
{
	iniciarReloj();
	int resultado = 0;
	int aux;
	NodoCola * x = inicio;
	NodoCola * y = NULL;
	if(inicio == NULL){
		printf("Me la gane suave\n");
	}else{
		while(x != NULL){
			y = x -> siguiente;
			while(y != NULL){
				if(x -> dato > y -> dato){
					aux = x -> dato;
					x -> dato = y -> dato;
					y -> dato = aux;
				}
				y = y -> siguiente;
			}
			x = x -> siguiente;
		}
	}
	detenerReloj();
	
	return resultado;
}

void ordenarPorQuicksortCola(NodoCola *&inicio)
{
	iniciarReloj();
	NodoCola *aux = inicio;
	// Creando un vector del tamano maximo de 20000000
	int *vector = (int*)malloc(sizeof(int)*20000000);
	int tamanoCola = 0;
	while(aux != NULL)
	{
		vector[tamanoCola] = aux->dato;
		aux = aux->siguiente;
		tamanoCola++;
	}
	
	quicksort(vector, 0, tamanoCola - 1);
	
	// vuelvo a colocar los valores ya ordenados en la cola
	aux = inicio;
	for (int i = 0; i < tamanoCola; i++)
	{
		aux->dato = vector[i];
		aux = aux->siguiente;
	}
	
	free(vector);
	detenerReloj();
}
//******************************************************************//
int ordenamientoCola(NodoCola *&inicio)
{
	int resultado = 0;
	
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Metodo de Ordenamiento Directo:\n");
		printf("2.Metodo de Ordenamiento Rapido:\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				resultado = burbujaCola(inicio);
				
				
				break;
			}          
			
			case 2: 
			{
				ordenarPorQuicksortCola(inicio);
				
				break;
			}        
			
			default:{
				system("CLS");
				
				break;
			}          
		}
	}
	return resultado;
}
//*******************************************************************//
int imprimirResultadoCola()
{
	int resultado = 0;
	
	printf("Duro %d milisegundos\n", tiempo);
	printf("Presione cualquier tecla para continuar\n");
	getch();
	return resultado;
}
//******************************************************************/
int busquedaSecuencialCola(NodoCola *&inicio)
{
	int resultado = 0;
	NodoCola *aux = inicio;
	int contador = 0;
	int n = 0;
	
	printf("ingrese un numero entre -999999 y 999999\n");
	scanf("%d",&n);
	
	iniciarReloj();
	if(colaVacia(inicio)){
		printf("Cola vacia\n");
	}else{
		while(aux != NULL){
			if(aux->dato == n){
				contador += 1;
				break;
			}
			aux = aux->siguiente;
		}
		if(contador == 0){
			printf(":( lo siento no encontre el dato\n");
		}else{
			printf("iuuuuuju el dato fue encontrado\n");
		}
	}
	detenerReloj();
	
	return resultado;
}

int busquedaCola(NodoCola *&inicio)
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Busqueda Secuencial:\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				resultado = busquedaSecuencialCola(inicio);
				
				getch();
				break;
			}          
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	
	return resultado;
}

//*****************************************************************//
int guardarResultadosCola()
{
	int resultado = 0;
	FILE *archivo;
	
	archivo = fopen("resultadoCola.txt ", "wt"); //PROCESO PARA GUARDAR
	
	if (archivo == NULL) {
		archivo = fopen("resultadoCola.txt ", "w+t");
	}	
	
	fprintf(archivo,"Duro %d milisegundos", tiempo);
	
	rewind(archivo);
	fclose(archivo);
	return resultado;
}

int menuCola(NodoCola *&inicio, NodoCola *&fin)
{
	int resultado = 0;
	int opcion=1;
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Generar Datos cola:\n");
		printf("2.Leer desde un archivo cola:\n");
		printf("3.Escribir en un archivo:\n");
		printf("4.Ordenamiento(2 metodos):\n");
		printf("5.Imprimir Resultados:\n");
		printf("6.Busqueda:\n");
		printf("7.Guardar Resultados:\n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = mostrarMenuGenerarDatosCola(inicio, fin);
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = leerArchivoCola();
				
				break;
			}        
			
			case 3: 
			{
				
				resultado = escribirArchivoCola();
				
				break;
			}        
			
			
			case 4: 
			{
				
				resultado = ordenamientoCola(inicio);
				
				break;
			}        
			
			
			case 5: 
			{
				resultado = imprimirResultadoCola();
				
				getch();
				
				break;
			}        
			
			
			case 6: 
			{
				
				resultado = busquedaCola(inicio);
				
				
				break;
			}        
			
			
			case 7: 
			{
				
				resultado = guardarResultadosCola();
				
				break;
			}       
			
			
			default:{
				system("CLS");
				
				break;
			}          
		}
		
	}
	
	
	return resultado;
}

int main (int argc, char *argv[]) 
{
	int resultado = 0;
	int opcion=1;
	NodoCola *inicioCola = NULL;
	NodoCola *finCola = NULL;
	NodoPila *inicioPila = NULL;
	srand(time(NULL));
	
	while(opcion!=0)
	{
		system("CLS");
		
		printf("----M E N U----\n");
		printf("1.Registro en Pila: \n");
		printf("2.Registro en Cola: \n");
		printf("0.Salir \n");
		printf("Seleccione Opcion: "); 
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1: 
			{
				
				resultado = menuPila(inicioPila);
				
				
				break;
			}          
			case 2: 
			{
				
				resultado = menuCola(inicioCola, finCola);
				
				break;
			}        
			
			default:{
				system("CLS");
				
				break;
			}          
		}
	}
	vaciarCola(inicioCola, finCola);
	vaciarPila(inicioPila);
	
	return resultado;
}

