ProjetoPI2
==========
Desenvolvimento de um jogo utilizando a Allegro 5.

Licença e Créditos
========
![My image](http://i.creativecommons.org/l/by-sa/3.0/88x31.png)
Este obra foi licenciado sob uma [Licença Creative Commons Atribuição-CompartilhaIgual 2.5 Brasil.](http://creativecommons.org/choose/results-one?license_code=by-sa&jurisdiction=br&version=2.5&lang=pt_BR)

This work is licensed under a [Creative Commons Attribution-ShareAlike 3.0 Unported License.](http://creativecommons.org/licenses/by-sa/3.0/)

Arquivos de audio utilizados no jogo, estão sendo retirados dos seguintes links:

http://www.freesfx.co.uk/
http://freemusicarchive.org/


Requerimentos
=============
Allegro 5.x instalado no sistema

Como compilar
=============

Utilizando make:

-> Entrar na pasta UsingMake e escrever Make:
```
$ cd UsingMake ; Make
```

```
.
├── bin
│   ├── data
│   │   ├── 256BYTES.TTF
│   │   ├── BORON2.TTF
│   │   ├── circuito.ttf
│   │   ├── images
│   │   │   ├── Gates
│   │   │   │   ├── AND.png
│   │   │   │   ├── ItemSelector.png
│   │   │   │   ├── NAND.png
│   │   │   │   ├── NOR.png
│   │   │   │   ├── NOT.png
│   │   │   │   ├── OR.png
│   │   │   │   ├── XNOR.png
│   │   │   │   └── XOR.png
│   │   │   ├── icons
│   │   │   │   ├── nosound.png
│   │   │   │   ├── sem_som.png
│   │   │   │   ├── som.png
│   │   │   │   └── sound.png
│   │   │   ├── intro
│   │   │   │   ├── allegro.png
│   │   │   │   ├── github.png
│   │   │   │   ├── pi.png
│   │   │   │   └── senac.png
│   │   │   ├── Objects
│   │   │   │   └── PC.png
│   │   │   ├── Player
│   │   │   │   ├── boy.png
│   │   │   │   ├── gb_walk (cópia).png
│   │   │   │   ├── gb_walk.png
│   │   │   │   ├── girl_meiocorpo.png
│   │   │   │   ├── girl.png
│   │   │   │   └── PlayerMenu.png
│   │   │   └── textbox.png
│   │   ├── levels
│   │   │   ├── blackscreen.png
│   │   │   ├── fase0
│   │   │   │   ├── bus_um_um.png
│   │   │   │   ├── bus_um_zero.png
│   │   │   │   ├── bus_zero_um.png
│   │   │   │   ├── bus_zero_zero.png
│   │   │   │   ├── faseruaverde.png
│   │   │   │   ├── faseruavermelho.png
│   │   │   │   └── teste.png
│   │   │   ├── fase1
│   │   │   │   ├── circ1_off.png
│   │   │   │   ├── circ1_on.png
│   │   │   │   ├── circ2_off.png
│   │   │   │   ├── circ2_on.png
│   │   │   │   ├── circ3_off.png
│   │   │   │   ├── circ3_on.png
│   │   │   │   ├── circ4_off.png
│   │   │   │   ├── circ4_on.png
│   │   │   │   ├── circ5_off.png
│   │   │   │   ├── circ5_on.png
│   │   │   │   ├── fase1.tmx
│   │   │   │   ├── faseone.png
│   │   │   │   ├── faseone_with_girl.png
│   │   │   │   ├── portas.png
│   │   │   │   ├── somenteobjetos.png
│   │   │   │   ├── teste.png
│   │   │   │   └── teste.xcf
│   │   │   ├── fase2
│   │   │   │   └── fundo-fase2.png
│   │   │   ├── fundo640.png
│   │   │   ├── menu
│   │   │   │   ├── BG2.png
│   │   │   │   ├── BG3.png
│   │   │   │   └── BG.png
│   │   │   ├── menu_fundo.png
│   │   │   ├── saidas_zer_um.png
│   │   │   ├── tile_alavancas.png
│   │   │   └── tile_circ.png
│   │   ├── PC.png
│   │   ├── sega.ttf
│   │   ├── sound
│   │   │   ├── badfeeling.wav
│   │   │   ├── doh.wav
│   │   │   ├── footstep.wav
│   │   │   ├── forcebewith.wav
│   │   │   ├── menu_open.wav
│   │   │   ├── music
│   │   │   │   └── Lunch.ogg
│   │   │   └── yesmaster.wav
│   │   ├── sourcecode.ttf
│   │   └── terminal.ttf
│   └── ProjetoPI2
├── doc
│   ├── allegro-5.0.10-manual.pdf
│   ├── latex
│   │   ├── caption2.sty
│   │   ├── fig1.jpg
│   │   ├── fig2.jpg
│   │   ├── main.aux
│   │   ├── main.bbl
│   │   ├── main.blg
│   │   ├── main.log
│   │   ├── main.pdf
│   │   ├── main.synctex.gz
│   │   ├── main.tex
│   │   ├── sbc.bst
│   │   ├── sbc-template.bib
│   │   ├── sbc-template.sty
│   │   └── table.jpg
│   ├── main.pdf
│   └── todo
├── LICENSE
├── LICENSE.htm
├── make
│   ├── Makefile
│   ├── obj
│   │   ├── Config
│   │   ├── Fases
│   │   │   ├── Fase0
│   │   │   │   └── fase0.o
│   │   │   ├── Fase1
│   │   │   │   └── fase1.o
│   │   │   └── Fase2
│   │   │       └── fase2.o
│   │   ├── gameloop.o
│   │   ├── Idioma
│   │   ├── init.o
│   │   ├── ItensMenu.o
│   │   ├── main.o
│   │   ├── Player.o
│   │   ├── StartMenu.o
│   │   └── textBox.o
│   └── src
│       ├── comum.h
│       ├── Config
│       │   ├── fases.conf
│       │   └── idioma.conf
│       ├── config.c
│       ├── config.h
│       ├── Fases
│       │   ├── Fase0
│       │   │   ├── fase0.c
│       │   │   └── fase0.h
│       │   ├── Fase1
│       │   │   ├── fase1.c
│       │   │   ├── fase1.c~
│       │   │   └── fase1.h
│       │   └── Fase2
│       │       ├── fase2.c
│       │       └── fase2.h
│       ├── gameloop.c
│       ├── gameloop.h
│       ├── Idioma
│       │   └── pt_br.conf
│       ├── init.c
│       ├── ItensMenu.c
│       ├── ItensMenu.h
│       ├── main.c
│       ├── Player.c
│       ├── Player.h
│       ├── StartMenu.c
│       ├── StartMenu.h
│       ├── textBox.c
│       └── textBox.h
├── README.md
├── README.md~
├── tamanho_objetos.txt
├── tree.txt
└── web
    └── DB
        └── create.sql

```
