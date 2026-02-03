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

int main() {
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