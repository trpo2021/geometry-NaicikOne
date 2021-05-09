LIB_DIR = src/lib/
LIB_TEST = src/test/
LIB_MAIN = src/main/
CC = gcc
AR = ar rc
FLAG = -lm -o
O_FLAG = -Wall -Wextra  -I src -c -MP -MMD
BIN = bin/
OBJ_LIB = obj/src/lib/
OBJ_MAIN = obj/src/main/
OBJ_TEST = obj/src/test/

all: geometry.exe test

calc: geometry.exe

geometry.exe: calc_ar
	$(CC) $(BIN)calc.a $(FLAG) $(BIN)geometry.exe

test: test_ar
	$(CC) $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o $(FLAG) $(BIN)test.exe

test_ar: test_main.o test.o libmainchek.o
	$(AR) $(BIN)test.a $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	$(AR) $(BIN)calc.a $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c -o obj/$(LIB_MAIN)$@

lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c -o obj/$(LIB_DIR)$@

libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c -o obj/$(LIB_DIR)$@

test_main.o: $(LIB_TEST)test_main.c
	$(CC) $(O_FLAG) $(LIB_TEST)test_main.c -o obj/$(LIB_TEST)$@

test.o: $(LIB_TEST)test.c
	$(CC) $(O_FLAG) $(LIB_TEST)test.c -o obj/$(LIB_TEST)$@

clean:
	rm *.o
	rm *.a
	rm *.exe
