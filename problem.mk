# Shared by every topic folder's Makefile.
# `make` builds each problem in the folder with its tests, e.g. ./is_sorted

CC = gcc
CFLAGS = -Wall -std=c11 -g

TOPIC := $(lastword $(subst /, ,$(CURDIR)))
PROBLEMS := $(basename $(wildcard *.c))

.PHONY: all clean

all: $(PROBLEMS)

$(PROBLEMS): %: %.c ../tests/$(TOPIC)/%.c $(wildcard ../adt/*.c)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROBLEMS) $(addsuffix .dSYM,$(PROBLEMS))
