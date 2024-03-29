
#include <iostream>
#include "matrix_mul.h"

using namespace std;

int main()
{
   mat_a_t in_mat_a[3][3] = {
      {0, 0, 1},
      {0, 1, 0},
      {1, 0, 0}
   };
   mat_b_t in_mat_b[3][3] = {
      {1, 1, 1},
      {0, 1, 1},
      {0, 0, 1}
   };
   result_t hw_result[3][3], sw_result[3][3];
   int err_cnt = 0;

   // Generate the expected result
   // Iterate over the rows of the A matrix
   for(int i = 0; i < MAT_A_ROWS; i++) {
      for(int j = 0; j < MAT_B_COLS; j++) {
         // Iterate over the columns of the B matrix
         sw_result[i][j] = 0;
         // Do the inner product of a row of A and col of B
         for(int k = 0; k < MAT_B_ROWS; k++) {
            sw_result[i][j] += in_mat_a[i][k] * in_mat_b[k][j];
         }
      }
   }

   matrix_mul(in_mat_a, in_mat_b, hw_result);


   // Print result matrix
   //cout << setw(6);
   for (int i = 0; i < MAT_A_ROWS; i++) {
      for (int j = 0; j < MAT_B_COLS; j++) {
         if (hw_result[i][j] != sw_result[i][j]) {
            err_cnt++;
         }
      }
   }

   if (err_cnt)
      cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
   else
      cout << "Test passes." << endl;
   return err_cnt;
}

