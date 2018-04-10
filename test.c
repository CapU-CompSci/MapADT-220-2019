

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



#include "hashmap.h"
#include "map.h"



int main(){

    map_t map = mapCreate();


    entry_t entry = {"hi", 7};


    mapInsert( &map, "hi", 7);
//<<<<<<< HEAD
	mapInsert(&map, "by", 14);
//=======
	mapInsert(&map, "by", 12);

//>>>>>>> 5f98e35cf70e4bf8b95c9008a1614d27d7c8c563
	mapInsert(&map, "as", 23);
	mapInsert(&map, "qw", 34);
	mapInsert(&map, "zx", 45);

	
	printf(" index is %d\n", mapindex("by"));
	printf(" the value in the map is %d\n", mapGet(map,"by"));
   
	printf(" the value in the map is %d\n", mapGet(map,"hi"));
	printf(" the value in the map is %d\n", mapGet(map,"as"));
	printf(" the value in the map is %d\n", mapGet(map,"qw"));
	printf(" the value in the map is %d\n", mapGet(map,"zx"));
	mapRemove(&map,"by");
    printf(" index is %d\n", mapindex("by"));
    mapInsert(&map,"by", 13);
	printf(" the value in the map is %d\n", mapGet(map,"by"));
}

