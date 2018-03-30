all: tmtest hmtest tmwc hmwc

tmtest: map.h treemap.h treemap.c map-tests.c
	gcc treemap.c map-tests.c -o tmtest

hmtest: map.h hashmap.h hasmap.c map-tests.c
	gcc hasmap.c map-tests.c -o hmtest

tmwc: map.h treemap.h treemap.c wordcloud.c
	gcc treemap.c wordcloud.c -o tmwc

hmwc: map.h hashmap.h hashmap.c wordcloud.c
	gcc treemap.c wordcloud.c -o hmwc

clean:
	@rm -f *.o tmtest hmtest tmwc hmwc