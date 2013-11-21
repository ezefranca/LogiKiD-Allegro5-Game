IDIR =.
CC=gcc -std=c99
CFLAGS=-I$(IDIR) -Wall -g

SRCDIR=src
SRCDIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)/./g' )
ODIR=obj
LIBS=-lallegro -lallegro_audio -lallegro_acodec -lallegro_image -lallegro_font -lallegro_main -lallegro_ttf -lallegro_primitives -lm

_OBJ = main.o init.o Player.o StartMenu.o ItensMenu.o pontuacao.o Fases/Fase0/fase0.o Fases/Fase1/fase1.o Fases/Fase2/fase2.o Fases/Fase3/fase3.o textBox.o gameloop.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

OUTPUTDIR = ../bin

$(ODIR)/%.o: $(SRCDIR)/%.c
	@$(call make_dir)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OUTPUTDIR)/logiKid: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	$(info ************  COMPILADO COM SUCESSO ************)

all: $(OUTPUTDIR)/ProjetoPI2

define make_dir
	@mkdir -p $(ODIR)
	for dir in $(SRCDIRS); \
	do \
		mkdir -p $(ODIR)/$$dir; \
	done
endef

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ allegro.log $(SRCDIR)/*~ $(OUTPUTDIR)/*
