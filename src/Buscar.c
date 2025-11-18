#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Agenda.h"//Incluimos las variables de agenda.h

bool buscarContacto(const Contacto contactos[], int n){

    if (n == 0) {//Verifica que si tengas contactos
        printf("\nNo hay contactos guardados.\n");
        return false;
    }

    char buscar_contacto[50];//Se declara la variable que va a buscar
    printf("\nIngrese el nombre, apellido o telefono del contacto que desea buscar: ");

    //Quite el getchar extra porque estaba cortando el primer caracter, osea que Hola lo leia como ola
    fgets(buscar_contacto, 50, stdin);//Lee lo que quieres buscar 
    buscar_contacto[strcspn(buscar_contacto, "\n")] = 0;//Esto borra el salto de linea que se genera cuando el usuario hace enter por que en realidad se guarda messi\n\0. El \n se borra y el 0 de por si creo que no aparece

    bool Encontrado = false;//Variable de verdadero y falso

    for (int i = 0; i < n; i++) {//Es el ciclo para darle toda la vuelta a los contactos

        if (strcmp(contactos[i].nombre, buscar_contacto) == 0 ||//Es de la biblioteca de string.h y se encarga de comparar letra por letra cada cadena
            strcmp(contactos[i].apellido, buscar_contacto) == 0 ||//El igual a 0 hace que la comparacion solo sea verdadera si lo de la izquierda es igual 
            strcmp(contactos[i].telefono, buscar_contacto) == 0)
        {
            printf("\nContacto %d\n", i+1);//Imprime el contacto una vez lo encuentre 
            printf("Nombre: %s\n", contactos[i].nombre);
            printf("Apellido: %s\n", contactos[i].apellido);
            printf("Telefono: %s\n", contactos[i].telefono);
            printf("Nacimiento: %d/%d\n", contactos[i].dia, contactos[i].mes);

            if (contactos[i].tipo == 1)//Revisa si el contacto es fijo o movil
                printf("Tipo: Fijo\n");
            else//Si no es fijo es movil
                printf("Tipo: Movil\n");

            Encontrado = true; //Ahora si esta donde debe
        }
    }

    if (!Encontrado)
        printf("\nNo se encontró el contacto.\n");

    return Encontrado;
}
