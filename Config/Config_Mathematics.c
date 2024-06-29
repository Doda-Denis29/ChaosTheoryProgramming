#include "Config_Mathematics.h"

void generateLorenzData(STRING filename, DOUBLE dt, INT iterations) {
    FILE* Florenz = fopen(filename, "w");
    if(!Florenz) {
        printf(ERROR_INIT);
        return;
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
/*
void drawData3D(STRING datFile, STRING output) {
    FILE *gnuplotPipe = popen(GNUPLOT_EXE, "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set terminal pngcairo\n");
        fprintf(gnuplotPipe, "set output %s/%s\n", OUTPUT_LOCATION, output);
        fprintf(gnuplotPipe, "set xlabel 'X'\n");
        fprintf(gnuplotPipe, "set ylabel 'Y'\n");
        fprintf(gnuplotPipe, "set zlabel 'Z'\n");
        fprintf(gnuplotPipe, "splot  with lines\n");

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

nt main() {
    generateLorenzData("lorenz_data.dat", 0.01, 10000);
    return 0;
}*/