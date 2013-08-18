IDIR =.
CC=gcc -std=c99
CFLAGS=-I$(IDIR) -Wall -g

SRCDIR=src
ODIR=obj
LIBS=-lallegro -lallegro_audio -lallegro_acodec -lallegro_image -lallegro_font -lallegro_main -lallegro_ttf -lallegro_primitives -lm

_OBJ = main.o init.o game.o Player.o EventTest.o StartMenu.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OUTPUTDIR = ../bin

$(ODIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUTDIR)/ProjetoPI2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	$(info ************  COMPILADO COM SUCESSO ************)

all: $(OUTPUTDIR)/ProjetoPI2

.PHONY: clean
    
clean:
	rm -f $(ODIR)/*.o *~ allegro.log $(SRCDIR)/*~ $(OUTPUTDIR)/*
	
