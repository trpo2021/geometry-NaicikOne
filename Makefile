LIB_DIR = src/lib/
MAIN_DIR = src/main/
FLAG = -lm -o
O_FLAG = -c

calc: geometry.exe clean

geometry.exe: calc_ar
	gcc -Wall -Werror  calc.a $(FLAG) geometry.exe

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	ar rcs calc.a lib_calc_trans.o libmainchek.o geometry.o

geometry.o:
	gcc -I src $(O_FLAG) $(MAIN_DIR)geometry.c

lib_calc_trans.o:
	gcc $(O_FLAG) $(LIB_DIR)lib_calc_trans.c

libmainchek.o:
	gcc $(O_FLAG) $(LIB_DIR)libmainchek.c

clean:
	rm *.o
