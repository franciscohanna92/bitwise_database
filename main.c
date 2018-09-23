#include <stdio.h>
#include <stdlib.h>
#include "lib/types.h"
#include "lib/methods.h"

struct Person people[] = {
        {"Gibby Pointin",     "514 Buena Vista Plaza",    "28250839", 1, 0, 0, 0, 1, 1, 1, 1},
        {"Delphinia Bartolo", "398 Thierer Center",       "20838528", 0, 1, 0, 1, 0, 0, 0, 0},
        {"Maje Gronowe",      "0 Eastlawn Trail",         "13872533", 1, 1, 1, 0, 0, 0, 1, 1},
        {"Melva Snowsill",    "59 Eliot Street",          "44932555", 0, 0, 1, 0, 0, 0, 1, 0},
        {"Osmund Norcop",     "56803 Schiller Place",     "10977960", 1, 0, 1, 1, 1, 0, 0, 1},
        {"Ingra Harbage",     "46368 Waubesa Alley",      "34175246", 0, 1, 1, 1, 1, 1, 1, 1},
        {"Nathanil Steeples", "248 John Wall Trail",      "46219182", 0, 1, 0, 0, 0, 0, 0, 1},
        {"Moria Jurasz",      "64 Lukken Crossing",       "10308278", 1, 0, 1, 0, 0, 1, 1, 1},
        {"Margarethe Pratte", "1909 Onsgard Road",        "34799551", 1, 1, 0, 0, 0, 1, 1, 0},
        {"Vanny Conklin",     "1339 Summer Ridge Circle", "30038417", 1, 0, 1, 0, 1, 0, 1, 0},
        {"El Duckfield",      "27 Canary Parkway",        "18206348", 0, 1, 0, 0, 0, 1, 1, 1},
        {"Teddie Matyushkin", "11 Orin Point",            "45782218", 1, 1, 1, 0, 0, 0, 0, 0},
        {"Maurise Sellor",    "6133 Russell Way",         "43032637", 1, 0, 1, 0, 1, 0, 1, 1},
        {"Northrop Juszczyk", "378 Porter Park",          "37213320", 0, 1, 0, 1, 0, 0, 1, 1},
        {"Hilary Setch",      "33 School Drive",          "43547160", 0, 1, 0, 0, 0, 1, 0, 1},
        {"Meta Treen",        "4091 Melby Court",         "18353621", 0, 0, 1, 1, 1, 1, 1, 0},
        {"Miranda Cowderoy",  "82749 Mandrake Crossing",  "14528296", 1, 0, 1, 0, 0, 0, 1, 0},
        {"Emlynn Cardus",     "16159 Oriole Street",      "17127670", 0, 1, 1, 0, 0, 1, 0, 0},
        {"Vanya Burnyate",    "851 8th Drive",            "21841053", 1, 0, 0, 1, 1, 0, 1, 1},
        {"John Wayne",        "513 Waubesa Trail",        "36708282", 0, 1, 0, 1, 0, 1, 1, 1}
};

void printMenu() {
    printf("\n1. Escribir datos con longitud fija\n");
    printf("2. Leer datos con longitud fija\n");
    printf("3. Escribir datos con longitud variable\n");
    printf("4. Leer datos con longitud variable\n");
    printf("5. Comparar tamaños de archivos\n");
    printf("0. Salir\n\n");

    printf("Ingrese una opción: ");
}


void writeFileFixedLength(int people_count) {
    FILE *fp;
    fp = fopen("../resources/fixed_length.dat", "wb+");
    printf("\nEscribiendo datos con tamaño fijo...");
    for (int i = 0; i < people_count; ++i) {
        writeFixedLength(people[i], fp);
    }
    printf("\n¡Datos escritos con éxito!\n");
    fclose(fp);
}

void readFileFixedLength(int people_count) {
    FILE *fp;
    fp = fopen("../resources/fixed_length.dat", "rb");
    printf("Leyendo datos con tamaño fijo...\n");
    printf("\n%-30s%-31s%-10s%-10s%-12s%-15s%-9s%-12s%-6s%-8s%-12s\n", "NOMBRE", "DIRECCIÓN", "DNI", "PRIMARIOS",
           "SECUNDARIOS", "UNIVERSITARIOS", "VIVIENDA", "OBRA SOCIAL", "HIJOS", "TRABAJA", "MONOTRIBUTO");
    for (int i = 0; i < people_count; ++i) {
        printPerson(readFixedLegnth(fp));
    }
    fclose(fp);
}

void writeFileVariableLength(int people_count) {
    FILE *fp;
    fp = fopen("../resources/variable_length.dat", "wb+");
    printf("\nEscribiendo datos con tamaño variable...");
    for (int i = 0; i < people_count; ++i) {
        writeVariableLength(people[i], fp);
    }
    printf("¡Datos escritos con éxito!\n");
    fclose(fp);
}

void readFileVariableLength(int people_count) {
    FILE *fp;
    fp = fopen("../resources/variable_length.dat", "rb");
    printf("Leyendo datos con tamaño variable...\n");

    printf("\n%-30s%-31s%-10s%-10s%-12s%-15s%-9s%-12s%-6s%-8s%-12s\n", "NOMBRE", "DIRECCIÓN", "DNI", "PRIMARIOS",
           "SECUNDARIOS", "UNIVERSITARIOS", "VIVIENDA", "OBRA SOCIAL", "HIJOS", "TRABAJA", "MONOTRIBUTO");
    for (int i = 0; i < people_count; ++i) {
        readVariableLegnth(fp);
    }
    fclose(fp);
}

void compareFileSizes() {
    FILE *fixed, *variable;
    fixed = fopen("../resources/fixed_length.dat", "rb");
    variable = fopen("../resources/variable_length.dat", "rb");

    printf("\nTamaños de los archivos escritos:");
    fseek(fixed, 0L, SEEK_END);
    printf("\n\t - fixed_length.dat: \t%li Bytes", ftell(fixed));

    fseek(variable, 0L, SEEK_END);
    printf("\n\t - variable_length.dat: %li Bytes\n", ftell(variable));

    fclose(fixed);
    fclose(variable);
}

int main() {
    int people_count = sizeof(people) / sizeof(struct Person);

    int op = -1;
    printMenu();
    scanf("%d", &op);
    fflush(stdin);
    while (op != 0) {
        switch (op) {
            case 1:
                writeFileFixedLength(people_count);
                printMenu();
                scanf("%d", &op);
                fflush(stdin);
            case 2:
                readFileFixedLength(people_count);
                printMenu();
                scanf("%d", &op);
                fflush(stdin);
                break;
            case 3:
                writeFileVariableLength(people_count);
                printMenu();
                scanf("%d", &op);
                fflush(stdin);
                break;
            case 4:
                readFileVariableLength(people_count);
                printMenu();
                scanf("%d", &op);
                fflush(stdin);
                break;
            case 5:
                compareFileSizes();
                printMenu();
                scanf("%d", &op);
                break;
            default:
                break;
        }
    }
    return 0;
}