#ifndef CONFIG_MATHEMATICS_H
#define CONFIG_MATHEMATICS_H

#include <stdio.h>
#include <math.h>
#include "Config_Definitions.h"

typedef struct {
    int x, y;
} POINTS_2D;

typedef struct {
    int x, y, z;
} POINTS_3D;

typedef struct {
    int x, y, z, w;
} POINTS_4D;

void generateLorenzData(STRING filename, DOUBLE dt, INT iterations);

void drawData3D(STRING datFile, STRING output);

#endif