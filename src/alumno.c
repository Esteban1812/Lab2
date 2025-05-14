/*********************************************************************************************************************
Copyright (c) 2025, Esteban Ignacio Lobo Silva <nachosilva04.com>
Copyright (c) 2025, Laboratorio de Electronica IV, Universidad Nacional de Tucumán, Argentina

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
******************************************************************************************************************** */

/** @file alumno.c
 ** @brief Codigo fuente del modulo para la gestion de alumnos
 */
/* === Headers files inclusions ==================================================================================== */

#include "alumno.h"
#include "config.h"
#include <stdio.h>
#include <stdbool.h>

/* === Macros definitions ========================================================================================== */

#ifndef ALUMNO_MAX_INSTANCIAS
#define ALUMNO_MAX_INSTANCIAS 2 //!< Cantidad máxima de alumnos
#endif

/* === Private data type declarations ============================================================================== */

struct Alumno {
    char nombre[50];   //!< Nombre del alumno
    char apellido[50]; //!< Apellido del alumno
    int documento;     //!< Documento del alumno
#ifndef USAR_MEMORIA_DINAMICA
    bool ocupado; //!< Indica si la instancia está ocupada
#endif
};

/* === Private function declarations =============================================================================== */

/**
 * @brief Crea una nueva instancia de alumno.
 *
 * @return alumno_t Puntero a la nueva instancia de alumno
 */

static alumno_t CrearInstancia();


/**
 * @brief Serializa un campo de texto clave-valor en formato JSON.
 *
 * @param clave Nombre del campo
 * @param valor Contenido de texto
 * @param salida Buffer de salida
 * @return int Longitud del texto generado
 */

static int SerializarTexto(const char * clave, const char * valor, char * salida);

/**
 * @brief Serializa un campo numérico clave-valor en formato JSON.
 *
 * @param clave Nombre del campo
 * @param valor Valor numérico
 * @param salida Buffer de salida
 * @return int Longitud del texto generado
 */

static int SerializarNumero(const char * clave, int valor, char * salida);

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

#ifndef USAR_MEMORIA_DINAMICA
static struct Alumno instancias[ALUMNO_MAX_INSTANCIAS] = {0}; // Arreglo de instancias de alumnos
#endif

/* === Private function definitions ================================================================================ */

#ifndef USAR_MEMORIA_DINAMICA
static alumno_t CrearInstancia() {
    alumno_t a = NULL;
    for (int i = 0; i < ALUMNO_MAX_INSTANCIAS; i++) {
        if (!instancias[i].ocupado) {     // Verifica si la instancia está libre
            instancias[i].ocupado = true; // Marca la instancia como ocupada
            a = &instancias[i];
            break;
        }
    }
    return a;
}
#endif
static int SerializarTexto(const char * clave, const char * valor, char * salida) {
    return sprintf(salida, "\"%s\":\"%s\"", clave, valor);
}

static int SerializarNumero(const char * clave, int valor, char * salida) {
    return sprintf(salida, "\"%s\":%d", clave, valor);
}

/* === Public function implementation ============================================================================== */

alumno_t CrearAlumno(char * nombre, char * apellido, int documento) {
#ifndef USAR_MEMORIA_DINAMICA
    alumno_t a = malloc(sizeof(struct Alumno));
#else
    alumno_t a = CrearInstancia();
#endif
    if (a != NULL) {
        a->documento = documento;
        strncpy(a->nombre, nombre, sizeof(a->nombre) - 1);
        strncpy(a->apellido, apellido, sizeof(a->apellido) - 1);
    }
    return a;
}

int Serializar(alumno_t a, char * salida, int tam) {
    char buffer[256];
    int total = 0;

    total += sprintf(buffer + total, "{");
    total += SerializarTexto("nombre", a->nombre, buffer + total);
    total += sprintf(buffer + total, ",");
    total += SerializarTexto("apellido", a->apellido, buffer + total);
    total += sprintf(buffer + total, ",");
    total += SerializarNumero("documento", a->documento, buffer + total);
    total += sprintf(buffer + total, "}");

    if (total >= tam)
        return -1;

    strcpy(salida, buffer);
    return total;
}

/* === End of documentation ======================================================================================== */