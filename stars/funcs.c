/*****
 *  Solution to examination project in High Performance Computing and Programming
 *
 *  funcs.c functions implementation file
 *
 * Author: Marcus Holm
 *
 **/

#include "common.h"
#include "funcs.h"
#include <stdlib.h>
#include <string.h>
#include "assert.h"

char spectral_types[] =
{
    'O', 'B', 'A', 'F', 'G', 'K', 'M', 'L', 'T'
};

double uniform_rand(double a, double b){
    return rand()/(RAND_MAX + 1.0)*(b-a) + a;
}

int uniform_rand_int(int a, int b){
    return rand()/(RAND_MAX + 1.0)*(b-a) + a;
}

void create_random_array(star_t * stars, int size)
{
    int i, index;
    
    for (i = 0; i < size; i++) {
        stars[i].index = i;
        index = uniform_rand_int(0, 9);
        stars[i].spectralType = spectral_types[index];
        stars[i].subType = uniform_rand_int(0, 9);
        stars[i].magnitude = uniform_rand(-10, 20);
        stars[i].position.x = uniform_rand(-1e5, 1e5);
        stars[i].position.y = uniform_rand(-1e5, 1e5);
        stars[i].position.z = uniform_rand(-3e3, 3e3);
        stars[i].distanceFromOrigin = sqrt(stars[i].position.x*stars[i].position.x + stars[i].position.y*stars[i].position.y + stars[i].position.z*stars[i].position.z);
        
        sprintf(stars[i].designation, "%c%d.%d", stars[i].spectralType, stars[i].subType, stars[i].index);
    }
}

void print_stars(star_t* array, int n)
{
   int i;
   for(i = 0; i<n; i++)
      printf("%s ",array[i].designation);
   printf("\n");
}




void sort(star_t* array, int n)
{
    quicksort(array, n);
}

void fill_matrix(star_t * array, matrix* m, int size)
{
    long int i,j, k;
    k = 0;
    float_t distance;
    for (i=0; i<m->rows; i++) {
        for (j=0; j<i; j++) {
            distance = getDistanceBetween(&array[i], &array[j]);
            matrix_set(m, i, j, distance);
            matrix_set(m, j, i, distance);
        }
        k++;
    }
    
}

void print_matrix(float_t** theMatrix, int n)
{
  int i, j;
  for(i = 0 ; i < n; i++)
  {
    printf("%d ", i);
    for(j = 0 ; j < n ; j++)
	  printf("%2.3f " , theMatrix[i][j]);
    putchar('\n');
   }
}

void calculate_differences(matrix* m, float_t* differences, int n_differences){
    assert(n_differences == (m->cols-1)*(m->rows-1));
    int i,j;
    float_t difference, current, t,b,l,r;
    
    for (i=1; i<m->rows-1; i++) {
        for (j=1; j<m->cols-1; j++) {
            current = matrix_get(m, i, j);
            t = matrix_get(m, i-1, j);
            b = matrix_get(m, i+1, j);
            r = matrix_get(m, i, j+1);
            b = matrix_get(m, i, j-1);
            
            difference = (fabsf(current-t) + fabsf(current-b) + fabsf(current - l) + fabsf(current - r)) / 4;
            
            differences[i*(m->cols-1) + j] = difference;
        }
    }
}

void fill_histogram(hist_param_t histparams, float_t* histdata, int* histogram){
    int i, j;
    float_t bin_bound;
    
    for (i=0; i<histparams.hist_size; i++) {
        bin_bound= histparams.min + histparams.bin_size;
        j = 0;
        while (histdata[i]>bin_bound) {
            bin_bound += histparams.bin_size;
            j++;
        }
        histogram[j]++;
    }
}

hist_param_t generate_histogram(matrix* m, int *histogram, int mat_size, int hist_size)
{
    hist_param_t result;
    int i;
    
    float_t* differences;
    
    result.hist_size = (mat_size-1)*(mat_size-1);
    differences = (float_t*)malloc(sizeof(float_t)*result.hist_size);
    calculate_differences(m,differences,result.hist_size);
    
    result.max = 0;
    result.min = 0;
    
    
    for (i=0; i<result.hist_size; i++) {
        if (differences[i] < result.min) {
            result.min = differences[i];
        }
        if (differences[i] > result.max) {
            result.max = differences[i];
        }
        
    }
    
    result.bin_size = ((result.max) - (result.min)) / NUM_HIST_BOXES;
    
    fill_histogram(result, differences, histogram);
    
    free(differences);
    
    return result;
}

void display_histogram(int *histogram, hist_param_t histparams)
{
   int i,j;

   for(i = 0; i < histparams.hist_size && histparams.bin_size*i < histparams.max; i++)
   {
      printf("%1.3e\t", histparams.bin_size*i+histparams.min);
   }
   printf("%1.2e\n", histparams.max);
  // printf("****\n");
   for(j = 0; j < i; j++)
   {
      printf("%d\t\t", histogram[j]);
   }
   printf("\n");
}
