
#ifndef DATAWHEREHOUSE_H_INCLUDED
#define DATAWHEREHOUSE_H_INCLUDED
typedef struct{
int id;
char nombreColor[20];
}eColor;

typedef struct{
int id;
char descripcion[20];
}eTipo;
typedef struct{
int id;
char descripcion[20];
float precio;

}eServicio;


#endif // DATAWHEREHOUSE_H_INCLUDED
eColor colores[] = {{5000, "gris"}, {5001, "negro"}, {5002, "blanco"}, {5003, "azul"}, {5004, "rojo"}};
eTipo tipos[] = {{1000, "rutera"}, {1001, "carrera"}, {1002, "mountain"}, {1003, "BMX"}};
eServicio servicios[] = {{20000, "limpieza", 250},{20001, "parche", 300}, {20002, "centrado", 400}, {20003, "cadena", 350}};

