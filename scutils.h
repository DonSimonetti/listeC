//
// Created by matts on 28/12/2017.
//

#ifndef LISTEC_SCUTILS_H
#define LISTEC_SCUTILS_H

#include <stdbool.h>
#include <math.h>

bool isEqual(float a, float b)
{
    return fabsf(a-b)<FLT_EPSILON;
}

#endif //LISTEC_SCUTILS_H
