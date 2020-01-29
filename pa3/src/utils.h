//========================================================================
// utils.h
//========================================================================
// Useful functions for arrays and sorting

#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

void print_array ( int arr[], size_t size );
void swap        ( int arr[], size_t i, size_t j );
int  compare     ( const void* a_p, const void* b_p );
void quick_recur( int arr[], size_t begin, size_t end );
size_t partition( int arr[], size_t begin, size_t end );

//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

#endif // UTILS_H

