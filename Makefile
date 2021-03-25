geometry: geometry.o lib_calc_trans.o libmainchek.o
	gcc geometry.o lib_calc_trans.o libmainchek.o -lm -o  geometry

geometry.o: geometry.c
	gcc -c geometry.c

lib_calc_trans.o: lib_calc_trans.c
	gcc -c lib_calc_trans.c

libmainchek.o: libmainchek.c
	gcc -c libmainchek.c

clean:
	rm -rf *.o geometry
