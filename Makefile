LIB_DIR = src/lib/
LIB_TEST = src/test/
LIB_MAIN = src/main/
CC = gcc
AR = ar rc
FLAG = -lm -o
O_FLAG = -I src -c

all: geometry.exe test

calc: geometry.exe

geometry.exe: calc_ar
	$(CC) calc.a $(FLAG) geometry.exe

test: test_ar
	$(CC) test_main.o test.o libmainchek.o $(FLAG) test.exe

test_ar: test_main.o test.o libmainchek.o
	$(AR) test.a test_main.o test.o libmainchek.o

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	$(AR) calc.a lib_calc_trans.o libmainchek.o geometry.o

geometry.o:
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c

lib_calc_trans.o:
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c

libmainchek.o:
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c

test_main.o:
	$(CC) $(O_FLAG) $(LIB_TEST)test_main.c

test.o:
	$(CC) $(O_FLAG) $(LIB_TEST)test.c

clean:
	rm *.o
	rm *.a
	rm *.exe
