CC = gcc
CFLAGS = -g -Wall

all: Main

Main: Main.c BinaryTree.c BinaryTree.h
    $(CC) $(CFLAGS) -o Main Main.c BinaryTree.c

clean:
    rm -f Main