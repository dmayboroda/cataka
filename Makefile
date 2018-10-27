CC = g++
CFLAGS = -Wall `sdl-config --cflags` $(DEBUG)
LIBS = `sdl-config --libs` -lSDL_image -lSDL_ttf -lSDL_mixer
NAME = 'catake'
HEADERS = src/ui.h
SOURCES = src/main.c $(HEADERS:.h=.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f src/*.o
	rm $(NAME)