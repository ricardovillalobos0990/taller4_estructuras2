/* Se definen las funciones para las operaciones correspondientes para el juego de josefo con listas 
* circulares simplemente enlazadas
*  Fecha 18/11/2017
*  Elaborado por: John Sebastian Nieto gil
*  Elaborado por: Ricardo Andres Villalobos
*/

/**
 * Insertar un nuevo nodo en una lista simple circular
 */
void insertarElementoListaCircular(Nodo* &lista, Nodo* &listaFin, int dato)
{
	Nodo* nuevoNodo = RESERVAR_MEMORIA;
	nuevoNodo->dato = dato;

	if(lista == NULL)
	{
		lista = nuevoNodo;
		nuevoNodo->siguiente = nuevoNodo;
	}
	else
	{
		listaFin->siguiente = nuevoNodo;
		nuevoNodo->siguiente = lista;
	}
	listaFin = nuevoNodo;
}

//Juego de josefo (va eliminando los nodos de una lista dependiendo el nuemero de salto, hasta que solo quede uno)
void josephus()
{
    int cantidad = 0;
    int saltos = 0; 
    int contador = 0;

    Nodo* lista = NULL;
    Nodo* listaFin = NULL;

	printf("\nIngrese la cantidad de jugadores: ");
	scanf("%d", &cantidad);

	printf("\nIngrese el numero de saltos: ");
	scanf("%d", &saltos);

	//Insertar la cantidad de jugadores
	for(int i = 1; i <= cantidad; i++)
	{
		insertarElementoListaCircular(lista, listaFin, i);
	}


	Nodo* aux = lista;
    Nodo* aux2 = NULL;

	while(aux != aux->siguiente)
	{
		for(int i = 0; i < saltos; i++)
		{
			aux2 = aux;
			aux = aux->siguiente;
		}
		aux2->siguiente = aux->siguiente;
		free(aux);
		aux = aux2;
	}
	printf("\nEl ganador es el jugador numero: %d", aux->dato);
	free(aux); //Se elimina el nodo ganador;
}
