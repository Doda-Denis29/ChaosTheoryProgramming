#include <stdio.h>
#include <stdlib.h>
#include "Config_test.h"

void plot3D() {
    FILE *gnuplotPipe = popen("D:/Programe_proiecte/C/LearningC/ExternalLibs/gnuplot/bin/gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output 'D:/Programe_proiecte/C/LearningC/Output/3dplot.png'\n");
        fprintf(gnuplotPipe, "set xlabel 'X'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z'\n");
        fprintf(gnuplotPipe, "splot '-' with lines\n");

        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                double z = x * y;
                fprintf(gnuplotPipe, "%d %d %f\n", x, y, z);
            }
            fprintf(gnuplotPipe, "\n");
        }

        fprintf(gnuplotPipe, "e\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
    } else {
        printf("Could not open GNUplot pipe\n");
    }
}

int main() {
    plot3D();
    testing();
    return 0;
}
