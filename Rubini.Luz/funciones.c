#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "ArrayList.h"

void altaCliente(ArrayList* listaClientes)
{
    int id;
    int dni;
    char apellido[50];
    char nombre[50];
    Cliente* cliente;
    printf("Ingrese id:");
    scanf("%d",&id);
    printf("Ingrese nombre:");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese apellido:");
    fflush(stdin);
    gets(apellido);
    printf("Ingrese dni:");
    scanf("%d",&dni);
    cliente=newClientePar(id,nombre,apellido,dni);
    if(cliente!=NULL)
    {
        al_add(listaClientes,cliente);
    }

}
Cliente* newClientePar(int id, char* nombre, char* apellido, int dni)
{
    Cliente* cliente;
    cliente=newCliente();
    if(cliente!=NULL)
    {
        cliente->id=id;
        strcpy(cliente->nombre,nombre);
        strcpy(cliente->apellido,apellido);
        cliente->dni=dni;
    }
    return cliente;
}
Cliente* newCliente(void)
{
    Cliente* cliente;
    cliente=(Cliente*)malloc(sizeof(Cliente));
    return cliente;
}
void modificarCliente(ArrayList* clientes)
{
    int id;
    int i;
    char opcion;
    Cliente* auxCliente=NULL;

    if(clientes!=NULL)
    {
        mostrarListaClientes(clientes);
        printf("Ingrese ID del cliente: ");
        scanf("%d",&id);
        for(i=0;i<al_len(clientes);i++)
        {
            auxCliente=al_get(clientes,i);
            if(auxCliente->id==id)
            {
                printf("¿Desea modificar este cliente?: s/n \n");
                mostrarCliente(auxCliente);
                opcion=tolower(getche());
                if(opcion=='s')
                {
                    modificarValores(clientes,i);
                }
                else
                {
                    printf("\nOperacion cancelada!");
                }

            }
        }
    }
}
void mostrarListaClientes(ArrayList* listaClientes)
{
    int i;
    Cliente* aux;
    system("cls");
    printf("LISTA DE CLIENTES:\n");
    printf("ID\t\tNOMBRE\t\tAPELLIDO\t\tDNI\n");
    for(i=0; i<al_len(listaClientes); i++)
    {
        aux=al_get(listaClientes,i);
        mostrarCliente(aux);
    }
}
void mostrarCliente(Cliente* cliente)
{
    printf("%d\t\t%s\t\t%s\t\t%d\n",cliente->id,cliente->nombre,cliente->apellido,cliente->dni);
}
void modificarValores(ArrayList* listaClientes,int posicion)
{
    int id;
    int dni;
    char apellido[50];
    char nombre[50];
    Cliente* auxCliente;
    printf("Ingrese id:");
    scanf("%d",&id);
    printf("Ingrese nombre:");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese apellido:");
    fflush(stdin);
    gets(apellido);
    printf("Ingrese dni:");
    scanf("%d",&dni);
    auxCliente=newClientePar(id,nombre,apellido,dni);
    if(auxCliente!=NULL)
    {
        al_set(listaClientes,posicion,auxCliente);
        printf("\nOperacion realizada!");
    }
}
void eliminarCliente(ArrayList* clientes)
{
    int id;
    int i;
    char opcion;
    Cliente* auxCliente=NULL;

    if(clientes!=NULL)
    {
        mostrarListaClientes(clientes);
        printf("Ingrese ID del cliente: ");
        scanf("%d",&id);
        for(i=0;i<al_len(clientes);i++)
        {
            auxCliente=al_get(clientes,i);
            if(auxCliente->id==id)
            {
                printf("¿Desea modificar este cliente?: s/n \n");
                mostrarCliente(auxCliente);
                opcion=tolower(getche());
                if(opcion=='s')
                {
                    al_remove(clientes,i);
                    printf("\nOperacion realizada!");
                }
                else
                {
                    printf("\nOperacion cancelada!");
                }

            }
        }
    }
}
void ordenarClientes(ArrayList* clientes)
{
    printf("LISTA ORDENADA POR APELLIDOS: A-Z");
    al_sort(clientes,compareApellidos,1);
    mostrarListaClientes(clientes);
}
int compareApellidos(void* clienteA,void* clienteB)
{
    int retorno=0;
    if(strcmp(((Cliente*)clienteA)->apellido,((Cliente*)clienteB)->apellido)==1)
    {
        retorno=1;
    }
    if(strcmp(((Cliente*)clienteA)->apellido,((Cliente*)clienteB)->apellido)==-1)
    {
        retorno=-1;
    }
    return retorno;
}
int cargarArchivo(FILE* pFile,ArrayList* listaServicios,ArrayList* clientes)
{
    char idCliente[10],nombre[100],apellido[100],dni[20],codigoProd[20],costo[10],estado[10],servicio[20];
    Cliente* cliente;
    Servicios* servicios;
    int i,j;
    if(listaServicios!=NULL)
    {
        pFile=fopen("servicios.csv","r");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,]%[^,]%[^,]%[^\n]\n",idCliente,nombre,apellido,dni,codigoProd,costo,estado,servicio);
                clientes=newCliente();
                cliente->id=atoi(idCliente);
                strcpy(cliente->nombre,nombre);
                strcpy(cliente->apellido,apellido);
                cliente->dni=atoi(dni);
                al_add(clientes,cliente);
                servicios=newServicio();
                for(i=0;i<al_len(listaServicios);i++)
                {
                    if(!=servicio)
                    {
                        servicios->dniCliente=atoi(dni);
                        servicios->codArticulo=atoi(codigoProd);
                        servicios->costo=atoi(costo);
                        servicios->estado=atoi(estado);
                        servicios->numServicio=atoi(servicio);
                        al_add(listaServicios,servicios);
                    }
                }


           }
        }
    }
    fclose(pFile);

    return 0;
}
Servicios* newServicio(void)
{
    Servicios* servicio;
    servicio=(Servicios*)malloc(sizeof(Servicios));
    return servicio;
}
