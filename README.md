ProjetoPI2
==========
Desenvolvimento de um jogo utilizando a Allegro 5.

Creditos
========
Todos os arquivos de audio utilizados no jogo, estão sendo retirados dos seguintes links:
http://www.freesfx.co.uk/

Requerimentos
=============
Allegro 5.x instalado no sistema

Como compilar
=============
Utilizando IDE:
```
-> Entrar na pasta UsingIDE e abrir o arquivo ProjetoPI2.sln
```

Ou por linha de comando...

```
-> Linux: $ cd UsingIDE ; xbuild ProjetoPI2.sln
-> Windows: cd UsingIDE ; msbuild ProjetoPI2.sln
```

Utilizando make:

-> Entrar na pasta UsingMake e escrever Make:
```
$ cd UsingMake ; Make
```

```
|   LICENSE
|   README.md
|
+---bin
|   \---data
|       |   sega.ttf
|       |   terminal.ttf
|       |
|       +---images
|       |   |   pi.png
|       |   |   senac.png
|       |   |
|       |   +---Gates
|       |   |       AND.png
|       |   |       ItemSelector.png
|       |   |       NAND.png
|       |   |       NOR.png
|       |   |       NOT.png
|       |   |       OR.png
|       |   |       XNOR.png
|       |   |       XOR.png
|       |   |
|       |   \---Player
|       |           gb_walk.png
|       |           PlayerMenu.png
|       |
|       +---levels
|       |       FASE-1.png
|       |
|       \---sound
|               footstep.wav
|
+---doc
|   |   main.pdf
|   |   todo
|   |
|   \---latex
|           caption2.sty
|           fig1.jpg
|           fig2.jpg
|           main.aux
|           main.bbl
|           main.blg
|           main.log
|           main.pdf
|           main.synctex.gz
|           main.tex
|           sbc-template.bib
|           sbc-template.sty
|           sbc.bst
|           table.jpg
|
+---UsingIDE
|   |   ProjetoPI2.sln
|   |   ProjetoPI2.userprefs
|   |
|   \---ProjetoPI2
|           ProjetoPI2.cproj
|           ProjetoPI2.pidb
|
\---UsingMake
    |   Makefile
    |
    \---src
        |   comum.h
        |   init.c
        |   ItensMenu.c
        |   ItensMenu.h
        |   main.c
        |   Player.c
        |   Player.h
        |   StartMenu.c
        |   StartMenu.h
        |
        \---Fases
            +---Fase1
            |       fase1.c
            |       fase1.h
            |
            \---Fase2
                    fase2.c
                    fase2.h
```
