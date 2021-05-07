LIB_DIR = src/lib/
LIB_TEST = src/test/
LIB_MAIN = src/main/
FLAG = -lm -o
O_FLAG = -I src -c

all: geometry.exe test

calc: geometry.exe

geometry.exe: calc_ar
	gcc calc.a $(FLAG) geometry.exe

test: test_ar
	gcc test_main.o test.o libmainchek.o $(FLAG) test.exe

test_ar: test_main.o test.o libmainchek.o
	ar rc test.a test_main.o test.o libmainchek.o

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	ar rc calc.a lib_calc_trans.o libmainchek.o geometry.o

geometry.o:
	gcc $(O_FLAG) $(LIB_MAIN)geometry.c

lib_calc_trans.o:
	gcc $(O_FLAG) $(LIB_DIR)lib_calc_trans.c

libmainchek.o:
	gcc $(O_FLAG) $(LIB_DIR)libmainchek.c

test_main.o:
	gcc $(O_FLAG) $(LIB_TEST)test_main.c

test.o:
	gcc $(O_FLAG) $(LIB_TEST)test.c

clean:
	rm *.o
	rm *.a
	rm *.exe
