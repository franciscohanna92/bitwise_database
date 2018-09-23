#include <stdio.h>
#include <memory.h>
#include "types.h"

/**
 *
 * @param person
 * @param fp
 */
void writeFixedLength(struct Person person, FILE* fp) {
    fwrite(person.nombre, sizeof(char), NAME_LENGTH, fp);
    fwrite(person.direccion, sizeof(char), ADDRRESS_LENGTH, fp);
    fwrite(person.dni, sizeof(char), DNI_LENGTH, fp);

    char data = (char) 0;
    data = (char) (person.estudios_primarios ? data | PRIMARIOS : data);
    data = (char) (person.estudios_secundarios ? data | SECUNDARIOS : data);
    data = (char) (person.estudios_universitarios ? data | UNIVERSITARIOS : data);
    data = (char) (person.vivienda_propia ? data | VIVIENDA : data);
    data = (char) (person.obra_social ? data | OBRASOCIAL : data);
    data = (char) (person.tiene_hijos ? data | HIJOS : data);
    data = (char) (person.trabaja ? data | TRABAJA : data);
    data = (char) (person.monotributista ? data | MONOTRIBUTO : data);

    fwrite(&data, sizeof(char), 1, fp);
}

/**
 *
 * @param fp
 * @return
 */
struct Person readFixedLegnth(FILE *fp) {
    struct Person person;

    fread(person.nombre, sizeof(char), NAME_LENGTH, fp);
    fread(person.direccion, sizeof(char), ADDRRESS_LENGTH, fp);
    fread(person.dni, sizeof(char), DNI_LENGTH, fp);

    char data;
    fread(&data, sizeof(char), 1, fp);
    person.estudios_primarios = (data & PRIMARIOS) == 0 ? 0 : 1;
    person.estudios_secundarios = (data & SECUNDARIOS) == 0 ? 0 : 1;
    person.estudios_universitarios = (data & UNIVERSITARIOS) == 0 ? 0 : 1;
    person.vivienda_propia = (data & VIVIENDA) == 0 ? 0 : 1;
    person.obra_social = (data & OBRASOCIAL) == 0 ? 0 : 1;
    person.tiene_hijos = (data & HIJOS) == 0 ? 0 : 1;
    person.trabaja = (data & TRABAJA) == 0 ? 0 : 1;
    person.monotributista = (data & MONOTRIBUTO) == 0 ? 0 : 1;
    return person;
}

/**
 *
 * @param person
 * @param fp
 */
void writeVariableLength(struct Person person, FILE* fp) {
    size_t data_length;

    data_length = strlen(person.nombre) + 1;
//    printf("%d\n", (int) data_length);
    fwrite(&data_length, sizeof(int), 1, fp);
    fwrite(person.nombre, sizeof(char), data_length, fp);

    data_length = strlen(person.direccion) + 1;
//    printf("%d\n", (int) data_length);
    fwrite(&data_length, sizeof(int), 1, fp);
    fwrite(person.direccion, sizeof(char), data_length, fp);

    data_length = strlen(person.dni) + 1;
//    printf("%d\n", (int) data_length);
    fwrite(&data_length, sizeof(int), 1, fp);
    fwrite(person.dni, sizeof(char), data_length, fp);

    char data = (char) 0;
    data = (char) (person.estudios_primarios ? data | PRIMARIOS : data);
    data = (char) (person.estudios_secundarios ? data | SECUNDARIOS : data);
    data = (char) (person.estudios_universitarios ? data | UNIVERSITARIOS : data);
    data = (char) (person.vivienda_propia ? data | VIVIENDA : data);
    data = (char) (person.obra_social ? data | OBRASOCIAL : data);
    data = (char) (person.tiene_hijos ? data | HIJOS : data);
    data = (char) (person.trabaja ? data | TRABAJA : data);
    data = (char) (person.monotributista ? data | MONOTRIBUTO : data);
//
    fwrite(&data, sizeof(char), 1, fp);
}

/**
 *
 * @param fp
 * @return
 */
struct Person readVariableLegnth(FILE *fp) {
    size_t data_length;

    fread(&data_length, sizeof(int), 1, fp);
    char name[data_length];
    fread(&name, sizeof(char), data_length, fp);

    fread(&data_length, sizeof(int), 1, fp);
    char address[data_length];
    fread(&address, sizeof(char), data_length, fp);

    fread(&data_length, sizeof(int), 1, fp);
    char dni[data_length];
    fread(&dni, sizeof(char), data_length, fp);

    char data;
    fread(&data, sizeof(char), 1, fp);
    int estudios_primarios = (data & PRIMARIOS) == 0 ? 0 : 1;
    int estudios_secundarios = (data & SECUNDARIOS) == 0 ? 0 : 1;
    int estudios_universitarios = (data & UNIVERSITARIOS) == 0 ? 0 : 1;
    int vivienda_propia = (data & VIVIENDA) == 0 ? 0 : 1;
    int obra_social = (data & OBRASOCIAL) == 0 ? 0 : 1;
    int tiene_hijos = (data & HIJOS) == 0 ? 0 : 1;
    int trabaja = (data & TRABAJA) == 0 ? 0 : 1;
    int monotributista = (data & MONOTRIBUTO) == 0 ? 0 : 1;


    printf("%-30s%-30s%-10s", name, address, dni);
    estudios_primarios ? printf("%-10s", "Si") : printf("%-10s", "No");
    estudios_secundarios ? printf("%-12s", "Si") : printf("%-12s", "No");
    estudios_universitarios ? printf("%-15s", "Si") : printf("%-15s", "No");
    vivienda_propia ? printf("%-9s", "Si") : printf("%-9s", "No");
    obra_social ? printf("%-12s", "Si") : printf("%-12s", "No");
    tiene_hijos ? printf("%-6s", "Si") : printf("%-6s", "No");
    trabaja ? printf("%-8s", "Si") : printf("%-8s", "No");
    monotributista ? printf("%-12s", "Si") : printf("%-12s", "No");

    printf("\n");
}


/**
 *
 * @param person
 */
void printPerson(struct Person person) {
    printf("%-30s%-30s%-10s", person.nombre, person.direccion, person.dni);
    person.estudios_primarios ? printf("%-10s", "Si") : printf("%-10s", "No");
    person.estudios_secundarios ? printf("%-12s", "Si") : printf("%-12s", "No");
    person.estudios_universitarios ? printf("%-15s", "Si") : printf("%-15s", "No");
    person.vivienda_propia ? printf("%-9s", "Si") : printf("%-9s", "No");
    person.obra_social ? printf("%-12s", "Si") : printf("%-12s", "No");
    person.tiene_hijos ? printf("%-6s", "Si") : printf("%-6s", "No");
    person.trabaja ? printf("%-8s", "Si") : printf("%-8s", "No");
    person.monotributista ? printf("%-12s", "Si") : printf("%-12s", "No");
    printf("\n");
}