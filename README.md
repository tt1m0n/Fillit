# fillit

General instructions

• Your project must be written in C and must respect the Norme coding standard.

• The allowed functions are : exit, open, close, write, read, malloc and free.

• Your Makefile must compile your code without relinks.

• It must contain the following rules : all, clean ,fclean et re.

• You must compile your binary with the Wall, Wextra and Werror flags. Any other flag are forbidden , especially those for optimising purposes.

• The binary must be named fillit and located in the root directory of your repos- itory.

• You’ll have to submit a file called author containing your username followed by a ’\n’ at the root of your repository.

------------------------------------------------------------------

Mandatory part

V.1 Program entry

Your executable must take only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format : 

every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino are separated by an newline each.

If the number of parameters sent to your executable is not 1, your program must display its usage and exit properly. 
If you don’t know what a usage is, execute the command cp without arguments in your Shell. It will give you an idea. Your file should contain between 1 and 26 Tetriminos.
The description of a Tetriminos must respect the following rules :

• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).

• A Tetrimino is a classic piece of Tetris composed of 4 blocks.

• Each character must be either a block character(’#’ ) or an empty character (’.’).

• Each block of a Tetrimino must touch at least one other block on any of his 4 sides (up, down, left and right).

Because each Tetrimino fills only 4 of the 16 available boxes, it is possible to describe the same 
Tetrimino in multiple ways. However, a rotated Tetrimino describes a different Tetrimino from the original, 
in the case of this project. This means no rotation is possible on a Tetrimino, when you will arrange it with the others.

The goal of this project is to arrange every Tetriminos with each others in order to make the smallest possible square. 
But in some cases, this square should contains holes when some given pieces won’t fit in perfectly with others.
Even if they are embedded in a 4x4 square, each Tetrimino is defined by its mini- mal boundaries (their ’#’). 
The 12 remaining empty characters will be ignored for the Tetriminos assemble process.
Tetriminos are ordered by they apparition order in the file. 
Among all the possible candidates for the smallest square, we only accept the one where Tetriminos is placed on their most upper-left position.

Your program must display the smallest assembled square on the standard output. To identify each Tetrimino in the square solution, you will assign a capital letter to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.
If the file contains at least one error, your program must display error on the stan- dard output followed by a newline and have to exit properly.

---------------------------------------------------------------------------------


How it is work

1. Compile my project (just type [make] at the root of repository)
2. type [./fillit sample]. "sample" it is a file with my map. Instead sample you can create your own map with tetraminos. 
