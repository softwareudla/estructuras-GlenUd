#include <stdio.h>
#include <string.h>
#include "funciones.h"

void Menu(struct Libro libro[20], int i){
    int opc;
     printf("\n\t\033[32m|-----------------------------------------------------|\n");
        printf("\t|                     MENU                            |\n");
        printf("\t|-----------------------------------------------------|\n");
        printf("\t|1.|  Registrar Libro                                 |\n");
        printf("\t|-----------------------------------------------------|\n");
        printf("\t|2.|  Mostrar Libros                                  |\n");
        printf("\t|-----------------------------------------------------|\n");
        printf("\t|3.|  Buscar Libro por ID o por Titulo del Libro      |\n");
        printf("\t|-----------------------------------------------------|\n");
        printf("\t|4.|  Eliminar Libro                                  |\n");
        printf("\t|-----------------------------------------------------|\n");
        printf("\t|5.|  Salir                                           |\n");
        printf("\t|-----------------------------------------------------|\033[0m \n");

}


void registrarLibros(struct Libro libro[20], int i)
{
    int opc1;
    int len;
    printf("Ingrese el ID del Libro  %d:\n", i + 1);
    scanf("%d", &libro[i].ID);
    printf("Ingrese el titulo %d del Libro:\n", i + 1);
    fflush(stdin);
    fgets(libro[i].Título, 100, stdin);
    len = strlen(libro[i].Título) - 1;
    libro[i].Título[len] = '\0';
    printf("Ingrese el autor del Libro %d:\n", i + 1);
    fflush(stdin);
    fgets(libro[i].Autor, 50, stdin);
    len = strlen(libro[i].Autor) - 1;
    libro[i].Autor[len] = '\0';
    printf("Ingrese el anio del Libro %d:\n", i + 1);
    scanf("%d",&libro[i].Año);
    printf("Seleccione el Estado del libro (1. Disponible, 2. Prestado): ");
    scanf("%d", &opc1);
    switch (opc1) {
            case 1:
                strcpy(libro[i].Estado, "Disponible");
                break;
            case 2:
                strcpy(libro[i].Estado, "Prestado");
                break;
            default:
                printf("\nNúmero incorrecto. Se asignará 'Disponible' por defecto.\n");
                strcpy(libro[i].Estado, "Disponible");

    }   
}

void mostrarLibros(struct Libro libro[20], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID != 0)
        {
            printf("ID: %d\t\tTitulo: %s\t\tAutor: %s\t\tAnio: %d\t\tEstado: %s\t\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
        }
    }
}

void buscarLibroPorId(struct Libro libro[20], int n)
{
    int id;
    printf("Ingrese el ID del libro a buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID == id)
        {
            printf("\nLibro encontrado:\n");
            printf("|%d\t%s\t%s\t%d\t%s|\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
            return;
        }
    }
    printf("\nNo se encontro un libro con el ID %d.\n", id);
}
void buscarLibroPorTituloOId(struct Libro libro[20], int n)
{
    int subopc;
    printf("\nSeleccione como desea buscar el libro:\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Titulo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &subopc);

    switch (subopc)
    {
    case 1:
    {                               // Buscar por ID
        buscarLibroPorId(libro, n); // Reutilizar la función existente
        break;
    }
    case 2:
    { // Buscar por Título
        char titulo[100];
        printf("Ingrese el titulo del libro a buscar: ");
        fflush(stdin);
        fgets(titulo, 100, stdin);
        titulo[strcspn(titulo, "\n")] = '\0'; // Eliminar salto de línea

        for (int i = 0; i < n; i++)
        {
            if (strcmp(libro[i].Título, titulo) == 0)
            {
                printf("\nLibro encontrado:\n");
                printf("|%d\t%s\t%s\t%d\t%s|\n", libro[i].ID, libro[i].Título, libro[i].Autor, libro[i].Año, libro[i].Estado);
                return;
            }
        }
        printf("\nNo se encontro un libro con el titulo \"%s\".\n", titulo);
        break;
    }
    default:
        printf("Opcion invalida. Volviendo al menu principal.\n");
    }
}
int eliminarLibros(struct Libro libro[20], int n)
{
    mostrarLibros(libro, n);
    int id;
    printf("\nIngrese el ID del libro a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
    {
        if (libro[i].ID == id)
        {
            // Desplazar los libros restantes hacia atrás
            for (int j = i; j < n - 1; j++)
            {
                libro[j] = libro[j + 1];
            }
            printf("Libro con ID %d eliminado.\n", id);
            return n - 1; // Actualizar el número de libros
        }
    }
    printf("No se encontró un libro con el ID %d.\n", id);
    return n; // No se elimina nada, número de libros no cambia
}