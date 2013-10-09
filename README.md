<- LogiKid ->
=

ProjetoPI2 - Projeto Integrador II
==========
Desenvolvimento de um jogo utilizando a Allegro 5.

Licença e Créditos
========
![My image](http://i.creativecommons.org/l/by-sa/3.0/88x31.png)

Este obra foi licenciado sob uma [Licença Creative Commons Atribuição-CompartilhaIgual 2.5 Brasil.](http://creativecommons.org/choose/results-one?license_code=by-sa&jurisdiction=br&version=2.5&lang=pt_BR)

This work is licensed under a [Creative Commons Attribution-ShareAlike 3.0 Unported License.](http://creativecommons.org/licenses/by-sa/3.0/)

Arquivos de audio utilizados no jogo, estão sendo retirados dos seguintes links:

http://freemusicarchive.org/

http://www.freesfx.co.uk/

Requerimentos
=============
Allegro 5.x instalado no sistema

Como compilar
=============

Utilizando make:

-> Entrar na pasta make e escrever make:

```
$ cd make ; Make
```
```
Estrutura de Arquivos
============
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
│   │   │   ├── circuito.jpg
│   │   │   ├── fase1
│   │   │   │   ├── faseone.png
│   │   │   │   ├── faseone_with_girl.png
│   │   │   │   └── somenteobjetos.png
│   │   │   ├── fase1.jpg
│   │   │   ├── fase2
│   │   │   │   └── fundo-fase2.png
│   │   │   ├── fase2.jpg
│   │   │   ├── fundo640.png
│   │   │   ├── menu
│   │   │   │   ├── BG2.png
│   │   │   │   ├── BG3.png
│   │   │   │   └── BG.png
│   │   │   └── menu_fundo.png
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
│   └── src
│       ├── comum.h
│       ├── Fases
│       │   ├── Fase1
│       │   │   ├── fase1.c
│       │   │   ├── fase1.c~
│       │   │   └── fase1.h
│       │   └── Fase2
│       │       ├── fase2.c
│       │       └── fase2.h
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
├── tamanho_objetos.txt
└── web
    └── DB
        └── create.sql                 
```
```
