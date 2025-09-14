build:
	gcc main.c -o quisebert -Wall -lm `pkg-config sdl3 --cflags --libs`
