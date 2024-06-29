#include "Config_Mathematics.h"
#include "Config_Functions.h"

int main() {
    STRING inputFilename = "lorenz.dat";
    STRING outputLoc = "butterfly_chaos.svg";
    
    CHAR* lorenz = getFileNameAndUseIt(inputFilename, INPUT_DAT_FILE_LOCATION);
    CHAR* output = getFileNameAndUseIt(outputLoc, OUTPUT_LOCATION);
    
    generateLorenzData(lorenz, 0.01, 10000);
	drawData3D(lorenz, output);
    
    free(lorenz);
    free(output);

    return EXIT_SUCCESS;
}