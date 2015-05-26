//
//  quicksort.h
//  Assignment_2
//
//  Created by Sergii Gryshkevych on 17/02/15.
//  Copyright (c) 2015 Sergii Gryshkevych. All rights reserved.
//

#ifndef Assignment_2_quicksort_h
#define Assignment_2_quicksort_h

#include "common.h"

void my_qsort(star_t* stars, int lo, int hi);
int partition(star_t* stars, int lo, int hi);

void quicksort(star_t* stars, int n);

#endif
