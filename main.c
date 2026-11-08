#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tUsuario.h"




void mostrar_menu_usuario(int *opcion, ListaUsuario **lista_usuarios);

int main(){
    int opcion;
    ListaUsuario *lista_usuarios = NULL;
   

    mostrar_menu_usuario(&opcion, &lista_usuarios);
    return 0;
}




void mostrar_menu_usuario(int *opcion, ListaUsuario **lista_usuarios) {
    int id_usuario;
    char nombre[50];
    float saldo;

    printf("1. Registrar usuario\n");
    printf("2. Buscar usuario\n");
    printf("3. Eliminar usuario\n");
    printf("4. Ingresar dinero\n");
    printf("5. Retirar dinero\n");
    printf("6. Consultar saldo\n");
    printf("7. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", opcion);
    do{
        switch(*opcion){
            case 1:
                printf("Ingrese el ID del usuario: ");
                scanf("%d", &id_usuario);
                printf("Ingrese el nombre del usuario: ");
                scanf(" %49[^\n]", nombre);
                printf("Ingrese el saldo inicial: ");
                scanf("%f", &saldo);

                Usuario *nuevo_usuario = crear_usuario(id_usuario,nombre,saldo);

                if (nuevo_usuario == NULL) {
                    printf("No se pudo crear el usuario.\n");
                    break;
                }

                if (registrar_usuario(lista_usuarios, nuevo_usuario) == NULL) {
                    printf("No se pudo registrar el usuario.\n");
                } else {
                    printf("Usuario registrado correctamente.\n");
                }

                destruir_usuario(nuevo_usuario);
                break;
            case 2:
                int id_usuario_encontrado;
                printf("Ingrese el ID del usuario a buscar: ");
                scanf("%d", &id_usuario_encontrado);
                int usuario_encontrado = buscar_usuario_recursivo(*lista_usuarios, id_usuario_encontrado);
               if(usuario_encontrado == 1) {
                    printf("Usuario encontrado\n");
                } else {
                    printf("Usuario no encontrado.\n");
                }
                // Llamar a la función para buscar usuario
                break;
            case 3:
                int id_usuario_buscado;
                printf("Ingrese el ID del usuario a eliminar: ");
                scanf("%d", &id_usuario_buscado);
                *lista_usuarios = eliminar_usuario(lista_usuarios,id_usuario_buscado);// Llamar a la función para eliminar usuario
                //printf("Usuario eliminado correctamente.\n");
                break;
            case 4: // Llamar a la función para ingresar dinero
                break;
            case 5:
                // Llamar a la función para retirar dinero
                break;
            case 6: int id_usuuario;
            printf("Ingrese el ID del usuario para consultar su saldo:");
            scanf("%d",&id_usuuario);
            consultar_saldo(*lista,id_usuuario);
          
                // consultar_saldo(&lista_usuarios,int id_usuario);// Llamar a la función para consultar saldo
                
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
        printf("Ingrese su opcion: ");
        scanf("%d",opcion);
    } while(*opcion != 7);

}