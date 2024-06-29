#ifndef CONFIG_FUNCTIONS_H
#define CONFIG_FUNCTIONS_H

#include <string.h>
#include "Config_Definitions.h"

CHAR* concatStrings(STRING string1, STRING string2, bool debug);
void createDatFile(STRING filename);

#endif