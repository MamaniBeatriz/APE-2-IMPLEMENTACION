
#ifndef TUSUARIO_H
#define TUSUARIO_H

 typedef struct Usuario Usuario;
 typedef struct ListaUsuario  ListaUsuario;
 typedef struct tFecha tFecha;
 typedef struct ListaOperaciones ListaOperaciones;
// Funciones para manejar la lista de usuarios
Usuario* registrar_usuario(ListaUsuario **lista, Usuario *nuevo_usuario);
Usuario* crear_usuario(int id_usuario, const char *nombre, float saldo);
void destruir_usuario(Usuario *usuario);
ListaUsuario* eliminar_usuario(ListaUsuario **lista_usuarios, int id_usuario_buscado);
// Funciones para manejar las operaciones de los usuarios
tFecha obtenerFecha();
void ingresar_dinero(ListaUsuario *lista, float monto, char *fecha);
void retirar_dinero(ListaUsuario *lista, float monto, char *fecha);
float consultar_saldo(ListaUsuario *lista);

// Funciones recursivas
int contar_operaciones_recursivo(ListaUsuario *lista);
int buscar_usuario_recursivo(ListaUsuario *lista,int id_usuario_buscado);


#endif