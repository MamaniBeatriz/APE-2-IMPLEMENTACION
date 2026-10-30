#include<stdio.h>
#include<stdlib.h>
#include "tUsuario.h"

void mostrar_menu_usuario(int *opcion);

int main(){
    int opcion;
    mostrar_menu_usuario(&opcion);
    return 0;
}


void mostrar_menu_usuario(int *opcion){
    printf("1. Registrar usuario\n");
    printf("2. Buscar usuario\n");
    printf("3. Eliminar usuario\n");
    printf("4. Ingresar dinero\n");
    printf("5. Retirar dinero\n");
    printf("6. Consultar saldo\n");
    printf("7. Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%d", &opcion);
    do{
        switch(*opcion){
            case 1:
                // Llamar a la función para registrar usuario
                break;
            case 2:
                // Llamar a la función para buscar usuario
                break;
            case 3:
                // Llamar a la función para eliminar usuario
                break;
            case 4:
                // Llamar a la función para ingresar dinero
                break;
            case 5:
                // Llamar a la función para retirar dinero
                break;
            case 6:
                // Llamar a la función para consultar saldo
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
        printf("Ingrese su opcion: ");
        scanf("%d", opcion);
    } while(*opcion != 7);

}