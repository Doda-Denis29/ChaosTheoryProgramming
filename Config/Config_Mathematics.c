#include "Config_Mathematics.h"
#include "Config_Functions.h"

void generateLorenzData(STRING filename, DOUBLE dt, INT iterations) {
    FILE* Florenz = fopen(filename, "w");
    if(!Florenz) {
        fprintf(stderr, "%s in %s, at line %d\n", ERROR_INIT, __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    CDOUBLE sigma = 10.0;
    CDOUBLE rho = 28.0;
    CDOUBLE beta = 8.0/3.0;

    DOUBLE x = 1.0;
    DOUBLE y = 1.0;
    DOUBLE z = 1.0;

    DOUBLE dx = 0.0;
    DOUBLE dy = 0.0;
    DOUBLE dz = 0.0;

    for(INT i = 0; i < iterations; i++) {
        dx = sigma * (y - x);
        dy = x * (rho - z) - y;
        dz = (x * y) - (beta * z);

        x += dx * dt;
        y += dy * dt;
        z += dz * dt;

        fprintf(Florenz,"%f %f %f\n", x, y, z);
    }

    fclose(Florenz);
}

void drawData3D(STRING datFile, STRING output) {
    FILE *gnuplotPipe = popen(GNUPLOT_EXE, "w");
    if (gnuplotPipe == NULL) {
        fprintf(stderr, "%s in %s, at line %d", ERROR_INIT, __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    fprintf(gnuplotPipe, "set title 'Chaos'\n");
    fprintf(gnuplotPipe, "set output '%s'\n", output);
    fprintf(gnuplotPipe, "set xlabel 'X'\n");
    fprintf(gnuplotPipe, "set ylabel 'Y'\n");
    fprintf(gnuplotPipe, "set zlabel 'Z'\n");
    fprintf(gnuplotPipe, "splot '%s' using 1:2:3 with lines\n", datFile);
    fflush(gnuplotPipe);

    pclose(gnuplotPipe);

    printf("Plot generated successfully as '%s'\n", output);
}