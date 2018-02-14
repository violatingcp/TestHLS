#include <cstdio>
#include "src/simple_algo_flow.h"

using namespace std;

void output_v0(mytype output[3][3]) { 
  cout << "Out: ";
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cout << i << " - " << j << " => " << output[i][j] << " "; cout << endl;
    }
  }
  cout << endl;
}

void output_v1(mytype output[9]) { 
  cout << "Out: ";
  for(int i=0; i<9; i++){
    cout << i << "=>" << output[i] << " "; 
  }
  cout << endl;
}

int main() {

    mytype dummy [3]    = {2,2,2};
    mytype output[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    mytype input [3][3] = { {1,1,1}, {2,2,2}, {3,3,3} };

    mytype output1[9] = { 0,0,0,0,0,0,0,0,0 };
    mytype input11[9] = { 1,1,1,2,2,2,3,3,3 };
    //simple_algo_flow_hw_v0(input, dummy, output);
    //output_v0(output);
    //simple_algo_flow_hw_v1(input11, dummy, output1);
    simple_algo_flow_hw_v2(input11, dummy, output1);
    output_v1(output1);
    
    mytype input2[3][3] = { {4,4,4}, {5,5,5}, {6,6,6} };
    mytype input21[9]   = {  4,4,4,   5,5,5,   6,6,6  };
    //simple_algo_flow_hw_v0(input2, dummy, output);
    //output_v0(output);
    //simple_algo_flow_hw_v1(input21, dummy, output1);
    simple_algo_flow_hw_v2(input21, dummy, output1);
    output_v1(output1);
    
    mytype input3[3][3] = { {7,7,7}, {8,8,8}, {9,9,9} };
    mytype input31[9]   = {  7,7,7,   8,8,8,   9,9,9 };
    //simple_algo_flow_hw_v0(input3, dummy, output);
    //output_v0(output);
    //simple_algo_flow_hw_v1(input31, dummy, output1);
    simple_algo_flow_hw_v2(input31, dummy, output1);
    output_v1(output1);
    
    return 0;
}
