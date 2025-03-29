build:
	gcc main.c -o quisebert -lm `pkg-config sdl3 --cflags --libs`
buildgraphics:
	gcc graphics.c -o graphics -lm `pkg-config sdl3 --cflags --libs`
