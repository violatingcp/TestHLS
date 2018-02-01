#ifndef SIMPLE_ALGO_SPARSE_H
#define SIMPLE_ALGO_SPARSE_H

#include "ap_fixed.h"
#include "ap_int.h"

//typedef ap_fixed<18,8> mytype;
typedef ap_uint<32> mytype;

void node(mytype input, mytype previous_output, mytype &output);
void simple_algo_flow_hw(mytype input[3], mytype dummy, mytype output[3]);

#endif
