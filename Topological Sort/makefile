all: a.exe clean

a.exe: main.obj $(ALG).obj
	@ gcc $^ -o $@

main.obj:
	@ gcc -I .. -Wall -O2 -c main.c -o $@

$(ALG).obj:
	@ gcc -I .. -Wall -O2 -c $(ALG).c -o $@

clean:
	@ del *.obj