all: geometry.o lib_calc_trans.o libmainchek.o
	gcc geometry.o lib_calc_trans.o libmainchek.o -lm -o geometry.exe

geometry.o:
	gcc -c src/main/geometry.c

lib_calc_trans.o:
	gcc -c src/lib/lib_calc_trans.c

libmainchek.o:
	gcc -c src/lib/libmainchek.c

test_main.o:
	gcc -c src/test/test_main.c

test: libmainchek.o test_main.o
	gcc -c src/test/test.c
	gcc test.o libmainchek.o test_main.o -lm -o test.exe

clean:
	rm -rf all *.o
