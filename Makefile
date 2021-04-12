C=gcc
FLAGS1=-lm -o
FLAGS2=-c
OBJ=geometry.o lib_calc_trans.o libmainchek.o
OBJ_DIR=src/hello/geometry.c
LIB_DIR1=src/libhello/lib_calc_trans.c
LIB_DIR2=src/libhello/libmainchek.c

geometry.c: $(OBJ)
	$(C) $(OBJ) $(FLAGS1)  geometry.exe

geometry.o: $(OBJ_DIR)
	$(C) $(FLAGS2) $(OBJ_DIR)

lib_calc_trans.o: $(LIB_DIR1)
	$(C) $(FLAGS2) $(LIB_DIR1)

libmainchek.o: $(LIB_DIR2)
	$(C) $(FLAGS2) $(LIB_DIR2)

clean:
	rm -rf *.o geometry
