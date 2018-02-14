#include "simple_algo_flow.h"
#include <cmath>
#include <cassert>
#ifndef __SYNTHESIS__
#include <cstdio>
#endif

void node(mytype input[3], mytype previous_output[3], mytype output[3]){
#pragma HLS ARRAY_PARTITION variable=input  complete 
#pragma HLS ARRAY_PARTITION variable=previous_output complete 
#pragma HLS ARRAY_PARTITION variable=output complete 
  for(int i0 = 0; i0 < 3; i0++) { 
    //    #pragma HLS unroll
    output[i0] = input[i0]*previous_output[i0];
  }
}


void simple_algo_flow_hw_v0(mytype input[3][3], mytype dummy[3], mytype output[3][3]){
#pragma HLS ARRAY_PARTITION variable=input  dim=1 complete 
#pragma HLS ARRAY_PARTITION variable=output dim=1 complete 
#pragma HLS ARRAY_PARTITION variable=dummy  complete
#pragma HLS PIPELINE

  //    mytype A1[3];
  //   mytype B1[3];
  //    mytype C1[3];
    mytype A1_out[3];
    mytype B1_out[3];
    mytype C1_out[3];

#pragma HLS ARRAY_PARTITION variable=A1_out complete
#pragma HLS ARRAY_PARTITION variable=B1_out complete
#pragma HLS ARRAY_PARTITION variable=C1_out complete

    for(int i = 0; i < 3; i++) { 
      //#pragma HLS unroll
      //      A1[i] = input[0][i];
      //      B1[i] = input[1][i];
      //      C1[i] = input[2][i];
      A1_out[i] = 0;
      B1_out[i] = 0;
      C1_out[i] = 0;
    }
    node(input[0], dummy,   A1_out);
    node(input[1], A1_out,  B1_out);
    node(input[2], B1_out,  C1_out);
    for(int i = 0; i < 3; i++) { 
      //#pragma HLS unroll
      output[0][i] = A1_out[i];
      output[1][i] = B1_out[i];
      output[2][i] = C1_out[i];  
    }  
}

void simple_algo_flow_hw_v1(mytype input[9], mytype dummy[3], mytype output[9]){
#pragma HLS ARRAY_PARTITION variable=input  dim=1 complete 
#pragma HLS ARRAY_PARTITION variable=output dim=1 complete 
#pragma HLS ARRAY_PARTITION variable=dummy  complete
#pragma HLS PIPELINE

  mytype A1[3];
  mytype B1[3];
  mytype C1[3];
  
  mytype A1_out[3];
  mytype B1_out[3];
  mytype C1_out[3];
#pragma HLS ARRAY_PARTITION variable=A1 complete
#pragma HLS ARRAY_PARTITION variable=B1 complete
#pragma HLS ARRAY_PARTITION variable=C1 complete

#pragma HLS ARRAY_PARTITION variable=A1_out complete
#pragma HLS ARRAY_PARTITION variable=B1_out complete
#pragma HLS ARRAY_PARTITION variable=C1_out complete
  
  for(int i = 0; i < 3; i++) { 
  A1[i] = input[i];
  B1[i] = input[3+i];
  C1[i] = input[6+i];
  A1_out[i] = 0;
  B1_out[i] = 0;
  C1_out[i] = 0;
  }
    node(A1, dummy,   A1_out);
    node(B1, A1_out,  B1_out);
    node(C1, B1_out,  C1_out);
    for(int i = 0; i < 3; i++) { 
      //#pragma HLS unroll
      output[i]   = A1_out[i];
      output[3+i] = B1_out[i];
      output[6+i] = C1_out[i];  
    }  
}
