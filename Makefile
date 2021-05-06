all: geometry.exe

geometry.exe: 
	gcc geometry.o lib_calc_trans.o libmainchek.o -lm -o geometry.exe

geometry.o:
	gcc -c src/main/geometry.c

lib_calc_trans.o:
	gcc -c src/lib/lib_calc_trans.c

libmainchek.o:
	gcc -c src/lib/libmainchek.c

clean:
	rm -rf *.o all
