#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tOperacion.h"
#include "tUsuario.h"
#include <time.h>

// Estructura para representar un usuario
typedef struct Usuario{
    int id_usuario;
    char nombre[50]; 
    float saldo;
}Usuario;

typedef struct ListaUsuario{
    Usuario dato;
    int cant_usuarios;
    struct ListaUsuario *sgte;
    struct ListaOperaciones *operaciones;
}ListaUsuario;

Usuario* crear_usuario(int id_usuario, const char *nombre, float saldo) {
    Usuario *nuevo_usuario = malloc(sizeof(Usuario));
    if (nuevo_usuario == NULL) {
        printf("La lista esta vacia.\n");
    }
    nuevo_usuario->id_usuario = id_usuario;
    strcpy(nuevo_usuario->nombre, nombre);
    nuevo_usuario->saldo = saldo;
    return nuevo_usuario;
}

void destruir_usuario(Usuario *usuario) {
    free(usuario);
}

Usuario* registrar_usuario(ListaUsuario **lista, Usuario *nuevo_usuario) {
    ListaUsuario *nuevo_nodo_usuario = malloc(sizeof(ListaUsuario));

    if (nuevo_nodo_usuario == NULL) {
        printf("Error la lista esta vacia.\n");
        
    }else{
        nuevo_nodo_usuario->dato = *nuevo_usuario;
        nuevo_nodo_usuario->cant_usuarios = 1;
        nuevo_nodo_usuario->sgte = *lista;
        nuevo_nodo_usuario->operaciones = NULL; // Inicializar la lista de operaciones como NULL
        *lista = nuevo_nodo_usuario;
        return &nuevo_nodo_usuario->dato;
    }
}