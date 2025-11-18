#include <stdio.h>
#include <string.h>
#include "Agenda.h"//Incluimos las variables de agenda.h

void ordenarContactos(Contacto contactos[], int n){//Se supone que esto es un algoritmo burbuja que ordena una lista comparando elementos vecinos y cambiando su lugar si estan mal

    if (n > 1) {//Hace que solo se pueda ejecutar si tienes mas de un contacto

        for (int i = 0; i < n - 1; i++) {//Hace que el ciclo se repita varias veces, el -1 es porque en cada pasada, el mayor elemento “sube” al final, pero aún faltan los demás.Entonces necesitas repetir tantas veces como elementos tienes menos 1.
            for (int j = 0; j < n - 1 - i; j++) { //Este ciclo compara elementos de 2 en 2 el limite es contactos -1 por que conforme avanza las cosas ya estan en su lugar//pequeña mejora

                if (strcmp(contactos[j].nombre, contactos[j + 1].nombre) > 0) {//Compara nombres j con nombres j+1 y strcmp devuelve un numero mayor a 0 si j > j+1. Osea que si pepe > antoine como esto esta mal alfabeticamente los reordena adelante
                            //En estas comparaciones no se usa strcmp por que ya se usan estructuras completas
                            //Abajo creeamos una variable temporal que es el contacto temp
                    Contacto temp = contactos[j];//Como temp esta vacia, a esta se le asigna lo de j
                    contactos[j] = contactos[j+1];//Como ya hay un lugar donde esta asigando j, ahora j+1 se asigna en j
                    contactos[j+1] = temp;//la j inicial que se encuentra en temp termina por almacenarse en j+1
                                //En el pseudo original no usaba estructuras completas por lo que tenia que repetir el proceso con cada variable: dia, mes, etc.
                }
            }//Si al compararlos llegan a estar coorrectamente ordenados se salta todo eso y procede a compararlo con el que sigue creo
        }

        printf("\nContactos ordenados por nombre.\n");

    } else {
        printf("No hay suficientes contactos para ordenar.\n");//Por si no hay contactos
    }
}
