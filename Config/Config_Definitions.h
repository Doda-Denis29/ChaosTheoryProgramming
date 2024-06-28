#ifndef CONFIG_DEFINITIONS_H
#define CONFIG_DEFINITIONS_H

#include <stdint.h>

//Custom Primitives
#define INT int
#define FLOAT float
#define DOUBLE double
#define UINT unsigned int
#define INT32 int32_t
#define STRING const char*
#define CINT const int
#define CFLOAT const float
#define CDOUBLE const double
#define CINT32 const int32_t

//Path definitions to make my life easier
#define GNUPLOT_EXE "D:/Programe_proiecte/C/LearningC/ExternalLibs/gnuplot/bin/gnuplot"
#define INPUT_DAT_FILE_LOCATION "D:/Programe_proiecte/C/LearningC/Output"
#define OUTPUT_LOCATION "D:/Programe_proiecte/C/LearningC/Output"

//Error messages
#define ERROR_GENERIC "There was a disturbance in the force"
#define ERROR_INIT "There was a disturbance in the init"
#define ERROR_PLOT "There was a disturbance in the plot"

#endif