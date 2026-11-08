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


int buscar_usuario_recursivo(ListaUsuario *lista_usuarios, int id_usuario){
   int encontrado;
    if(lista_usuarios==NULL){
        encontrado=0;
    }
     else{
        if(lista_usuarios->dato.id_usuario==id_usuario){
        encontrado=1;
    }else{
        encontrado=buscar_usuario_recursivo(lista_usuarios->sgte,id_usuario);
    }
    return encontrado;
}
}



ListaUsuario *eliminar_usuario(ListaUsuario **lista_usuarios,int id_usuario_buscado) {
    if(buscar_usuario_recursivo(*lista_usuarios,id_usuario_buscado)==1){
    printf("ID del usuario eliminado:%d\n",(*lista_usuarios)->dato.id_usuario);
    free(*lista_usuarios);
    *lista_usuarios = (*lista_usuarios)->sgte;
    }else{
        printf("Usuario no encontrado.\n");
    }
return *lista_usuarios;
}

tFecha obtenerFecha(){
    time_t tiempo;
    struct tm *fechaActual;
    
    tiempo=time(NULL);
    fechaActual=localtime(&tiempo);
    tFecha fecha;
    fecha.dia=fechaActual->tm_mday;
    fecha.mes=fechaActual->tm_mon + 1;
    fecha.anio=fechaActual->tm_year + 1900;
    return fecha;
}

void consultar_saldo(ListaUsuario *lista_usuario, int id_usuario) {
    while (lista_usuario != NULL && lista_usuario->dato.id_usuario != id_usuario) {
        lista_usuario = lista_usuario->sgte;
    }

    if (lista_usuario == NULL) {
        printf("Usuario no encontrado.\n");
    }

    printf( "El usuario %d tiene un saldo de: %.2f\n",lista_usuario->dato.id_usuario,lista_usuario->dato.saldo);
}















