#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    system("color 0f");
    ArrayList* listaClientes=al_newArrayList();
    ArrayList* listaServicios=al_newArrayList();
    char seguir='s';
    int opcion;
    FILE* miArchivo=NULL;
    while(seguir=='s')
    {
        printf("1- Alta del cliente\n");
        printf("2- Modificar datos del cliente\n");
        printf("3- Baja del cliente\n");
        printf("4- Listar clientes\n");
        printf("5- Importar servicios tecnicos desde CSV\n");
        printf("6- Ingresar servicio tecnico\n");
        printf("7- Finalizar un servicio tecnico\n");
        printf("9- Exportar servivios tecnicos de un cliente\n");
        printf("10- Imprimir servicios tecnicos por productos\n");
        printf("11- Informar:\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);
        while(opcion<1 || opcion>7)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }


        switch(opcion)
        {
            case 1:
                altaCliente(listaClientes);
                break;
            case 2:
                modificarCliente(listaClientes);
                break;
            case 3:
                eliminarCliente(listaClientes);
                break;
            case 4:
                ordenarClientes(listaClientes);
                break;
            case 5:
                cargarArchivo();
                break;
            case 6:

                break;
            case 7:
            seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }
    return 0;
}
