#include <stdio.h>
#include <string.h>
#include "Agenda.h"//Incluimos las variables de agenda.h

void agregarContacto(Contacto contactos[], int *n){ //Esta esla funcion que colocamos en el .h
    
    if (*n < MAX_CONTACTOS) {//Hace que solo funcione si los contactos que tenemos son menos que los maximos posibles

        Contacto neo; //Variable temporal donde primero guardo todo

        printf("\nIngrese el nombre: ");
        fgets(neo.nombre, 50, stdin);//A diferencia de scanf, fgets permite leer espacios de esta manera podemos guardar nombres como juan pablo y la variable new.nombre
        neo.nombre[strcspn(neo.nombre, "\n")] = 0;//Esto solo es para eliminar el enter y que el nombre quede solo

        printf("Ingrese el apellido: ");
        fgets(neo.apellido, 50, stdin);//La estructura es fgets(variable, tamaño, stdin)
        neo.apellido[strcspn(neo.apellido, "\n")] = 0;

        printf("Ingrese el dia de nacimiento: ");
        scanf("%d", &neo.dia);//Aqui no es necesario un fgets por que no esperamos que los dias lleven espacio
        getchar(); //limpia el enter

        printf("Ingrese el mes de nacimiento: ");
        scanf("%d", &neo.mes);
        getchar();

        printf("Ingrese el telefono: ");
        //Quité un getchar extra que hacía que el usuario tuviera que dar dos enters
        fgets(neo.telefono, 50, stdin);
        neo.telefono[strcspn(neo.telefono, "\n")] = 0;

        printf("Ingrese el tipo de telefono (1=Fijo, 2=Movil): ");
        scanf("%d", &neo.tipo);
        getchar();

        contactos[*n] = neo;
        (*n)++;

        printf("\nContacto agregado correctamente.\n");

    } else {
        printf("La agenda esta llena.\n");
    }
}