build:
	clang -std=c11 ./src/main.c -lSDL2 -lm -o renderer

run:
	./renderer

clean:
	rm renderer
