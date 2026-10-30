
#ifndef TUSUARIO_H
#define TUSUARIO_H

 typedef struct Usuario Usuario;
 typedef struct ListaUsuario  ListaUsuario;
 typedef struct ListaOperaciones ListaOperaciones;
// Funciones para manejar la lista de usuarios
ListaUsuario* registrar_usuario(ListaUsuario **lista, Usuario nuevo_usuario);
ListaUsuario* eliminar_usuario(ListaUsuario **lista, int id_usuario_eliminar);
// Funciones para manejar las operaciones de los usuarios
void ingresar_dinero(ListaUsuario *lista, float monto, char *fecha);
void retirar_dinero(ListaUsuario *lista, float monto, char *fecha);
float consultar_saldo(ListaUsuario *lista);

// Funciones recursivas
int contar_operaciones_recursivo(ListaUsuario *lista);
int buscar_usuario_recursivo(ListaUsuario *lista,int id_usuario_buscado);



#endif