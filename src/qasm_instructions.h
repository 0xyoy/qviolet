#include <complex.h>

typedef float complex fc;
typedef fc qubit[2];
typedef qubit* qreg;

void print_circ();

static fc p(qubit* q1, qubit* q2, uint8_t a, uint8_t b);

/* qasm_qubits is handled differently */

//void qasm_prep_x(uint8_t size, qreg r);
//void qasm_prep_y(uint8_t size, qreg r);
void qasm_prep_z(uint8_t size, qreg r);

void qasm_x(qubit* q);
//void qasm_y(qubit* q);
//void qasm_z(qubit* q);

void qasm_h(qubit* q);
//void qasm_i(qubit* q);

//void qasm_rx(qubit* q, float angle);
//void qasm_ry(qubit* q, float angle);
//void qasm_rz(qubit* q, float angle);

//void qasm_x90(qubit* q);
//void qasm_mx90(qubit* q);
//void qasm_y90(qubit* q);
//void qasm_my90(qubit* q);

//void qasm_s(qubit* q);
//void qasm_st(qubit* q);

//void qasm_t(qubit* q);
//void qasm_tt(qubit* q);

void qasm_cnot(qubit* q1, qubit* q2);

//void qasm_cz(qubit* q1, qubit* q2);
//void qasm_swap(qubit* q1, qubit* q2);

//void qasm_cr(qubit* q1, qubit* q2, float angle);
//void qasm_crk(qubit* q1, qubit* q2, uint8_t k);

//void qasm_toffoli(qubit* q1, qubit* q2, qubit* q3);
//void qasm_measure_x(qubit* q);
//void qasm_measure_y(qubit* q);
//void qasm_measure_z(qubit* q);
//void qasm_measure_all(uint8_t size, qreg r);

void qasm_display(uint8_t size, qreg r);
//void qasm_display_binary(uint8_t size, reg r);

//void qasm_not(bit* b);
