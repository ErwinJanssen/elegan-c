#include "safe-c/safe_string.h"

#include <stdio.h>
#include <string.h>

#include "safe-c/safe_memory.h"

cstring copy_string(const_cstring source)
{
    if (!source)
    {
        fprintf(stderr, "An error occurred in '%s': parameter 'source' is NULL.\n",
                __FUNCTION__);
        exit(EXIT_FAILURE);
    }

    cstring copy = safe_malloc(strlen(source) + sizeof(char));
    copy = strcpy(copy, source);
    return copy;
}


