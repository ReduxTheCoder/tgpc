make: src/main.c
	gcc -Wall -Wextra -Wall -g -pedantic src/main.c -o bin/tgpc

run: src/main.c
	make
	./bin/tgpc

build: src/main.c
	make
	mv ./bin/tgpc ~/.local/bin/tgpc
