/*
*  COMP 220 Project 4: Hashmap ADT implemation 
*  Author: Cap Comp220 Spring 2019
*  Date: April 1, 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hashmap.h"

Hashmap_t hashConstructor(int cap)
{
    Hashmap_t new;
    new.map = (linkedList*)calloc(cap, sizeof(linkedList)):
    new.capacity = cap;
    return new;
}