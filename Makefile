all: tmtest hmtest tmwc hmwc

tmtest: map.h treemap.h treemap.c map-test.c
	gcc treemap.c map-test.c -DTREEMAP -o tmtest

hmtest: map.h hashmap.h hashmap.c map-test.c
	gcc hashmap.c map-test.c -DHASHMAP -o hmtest

tmwc: map.h treemap.h treemap.c freqTree.h freqTree.c wordcloud.c
	gcc treemap.c freqTree.c wordcloud.c -DTREEMAP -o tmwc

hmwc: map.h hashmap.h hashmap.c freqTree.h freqTree.c wordcloud.c
	gcc hashmap.c freqTree.c wordcloud.c -DHASHMAP -o hmwc

clean:
	@rm -f *.o tmtest hmtest tmwc hmwc