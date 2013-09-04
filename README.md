ProjetoPI2
==========
Desenvolvimento de um jogo utilizando a Allegro 5.

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
|   +---data
|   |   |   gb_walk.png
|   |   |   pi.png
|   |   |   sega.ttf
|   |   |   senac.png
|   |   |   terminal.ttf
|   |   |
|   |   \---levels
|   |           FASE-1.png
|   |
|   \---logic
|           exemplo.txt
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
        |   EventTest.c
        |   EventTest.h
        |   game.c
        |   init.c
        |   main.c
        |   Player.c
        |   Player.h
        |   StartMenu.c
        |   StartMenu.h
        |
        \---lEngine
                exemplo.txt
                File.c
                File.h
                lEngine.c
                lEngine.h
```
