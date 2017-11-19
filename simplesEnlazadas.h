/* Se definen las funciones para las operaciones correspondientes en listas simples enlazadas
*  Fecha 18/11/2017
*  Elaborado por: John Sebastian Nieto gil
*  Elaborado por: Ricardo Andres Villalobos
*/
#define RESERVAR_MEMORIA (Nodo *)malloc(sizeof(Nodo))

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

//Prototipo de las funciones
void insertarElementoLista(Nodo* &, Nodo* &);
void insertarElementoAlInicio(Nodo* &, Nodo *&);
void insertarElementoAlFinal(Nodo* &, Nodo *&);
void insertarElementoDespues(Nodo* &, Nodo* &, Nodo *&);
void insertarElementoAntes(Nodo* &, Nodo *&);
void mostrarElementosLista(Nodo* );
int BuscarElementosLista(Nodo* , int);
void eliminarElementoLista(Nodo* &, Nodo* &, int);
void eliminarEstructura(Nodo* &);
void editarElementoLista(Nodo* &, Nodo* &, int);
void insertarElementoListaOrdenada(int, Nodo* &);
void editarElementoListaOrdenada(Nodo* &);
int pedirDato();

/**
 * Insertar un nuevo nodo donde lo requiera el usuario
 */
void insertarElementoLista(Nodo* &lista, Nodo* &listaFin)
{
	int opcion = 0;
	int dato = 0;

	Nodo* nuevoNodo = RESERVAR_MEMORIA;

	dato = pedirDato();

	nuevoNodo->dato = dato;

	printf("\nOpcion:");
	printf("\n1. Al principio de la lista");
	printf("\n2. Al final de la lista");
	printf("\n3. Despues de un numero dado");
	printf("\n4. Antes de un numero dado");
	printf("\nEscoger opcion: ");
	scanf("%d", &opcion);


	if(lista == NULL)
	{
		lista = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		listaFin = nuevoNodo;
		printf("\nLista vacia, elemento insertado al inicio de la lista");
	}
	else
	{
		switch(opcion)
		{
			case 1:
				insertarElementoAlInicio(lista, nuevoNodo);
				break;
			case 2:
				insertarElementoAlFinal(listaFin, nuevoNodo);
				break;
			case 3:
				insertarElementoDespues(lista, listaFin, nuevoNodo);
				break;
			case 4:
				insertarElementoAntes(lista, nuevoNodo);
				break;

			default:
				printf("\nOpcion invalida");
				break;
		}
	}

}

/**
 * Insertar el nodo siempre al inicio de la lista
 */
void insertarElementoAlInicio(Nodo* &lista, Nodo *&nuevoNodo)
{
	nuevoNodo->siguiente = lista;
	lista = nuevoNodo;
}

/**
 * Insertar el nodo siempre al final de la lista
 */
void insertarElementoAlFinal(Nodo* &listaFin, Nodo *&nuevoNodo)
{
	listaFin->siguiente = nuevoNodo;
	nuevoNodo->siguiente = NULL;
	listaFin = nuevoNodo;
}

/**
 * Insertar el nuevo nodo después de uno que haya elegido el usuario
 */
void insertarElementoDespues(Nodo* &lista, Nodo* &listaFin, Nodo *&nuevoNodo)
{
	int numero = 0;
	Nodo* auxCopia = lista;

	printf("\n Ingresar el numero del cual desea colocar despues el nuevo numero: ");
	scanf("%d", &numero);

	while(auxCopia != NULL)
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia->siguiente;
			auxCopia->siguiente = nuevoNodo;

			if(nuevoNodo->siguiente == NULL) //Comprueba si el elemento escogido es el último
			{
                listaFin = nuevoNodo;
			}
			break;
		}
		auxCopia = auxCopia->siguiente;
	}
}

/**
 * Insertar el nuevo nodo antes de uno que haya elegido el usuario
 */
void insertarElementoAntes(Nodo* &lista, Nodo *&nuevoNodo)
{
	Nodo* auxCopia = lista;
	Nodo* auxCopia2 = NULL;
	int numero = 0;

	printf("\n Ingresar el numero del cual desea colocar antes el nuevo numero: ");
	scanf("%d", &numero);

	while(auxCopia != NULL)
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia;

			if(auxCopia2 == NULL) //Comprueba si el elemento escogido es el primero de la lista
			{
				lista = nuevoNodo;
			}
			else
			{
				auxCopia2->siguiente = nuevoNodo;
			}
			break;
		}

		auxCopia2 = auxCopia;
		auxCopia = auxCopia->siguiente;
	}
}

/**
 * Visualiza todos los elementos de la lista
 */
void mostrarElementosLista(Nodo* lista)
{
	Nodo* aux = lista;
	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
		while(aux != NULL)
		{
			printf("\n%d", aux->dato);
			aux = aux->siguiente;
		}
	}
}

/**
 * Muestras todos los datos que coincidan con el escogido por el usuario
 */
int buscarElementosLista(Nodo* lista, int numero)
{
	Nodo* aux = lista;
	int i = 0;
	int contador = 0;
	int encontrado = 0;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
		while(aux != NULL)
		{
            i++;
			if(aux->dato == numero)
			{
                contador++;
				printf("\nElemento encontrado direccion en memoria: %p, posicion: %d.", aux, i);
			}
			aux = aux->siguiente;
		}
	}

	if(contador == 0)
	{
		printf("\nElemento no encontrado");
		encontrado = 0;
	}
	else
	{
		encontrado = 1;
	}

	return encontrado;
}

/**
 * Elimina un elemento de la lista, el que el usuario haya elegido
 */
void eliminarElementoLista(Nodo* &lista, Nodo* &listaFin, int numero)
{
	Nodo* aux = lista;
	Nodo* aux2 = NULL;

	int i = 0;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{

		while(aux != NULL)
		{
			if(aux->dato == numero)
			{
				i++;
				if(aux2 == NULL) //Si el elemento es el primero de la lista
				{
					lista = aux->siguiente;
				}
				else
				{
					aux2->siguiente = aux->siguiente;
					if(aux->siguiente == NULL)
					{
						listaFin = aux2;
					}
				}
				free(aux);
				break;
			}
			aux2 = aux;
			aux = aux->siguiente;
		}
	}

	if(i == 0)
	{
		printf("\nElemento no encontrado");
	}
}

/**
 * Eliminar la lista completa
 */
void eliminarEstructura(Nodo* &lista)
{
	Nodo* aux = lista;
	if(lista == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
		while(lista != NULL)
		{
			aux = lista;
			lista = aux->siguiente;
			free(aux);
		}
	}
}

/**
 * Editar un elemento de la lista, el que el usuario elija
 * el parametro ordenada, es para comprobar si se va a editar una lista ordenada o no
 */
void editarElementoLista(Nodo* &lista, Nodo* &listaFin, int ordenada)
{
	Nodo* aux = lista;

	int numero = 0;
	int i = 0;
	int nuevoDato = 0;
	int contador = 0;

	char comprobar;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}

	else
	{
		printf("\nIngrese el numero a editar: ");
		scanf("%d", &numero);
		while(aux != NULL)
		{
            i++;
			if(aux->dato == numero)
			{
			contador++;
				printf("\nElemento encontrado direccion en memoria: %p, posicion: %d.", &aux, i);
				printf("\nDesea editar este elemento. S / N: ");
				getchar();
				scanf("%c", &comprobar);
				if((comprobar == 's') || (comprobar == 'S'))
				{
					nuevoDato = pedirDato();
					if(ordenada == 1) //Si la lista es ordenada
					{
						eliminarElementoLista(lista, listaFin, numero);
						insertarElementoListaOrdenada(nuevoDato, lista);
					}
					else
					{
						aux->dato = nuevoDato;
					}
					
					printf("\n¿Desea buscar otra coincidencia?. S o N: ");
					getchar();
					scanf("%c", &comprobar);
					if(comprobar == 'n' || comprobar == 'N')
					{
						break;
					}
				}
			}
			aux = aux->siguiente;
		}
	}

	if(contador == 0)
	{
		printf("\nElemento no encontrado");
	}
}

/**
 * Insertar un nuevo nodo de forma ordenada en la lista
 */
void insertarElementoListaOrdenada(int dato, Nodo* &lista)
{
	Nodo* nuevoNodo = RESERVAR_MEMORIA;
	Nodo* aux1 = lista;
	Nodo* aux2 = NULL;

	nuevoNodo->dato = dato;

	while((aux1 != NULL) && (aux1->dato < dato))
	{
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}

	if(lista == aux1) // Si el elemento se debe insertat al inicio de la lista
	{
		lista = nuevoNodo;
	}
	else
	{
		aux2->siguiente = nuevoNodo;
	}

	nuevoNodo->siguiente = aux1;
}

/**
 * Ingresa un nuevo dato solicitado por teclado
 */

int pedirDato()
{
	int dato;

	printf("\nIngrese un dato: ");
	scanf("%d", &dato);

	return dato;
}

