
#include <ctime>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <string>
void limpiarPantalla() {
    system("cls");
}

void mostrarTitulo(const char *titulo) {
    printf("\n========================================\n");
    printf(" %s\n", titulo);
    printf("========================================\n");
}

void pausar() {
    system("pause"); 
}

int pago[10];
char fecha[10][11];
char hora[10][6];
char cedula[10][20];
char nombre[10][50];
char apellido1[10][50];
char apellido2[10][50];
int caja[10];
int servicio[10];
char factura[10][20];
float monto[10];
float comision[10];
float deducido[10];
float pagado[10];
float vuelto[10];
bool registrado[10] = {false};

void inicializar() {
    limpiarPantalla();
    mostrarTitulo("INICIALIZAR VECTORES");
    for (int i = 0; i < 10; i++) {
        registrado[i] = false;
    }
    printf("Vectores inicializados correctamente.\n");
    pausar();
}

void realizar() {
    limpiarPantalla();
    mostrarTitulo("REALIZAR PAGO");

    int i = 0;
    while (i < 10 && registrado[i]) {
        i++;
    }

    if (i == 10) {
        printf("¡Atención! No hay espacio para más pagos.\n");
        pausar();
        return;
    }

    pago[i] = i + 1;
    printf("Fecha (DD/MM/AAAA): ");
    scanf("%s", fecha[i]);
    printf("Hora (HH:MM): ");
    scanf("%s", hora[i]);
    printf("Cedula: ");
    scanf("%s", cedula[i]);
    printf("Nombre: ");
    scanf("%s", nombre[i]);
    printf("Apellido1: ");
    scanf("%s", apellido1[i]);
    printf("Apellido2: ");
    scanf("%s", apellido2[i]);
    caja[i] = rand() % 3 + 1;
    printf("Tipo de Servicio (1=Luz, 2=Telefono, 3=Agua): ");
    scanf("%d", &servicio[i]);
    printf("Numero de Factura: ");
    scanf("%s", factura[i]);
    printf("Monto a Pagar: ");
    scanf("%f", &monto[i]);

    switch (servicio[i]) {
        case 1:
            comision[i] = monto[i] * 0.04;
            break;
        case 2:
            comision[i] = monto[i] * 0.055;
            break;
        case 3:
            comision[i] = monto[i] * 0.065;
            break;
    }

    deducido[i] = monto[i] - comision[i];

    printf("Monto Pagado: ");
    scanf("%f", &pagado[i]);
    while (pagado[i] < monto[i]) {
        printf("El monto pagado no puede ser menor al monto a pagar. Ingrese nuevamente: ");
        scanf("%f", &pagado[i]);
    }

    vuelto[i] = pagado[i] - monto[i];

    registrado[i] = true;
    printf("\n¡Pago registrado exitosamente!\n");
    pausar();
}

void consultar() {
    limpiarPantalla();
    mostrarTitulo("CONSULTAR PAGO");

    int num;
    printf("Ingrese el NUMERO DE PAGO que desea consultar: ");
    scanf("%d", &num);

    int i = 0;
    while (i < 10 && (pago[i] != num || !registrado[i])) {
        i++;
    }

    if (i == 10) {
        printf("¡Error! Pago no registrado.\n");
        pausar();
        return;
    }

    printf("\n--- DETALLES DEL PAGO ---\n");
    printf("Numero de Pago: %d\n", pago[i]);
    printf("Fecha: %s\n", fecha[i]);
    printf("Hora: %s\n", hora[i]);
    printf("Cedula: %s\n", cedula[i]);
    printf("Nombre: %s %s %s\n", nombre[i], apellido1[i], apellido2[i]);
    printf("Caja: %d\n", caja[i]);
    printf("Servicio: %d\n", servicio[i]);
    printf("Factura: %s\n", factura[i]);
    printf("Monto: %.2f\n", monto[i]);
    printf("Comision: %.2f\n", comision[i]);
    printf("Deducido: %.2f\n", deducido[i]);
    printf("Pagado: %.2f\n", pagado[i]);
    printf("Vuelto: %.2f\n", vuelto[i]);

    pausar();
}

void modificar() {
    limpiarPantalla();
    mostrarTitulo("MODIFICAR PAGO");

    int num;
    printf("Ingrese el numero de pago a modificar: ");
    scanf("%d", &num);

    int i = 0;
    while (i < 10 && (pago[i] != num || !registrado[i])) {
        i++;
    }

    if (i == 10) {
        printf("¡Error! Pago no registrado.\n");
        pausar();
        return;
    }

    printf("\n--- DATOS ACTUALES ---\n");
    printf("Fecha: %s\n", fecha[i]);
    printf("Hora: %s\n", hora[i]);
    printf("Cedula: %s\n", cedula[i]);
    printf("Nombre: %s %s %s\n", nombre[i], apellido1[i], apellido2[i]);
    printf("Tipo de Servicio: %d\n", servicio[i]);
    printf("Factura: %s\n", factura[i]);
    printf("Monto a Pagar: %.2f\n", monto[i]);

    printf("\nIngrese los nuevos datos:\n");
    printf("Fecha (DD/MM/AAAA): ");
    scanf("%s", fecha[i]);
    printf("Hora (HH:MM): ");
    scanf("%s", hora[i]);
    printf("Cedula: ");
    scanf("%s", cedula[i]);
    printf("Nombre: ");
    scanf("%s", nombre[i]);
    printf("Apellido1: ");
    scanf("%s", apellido1[i]);
    printf("Apellido2: ");
    scanf("%s", apellido2[i]);
    printf("Tipo de Servicio (1=Luz, 2=Telefono, 3=Agua): ");
    scanf("%d", &servicio[i]);
    printf("Numero de Factura: ");
    scanf("%s", factura[i]);
    printf("Monto a Pagar: ");
    scanf("%f", &monto[i]);

    switch (servicio[i]) {
        case 1:
            comision[i] = monto[i] * 0.04;
            break;
        case 2:
            comision[i] = monto[i] * 0.055;
            break;
        case 3:
            comision[i] = monto[i] * 0.065;
            break;
    }

    deducido[i] = monto[i] - comision[i];

    printf("Monto Pagado: ");
    scanf("%f", &pagado[i]);
    while (pagado[i] < monto[i]) {
        printf("El monto pagado no puede ser menor al monto a pagar. Ingrese nuevamente: ");
        scanf("%f", &pagado[i]);
    }

    vuelto[i] = pagado[i] - monto[i];

    printf("\n¡Pago modificado exitosamente!\n");
    pausar();
}

void eliminar() {
    limpiarPantalla();
    mostrarTitulo("ELIMINAR PAGO");

    int num;
    printf("Ingrese el numero de pago a eliminar: ");
    scanf("%d", &num);

    int i = 0;
    while (i < 10 && (pago[i] != num || !registrado[i])) {
        i++;
    }

    if (i == 10) {
        printf("¡Error! Pago no registrado.\n");
        pausar();
        return;
    }

    char confirmar;
    printf("¿Está seguro de eliminar el pago? (S/N): ");
    scanf(" %c", &confirmar);

    if (confirmar == 'S' || confirmar == 's') {
        registrado[i] = false;
        printf("\n¡Pago eliminado exitosamente!\n");
    } else {
        printf("\nEliminación cancelada.\n");
    }

    pausar();
}

void reportes() {
    int opcion;
    float total = 0;

    do {
        limpiarPantalla();
        mostrarTitulo("SUBMENU REPORTES");
        printf("1. Ver todos los pagos\n");
        printf("2. Ver pagos por tipo de servicio\n");
        printf("3. Ver pagos por codigo de caja\n");
        printf("4. Ver dinero comisionado por servicios\n");
        printf("5. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                limpiarPantalla();
                mostrarTitulo("TODOS LOS PAGOS");
                for (int i = 0; i < 10; i++) {
                    if (registrado[i]) {
                        printf("Pago %d: %s, %s, Monto: %.2f\n", pago[i], fecha[i], hora[i], monto[i]);
                    }
                }
                pausar();
                break;
            case 2:
                limpiarPantalla();
                mostrarTitulo("PAGOS POR TIPO DE SERVICIO");
                int tipo;
                printf("Ingrese el tipo de servicio (1=Luz, 2=Telefono, 3=Agua): ");
                scanf("%d", &tipo);
                for (int i = 0; i < 10; i++) {
                    if (registrado[i] && servicio[i] == tipo) {
                        printf("Pago %d: %s, %s, Monto: %.2f\n", pago[i], fecha[i], hora[i], monto[i]);
                    }
                }
                pausar();
                break;
            case 3:
                limpiarPantalla();
                mostrarTitulo("PAGOS POR CODIGO DE CAJA");
                int codigo;
                printf("Ingrese el codigo de caja (1-3): ");
                scanf("%d", &codigo);
                for (int i = 0; i < 10; i++) {
                    if (registrado[i] && caja[i] == codigo) {
                        printf("Pago %d: %s, %s, Monto: %.2f\n", pago[i], fecha[i], hora[i], monto[i]);
                    }
                }
                pausar();
                break;
            case 4:
                limpiarPantalla();
                mostrarTitulo("DINERO COMISIONADO POR SERVICIOS");
                total = 0;
                for (int i = 0; i < 10; i++) {
                    if (registrado[i]) {
                        total += comision[i];
                    }
                }
                printf("Total comisionado: %.2f\n", total);
                pausar();
                break;
            case 5:
                printf("Regresando al menu principal...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                pausar();
        }
    } while (opcion != 5);
}

int main() {
    srand(time(NULL));
    int opcion;
    do {
        limpiarPantalla();
        mostrarTitulo("MENU PRINCIPAL");
        printf("1. Inicializar Vectores\n");
        printf("2. Realizar Pagos\n");
        printf("3. Consultar Pagos\n");
        printf("4. Modificar Pagos\n");
        printf("5. Eliminar Pagos\n");
        printf("6. Submenu Reportes\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                inicializar();
                break;
            case 2:
                realizar();
                break;
            case 3:
                consultar();
                break;
            case 4:
                modificar();
                break;
            case 5:
                eliminar();
                break;
            case 6:
                reportes();
                break;
            case 7:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                pausar();
        }
    } while (opcion != 7);

    return 0;
}
