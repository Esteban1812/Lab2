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

/** @file main.c
 ** @brief Codigo fuente principal: serializa y muestra los datos del alumno en formato JSON
 **/

/* === Headers files inclusions ==================================================================================== */

#include <stdio.h>
#include "alumno.h"

/* === Macros definitions ========================================================================================== */

/* === Private data type declarations ============================================================================== */

/* === Private function declarations =============================================================================== */

/* === Private variable definitions ================================================================================ */

/* === Public variable definitions ================================================================================= */

/* === Private function definitions ================================================================================ */

/* === Public function implementation ============================================================================== */

int main(void) {
    char salida[100];
    int resultado;

    alumno_t Esteban = CrearAlumno("Esteban", "Lobo Silva", 43648129);
    alumno_t Juan = CrearAlumno("Juan", "Pérez", 87654321);

    resultado = Serializar(Esteban, salida, sizeof(salida));

    if (resultado >= 0) {
        printf("Serializado: %s\n", salida);
    } else {
        printf("Error: espacio insuficiente para serializar\n");
    }

    resultado = Serializar(Juan, salida, sizeof(salida));

    if (resultado >= 0) {
        printf("Serializado: %s\n", salida);
    } else {
        printf("Error: espacio insuficiente para serializar\n");
    }

    return 0;
}
/* === End of documentation ========================================================================================
 */