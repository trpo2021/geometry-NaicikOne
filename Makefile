LIB_DIR = src/lib/
LIB_MAIN = src/main/
FLAG = -lm -o
O_FLAG = -c

calc: geometry.exe clean

geometry.exe: calc_ar
	gcc calc.a $(FLAG) geometry.exe

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	ar rcs calc.a lib_calc_trans.o libmainchek.o geometry.o

geometry.o:
	gcc $(O_FLAG) $(LIB_MAIN)geometry.c

lib_calc_trans.o:
	gcc $(O_FLAG) $(LIB_DIR)lib_calc_trans.c

libmainchek.o:
	gcc $(O_FLAG) $(LIB_DIR)libmainchek.c

clean:
	rm *.o
