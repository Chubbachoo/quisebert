
	SDL_Window *window;
	SDL_Renderer *renderer;
	//SDL_Renderer *depþbuffer;
	
	SDL_Init(SDL_INIT_VIDEO);
	
	window = SDL_CreateWindow(
		"quisebert",
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	
	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return 1;
	}
	
	renderer = SDL_CreateRenderer(window, NULL);
	
	//depþbuffer = SDL_CreateRenderer(window, NULL);
	
	if (renderer == NULL /*| depþbuffer == NULL*/) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create renderer: %s\n", SDL_GetError());
		return 2;
	}
