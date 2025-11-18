#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"

int main(){
    Contacto contactos[MAX_CONTACTOS];
    int n = 0, opcion;

    cargarContactos(contactos, &n); //Antes estaba dentro del do-while 

    do {
        printf("\n      Agenda\n");
        printf("1. Agregar contacto\n");
        printf("2. Mostrar contactos\n");
        printf("3. Ordenar contactos alfabeticamente\n");
        printf("4. Buscar contacto\n");
        printf("5. Salir\n");
        printf("\nSeleccione una opcion: ");

        scanf("%d", &opcion);
        getchar(); // Sirve para limpiar la intefaz

        switch (opcion)//Tomamos como variable lo que escojimos como opcion
        {
        case 1:
            agregarContacto(contactos, &n);
            guardarContactos(contactos, n);
            break;

        case 2:
            mostrarContactos(contactos, n);
            break;

        case 3:
            ordenarContactos(contactos, n);
            break;

        case 4:
            buscarContacto(contactos, n);
            break;

        case 5:
            guardarContactos(contactos, n);
            printf("Bye :)...\n");
            break;

        default:
            printf("Error fatal");//Por si mete otro numero distinto del 1 al 5
            break;
        }

    } while (opcion != 5);//Hace que regrese al menu hasta que le des al 5 para cerrar el programa

    return 0;
}