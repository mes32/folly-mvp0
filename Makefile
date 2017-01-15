# Makefile for Folly MVP 0

# --- Define compiler and compiler options ---
CC = gcc
CFLAGS = -std=c99 -g -Wall -O2
INCLUDES = -lncurses


# --- List program modules and associated object files ---
MODULES_LIST = \
	main \
	game_map \
	game_world \
	gameplay_screen \
	goodbye_screen \
	help_screen \
	inventory_screen \
	load_screen \
	map_tile \
	narrative_stack \
	ncwindow \
	player_character \
	save_screen \
	welcome_screen \

OBJECT_FILES = $(MODULES_LIST:%=obj/%.o)

# --- Define the build rules ---
PROGRAM_BINARY = bin/folly-mvp0

all: $(PROGRAM_BINARY)

$(PROGRAM_BINARY) : $(OBJECT_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECT_FILES) -o $(PROGRAM_BINARY)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@ -c 

clean:
	rm -f $(PROGRAM_BINARY) $(OBJECT_FILES)