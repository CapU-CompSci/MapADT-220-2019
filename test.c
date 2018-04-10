

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



#include "hashmap.h"
#include "map.h"


int main(){

    map_t map = mapCreate();


    entry_t entry = {"hi", 7};


    mapInsert( &map, "hi", 7);
	mapInsert(&map, "by", 12);
	mapInsert(&map, "as", 23);
	mapInsert(&map, "qw", 34);
	mapInsert(&map, "zx", 45);
	printf("helo world\n");
	
	printf(" index is %d\n", mapindex("by"));
	printf(" the value in the map is %d\n", mapGet(map,"by"));
    printf(" the value in the map is %d\n", mapGet(map,"by"));
	printf(" the value in the map is %d\n", mapGet(map,"hi"));
	printf(" the value in the map is %d\n", mapGet(map,"as"));
	printf(" the value in the map is %d\n", mapGet(map,"qw"));
	printf(" the value in the map is %d\n", mapGet(map,"zx"));
	mapRemove(&map,"bu");
    printf(" index is %d\n", mapindex("by"));
    

}

