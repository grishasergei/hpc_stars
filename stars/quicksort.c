//
//  quicksort.c
//  Assignment_2
//
//  Created by Sergii Gryshkevych on 17/02/15.
//  Copyright (c) 2015 Sergii Gryshkevych. All rights reserved.
//

#include <stdio.h>
#include "quicksort.h"


void my_qsort(star_t* stars, int lo, int hi);

void swap(star_t* left, star_t* right){
    star_t buf;
    
    buf = *right;
    *right = *left;
    *left = buf;
}

int getPivotIndex(int lo, int hi){
    return lo + (int)((hi-lo)/2);
}

int partition(star_t* stars, int lo, int hi){
    int pivotIndex;
    float_t pivotValue;
    int partitionIndex;
    int i;
    
    pivotIndex = getPivotIndex(lo, hi);
    pivotValue = stars[pivotIndex].distanceFromOrigin;

    partitionIndex = lo;
    swap(&stars[pivotIndex],&stars[hi]);
    
    for (i=lo; i<hi; i++) {
        if(stars[i].distanceFromOrigin < pivotValue){
            swap(&stars[i],&stars[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&stars[partitionIndex], &stars[hi]);
    
    return partitionIndex;
}

/*******************
    serial sort
 *******************/

void my_qsort(star_t* stars, int lo, int hi){
    int p;
    if (lo<hi){
        p = partition(stars,lo,hi);
        my_qsort(stars,lo,p-1);
        my_qsort(stars,p+1,hi);
    }
}


void quicksort(star_t* stars, int n){
    my_qsort(stars,0,n-1);
}

