
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
ListaOperaciones*crear_operacion(int id_operacion, float monto, int tipo);
void ingresar_dinero(ListaUsuario **lista, float monto,int id_usuariooo);
void retirar_dinero(ListaUsuario **lista, float monto, int id_usuario);
void consultar_saldo(ListaUsuario *lista_usuario,int id_usuuario);

// Funciones recursivas
int buscar_operaciones_recursivo(ListaUsuario *lista_usuarios, int id_usuario);
int cant_operaciones_recursiva(ListaOperaciones *operacion);
#endif