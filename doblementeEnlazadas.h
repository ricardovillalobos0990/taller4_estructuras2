/* Se definen las funciones para las operaciones correspondientes en listas simples dobles enlazadas
*  Fecha 18/11/2017
*  Elaborado por: John Sebastian Nieto gil
*  Elaborado por: Ricardo Andres Villalobos
*/

#define RESERVAR_MEMORIA_DOBLE (NodoDoble *)malloc(sizeof(NodoDoble))

struct NodoDoble
{
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

void insertarElementoListaDoble(NodoDoble* &, NodoDoble* &);
void insertarElementoAlInicioDoble(NodoDoble* &, NodoDoble *&, NodoDoble* &);
void insertarElementoAlFinalDoble(NodoDoble* &, NodoDoble *&);
void insertarElementoDespuesDoble(NodoDoble* &, NodoDoble* &, NodoDoble *&);
void insertarElementoAntesDoble(NodoDoble* &, NodoDoble *&);
void mostrarElementosListaDoble(NodoDoble* , NodoDoble* );
void BuscarElementosListaDoble(NodoDoble* );
void eliminarElementoListaDoble(NodoDoble* &, NodoDoble* &, int);
void eliminarEstructuraDoble(NodoDoble* &);
void editarElementoListaDoble(NodoDoble* &, NodoDoble* &, int);
void insertarElementoListaOrdenadaDoble(int, NodoDoble* &, NodoDoble* &);

/**
 * Insertar un nuevo nodo donde lo requiera el usuario
 */
void insertarElementoListaDoble(NodoDoble* &lista, NodoDoble* &listaFin)
{
	short opcion = 0;
	int dato = 0;

	NodoDoble* nuevoNodo = RESERVAR_MEMORIA_DOBLE;

	dato = pedirDato();

	nuevoNodo->dato = dato;

	printf("\nOpcion:");
	printf("\n1. Al principio de la lista");
	printf("\n2. Al final de la lista");
	printf("\n3. Despues de un numero dado");
	printf("\n4. Antes de un numero dado");
	printf("\nEscoger opcion: ");
	scanf("%d", &opcion);

	if(lista == NULL) //Si la lista está vacía
	{
		lista = nuevoNodo;
		nuevoNodo->siguiente = NULL;
		nuevoNodo->anterior = NULL;
		listaFin = nuevoNodo;
		printf("\nLista vacia, elemento insertado al inicio de la lista");
	}
	else
	{
		switch(opcion)
		{
			case 1:
				insertarElementoAlInicioDoble(lista, listaFin, nuevoNodo);
				break;
			case 2:
				insertarElementoAlFinalDoble(listaFin, nuevoNodo);
				break;
			case 3:
				insertarElementoDespuesDoble(lista, listaFin, nuevoNodo);
				break;
			case 4:
				insertarElementoAntesDoble(lista, nuevoNodo);
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
void insertarElementoAlInicioDoble(NodoDoble* &lista, NodoDoble* &listaFin, NodoDoble *&nuevoNodo)
{
	nuevoNodo->siguiente = lista;
	lista->anterior = nuevoNodo;
	nuevoNodo->anterior = NULL;
	lista = nuevoNodo;
}

/**
 * Insertar el nodo siempre al final de la lista
 */
void insertarElementoAlFinalDoble(NodoDoble* &listaFin, NodoDoble *&nuevoNodo)
{
	nuevoNodo->siguiente = NULL;
	nuevoNodo->anterior = listaFin;
	listaFin->siguiente = nuevoNodo;
	listaFin = nuevoNodo;

}

/**
 * Insertar el nuevo nodo después de uno que haya elegido el usuario
 */
void insertarElementoDespuesDoble(NodoDoble* &lista, NodoDoble* &listaFin, NodoDoble *&nuevoNodo)
{
	int numero = 0;
	NodoDoble* auxCopia = lista;

	printf("\n Ingresar el numero del cual desea colocar despues el nuevo numero: ");
	scanf("%d", &numero);

	while(auxCopia != NULL)
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia->siguiente;
			nuevoNodo->anterior = auxCopia;
			if(nuevoNodo->siguiente == NULL) //Comprueba si el elemento escogido es el último
			{
                listaFin = nuevoNodo;
			}
			else
			{
				auxCopia->siguiente->anterior = nuevoNodo;
			}
			auxCopia->siguiente = nuevoNodo;
			break;
		}
		auxCopia = auxCopia->siguiente;
	}
}

/**
 * Insertar el nuevo nodo antes de uno que haya elegido el usuario
 */
void insertarElementoAntesDoble(NodoDoble* &lista, NodoDoble *&nuevoNodo)
{
	NodoDoble* auxCopia = lista;
	int numero = 0;

	printf("\n Ingresar el numero del cual desea colocar antes el nuevo numero: ");
	scanf("%d", &numero);

	while(auxCopia != NULL)
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia;

			if(auxCopia->anterior == NULL) //Comprueba si el elemento escogido es el primero de la lista
			{
				lista = nuevoNodo;
				nuevoNodo->anterior = NULL;
			}
			else
			{
				nuevoNodo->anterior = auxCopia->anterior;
				auxCopia->anterior->siguiente = nuevoNodo;
			}
			auxCopia->anterior = nuevoNodo;
			break;
		}
		auxCopia = auxCopia->siguiente;
	}
}

/**
 * Visualiza todos los elementos de la lista, puede ser de atrás hacia adelante o viceversa
 */
void mostrarElementosListaDoble(NodoDoble* lista, NodoDoble* listaFin)
{
    NodoDoble* aux = lista;
    int numero = 0;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
        printf("\n1.Mostrar del principio al final");
        printf("\n2.Mostrar del final al principio");
        printf("\nEscoger opcion: ");
        getchar();
        scanf("%d", &numero);
        if(numero != 1)
        {
            aux = listaFin;
        }
		while(aux != NULL)
		{
			printf("\n%d", aux->dato);

			if(numero == 1)
			{
				aux = aux->siguiente;
			}
			else
			{
				aux = aux->anterior;
			}

		}
	}
}

/**
 * Muestras todos los datos que coincidan con el escogido por el usuario
 */
void buscarElementosListaDoble(NodoDoble* lista)
{
	NodoDoble* aux = lista;
	int numero = 0;
	int i = 0;
	int contador = 0;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
		printf("\nIngrese el numero a buscar: ");
		scanf("%d", &numero);
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
	}
}

/**
 * Elimina un elemento de la lista, el que el usuario haya elegido
 */
void eliminarElementoListaDoble(NodoDoble* &lista, NodoDoble* &listaFin,int numero)
{
	NodoDoble* aux = lista;
	int contador = 0;

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
                contador++;

				if(aux == lista)
				{
					lista = aux->siguiente;
					if(aux->siguiente != NULL) //comprueba que el elemento no sea el último de la lista
					{
						aux->siguiente->anterior = NULL;
					}
					
				}
				else
				{
					aux->anterior->siguiente = aux->siguiente;
					listaFin = aux->anterior;
				}
				free(aux);
				break;
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
 * Eliminar la lista completa
 */
void eliminarEstructuraDoble(NodoDoble* &lista, NodoDoble* &listaFin)
{
	NodoDoble* aux = lista;
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
void editarElementoListaDoble(NodoDoble* &lista, NodoDoble* &listaFin, int ordenada)
{
	NodoDoble* aux = lista;

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
					if(ordenada == 1)
					{
						eliminarElementoListaDoble(lista, listaFin, numero);
						insertarElementoListaOrdenadaDoble(nuevoDato, lista, listaFin);
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
void insertarElementoListaOrdenadaDoble(int dato, NodoDoble* &lista, NodoDoble* &listaFin)
{
	NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
	nuevo->dato = dato;

	NodoDoble* aux = lista;
	NodoDoble* aux2 = NULL;

	if(aux == NULL)
	{
		lista = nuevo;
		listaFin = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = NULL;
	}
	else
	{
		while((aux != NULL) && (aux->dato < dato))
		{
			aux = aux->siguiente;
		}

		if(aux == lista) // Si el elemento se debe insertar al inicio de la lista
		{
			nuevo->siguiente = lista;
			nuevo->anterior = NULL;
			aux->anterior = nuevo;
			lista = nuevo;

		}
		else
		{
			if(aux == NULL) // Si el elemento se debe insertar al final de la lista
			{
				nuevo->anterior = listaFin;
                listaFin->siguiente = nuevo;
				nuevo->siguiente = NULL;
				listaFin = nuevo;
			}
			else // el elemento se debe insertar en el medio de dos
			{
				nuevo->siguiente = aux;
				nuevo->anterior = aux->anterior;
				aux->anterior->siguiente = nuevo;
				aux->anterior = nuevo;
			}
		}
	}
}
