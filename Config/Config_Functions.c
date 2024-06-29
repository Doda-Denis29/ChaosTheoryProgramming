#include "Config_Functions.h"

CHAR* concatStrings(STRING string1, STRING string2, bool debug) {
    if(debug) {
        printf("%s and %s\n", string1, string2);
    }
    UINT sizeString1 = strlen(string1);
    UINT sizeString2 = strlen(string2);

    CHAR* resultConcat = malloc(sizeString1 + sizeString2 + 2);

    if(resultConcat == NULL) {
        fprintf(stderr, "%s in %s, at line %d", ERROR_INIT, __FILE__, __LINE__);
        return NULL;
    }

    strncpy(resultConcat, string1, sizeString1);
    resultConcat[sizeString1] = '\0';
    strncat(resultConcat, "/", 2);
    strncat(resultConcat, string2, sizeString2);

    if(debug) {
        printf("%s <- current resultConcat at line %d, in file %s\n", resultConcat, __LINE__, __FILE__);
        UINT size = strlen(resultConcat);
        printf("%d is the size of resultConcat\n", size);
    }

    return resultConcat;
}

void createDatFile(STRING filename) {
    CHAR* concatOutput = concatStrings(INPUT_DAT_FILE_LOCATION, filename, false);
    FILE* Fdat = fopen(concatOutput, "w");

    if(Fdat == NULL) {
        fprintf(stderr, "%s in %s, at line %d\n", ERROR_INIT, __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    free(concatOutput);
    fclose(Fdat);
}

void createOutputFile(STRING filename) {
    CHAR* concatOutput = concatStrings(OUTPUT_LOCATION, filename, false);
    FILE* Fdat = fopen(concatOutput, "w");

    if(Fdat == NULL) {
        fprintf(stderr, "%s in %s, at line %d\n", ERROR_INIT, __FILE__, __LINE__);
        exit(EXIT_FAILURE);
    }

    free(concatOutput);
    fclose(Fdat);
}

CHAR* getFileNameAndUseIt(STRING filename, STRING baseLocation) {
    CHAR* result = concatStrings(baseLocation, filename, false);

    if (strcmp(baseLocation, OUTPUT_LOCATION) == 0) {
        createOutputFile(filename);
    } else if (strcmp(baseLocation, INPUT_DAT_FILE_LOCATION) == 0) {
        createDatFile(filename);
    }

    return result;
}