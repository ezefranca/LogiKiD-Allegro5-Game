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
