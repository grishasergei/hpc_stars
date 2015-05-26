/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  main.c main implementation file 
 *  
 * Author: Marcus Holm
 *
 **/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "common.h"
#include "funcs.h"
#include "matrix.h"

#include <time.h>
#include "limits.h"

void printtime(clock_t s, clock_t e)
{
   printf("time: %f\n", (double)(e-s)/CLOCKS_PER_SEC);    
}

int main(int argc, char **argv)
{
   int N, i, j;
   clock_t start, end;
    /*
   if(argc < 2)
   {
      printf("usage: ./a.out N\n");
      return 0;
   }
     */
    N = 1000;//atoi(argv[1]);
    
    printf("MAX INT: %d\n", INT_MAX);
    
   star_t *stars;
   stars = (star_t *) malloc(N*sizeof(star_t));
   
   printf("creating random stars: \t");
   start = clock();
   
   create_random_array(stars, N);
   
   end = clock();
   printtime(start, end);
 //  print_stars(stars, N);
         
   printf("sorting stars:    \t");
   start = clock();

   sort(stars, N);
   
   end = clock();
   printtime(start, end);
//      print_stars(stars, N);
   
   printf("allocating matrix: \t");
   start = clock();
   //float_t **matrix;
    matrix* m;
    m = matrix_create(N, N);
    
   end = clock();
   printtime(start, end);
   
   printf("filling matrix: \t");
   start = clock();
   fill_matrix(stars, m, N);
   
   //print_matrix(matrix,N);
   end = clock();
   printtime(start, end);
   
   printf("generating histogram: \t");
   start = clock();
   int *histogram = (int *)calloc(NUM_HIST_BOXES,sizeof(int));
   hist_param_t histparams = generate_histogram(m, histogram, N, NUM_HIST_BOXES);
   end = clock();
   printtime(start, end);

   display_histogram(histogram, histparams);
    
    free(histogram);
    free(m->data);
    free(m);
    /*
    for (i=0; i<N; i++) {
        printf("%s: %f\n",stars[i].designation,stars[i].distanceFromOrigin);
    }
    */
    /*
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            printf("%.2f ",matrix_get(*m, i, j));
        }
        printf("\n");
    }
     */
}
