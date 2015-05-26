/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  funcs.h functions header file
 *
 * Author: Marcus Holm
 *
 **/

#ifndef _FUNCS_H
#define _FUNCS_H

#include "quicksort.h"
#include "matrix.h"

void create_random_array(star_t * array, int size);
void sort(star_t* array, int n);
void print_stars(star_t* array, int n);


void fill_matrix(star_t * array, matrix* m, int size);
void print_matrix(float_t** matrix, int n);

hist_param_t generate_histogram(matrix* m, int *histogram, int mat_size, int hist_size);

void display_histogram(int *histogram, hist_param_t histparams);
#endif
