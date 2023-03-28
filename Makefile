CC=cc
CFLAGS=-I/opt/homebrew/include -g -Wall
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework IOKit -framework CoreVideo -framework Cocoa -framework CoreFoundation -ledit

SOURCES=src/game.c
OUTPUT=game

all: $(OUTPUT)
$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(OUTPUT) $(LDFLAGS)

clean:
	rm -f $(OUTPUT)
	rm -rf $(OUTPUT).dSYM
