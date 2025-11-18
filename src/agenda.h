#ifndef __AGENDA_H__
#define __AGENDA_H__

#include <stdbool.h>

#define MAX_CONTACTOS 1000

typedef struct {
    char nombre[50], apellido[50], telefono[50];
    int dia, mes;
    int tipo;
} Contacto;

void cargarContactos(Contacto contactos[], int *n);
void guardarContactos(const Contacto contactos[], int n);
void agregarContacto(Contacto contactos[], int *n);
void mostrarContactos(const Contacto contactos[], int n);
void ordenarContactos(Contacto contactos[], int n);
bool buscarContacto(const Contacto contactos[], int n);

#endif