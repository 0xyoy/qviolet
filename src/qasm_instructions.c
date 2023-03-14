#include <stdio.h>
#include <stdint.h>
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

static fc p(qubit* q1, qubit* q2, uint8_t a, uint8_t b) {
    return (*q1)[a]*(*q2)[b];
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

void qasm_display(uint8_t size, qreg r) {
    for(int i = 0; i < size; i++) {
        printf("q%i: %f+%fi %f+%fi\n", i, creal(r[i][0]), cimag(r[i][0]), creal(r[i][1]), cimag(r[i][1]));
    }
    printf("\n");
}
