

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



#include "hashmap.h"
#include "map.h"

int main(){

    map_t map = mapCreate();


    entry_t entry = {"hi", 7};


     mapInsert( &map, entry);


}

