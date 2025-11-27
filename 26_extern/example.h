#ifndef EXAMPLE_H
#define EXAMPLE_H

// When this is compiled with a C++ compiler, it will handle correctly
// creating the symbol 'add' for use in the main.c file.
// This can be verified with 
//   'nm example.o'

// this will add extern "C" only when using a c++ compiler
#ifndef __cplusplus
extern "C"
#endif
int add(int, int);

#endif
