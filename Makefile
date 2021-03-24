geometry: geometry.o lib_calc_trans.o mainchek.o
	gcc geometry.o lib_calc_trans.o mainchek.o  -o geometry

geometry.o: geometry.c
	gcc -c geometryn.c

lib_calc_trans.o: lib_calc_trans.c
	gcc -c lib_calc_trans.c

mainchek.o: mainchek.c
	gcc -c mainchek.c

clean:
	rm -rf *.o geometry
