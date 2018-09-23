//
// Created by franciscohanna92 on 10/09/18.
//

#define NAME_LENGTH 30
#define ADDRRESS_LENGTH 50
#define DNI_LENGTH 10
#define PRIMARIOS 128
#define SECUNDARIOS 64
#define UNIVERSITARIOS 32
#define VIVIENDA 16
#define OBRASOCIAL 8
#define HIJOS 4
#define TRABAJA 2
#define MONOTRIBUTO 1

#ifndef BITWISE_DATABASE_TYPES_H
#define BITWISE_DATABASE_TYPES_H

struct Person {
    char nombre[NAME_LENGTH];
    char direccion[ADDRRESS_LENGTH];
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

#endif //BITWISE_DATABASE_TYPES_H
