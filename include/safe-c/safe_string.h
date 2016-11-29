#ifndef SAFE_STRING_H
#define SAFE_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef char* cstring;
typedef const char* const_cstring;
typedef cstring* cstring_array;

/**
 * copy_string, a safe alternative to `strcpy`. Instead of passing a pointer to
 * a previously created buffer, `copy_string` will create that buffer, create
 * a copy of `source` and return this.
 *
 * @param source
 *      The source that will be copied up to and including the first encountered
 *      '\0' character. Therefore it is very important that source is a null
 *      terminated string, undefined behaviour occurs if this is not the case.
 *      If `source == NULL`, this function will call `exit()` and print an error
 *      message indicating the error.
 *
 * @return
 *      The return value will be a pointer (cstring) to the copy of the source.
 *      This function will never return NULL.
 */
cstring copy_string(const_cstring source);

#ifdef __cplusplus
}
#endif

#endif /* SAFE_STRING_H */
