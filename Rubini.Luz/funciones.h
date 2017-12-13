#include "ArrayList.h"
struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int dni;
}typedef Cliente;
struct
{
    int dniCliente;
    char codArticulo[50];
    float costo;
    int estado;
    int numServicio;

}typedef Servicios;

void altaCliente(ArrayList* listaClientes);
Cliente* newClientePar(int id, char* nombre, char* apellido, int dni);
Cliente* newCliente(void);
void modificarCliente(ArrayList* clientes);
void mostrarListaClientes(ArrayList* listaClientes);
void mostrarCliente(Cliente* cliente);
void modificarValores(ArrayList* listaClientes,int posicion);
void eliminarCliente(ArrayList* clientes);
void ordenarClientes(ArrayList* clientes);
int compareApellidos(void* clienteA,void* clienteB);
