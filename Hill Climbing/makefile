all: a.exe clean

a.exe: main.obj kqueens.obj
	gcc main.obj kqueens.obj -o a.exe

main.obj:
	gcc -I . -Wall -O2 -c main.c -o main.obj

kqueens.obj:
	gcc -I . -Wall -O2 -c kqueens.c -o kqueens.obj

clean:
	del *.obj