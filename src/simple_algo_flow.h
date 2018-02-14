#ifndef SIMPLE_ALGO_SPARSE_H
#define SIMPLE_ALGO_SPARSE_H

#include "ap_fixed.h"
#include "ap_int.h"

//typedef ap_fixed<18,8> mytype;
typedef ap_uint<8> mytype;

void node(mytype input[3], mytype previous_output[3], mytype output[3]);
void simple_algo_flow_hw_v0(mytype input[3][3], mytype dummy[3], mytype output[3][3]);
void simple_algo_flow_hw_v1(mytype input[9]   , mytype dummy[3], mytype output[9]);

#endif
