all: laba1	
laba1:laba1.c
	gcc -Wall -Werror -o laba1 laba1.c
clean:
	rm laba1
run:
	./laba1