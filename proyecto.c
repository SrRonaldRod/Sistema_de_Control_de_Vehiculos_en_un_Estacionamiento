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