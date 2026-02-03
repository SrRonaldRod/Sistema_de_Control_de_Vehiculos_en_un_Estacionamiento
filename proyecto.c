#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PRECIO_HORA 5

typedef struct {
    char placa[10];
    char tipo[20];
    int horaEntrada;
    int horaSalida;
    int montoPagado;
    int estaActivo;   // 1 si esta dentro, 0 si ya salio
} Vehiculo;

// --- FUNCIONES DE APOYO ---

void limpiarConsola() {
    int caracter;
    while ((caracter = getchar()) != '\n' && caracter != EOF);
}

int esNumeroPuro(char cadena[]) {
    int i = 0;
    if (cadena[0] == '\0') return 0;
    while (cadena[i] != '\0') {
        if (!isdigit(cadena[i])) return 0;
        i++;
    }
    return 1;
}

int verificarPlacaRepetida(char placaAComparar[], Vehiculo lista[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].estaActivo == 1 && strcmp(lista[i].placa, placaAComparar) == 0) {
            return 1;
        }
    }
    return 0; 
}

int validarFormatoPlaca(char placaTexto[]) {
    int largo = strlen(placaTexto);
    if (largo < 3 || largo > 8) {
        printf("[!] ERROR: La placa debe tener entre 3 y 8 caracteres.\n");
        return 0;
    }
    for (int i = 0; i < largo; i++) {
        if (!isalnum(placaTexto[i])) {
            printf("[!] ERROR: Solo se permiten letras y numeros.\n");
            return 0;
        }
    }
    return 1;
}

int validarHoraCorrecta(int horaDigitada) {
    if (horaDigitada < 0 || horaDigitada > 23) {
        printf("[!] ERROR: La hora debe ser entre 0 y 23.\n");
        return 0;
    }
    return 1;
}

// --- LOGICA PRINCIPAL DEL SISTEMA ---

int registrarEntrada(Vehiculo lista[], int cantidadActual, int limiteMaximo) {
    if (cantidadActual >= limiteMaximo) {
        printf("\n[!] Estacionamiento lleno.\n");
        return cantidadActual;
    }

    char placaTemporal[10];
    char entradaAux[100];
    printf("\n--- REGISTRO DE ENTRADA ---\n");
    
    do {
        printf("Placa: ");
        scanf("%s", placaTemporal);
        limpiarConsola();
        
        for(int i=0; placaTemporal[i]; i++) placaTemporal[i] = toupper(placaTemporal[i]);

        if (!validarFormatoPlaca(placaTemporal)) continue;
        if (verificarPlacaRepetida(placaTemporal, lista, cantidadActual)) {
            printf("[!] ERROR: El vehiculo %s ya esta en el estacionamiento.\n", placaTemporal);
            continue;
        }
        break;
    } while (1);

    strcpy(lista[cantidadActual].placa, placaTemporal);

    int seleccionTipo = 0;
    do {
        printf("Tipo (1. Auto, 2. Moto, 3. Camioneta): ");
        scanf("%s", entradaAux);
        limpiarConsola();
        if (esNumeroPuro(entradaAux)) {
            seleccionTipo = atoi(entradaAux);
            if (seleccionTipo < 1 || seleccionTipo > 3) {
                printf("[!] ERROR: Seleccione 1, 2 o 3.\n");
                seleccionTipo = 0;
            }
        } else {
            printf("[!] ERROR: Ingrese solo el numero, sin letras.\n");
        }
    } while (seleccionTipo == 0);

    if (seleccionTipo == 1) strcpy(lista[cantidadActual].tipo, "Auto");
    else if (seleccionTipo == 2) strcpy(lista[cantidadActual].tipo, "Moto");
    else strcpy(lista[cantidadActual].tipo, "Camioneta");

// --- PROGRAMA PRINCIPAL ---

int main() {
       int capacidadEstacionamiento = 0;
    char entradaAux[100];

    printf("--- CONFIGURACION DE CAPACIDAD ---\n");
    do {
        printf("Elija tama\xa4o (S: 20, M: 50, L: 100): ");
        scanf("%s", entradaAux);
        limpiarConsola();

        if (strlen(entradaAux) > 1) {
            printf("[!] ERROR: Ingrese solo una letra.\n");
            continue;
        }

        char letra = toupper(entradaAux[0]);
        if (letra == 'S') capacidadEstacionamiento = 20;
        else if (letra == 'M') capacidadEstacionamiento = 50;
        else if (letra == 'L') capacidadEstacionamiento = 100;
        else printf("[!] ERROR: Opcion invalida.\n");

    } while (capacidadEstacionamiento == 0);

    Vehiculo listaGlobal[capacidadEstacionamiento];
    int cantidadVehiculos = 0;
    int opcionMenu;

    do {
        printf("\n--- SISTEMA DE CONTROL DE ESTACIONAMIENTO ---\n");
        printf("1. Registrar Entrada\n");
        printf("2. Registrar Salida (Cobrar)\n");
        printf("3. Mostrar listado de vehiculos\n");
        printf("4. Contar vehiculos actuales (Recursivo)\n");
        printf("5. Guardar registros y Salir\n");
        printf("Seleccione una opcion: ");
        
        scanf("%s", entradaAux);
        limpiarConsola();

        if (esNumeroPuro(entradaAux)) {
            opcionMenu = atoi(entradaAux);
        } else {
            opcionMenu = 0; 
        }
    
    printf("Integrantes:\n");
printf("Ronald Rodriguez C.I: 31.762.090\n");
printf ("Manuel Rodríguez C.I: 31.657.231\n");
printf ("Jaiverson Infante C.I: 31.797.621\n");
printf ("Alexander Sánchez C.I: 31.644.118\n");
printf ("David Torres C.I:31.762.289\n");
printf ("Alexander Rodríguez C.I: 31.797.479\n");
printf ("Jean Paul Gonzalez C.I: 31.547.107\n");
    return 0;
    }
}   