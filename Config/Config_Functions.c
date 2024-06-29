#include "Config_Functions.h"

CHAR* concatStrings(STRING string1, STRING string2, bool debug) {
    if(debug) {
        printf("%s, string1 and %s, string2", string1, string2);
    }
    UINT sizeString1 = strlen(string1);
    UINT sizeString2 = strlen(string2);

    CHAR* resultConcat = malloc(sizeString1 + sizeString2 + 1);

    if(resultConcat == NULL) {
        fprintf(stderr, "%s in %s, at line %d", ERROR_INIT, __FILE__, __LINE__);
        return NULL;
    }

    strncpy(resultConcat, string1, sizeString1);
    resultConcat[sizeString1] = '\0';
    strncat(resultConcat, string2, sizeString2);

    if(debug) {
        printf("%s <- current resultConcat at line %d, in file %s", resultConcat, __LINE__, __FILE__);
    }

    return resultConcat;
}

void createDatFile(STRING filename) {
    CHAR* concatOutput = concatStrings(OUTPUT_LOCATION, filename, true);
    FILE* Fdat = fopen(concatOutput, "w");

    if(Fdat == NULL) {
        fprintf(stderr, "%s in %s, at line %d", ERROR_INIT, __FILE__, __LINE__);
        return;
    }

    fclose(Fdat);
}