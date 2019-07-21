# Makefile
#-Wextra
# -std=c99

all: build

build:
	gcc bitmma3.c -o mangoPaola5 -O0 -Wall -lm -Wextra
