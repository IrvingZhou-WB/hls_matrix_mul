#ifndef __MATRIX_MUL_H__
#define __MATRIX_MUL_H__

#define MAT_A_ROWS 3
#define MAT_A_COLS 3
#define MAT_B_ROWS 3
#define MAT_B_COLS 3

typedef char mat_a_t;
typedef char mat_b_t;
typedef short result_t;

void matrix_mul(
      mat_a_t a[MAT_A_ROWS][MAT_A_COLS],
      mat_b_t b[MAT_B_ROWS][MAT_B_COLS],
      result_t res[MAT_A_ROWS][MAT_B_COLS]);

#endif

