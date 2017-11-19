/* Menu de opciones del programa
*  Fecha 18/11/2017
*  Elaborado por: John Sebastian Nieto gil
*  Elaborado por: Ricardo Andres Villalobos
*/
#define PAUSE getchar();printf("\nPresiona una tecla para continuar");getchar()

int menuEstructura();
int menuOrden();
void menu();

/**
 * Muestra un menu para las opciones correspondientes
 * de listas 
 */
void menu()
{

	Nodo * lista = NULL;
	Nodo * listaFin = NULL;
	NodoDoble* listaDoble = NULL;
	NodoDoble* listaFinDoble = NULL;

	int opcion = 0;
	int subOpcion = 0;
	int opcionEstructura = 0;
	int numero = 0;
	int ordenada = 0;
	char comprobar;

	do
	{
		system("clear");
		printf("\n\t---Menu principal--");
		printf("\n 1. Listas simplemente y doblemente enlazadas");
		printf("\n 2. Juego de josefo");
		printf("\n 3. Listas circulares doblemente enlazadas");
		printf("\n 0. Salir");
		printf("\n\nOpcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 0:
				printf("\nVuelve pronto...\n");
				exit(0);
				break;
			case 1:
				do
				{
					system("clear");
					printf("\n\t---Menu Listas-");
					printf("\n 1. Listas simplemente enlazadas");
					printf("\n 2. Listas doblemente enlazadas");
					printf("\n 0. Salir");
					printf("\n\nOpcion: ");
					scanf("%d", &subOpcion);

					switch(subOpcion)
					{
						case 0:
							eliminarEstructura(lista);
							break;

						case 1:
							do
							{
								system("clear");
								printf("\nListas simplemente enlazadas\n");
								ordenada = menuOrden();

								if(ordenada == 0)
								{
									break;
								}

								do
								{

									opcionEstructura = menuEstructura();

									switch(opcionEstructura)
									{
										case 0:
											eliminarEstructura(lista);
											break;

										case 1:
											if(ordenada == 1)
											{
												numero = pedirDato();
												insertarElementoListaOrdenada(numero, lista);
												
											}
											else
											{
												insertarElementoLista(lista, listaFin);
											}
											
											PAUSE;
											break;

										case 2:
											mostrarElementosLista(lista);
											PAUSE;
											break;

										case 3:
											numero = pedirDato();
											buscarElementosLista(lista, numero);
											PAUSE;
											break;

										case 4:
											numero = pedirDato();
											eliminarElementoLista(lista, numero);
										    PAUSE;
											break;

										case 5:
											printf("\nDesea eliminar toda la estructura? S / N: ");
											getchar();
											scanf("%c", &comprobar);
											if(comprobar == 's' || comprobar == 'S')
											{
												eliminarEstructura(lista);
											}
										    PAUSE;
											break;;

										case 6:
											editarElementoLista(lista, ordenada);
										    PAUSE;
											break;

										default:
										    printf("\nNo es una opcion valida");
										    PAUSE;
										    break;
									}
								}
								while(opcionEstructura != 0);
							}
							while(ordenada != 0);
							break;

                        case 2:
                        	do
							{
								system("clear");
								printf("\nListas doblemente enlazadas\n");
								ordenada = menuOrden();

								if(ordenada == 0)
								{
									break;
								}

								do
								{
									opcionEstructura = menuEstructura();

									switch(opcionEstructura)
									{
										case 0:
	                                        eliminarEstructuraDoble(listaDoble, listaFinDoble);
											break;

										case 1:
											if(ordenada == 1)
											{
												numero = pedirDato();
												insertarElementoListaOrdenadaDoble(numero, listaDoble, listaFinDoble);
											}
											else
											{
												insertarElementoListaDoble(listaDoble, listaFinDoble);
											}
											PAUSE;
											break;

										case 2:
											mostrarElementosListaDoble(listaDoble, listaFinDoble);
											PAUSE;
											break;

										case 3:
											buscarElementosListaDoble(listaDoble);
											PAUSE;
											break;

										case 4:
											printf("\nIngrese el numero a Borrar: ");
											scanf("%d", &numero);
											eliminarElementoListaDoble(listaDoble, listaFinDoble, numero);
										    PAUSE;
											break;

										case 5:
											printf("\nDesea eliminar toda la estructura? S / N: ");
											getchar();
											scanf("%c", &comprobar);
											if(comprobar == 's' || comprobar == 'S')
											{
												eliminarEstructuraDoble(listaDoble, listaFinDoble);
											}
										    PAUSE;
											break;;

										case 6:
											editarElementoListaDoble(listaDoble, listaFinDoble, ordenada);
										    PAUSE;
											break;

										default:
										    printf("\nNo es una opcion valida");
										    PAUSE;
										    break;
									}
								}
								while(opcionEstructura != 0);
							}
							while(ordenada != 0);
							break;


						default:
							printf("\nOpcion no valida");
							PAUSE;
							break;

					}

				}while(subOpcion != 0);
				break;
			case 2:
                josephus();
                PAUSE;
				break;

			case 3:
				do
				{
					system("clear");
					printf("\n\t\t\t---MENU---");
					printf("\n\t1. Listas Circulares Ordenadas");
					printf("\n\t2. Listas Circulares Sin Ordenadas");
					printf("\n\t0. Salir");
					printf("\n\n\tIngrese una opcion\n");
					scanf("%d", &subOpcion);

					do
					{
						opcionEstructura = menuEstructura();

						switch(opcionEstructura)
						{
							case 0:
	                            eliminarEstructuraCircular(listaDoble);
								break;

							case 1:
								if(subOpcion == 1)
								{
									numero = pedirDato();
									insertarElementoListaOrdenadaDobleCircular(numero, listaDoble);
									
								}
								else
								{
									insertarElementoListaDobleCircular(listaDoble);
								}
								PAUSE;
								break;

							case 2:
								mostrarElementosListaDobleCircular(listaDoble);
								PAUSE;
								break;

							case 3:
								buscarElementosListaDobleCircular(listaDoble);
								PAUSE;
								break;

							case 4:
								printf("\nIngrese el numero a Borrar: ");
								scanf("%d", &numero);
								eliminarElementoListaDobleCircular(listaDoble, numero);
							    PAUSE;
								break;

							case 5:
								printf("\nDesea eliminar toda la estructura? S/N: ");
								getchar();
								scanf("%c", &comprobar);
								if(comprobar == 's' || comprobar == 'S')
								{
									eliminarEstructuraCircular(listaDoble);
								}
							    PAUSE;
								break;

							case 6:
								editarElementoListaDobleCircular(listaDoble, subOpcion);
							    PAUSE;
								break;

							default:
							    printf("\nNo es una opcion valida");
							    PAUSE;
							    break;
						}
					}while(opcionEstructura != 0);

						
				}
				while(subOpcion != 0);
				break;

			default:
				break;
		}
	}while(opcion != 0);

}

/**
 * Imprime las operaciones de la estructura
 * y retorna la seleccionada
 */
int menuEstructura()
{
	int opcion = 0;
	system("clear");
	printf("\n\t\t\t---MENU---");
	printf("\n\t1. Insertar Elementos");
	printf("\n\t2. Mostrar Elementos");
	printf("\n\t3. Buscar Elemento");
	printf("\n\t4. Eliminar elemento");
	printf("\n\t5. Eliminar estructura");
	printf("\n\t6. Editar Elemento");
	printf("\n\t0. Salir");
	printf("\n\n\tIngrese una opcion\n");
	scanf("%d", &opcion);

	return opcion;
}

/**
 * Imprime dos opciones para una lista
 * y retorna la seleccionada
 */
int menuOrden()
{
	int ordenada = 0;
	printf("\n 1. Ordenadas");
	printf("\n 2. Sin Ordenar");
	printf("\n 0. Salir");
	printf("\n\nOpcion: ");
	scanf("%d", &ordenada);

	return ordenada;
}

