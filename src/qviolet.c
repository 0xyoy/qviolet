/* qviolet - cQASM interpreter
 * Copyright (C) 2023 anna@brokenlove.online
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

#include "qasm_instructions.h"

typedef float complex fc;
typedef fc qubit[2];
typedef qubit* qreg;

int main() {
    printf("hello qviolet\n");
    uint8_t size = 2;
    qreg r = (qreg) malloc(sizeof(qubit)*size);
    /*  TODO check for entanglement by using an array (basically a graph) 
     *  before each multi-qbit operation, check the normalisation condition. if it holds after the operation, the operation did not cause entanglement. if it doesnt hold - qubits have been entangled. */
    qasm_prep_z(size, r);
    qasm_h(&(r[0]));
    qasm_x(&(r[1]));
    qasm_cnot(&(r[0]), &(r[1]));
    qasm_display(size, r);
    print_circ();
    printf("\n");
    return 0;
}
