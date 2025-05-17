build:
	gcc main.c -o quisebert -lm `pkg-config sdl3 --cflags --libs`
