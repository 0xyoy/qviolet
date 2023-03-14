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
#include <stdint.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define c0 0+0*I
#define c1 1+0*I

typedef float complex fc;
typedef fc qubit[2];
typedef qubit* qreg;

void print_circ() {
    printf(" q0 --|0>--[H]---.---[M]\n                 |\n q1 --|0>--[X]--[C]--[M]");
}

/* print probabilities of all registers */
void print_probs(uint8_t size, qreg r) {
    for(int i = 0; i < size; i++) {
        printf("q%i: %f+%fi %f+%fi\n", i, creal(r[i][0]), cimag(r[i][0]), creal(r[i][1]), cimag(r[i][1]));
    }
    printf("\n");
}

void qasm_prep_z(uint8_t size, qreg r) {
    for(int i = 0; i < size; i++) {
        r[i][0] = c1;
        r[i][1] = c0;
    }
}

void qasm_x(qubit* q) {
    fc q0 = (*q)[0];
    (*q)[0] = (*q)[1];
    (*q)[1] = q0;
}

void qasm_h(qubit* q) {
    fc q0 = (*q)[0];
    (*q)[0] = ((*q)[0]+(*q)[1])/sqrt(2);
    (*q)[1] = (q0-(*q)[1])/sqrt(2); 
}

fc p(qubit* q1, qubit* q2, uint8_t a, uint8_t b) {
    return (*q1)[a]*(*q2)[b];
}

void qasm_cnot(qubit* q1, qubit* q2) {
    fc res[4];
    res[0] = p(q1, q2, 0, 0);
    res[1] = p(q1, q2, 0, 1);
    res[2] = p(q1, q2, 1, 1);
    res[3] = p(q1, q2, 1, 0);
    
    (*q1)[0] = res[0];
    (*q2)[0] = res[1];
    (*q1)[1] = res[2];
    (*q2)[1] = res[3];
}

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
    print_probs(size, r);
    print_circ();
    printf("\n");
    return 0;
}
