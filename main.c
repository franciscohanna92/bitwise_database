#include <stdio.h>
#define NAME_LENGTH 30
#define ADDRRESS_LENGTH 50
#define DNI_LENGTH 8

#define PRIMARIOS 128
#define SECUNDARIOS 64
#define UNIVERSITARIOS 32
#define VIVIENDA 16
#define OBRASOCIAL 8
#define HIJOS 4
#define TRABAJA 2
#define MONOTRIBUTO 1

struct Person {
    char name[NAME_LENGTH];
    char address[ADDRRESS_LENGTH];
    char dni[DNI_LENGTH];
    int estudios_primarios;
    int estudios_secundarios;
    int estudios_universitarios;
    int vivienda_propia;
    int obra_social;
    int tiene_hijos;
    int trabaja;
    int monotributista;
};

void printbincharpad(char c) {
    for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
    putchar('\n');
}

void write_data(struct Person person, FILE* fp) {
    fwrite(person.name, sizeof(char), NAME_LENGTH, fp);
    fwrite(person.address, sizeof(char), ADDRRESS_LENGTH, fp);
    fwrite(person.dni, sizeof(char), DNI_LENGTH, fp);

    char data = (char) NULL;
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

void read_data(FILE *fp) {
    struct Person person;

    fread(person.name, sizeof(char), NAME_LENGTH, fp);
    fread(person.address, sizeof(char), ADDRRESS_LENGTH, fp);
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

    printf("%s, %s, %s, %d, %d, %d, %d, %d, %d, %d, %d",
           person.name,
           person.address,
           person.dni,
           person.estudios_primarios,
           person.estudios_secundarios,
           person.estudios_universitarios,
           person.vivienda_propia,
           person.obra_social,
           person.tiene_hijos,
           person.trabaja,
           person.monotributista
    );
}

int main() {
    FILE *fp;

    struct Person person = {
            "Francisco E. Hanna",
            "Ignacio de la Roza Oeste 2684",
            "36708282",
            0,
            1,
            0,
            0,
            0,
            0,
            0,
            1
    };

    fp = fopen("../resources/fixed_length.dat", "wb+");
    write_data(person, fp);
    fclose(fp);

    fp = fopen("../resources/fixed_length.dat", "rb");
    read_data(fp);
    fclose(fp);

    return 0;
}