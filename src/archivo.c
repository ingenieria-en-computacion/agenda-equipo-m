#include <stdio.h>
#include <string.h>
#include "Agenda.h"

void cargarContactos(Contacto contactos[], int *n){
    FILE *f = fopen("contactos.txt", "r");

    if (!f){
        printf("No se encontró contactos.txt, se creará uno nuevo.\n");
        *n = 0;
        return;
    }

    *n = 0;

    while (fscanf(f, "%49[^_]_%49[^_]_%49[^_]_%d_%d_%d\n",
        contactos[*n].nombre,
        contactos[*n].apellido,
        contactos[*n].telefono,
        &contactos[*n].dia,
        &contactos[*n].mes,
        &contactos[*n].tipo) == 6) 
    {
        (*n)++;
        if (*n >= MAX_CONTACTOS) break;
    }

    fclose(f);
    printf("Contactos cargados correctamente (%d).\n", *n);
}

void guardarContactos(const Contacto contactos[], int n){
    FILE *f = fopen("contactos.txt", "w");

    if (!f){
        printf("Error al guardar contactos.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s_%s_%s_%d_%d_%d\n",
            contactos[i].nombre,
            contactos[i].apellido,
            contactos[i].telefono,
            contactos[i].dia,
            contactos[i].mes,
            contactos[i].tipo);
    }

    fclose(f);
    printf("Contactos guardados correctamente (%d).\n", n);
}
