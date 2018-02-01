#include "simple_algo_flow.h"
#include <cmath>
#include <cassert>
#ifndef __SYNTHESIS__
#include <cstdio>
#endif

void node(mytype input, mytype previous_output, mytype& output){
    
    output = input*previous_output;
    
}


void simple_algo_flow_hw(mytype input[3], mytype dummy, mytype output[3]){
    
    #pragma HLS ARRAY_PARTITION variable=input complete 
    #pragma HLS ARRAY_PARTITION variable=output complete 
    
    #pragma HLS PIPELINE
    
    mytype A1 = input[0];
    mytype B1 = input[1];
    mytype C1 = input[2];
    mytype A1_out = 0;
    mytype B1_out = 0;
    mytype C1_out = 0;
    
    node(A1, dummy, A1_out);
    node(B1, A1_out,  B1_out);
    node(C1, B1_out,  C1_out);

    output[0] = A1_out;
    output[1] = B1_out;
    output[2] = C1_out;    
}
