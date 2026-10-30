 #ifndef TOPERACION_H
 #define TOPERACION_H
 //ESTRUCTURAS 
 typedef struct Operaciones{//guarda la informacion de una operacion 
    int ID_operaciones;
    float monto;
    int tipo;
    char fecha[11];
}Operaciones;

typedef struct ListaOperaciones{
    Operaciones dato;//guarda los datos de una operacion 
     int cant_operaciones;//guarda la cantidad de operaciones realizadas por ese usuario
    struct ListaOperaciones *sgte;// apunta a la siguiente operacion realizada por ese mismo usuario 
}ListaOperaciones;

#endif

