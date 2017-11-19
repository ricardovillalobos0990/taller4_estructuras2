/* Se definen las funciones para las operaciones correspondientes en listas circulares doblemente enlazadas
*  Fecha 18/11/2017
*  Elaborado por: John Sebastian Nieto gil
*  Elaborado por: Ricardo Andres Villalobos
*/


void insertarElementoListaDobleCircular(NodoDoble* &);
void insertarElementoAlInicioDobleCircular(NodoDoble* &, NodoDoble *&);
void insertarElementoAlFinalDobleCircular(NodoDoble* &, NodoDoble *&);
void insertarElementoDespuesDobleCircular(NodoDoble* &, NodoDoble *&);
void insertarElementoAntesDobleCircular(NodoDoble* &, NodoDoble* &);
void mostrarElementosListaDobleCircular(NodoDoble*);
void buscarElementosListaDobleCircular(NodoDoble*);
void eliminarElementoListaDobleCircular(NodoDoble*  &, int);
void eliminarEstructuraCircular(NodoDoble* &);
void editarElementoListaDobleCircular(NodoDoble* &, int);
void insertarElementoListaOrdenadaDobleCircular(int, NodoDoble* &);

/**
 * Insertar un nuevo nodo donde lo requiera el usuario
 */
void insertarElementoListaDobleCircular(NodoDoble* &lista)
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

	if(lista == NULL)
	{
		lista = nuevoNodo;
		nuevoNodo->siguiente = nuevoNodo;
		nuevoNodo->anterior = nuevoNodo;
		printf("\nLista vacia, elemento insertado al inicio de la lista");
	}
	else
	{
		switch(opcion)
		{
			case 1:
				insertarElementoAlInicioDobleCircular(lista, nuevoNodo);
				break;
			case 2:
				insertarElementoAlFinalDobleCircular(lista, nuevoNodo);
				break;
			case 3:
				insertarElementoDespuesDobleCircular(lista, nuevoNodo);
				break;
			case 4:
				insertarElementoAntesDobleCircular(lista, nuevoNodo);
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
void insertarElementoAlInicioDobleCircular(NodoDoble* &lista, NodoDoble *&nuevoNodo)
{
	nuevoNodo->siguiente = lista;
	lista->anterior = nuevoNodo;
	nuevoNodo->anterior = lista->anterior;
	lista->anterior->siguiente = nuevoNodo;
	lista = nuevoNodo;
}

/**
 * Insertar el nodo siempre al final de la lista
 */
void insertarElementoAlFinalDobleCircular(NodoDoble* &lista, NodoDoble *&nuevoNodo)
{
	nuevoNodo->siguiente = lista;
	nuevoNodo->anterior = lista->anterior;
	lista->anterior->siguiente = nuevoNodo;
	lista->anterior = nuevoNodo;

}

/**
 * Insertar el nuevo nodo después de uno que haya elegido el usuario
 */
void insertarElementoDespuesDobleCircular(NodoDoble* &lista, NodoDoble *&nuevoNodo)
{
	int numero = 0;
	NodoDoble* auxCopia = lista;

	printf("\n Ingresar el numero del cual desea colocar despues el nuevo numero: ");
	scanf("%d", &numero);

	do
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia->siguiente;
			nuevoNodo->anterior = auxCopia;
			auxCopia->siguiente->anterior = nuevoNodo;
			auxCopia->siguiente = nuevoNodo;
			break;
		}
		auxCopia = auxCopia->siguiente;
	}
	while(auxCopia != lista);
}

/**
 * Insertar el nuevo nodo antes de uno que haya elegido el usuario
 */
void insertarElementoAntesDobleCircular(NodoDoble* &lista, NodoDoble *&nuevoNodo)
{
	NodoDoble* auxCopia = lista;
	int numero = 0;

	printf("\n Ingresar el numero del cual desea colocar antes el nuevo numero: ");
	scanf("%d", &numero);

	do
	{
		if(auxCopia->dato == numero)
		{
			nuevoNodo->siguiente = auxCopia;

			if(auxCopia->anterior == lista->anterior) //Comprueba si el elemento escogido es el primero de la lista
			{
				lista->anterior->siguiente = nuevoNodo;
				nuevoNodo->anterior = lista->anterior;
				lista = nuevoNodo;
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
	while(auxCopia != lista);
}

/**
 * Visualiza todos los elementos de la lista, puede ser de atrás hacia adelante o viceversa
 */
void mostrarElementosListaDobleCircular(NodoDoble* lista)
{
    NodoDoble* aux = lista;
    NodoDoble* condicion = lista;
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
            aux = lista->anterior;
            condicion = lista->anterior;
        }
		do
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

		}while(aux != condicion);
	}
}

/**
 * Muestras todos los datos que coincidan con el escogido por el usuario
 */
void buscarElementosListaDobleCircular(NodoDoble* lista)
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
		do
		{
            i++;
			if(aux->dato == numero)
			{
                contador++;
				printf("\nElemento encontrado direccion en memoria: %p, posicion: %d.", aux, i);
			}
			aux = aux->siguiente;
		}while(aux != lista);
	}

	if(contador == 0)
	{
		printf("\nElemento no encontrado");
	}
}

/**
 * Elimina un elemento de la lista, el que el usuario haya elegido
 */
void eliminarElementoListaDobleCircular(NodoDoble* &lista, int numero)
{
	NodoDoble* aux = lista;
	int contador = 0;
	int i = 0;

	if(aux == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{

		do
		{
			if(aux->dato == numero)
			{
                contador++;

				if(aux == lista) //comprueba si el elemento es el primero de la lista
				{
					aux->siguiente->anterior = lista->anterior;
					lista->anterior->siguiente = aux->siguiente;
					if(aux->siguiente == lista) //comprueba si el elemento es el único de la lista
					{
						lista = NULL;
					}
					else
					{
						lista = aux->siguiente;
					}
				}
				else
				{
					aux->anterior->siguiente = aux->siguiente;
					aux->siguiente->anterior = aux->anterior;
				}
				free(aux);
				break;
			}
			aux = aux->siguiente;
			i++;
		}while(aux != lista);
	}

	if(contador == 0)
	{
		printf("\nElemento no encontrado");
	}
}

/**
 * Eliminar la lista completa
 */
void eliminarEstructuraCircular(NodoDoble* &lista)
{
	NodoDoble* aux = lista;

	if(lista == NULL)
	{
		printf("\nLista Vacia");
	}
	else
	{
		do
		{
			aux = lista;
			aux->siguiente->anterior = lista->anterior; 
			lista->anterior->siguiente = aux->siguiente;
			lista = aux->siguiente;
			free(aux);
		}
		while(lista != aux);
		lista = NULL; //Reinica lista a NULL después de eliminar todos los elementos
	}
}

/**
 * Editar un elemento de la lista, el que el usuario elija
 * el parametro ordenada, es para comprobar si se va a editar una lista ordenada o no
 */
void editarElementoListaDobleCircular(NodoDoble* &lista, int ordenada)
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
		do
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
						eliminarElementoListaDobleCircular(lista, numero);
						insertarElementoListaOrdenadaDobleCircular(nuevoDato, lista);
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
		}while(aux != lista);
	}

	if(contador == 0)
	{
		printf("\nElemento no encontrado");
	}
}

/**
 * Insertar un nuevo nodo de forma ordenada en la lista
 */
void insertarElementoListaOrdenadaDobleCircular(int dato, NodoDoble* &lista)
{
	NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
	nuevo->dato = dato;

	NodoDoble* aux = lista;

	if(aux == NULL)
	{
		lista = nuevo;
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;
	}
	else
	{
		while((aux != lista->anterior) && (aux->dato < dato))
		{
			aux = aux->siguiente;
		}

		if(aux == lista) // Comprueba si solo hay un elemento en la lista
		{
			nuevo->siguiente = aux;
			nuevo->anterior = aux->anterior;
			aux->anterior->siguiente = nuevo;
			aux->anterior = nuevo;
			if(dato < aux->dato) // Comprueba si el nuevo dato debe ir antes
			{
				lista = nuevo;
			}

		}
		else
		{
			if((aux->siguiente == lista) && (aux->dato < dato)) //Si el elemento se debe insertar al final de la lista
			{
				nuevo->anterior = aux;
				nuevo->siguiente = aux->siguiente;
				aux->siguiente->anterior = nuevo;
                aux->siguiente = nuevo;
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

