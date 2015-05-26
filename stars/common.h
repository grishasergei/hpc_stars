/*****
 *  Solution to examination project in High Performance Computing and Programming
 * 
 *  common.h common definitions header file
 *
 * Author: Marcus Holm
 *
 **/

#ifndef _COMMON_H
#define _COMMON_H


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define float_t float 
#define NUM_HIST_BOXES 10


typedef struct star{
  int index;                   // counting index
  char spectralType;           // random: O, B, A, F, G, K, M, L, T
  unsigned short subType;      // random: 0-9
  float_t magnitude;           // random: (-10, +20)
  char designation[7]; 	       // sprintf("%c%d.%s", spectralType, subType, itoa(index)) 
  struct pos{
     float_t x, y, z;          // x & y random in (-1e5, 1e5), z random in (-3e3, 3e3)
  } position;
    float_t distanceFromOrigin;
} star_t;

typedef struct hist_params{
   int hist_size;
   float_t min, max, bin_size;
} hist_param_t;

float_t getDistanceBetween(star_t* s1, star_t* s2);

#endif
