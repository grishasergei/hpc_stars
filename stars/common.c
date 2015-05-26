//
//  common.c
//  stars
//
//  Created by Sergii Gryshkevych on 26/05/15.
//  Copyright (c) 2015 Sergii Gryshkevych. All rights reserved.
//

#include <stdio.h>
#include "common.h"

float_t getDistanceBetween(star_t* s1, star_t* s2){
    double x,y,z;
    
    x = s1->position.x - s2->position.x;
    y = s1->position.y - s2->position.y;
    z = s1->position.z - s2->position.z;
    
    return sqrt(x*x + y*y + z+z);
}