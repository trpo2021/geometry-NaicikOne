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

all: geometry.exe test.exe clean

calc: geometry.exe clean

geometry.exe: calc_ar
	$(CC) $(BIN)calc.a $(FLAG) $(BIN)$@

test.exe: test_ar
	$(CC) $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o $(FLAG) $(BIN)$@

test_ar: test_main.o test.o libmainchek.o
	$(AR) $(BIN)test.a $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	$(AR) $(BIN)calc.a $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c -o $(OBJ_MAIN)$@

lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c -o $(OBJ_LIB)$@

libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c -o $(OBJ_LIB)$@

test_main.o: $(LIB_TEST)test_main.c
	$(CC) $(O_FLAG) $(LIB_TEST)test_main.c -o $(OBJ_TEST)$@

test.o: $(LIB_TEST)test.c
	$(CC) $(O_FLAG) $(LIB_TEST)test.c -o $(OBJ_TEST)$@

.PHONY: clean
clean:
	$(RM) $(OBJ_LIB)*.o $(OBJ_MAIN)*.o $(OBJ_TEST)*.o
	$(RM) $(OBJ_LIB)*.d $(OBJ_MAIN)*.d $(OBJ_TEST)*.d
