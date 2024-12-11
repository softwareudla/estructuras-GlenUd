#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    struct Libro libro[20];
    int opc;
    int i = 0; // Contador de libros registrados
    int n = 0; // Número total de libros registrados

    do
    {
       Menu(libro, i);
        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            if (n < 20)
            {
                registrarLibros(libro, i);
                i++;
                n++; // Incrementar el número total de libros registrados
            }
            else
            {
                printf("No se pueden registrar más libros. El límite es 20.\n");
            }
            break;
        case 2:
            if (n > 0)
            {
                mostrarLibros(libro, n);
            }
            else
            {
                printf("No hay libros registrados.\n");
            }
            break;
        case 3:
            if (n > 0)
            {
                buscarLibroPorTituloOId(libro, n); // Llamamos directamente a la función
            }
            else
            {
                printf("No hay libros registrados.\n");
            }
            break;
        case 4:
            if (n > 0)
            {
                n = eliminarLibros(libro, n); // Actualizar el número total de libros después de eliminar
            }
            else
            {
                printf("No hay libros para eliminar.\n");
            }
            break;
        case 6:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opc != 6);
}