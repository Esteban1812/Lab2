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
*********************************************************************************************************************/

#ifndef ALUMNO_H_
#define ALUMNO_H_

/** @file alumno.h
 ** @brief Declaración de funciones del módulo Alumno
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/**
 * @brief Estructura que representa a un alumno.
 *
 */

typedef struct Alumno *alumno_t;

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief es un metodo de la clase ALUMNO para crear el objeto alumno.
 * 
 * @param nombre Cadena con el nombre del alumno a crear
 * @param apellido Cadena con el apellido del alumno a crear
 * @param documento Documento del alumno a crear
 * @return alumno_t Retorna un puntero a la estructura de datos asignada para almacenar los datos del nuevo 
alumno creado
 */

alumno_t CrearAlumno(char * nombre, char * apellido, int documento);

/**
 * @brief Funcion para serializar los datos de un alumno a formato JSON.
 *
 * @param a Referencia al objeto Alumno a serializar
 * @param salida Buffer donde se escribe el JSON generado
 * @param tam Tamaño máximo del buffer de salida
 * @return int Longitud de la cadena generada o -1 si no hay suficiente espacio
 */
int Serializar( alumno_t a, char * salida, int tam);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ALUMNO_H_ */