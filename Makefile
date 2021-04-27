all: geometry.o lib_calc_trans.o libmainchek.o #сборка приложения
	gcc geometry.o lib_calc_trans.o libmainchek.o -lm -o geometry.exe

geometry.o: lib_calc_trans.o libmainchek.o
	gcc -c src/main/geometry.c

lib_calc_trans.o:
	gcc -c src/alllib/lib_calc_trans.c

libmainchek.o:
	gcc -c src/alllib/libmainchek.c

clean:
	rm -rf all *.o
