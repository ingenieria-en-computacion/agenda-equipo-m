#include <stdio.h>
#include <string.h>
#include "Agenda.h"//Incluimos las variables de agenda.h

void mostrarContactos(const Contacto contactos[], int n){//Hacemos que todo esto entre dentro de el arreglo

    if (n == 0) { //Si los contactos son igual a 0
        printf("\nNo hay contactos en la agenda.\n");
    } else {

        for (int i = 0; i < n; i++) { //Declaramos i para el numero de contactos, y con este ciclo le da la vuelta a todos los contactos//Cambié <= por <
            printf("\nContacto %d\n", i+1);//No existe un contacto 0 por lo que empieza por sumarle 1
            printf("Nombre: %s\n", contactos[i].nombre);//El porcentaje s es por que es una cadena, contactos es el arreglo donde esta guardado y .nombre el dato que usamos
            printf("Apellido: %s\n", contactos[i].apellido);
            printf("Telefono: %s\n", contactos[i].telefono);
            printf("Nacimiento: %d/%d\n", contactos[i].dia, contactos[i].mes);

            if (contactos[i].tipo == 1)//Primero preguntamos si puso 1 que significa que su telefono es fijo
                printf("Tipo: Fijo\n");
            else//Si no por logica es movil
                printf("Tipo: Movil\n");
        }
    }
}
