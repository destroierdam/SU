/*
* This code combines the use of strcpy_s, needed in Visual C++ but not implemented in gcc
* and allows code, written in Visual C++ to be compiled by gcc.
* 
* All benefits that come from using strcpy_s are eliminated.
* This code just calls the strcpy function define in <cstring>
* 
*/
// strcpy_s is only guaranteed to be available if __STDC_LIB_EXT1__ is defined by the implementation 
// AND if the user defines __STDC_WANT_LIB_EXT1__ to the integer constant 1 BEFORE including string.h.

#ifdef __STDC_LIB_EXT1__ // Check if we can use strcpy_s
#define __STDC_WANT_LIB_EXT1__ 1 // Allow use of strcpy_s
#else
#include <cstring> // strcpy()
void strcpy_s(char * dest,unsigned int sizeInBytes,const char * src)
{
    strcpy(dest,src); // else, replace strcpy_s with strcpy
}
void strcpy_s(char * dest,const char * src)
{
    strcpy(dest, src);
}
#endif // __STDC_LIB_EXT1__
