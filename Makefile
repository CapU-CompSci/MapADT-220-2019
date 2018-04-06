all: tmtest hmtest tmwc hmwc

tmtest: map.h treemap.h treemap.c map-test.c
	gcc treemap.c map-test.c -o tmtest

hmtest: map.h hashmap.h hasmap.c map-test.c
	gcc hasmap.c map-test.c -o hmtest

tmwc: map.h treemap.h treemap.c wordcloud.c
	gcc treemap.c wordcloud.c -o tmwc

hmwc: map.h hashmap.h hashmap.c wordcloud.c
	gcc treemap.c wordcloud.c -o hmwc

clean:
	@rm -f *.o tmtest hmtest tmwc hmwc