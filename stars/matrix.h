//
//  matrix.h
//  stars
//
//  Created by Sergii Gryshkevych on 26/05/15.
//  Copyright (c) 2015 Sergii Gryshkevych. All rights reserved.
//

#ifndef __stars__matrix__
#define __stars__matrix__

#include <stdio.h>
#include "common.h"

typedef struct{
    float_t* data;
    long int rows;
    long int cols;
}matrix;

float_t matrix_get(matrix* m, long int row, long int col);
void    matrix_set(matrix* m, long int row, long int col, float_t value);
matrix* matrix_create(long int rows, long int cols);

#endif /* defined(__stars__matrix__) */
