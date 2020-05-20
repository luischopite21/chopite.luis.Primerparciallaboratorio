#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "datawherehouse.h"

#define TAM 5
#define CANT 5
#define TAMTIPOS 4
#define TAMCOLORES 5
#define TAMSERVICIOS 4
#define TAMTRABAJOS 100
#define TAMCLIENTES 100

typedef struct
{
    int dia;
    int mes;
    int anio;

} efecha;



typedef struct{
int id;
char marca[20];
int idTipo;
int idColor;
float rodado;
int isEmpty;
int idCliente;

}eBicicleta;



typedef struct{
int id;
int idBicicleta;
int idServicio;
efecha fecha;
int isEmpty;
}eTrabajo;

typedef struct{
int id;
char nombre[20];
char sexo;


}eClientes;



int menuAmable();
void hardcodearServicios(eServicio x[], int cant);
void hardcodearTipos(eTipo x[], int cant, eColor colores[]);
int buscarLibre(eBicicleta x[], int tam);
void hardcodearColores(eColor x[], int cant);
int altaBicicleta(int idx, eBicicleta x[], int tam, eClientes cliente[], int idCliente, int tamClientes);
void inicializarBicicletas(eBicicleta x[], int tam);
int buscarBicicleta(int idx, eBicicleta x[], int tam);
int DescripcionColor(int idx, eColor color[], int tamColores);
int DescripcionTipo(int idx, eTipo tipo[], int tamTipos);
void mostrarBicicleta(eBicicleta x, int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes clientes[], int tamClientes, int idCliente);
void bajaBicicleta(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int idCliente, int tamClientes);
int menuModificar();
void modificarBicicleta(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
void mostrarBicicletas(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
void mostrarTipos(eTipo tipo[], int tamTipos);
void mostrarColores(eColor color[], int tamColores);
void mostrarServicios(eServicio servicio[], int tamServicios);
int altaTrabajo(eTrabajo y[], int idTrabajo, eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eServicio servicio[], int tamServicio, eClientes cliente[], int tamClientes, int idCliente);
void mostrarTrabajos(eTrabajo x[], int tamTrabajos);
void inicializarTrabajos(eTrabajo x[], int tamTrabajos);
int mostrarDescripcionCliente(eClientes x[], int tamClientes, int id, char descripcion[]);
void informes(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
int menuInformes();
void MostrarBiciColor(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
void MostrarBiciTipo(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
void MostrarBiciMenorRodado(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);
void MostrarBiciColorMayor(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente);


int main()
{
    int proximoid = 100;
    int proximoTrabajo = 1;
    int proximoCliente = 6000;
    eBicicleta biciclestas[TAM];
    eTrabajo trabajos[TAMTRABAJOS];
    eClientes clientes[TAMCLIENTES];
    char continuar = 's';
    char confirma;
    inicializarBicicletas(biciclestas, TAM);
    inicializarTrabajos(trabajos, TAMTRABAJOS);
    do
    {
        system("cls");
        switch(menuAmable())
        {
        case 1:
          if(altaBicicleta(proximoid, biciclestas, TAM, clientes, proximoCliente, TAMCLIENTES)){
            proximoid++;
            proximoCliente++;
          }
            break;
        case 2:
            modificarBicicleta(biciclestas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, clientes, TAMCLIENTES, proximoCliente);
            break;
        case 3:
          bajaBicicleta(biciclestas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, clientes, proximoCliente, TAMCLIENTES);
            break;
        case 4:
             printf("\n id      marca    color       tipo      rodado  cliente\n\n");
            mostrarBicicletas(biciclestas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, clientes, TAMCLIENTES, proximoCliente);
            break;
        case 5:
            mostrarTipos(tipos, TAMTIPOS);
            break;
        case 6:
             mostrarColores(colores, TAMCOLORES);
            break;

            case 7:
             mostrarServicios(servicios, TAMSERVICIOS);
            break;
            case 8:
                if(altaTrabajo(trabajos, proximoTrabajo, biciclestas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, servicios, TAMSERVICIOS, clientes, TAMCLIENTES, proximoCliente)){
                    proximoTrabajo++;
                };

            break;
            case 9:
             mostrarTrabajos(trabajos, TAMTRABAJOS);
            break;
             case 10:
         informes(biciclestas, TAM, colores, TAMCOLORES, tipos, TAMTIPOS, clientes, TAMCLIENTES, proximoCliente);
            break;
        case 0:
            printf("\ndesea salir? s/n: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                continuar = 'n';
            }
            break;
        }
        system("pause");
        printf("\n\n");
    }
    while(continuar == 's');




    return 0;
}

int menuAmable()
{
    system("cls");
    int opcion;
    printf("**** Menu de opciones: ****\n\n");
    printf("1- alta bicicleta \n");
    printf("2- modificar bicicleta \n");
    printf("3- baja bicicleta \n");
    printf("4- listar bicicletas \n");
    printf("5- listar tipos \n");
    printf("6- listar colores \n");
    printf("7- listar servicios \n");
    printf("8- alta trabajo \n");
    printf("9- listar trabajo \n");
    printf("10- Informes \n");
    printf("0- salir \n\n");
    printf("elija una opcion para continuar: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;


}

void hardcodearColores(eColor x[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        x[i].id = colores[i].id;
        strcpy(x[i].nombreColor, colores[i].nombreColor);


    }


}

void hardcodearTipos(eTipo x[], int cant, eColor colores[])
{
    for(int i = 0; i < cant; i++)
    {
        x[i].id = tipos[i].id;
        strcpy(x[i].descripcion, colores[i].nombreColor);


    }


}

void hardcodearServicios(eServicio x[], int cant)
{
    for(int i = 0; i < cant; i++)
    {
        x[i].id = servicios[i].id;
        strcpy(x[i].descripcion, servicios[i].descripcion);
        x[i].precio = servicios[i].precio;


    }


}

int altaBicicleta(int idx, eBicicleta x[], int tam, eClientes cliente[], int idCliente, int tamClientes)
{
    int altaExitosa = 0;
    int indice;
    eBicicleta aux;
    eClientes auxi;
    int color;
    float rodado;
    int tipo;
    indice = buscarLibre(x, tam);


    system("cls");
    printf("**** Alta de Bicicletas ****\n\n");
    if(indice == -1)
    {
        printf("sistema completo\n\n");

    }
    else
    {
        aux.id = idx;
        printf("\nindique la marca: ");
        fflush(stdin);
        gets(aux.marca);


        system("cls");
        printf("opciones: \n");
        printf("-----------\n20\n\n----------- \n26\n\n----------- \n27.5\n\n----------- \n29\n-----------");
        printf("\nindique el rodado: ");
        scanf("%f", &rodado);

        while(rodado != 20 && rodado != 26 && rodado != 27.5 && rodado != 29){
            printf("\nerror ingrese una opcion valida: ");
            scanf("%f", &rodado);

        }
        aux.rodado = rodado;

        system("cls");
        printf("opciones: \n");
        printf("-----------\n1 gris\n\n----------- \n2 negro\n\n----------- \n3 blanco\n\n----------- \n4 azul\n\n----------- \n5 rojo\n\n-----------");
        printf("\nindique el color: ");
        scanf("%d", &color);
         while(color < 1 || color > 5){
            printf("\nerror ingrese una opcion valida: ");
            scanf("%d", &color);
         }
         aux.idColor = color - 1;

        system("cls");
        printf("opciones: \n");
        printf("-----------\n1 rutera\n\n----------- \n2 carrera\n\n----------- \n3 mountain\n\n----------- \n4 BMX\n\n-----------");
        printf("\nindique el tipo: ");
        scanf("%d", &tipo);
         while(tipo < 1 || tipo > 4){
            printf("\nerror ingrese una opcion valida: ");
            scanf("%d", &tipo);


         }
          printf("\ningrese nombre del cliente: ");
        fflush(stdin);
        gets(auxi.nombre);

        printf("\n\ningrese el sexo del cliente: ");
        fflush(stdin);
        scanf("%c", &auxi.sexo);

        auxi.id = idCliente;

         aux.idTipo = tipo - 1;

        aux.isEmpty = 0;
        cliente[indice] = auxi;

        x[indice] = aux;
        altaExitosa = 1;

        printf("alta realizada con exito\n\n");
    }
    return altaExitosa;

}


void inicializarBicicletas(eBicicleta x[], int tam)
{
    for(int i = 0; i <  tam; i++)
    {

        x[i].isEmpty = 1;

    }


}

int buscarLibre(eBicicleta x[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if( x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
void bajaBicicleta(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int idCliente, int tamClientes){
    int buscado;
    int existe;
    char confirmar;
    system("cls");
    printf("\n**** Baja de bicicletas ****\n\n");
    printf("ingrese id: ");
    scanf("%d", &buscado);
    existe = buscarBicicleta(buscado, x, tam);
    if(existe == -1 || x[existe].isEmpty != 0)
    {
        system("cls");
        printf("\nNo existe una bicicleta con ese id\n\n");
    }
    else
    {
     printf("\n id      marca    color       tipo      rodado\n\n");
        mostrarBicicleta(x[existe], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
        printf("\nconfirma la baja? s/n: ");
        fflush(stdin);
        scanf("%c", &confirmar);
        if(confirmar == 's')
        {
            x[existe].isEmpty = 1;
            printf("\nOperacion exitosa.\n\n");
        }
        else
        {
            printf("\nOperacion cancelada.\n\n");
        }

    }
}
int buscarBicicleta(int idx, eBicicleta x[], int tam)
{
    int existe = -1;
    for(int i = 0; i < tam; i++)
    {
        if(x[i].id == idx)
        {
            existe = i;
            break;
        }
    }

    return existe;
}


void mostrarBicicleta(eBicicleta x, int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes clientes[], int tamClientes, int idCliente)
{
    char colorDescripcion[20];
    char tipoDescripcion[20];
    char nombreCliente[20];
    int idColorBicicleta = x.idColor;
    int indColorBuscado;
    int idTipoBicicleta = x.idTipo;
    int indTipoBuscado;
    if(x.isEmpty == 0)
    {
        mostrarDescripcionCliente(clientes, tamClientes, idCliente, nombreCliente);

        indColorBuscado = DescripcionColor(idColorBicicleta, color, tamColores);
        strcpy(colorDescripcion, color[indColorBuscado].nombreColor);

        indTipoBuscado = DescripcionTipo(idTipoBicicleta, tipo, tamTipos);
        strcpy(tipoDescripcion, tipo[indTipoBuscado].descripcion);



        printf("%4d ---  %s ---  %s ---  %s --- %.1f %s\n\n", x.id, x.marca, colorDescripcion, tipoDescripcion, x.rodado, nombreCliente);

    }
    else
    {

        printf("no hay bicicletas para listar\n");

    }
}
int DescripcionTipo(int idx, eTipo tipo[], int tamTipos)
{

    int idTipo;
    for(int i = 0; i < tamTipos; i++)
    {
        if(idx == tipos[i].id)
        {
            idTipo = i;
            break;
        }
    }

    return idTipo;
}

int DescripcionColor(int idx, eColor color[], int tamColores)
{

    int idColor;
    for(int i = 0; i < tamColores; i++)
    {
        if(idx == colores[i].id)
        {
            idColor = i;
            break;
        }
    }

    return idColor;
}

void modificarBicicleta(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente)
{
    int buscado;
    int existe;
    eBicicleta aux;
    float rodado;
    int tipoo;
    system("cls");
    printf("\n**** Modificar Bicicleta ****\n\n");
    printf("ingrese id:");
    scanf("%d", &buscado);
    existe = buscarBicicleta(buscado, x, tam);
    if(existe == -1 || x[existe].isEmpty != 0)
    {
        system("cls");
        printf("\nNo existe una bicicleta registrada con ese id\n\n");
    }
    else
    {
        printf("\n id      marca    color       tipo      rodado\n\n");
        mostrarBicicleta(x[existe], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
        switch(menuModificar())
        {
        case 1:
            system("cls");
            printf("\n\nIngrese nuevo rodado:\n");
            printf("opciones: \n");
        printf("-----------\n20\n\n----------- \n26\n\n----------- \n27.5\n\n----------- \n29\n-----------");
        printf("\nindique el rodado: ");
        scanf("%f", &rodado);

        while(rodado != 20 && rodado != 26 && rodado != 27.5 && rodado != 29){
            printf("\nerror ingrese una opcion valida: ");
            scanf("%f", &rodado);

        }
        aux.rodado = rodado;
        x[existe].rodado = aux.rodado;
         printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;

        case 2:
             printf("\n\nIngrese nuevo Tipo:\n");

            system("cls");
             printf("opciones: \n");
        printf("-----------\n1 rutera\n\n----------- \n2 carrera\n\n----------- \n3 mountain\n\n----------- \n4 BMX\n\n-----------");
        printf("\nindique el tipo: ");
        scanf("%d", &tipoo);
         while(tipoo < 1 || tipoo > 4){
            printf("\nerror ingrese una opcion valida: ");
            scanf("%d", &tipoo);
         }
         aux.idTipo = tipoo - 1;
          x[existe].idTipo = aux.idTipo;
            printf("\n\nModificacion realizada de manera exitosa\n\n");
            break;

}
}
}

int menuModificar()
{
    int opcion;
    printf("\nque desea modificar?: \n\n");
    printf("1---- Rodado\n\n");
    printf("2---- Tipo\n\n");
    scanf("%d", &opcion);



    return opcion;




}

void mostrarBicicletas(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){
   int flag = 0;
   eBicicleta aux;

   for(int i = 0; i < tam - 1; i++){
    for(int j = i + 1; j < tam; j++){
        if(x[i].idTipo < x[j].idTipo){
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
        }else if(x[i].idTipo == x[j].idTipo && x[i].rodado < x[j].rodado){
        aux = x[i];
            x[i] = x[j];
            x[j] = aux;

        }

    }


   }
for(int i = 0; i < tam; i++){
    if(x[i].isEmpty == 0){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
        flag = 1;
    }
}
if(flag == 0){
        system("cls");
    printf("no hay bicicletas listadas\n\n");
}


}


void mostrarTipos(eTipo tipo[], int tamTipos){
    system("cls");
    printf("\n\nTipos de bicicletas: \n\n");
    printf("\n id ---- tipo \n\n");
for(int i = 0; i < tamTipos; i++){
    printf("\n%d ---- %s\n\n", tipo[i].id, tipo[i].descripcion);
    printf("\n----------------------------------\n\n");
}


}

void mostrarColores(eColor color[], int tamColores){
    system("cls");
    printf("\n\nColores de bicicletas: \n\n");
     printf("\n id ---- Color \n\n");
for(int i = 0; i < tamColores; i++){
    printf("\n%d ---- %s\n\n", color[i].id, color[i].nombreColor);
     printf("\n----------------------------------\n\n");
}


}

void mostrarServicios(eServicio servicio[], int tamServicios){
    system("cls");
    printf("\n\nServicios de bicicletas: \n\n");
     printf("\n id ---- tipo ---- precio \n\n");
for(int i = 0; i < tamServicios; i++){
    printf("\n%d ---- %s ---- %.2f$\n\n", servicio[i].id, servicio[i].descripcion, servicio[i].precio);
     printf("\n----------------------------------\n\n");
}


}

int altaTrabajo(eTrabajo y[], int idTrabajo, eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eServicio servicio[], int tamServicio, eClientes cliente[], int tamClientes, int idCliente)
{
    int todoOk = 0;
eTrabajo aux;
int indTrabajo = 0;
idTrabajo = aux.id;
idTrabajo++;
mostrarBicicletas(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
printf("\n\nelija una Bicicleta: ");
scanf("%d", &aux.idBicicleta);
mostrarServicios(servicio, tamServicio);
printf("\n\nelija un servicio:");
scanf("%d", &aux.idServicio);
printf("\n\nElija Fecha del alta dd/mm/aaaa: ");
scanf("%d/%d/%d", &aux.fecha.dia, aux.fecha.mes, aux.fecha.anio);
aux.isEmpty = 0;
y[indTrabajo] = aux;
indTrabajo++;

system("cls");
printf("\n\nalta realizada exitosamente");
todoOk = 1;
return todoOk;

}

void mostrarTrabajos(eTrabajo x[], int tamTrabajos){
    int flag = 0;
    printf("\nid  bicicleta  Servicio  fecha \n\n");
for(int i = 0; i < tamTrabajos; i++){
        if(x[i].isEmpty == 0){
    printf("%d ---- %d ---- %d ---- %d/%d/%d", x[i].id, x[i].idBicicleta, x[i].idServicio, x[i].fecha.dia, x[i].fecha.mes, x[i].fecha.anio);
    flag = 1;
        }
}
if(flag == 0){
printf("no hay trabajos que mostrar\n");
}
}

void inicializarTrabajos(eTrabajo x[], int tamTrabajos)
{
    for(int i = 0; i <  tamTrabajos; i++)
    {

        x[i].isEmpty = 1;

    }


}
int mostrarDescripcionCliente(eClientes x[], int tamClientes, int id, char descripcion[]){
  int todoOk = 0;
    for(int i = 0; i < tamClientes; i++){
        if(x[i].id == id)
        {
            strcpy(descripcion, x[i].nombre);
            todoOk = 1;

        }



    }

return todoOk;

}

void informes(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){
 char continuar = 's';
    char confirma;

    do
    {
        system("cls");
        switch(menuInformes())
        {
        case 1:
     MostrarBiciColor(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
            break;
        case 2:
           MostrarBiciTipo(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
            break;
        case 3:
        MostrarBiciMenorRodado(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
            break;
        case 4:
            MostrarBiciPorTipo(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
            break;
        case 5:
         printf("5");
            break;
        case 6:
          MostrarBiciColorMayor(x, tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
            break;

            case 7:
            printf("7");
            break;
            case 8:
printf("8");
            break;
            case 9:
            printf("9");
            break;
             case 10:
             printf("10");
            break;
        case 0:
            printf("\ndesea salir? s/n: \n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                continuar = 'n';
            }
            break;
        }
        system("pause");
        printf("\n\n");
    }
    while(continuar == 's');







}

int menuInformes(){



system("cls");
    int opcion;
    printf("**** Menu de Informes: ****\n\n");
    printf("1- Mostrar bicicletas por el color seleccionado \n");
    printf("2- mostrar bicicleta por el tipo seleccionado \n");
    printf("3- informar las bicicletas de menor rodado\n");
    printf("4- listar bicicletas por tipo\n");
    printf("5- contar bicicleta por color y tipo \n");
    printf("6- mostrar los colores mas elegidos \n");
    printf("7- mostrar trabajos de una bicicleta \n");
    printf("8- mostrar gastos de una bicicleta\n");
    printf("9- listar Servicios realizados \n");
    printf("10- Informar servicios realizados por fecha \n");
    printf("0- salir \n\n");
    printf("elija una opcion para continuar: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;


}

void MostrarBiciColor(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){
    int colorBuscado;
    mostrarColores(color, tamColores);
    printf("por cual color desea buscar?: ");
    scanf("%d", &colorBuscado);

for(int i = 0; i < tam; i++){
    if(colorBuscado == x[i].idColor){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
    }


}
}
void MostrarBiciTipo(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){
    int TipoBuscado;

    mostrarTipos(tipo, tamTipos);
    printf("por cual tipo desea buscar?: ");
    scanf("%d", &TipoBuscado);


for(int i = 0; i < tam; i++){
    if(TipoBuscado == x[i].idTipo){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
    }


}

}

void MostrarBiciMenorRodado(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){
 float RodadoBuscado;

    printf("por cual rodado deseas buscar?: ");
    scanf("%d", &RodadoBuscado);


for(int i = 0; i < tam; i++){
    if(RodadoBuscado == x[i].rodado){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
    }


}



}

void MostrarBiciPorTipo(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){


for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam; j++){
    if(x[i].idTipo == x[j].idTipo){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
    }
    }


}



}

void MostrarBiciColorMayor(eBicicleta x[], int tam, eColor color[], int tamColores, eTipo tipo[], int tamTipos, eClientes cliente[], int tamClientes, int idCliente){

    int colorBuscado;
    int contador = 0;


for(int i = 0; i < tam; i++){
    if(colorBuscado == x[i].idColor){
        mostrarBicicleta(x[i], tam, color, tamColores, tipo, tamTipos, cliente, tamClientes, idCliente);
        contador++;
    }


}
printf("existen %d bicicletas del color buscado", contador);
}

