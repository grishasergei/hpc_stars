//
//  matrix.c
//  stars
//
//  Created by Sergii Gryshkevych on 26/05/15.
//  Copyright (c) 2015 Sergii Gryshkevych. All rights reserved.
//

#include "matrix.h"
#include <stdlib.h>
#include "assert.h"

float_t  matrix_get(matrix* m, long int row, long int col){
    assert((row>=0) && (row<m->rows));
    assert((col>=0) && (col<m->cols));
    return m->data[m->cols*row + col];
}

void    matrix_set(matrix* m, long int row, long int col, float_t value){
    //assert((row>=0) && (row<m->rows));
    //assert((col>=0) && (col<m->cols));
    
    m->data[m->cols*row + col] = value;
}

matrix* matrix_create(long int rows, long int cols){
    assert(rows>0);
    assert(cols>0);
    
    matrix* result = (matrix*)malloc(sizeof(matrix));

    result->data = (float_t*)calloc(rows*cols, sizeof(float_t));
    assert(result->data != NULL);
    result->cols = cols;
    result->rows = rows;
    
    return result;
}