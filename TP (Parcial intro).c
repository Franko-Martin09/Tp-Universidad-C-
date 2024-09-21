#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USUARIO "ADMIN"
#define CLAVE 22478
#define L 3
#define E 150


struct menu{
	int codigo_menu;
	char nombre[30];
	char entrada[30];
	char platoPrincipal[30];
	char postre[30];
	int cantidad;
	int precio;
	int solicitud;
};

struct comanda
{
 int codigocomensal;
 int nro_mesa;
 int codigoMenu[4];
 int menuPedido;

};

void inicio_sesion(char[],int,int);
void ingresofecha(int,int,int);
int ingresoMenu(struct menu[],int,int);
void ver_menu(struct menu[]);
void Editar_menu(int,int , struct menu[]);
void EliminarMenu(int,struct menu []);
void cerrarsesion(char [],int,int);

int main(){
                                                                        //declaramos los structs
    struct menu agregar [L];
    struct comanda cliente[E];
                                                                        // variables a usar
    int contMenu[4]={0};   char usuario [4]; int clave=0,intento=0;     // para el inicio de sesion
    int opcion,opEditar,opcion_comensales=0,opcMenu=0,contador=0;
    int dia=0,mes=0,ano=0;                                              //para el ingreso de fecha
    int comensalcodigo2[4];                                             //codigos de los pedidos
                                comensalcodigo2[0]=12;
                                comensalcodigo2[1]=34;
                                comensalcodigo2[2]=777;
    int codigomenu=0,otra_orden=0,codigo_comensal=0,codigoencontrado=0,cont=0,pedidosHechos=0;//para el pedido
    int contadorMenu1=0,contadorMenu2=0,contadorMenu3=0;
    int pago=0,precio[L]={0},totalrecaudado=0;
    char Mas_solicitado[30];int mayor=0,menor=0;char Menos_solicitado[30];




    for(int i=0;i<L;i++){//esto esta mal por que me cada vez q ingrese me pone todo el menu en 0,
		agregar[i].codigo_menu=0;//
		}//esta funcion deberia estar a fuera de esta funcion, al principio del main,

 for(int i=0;i<L;i++){agregar[i].solicitud=0;}

          //inicia programa

   printf("-BIENVENIDO/A-\n");
   //inicio_sesion(usuario,clave,intento);

//Menu
       do
{
    printf("Bienvenido al Menu, eliga la opcion deseada...\n");			//imprime el menu
    printf("\t1.Agregar Menu.\n");
    printf("\t2.Eliminar Menu.\n");
    printf("\t3.Editar Menu.\n");
    printf("\t4.Abrir restaurante.\n");
    printf("\t5.Salir.\n\t");
    scanf("%d", &opcMenu);
    system("cls");														//termina el menu

    switch(opcMenu)
       {
            case 1:
              printf("AGREGAR MENU\n");
              totalrecaudado=ingresoMenu(agregar,contador,opcion);
              contador++;
            break;

             case 2: printf("\tOpci%cn elegida:\tEliminar Menu\n",149);
             EliminarMenu(opEditar,agregar);
            break;

             case 3: printf("\tOpci%cn elegida:\tEditar Menu\n",149);
               Editar_menu(opEditar,contador,agregar);
            break;

            case 4:
              printf("\tOpci%cn elegida:\tAbrir Restaurante\n",149);
             // ingresofecha(dia,mes,ano);

         do     // menu para los comensales
            {
         printf("\nEliga la opcion deseada...\n");
         printf("\t1.Ver menus del dia.\n");
         printf("\t2.Pedir comanda(hasta 4 menus).\n");
         printf("\t3.Cancelar comandas.\n");
         printf("\t4.Cerrar Restaurante.\n");
         scanf("%d",&opcion_comensales);
         system("cls");

         switch(opcion_comensales)
               {
               case 1:
                   printf("\tOpcion elegida:\tVer menus del dia.\n");
                   ver_menu(agregar);
                  break;
               case 2:
                   printf("\tOpcion elegida:\tPedir comanda(hasta 4 menus).\n");
            do
         {
                 printf("\nIngresar codigo del menu a pedir:\t");
                 scanf("%d",&codigomenu);
                for (int i=0;i<L;i++)
           { if (codigomenu==agregar[i].codigo_menu)
             {codigoencontrado=1; cliente[i].codigoMenu[i]=agregar[i].codigo_menu;
                 if(cliente[i].codigoMenu[i] == agregar[0].codigo_menu)
                 {printf("\nEl codigo %d pertenece al menu %s",cliente[i].codigoMenu[i],agregar[0].nombre);
                   contadorMenu1++; cliente[i].codigocomensal=comensalcodigo2[i];
                    precio[i]=agregar[i].precio*agregar[i].cantidad;
                    printf("\ncodigo del comensal:\t%d\n",cliente[i].codigocomensal);

                 }
                 else if (cliente[i].codigoMenu[i] == agregar[1].codigo_menu && codigoencontrado==1)
                    { printf("\nEl codigo %d pertenece al menu %s",cliente[i].codigoMenu[i],agregar[1].nombre);
                      contadorMenu2++;
                       cliente[i].codigocomensal=comensalcodigo2[i];
                       precio[i]=agregar[i].precio*agregar[i].cantidad;
                    printf("\ncodigo del comensal:\t%d\n",cliente[i].codigocomensal);
                    }
                 else if(cliente[i].codigoMenu[i] == agregar[2].codigo_menu && codigoencontrado==1)
                    {  printf("\nEl codigo %d pertenece al menu %s",cliente[i].codigoMenu[i],agregar[2].nombre);
                       contadorMenu3++;
                        cliente[i].codigocomensal=comensalcodigo2[i];
                        precio[i]=agregar[i].precio*agregar[i].cantidad;
                      printf("\ncodigo del comensal:\t%d\n",cliente[i].codigocomensal);
                    }
                     agregar[i].solicitud++; cliente[i].menuPedido=agregar[i].solicitud;
                     //aumento el contador de solicitud de ese menu.
                     //le asigo su valor para hacer la comparacion final de solicitud
             }
             pedidosHechos=contadorMenu1+contadorMenu2+contadorMenu3;
             pago=precio[0]+precio[1]+precio[2];

           }
            if(codigoencontrado==0){printf("El codigo no fue encontrado, vuelva a intentarlo.");}

            printf("\n Desea ordenar otro menu?\n\t1,Si.\n\t2.No.\n");
            scanf("%d",&otra_orden);
     }while(otra_orden==1);
       system("cls");
                  break;

               case 3:
                   printf("\tOpcion elegida:\tcancelar comanda.\n");
                   printf("Ingrese el codigo de comanda a cancelar:\t");
                   scanf("%d",&codigo_comensal);
      for(int cancelar=0;cancelar<E;cancelar++)
         { if(codigo_comensal==cliente[cancelar].codigocomensal)
            {   codigoencontrado=1;cliente[cancelar].codigocomensal=agregar[cancelar].codigo_menu;
              if(codigoencontrado==1)
              {  if(cliente[cancelar].codigocomensal == agregar[0].codigo_menu)
                     {printf("\nEl codigo %d pertenece al menu %s",cliente[cancelar].codigocomensal,agregar[0].nombre);
                      contadorMenu1--;
                       printf("Seguro que quiere cancelar la comanda?\n\t1.Si\n\t2.no\nIngrese la opcion deseada:\t");
                      scanf("%d",&opcion);
                       if(opcion==1)
                         {  cliente[cancelar].codigocomensal=0;
                            printf("\nPedido cancelado");
                         }
                      }
                else if (cliente[cancelar].codigoMenu[cancelar] == agregar[1].codigo_menu && codigoencontrado==1)
                   {  printf("\nEl codigo %d pertenece al menu %s",cliente[cancelar].codigocomensal,agregar[1].nombre);
                      contadorMenu2--;
                      printf("Seguro que quiere cancelar la comanda?\n\t1.Si\n\t2.no\nIngrese la opcion deseada:\t");
                      scanf("%d",&opcion);
                       if(opcion==1)
                         {  cliente[cancelar].codigocomensal=0;
                            printf("\nPedido cancelado");
                         }
                      }

                      else if(cliente[cancelar].codigoMenu[cancelar] == agregar[2].codigo_menu && codigoencontrado==1)
                    {  printf("\nEl codigo %d pertenece al menu %s",cliente[cancelar].codigoMenu[cancelar],agregar[2].nombre);
                       contadorMenu3--;
                       printf("Seguro que quiere cancelar la comanda?\n\t1.Si\n\t2.no\nIngrese la opcion deseada:\t");
                       scanf("%d",&opcion);
                       if(opcion==1)
                        { cliente[cancelar].codigocomensal=0;
                         printf("\nPedido cancelado");
                       }
                    }
               agregar[cancelar].solicitud--;cliente[cancelar].menuPedido=agregar[cancelar].solicitud;
               //decremento el contador de solicitud de ese menu.
               //le asigo su valor para hacer la comparacion final de solicitud,
              }
            }
         } pedidosHechos=contadorMenu1+contadorMenu2+contadorMenu3;

            if(codigoencontrado==0){printf("\nEl c%cdigo de la comanda no ha sido encontrada,vuelva a intentar\n",149);system("pause");}
            system("cls");
                  break;

               case 4:
                    printf("\tOpcion elegida:\tCerrar Restaurante\n");
              for(int x=0;x<L;x++)
                { if(agregar[x].solicitud>mayor)
                   { mayor=agregar[x].solicitud;
                    strcpy(Mas_solicitado,agregar[x].nombre);
                   }
                }
                if (contadorMenu1<contadorMenu2)
                 { if (contadorMenu1<contadorMenu3)
                   { if (contadorMenu2<contadorMenu3)
                      printf("\nEl menu menos solicitado es %s \n",agregar[0].nombre);
                   else printf ("\nEl menu menos solicitado es %s \n",agregar[0].nombre);
                    }
                 }
               else
               { if (contadorMenu2<contadorMenu3)
                 { if (contadorMenu1<contadorMenu3)
                    printf ("\nEl menu menos solicitado es %s\n",agregar[1].nombre);
                else printf ("\nEl menu menos solicitado es %s\n",agregar[1].nombre);
                 }
               }
          printf("\nEl menu mas solicitado es :%s \n",Mas_solicitado);
          printf("\n\tTotal de pedidos:\t%d",pedidosHechos);
          printf("\n\tTotal recaudado:\t%d\n",pago);

            system("pause");
            system("cls");

        printf("\n\tCerrando Sesion..\t\n");
        cerrarsesion(usuario,clave,intento);
                    opcion_comensales=8;
                    opcMenu=8;
                 break;
              }
          }while (opcion_comensales<4);
     }
}while(opcMenu<5);

    return 0;
}
void inicio_sesion(char user [],int clave,int intento)
{
    do{ printf("\ningrese usuario:\t");
        fflush(stdin);
        gets(user);

        printf("ingrese clave:\t");
        scanf("%d",&clave);
        fflush(stdin);

        if(strcmp(user, USUARIO)==0 && clave==CLAVE)
            {
            printf("\n\t Bienvenido/a al sistema\n");
            intento= 1;
            }
        else
              {
            printf("\n usuario y/o clave incorrectos\n");
              }
       }while(intento==0);
         system("pause");
}
void ingresofecha(int d,int m,int a)
  {
         printf("\tIngrese la fecha\t\n");
         printf("\tDia:\t");
         scanf("%d",&d);
         printf("\tMes:\t");
         scanf("%d",&m);
         printf("\tA%co:\t",164);
         scanf("%d",&a);
         system("cls");
  }
int ingresoMenu(struct menu agregar [],int cont,int opcionmenu)
  {
        for(int i=0;i<L;i++){
	 if(agregar[i].codigo_menu==0)
		{
	    printf("\ncodigo:");
       	    scanf("%d",&agregar[i].codigo_menu);

       	    printf("\n nombre:");
            fflush(stdin);
            fgets(agregar[i].nombre,30,stdin);

            printf("\n Entrada:");
            fflush(stdin);
            fgets(agregar[i].entrada,30,stdin);

       		printf("\n Plato principal:");
            fflush(stdin);
            fgets(agregar[i].platoPrincipal,30,stdin);

       		printf("\nPostre:");
       		fflush(stdin);
       		fgets(agregar[i].postre,30,stdin);

       		printf("\nCantidad:");
       		scanf("%d",&agregar[i].cantidad);

       		printf("\nPrecio:");
       		scanf("%d",&agregar[i].precio);

              cont++;//el contador aumenta incluso si el menu eliminado es vuelto a ingresar


           printf("\n desea ingresar otro menu ? (1si) (2no):\t");
           scanf("%d",&opcionmenu);
               if(opcionmenu==2){
                 i=5;
               }
        }else{if( agregar[i].codigo_menu!=0){
				printf("para agregar otro menu primero borre uno existente, solo se agregan hasta 3 menu");
				system("cls");}//fin del 2do if
		}//fin del else

		}//fin del for

  };
void  Editar_menu(int opcion,int cont, struct menu agregar[])
{
        printf("\n\tEDITAR MENU\t");
    	printf("\npor favor ingrese codigo del menu a editar:");
    	scanf("%d",&opcion);

    	if(cont==0)
            { printf("\n\tPrimero ingrese un menu\n");
            system("pause"); }
                else
                {
                    for(int i=0;i<L;i++)
                        {
                        if(opcion==agregar[i].codigo_menu){
                            printf("\ncodigo:");
                            scanf("%d",&agregar[i].codigo_menu);

                            printf("\n nombre:");
                            fflush(stdin);
                            fgets(agregar[i].nombre,30,stdin);

                            printf("\n Entrada:");
                            fflush(stdin);
                            fgets(agregar[i].entrada,30,stdin);

                            printf("\n Plato principal:");
                            fgets(agregar[i].platoPrincipal,30,stdin);

                            printf("\nPostre:");
                            fflush(stdin);
                            fgets(agregar[i].postre,30,stdin);

                            printf("\nCantidad:");
                            scanf("%d",&agregar[i].cantidad);

                            printf("\nPrecio:");
                            scanf("%d",&agregar[i].precio); } //sobreescribe el contenido del menu seleccionado
                      }
             }
    system("cls");
}
void EliminarMenu(int opcion, struct menu agregar [])
{
    printf("\npor favor ingrese codigo del menu a editar:");
    scanf("%d",&opcion);
    for(int i=0;i<L;i++)
     {
      if(opcion==agregar[i].codigo_menu)
          {
          printf("\nEl codigo %d pertenece al menu %s",agregar[i].codigo_menu,agregar[i].nombre);
          printf("\nEsta seguro de querer eliminar el menu? (1.si) (2.no)");
          scanf("%d",&opcion);
             if(opcion==1)
              {agregar[i].codigo_menu=0;

                printf("\nEl menu ha sido eliminado\n");}
          }
     }
}
 void ver_menu(struct menu agregar [])
{
    for(int m=0;m<L;m++)
      {
        printf("Menu %d...\n\tNombre:\t%s\n",m+1,agregar[m].nombre);
        printf("\tEntrada:\t%s\n\tPlato principal:\t%s\n",agregar[m].entrada,agregar[m].platoPrincipal);
        printf("\tPostre:\t%s\n\tPrecio:\t%d\n\tCodigo del menu:\t%d\n",agregar[m].postre,agregar[m].precio,agregar[m].codigo_menu);
      }
    system("pause");
    system("cls");
}
void cerrarsesion(char user[],int clave,int intento)
{
    do{ printf("\ningrese usuario:\t");
        fflush(stdin);
        gets(user);

        printf("ingrese clave:\t");
        scanf("%d",&clave);
        fflush(stdin);

        if(strcmp(user, USUARIO)==0 && clave==CLAVE)
            {
            printf("\n\t sesion cerrado correctamente\n");
            intento= 1;
            }
        else
              {
            printf("\n usuario y/o clave incorrectos\n");
              }
       }while(intento==0);
         system("pause");
}
