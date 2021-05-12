LIB_DIR = src/lib/
LIB_MAIN = src/main/
CC = gcc
AR = ar rc
FLAG = -lm -o
O_FLAG = -Wall -Wextra  -I src -c -MP -MMD
BIN = bin/
OBJ_LIB = obj/$(LIB_DIR)
OBJ_MAIN = obj/$(LIB_MAIN)

all: geometry.exe

geometry.exe: calc.a
	$(CC) $(BIN)calc.a $(FLAG) $(BIN)$@

calc.a: lib_calc_trans.o libmainchek.o geometry.o
	$(AR) $(BIN)$@ $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c $(FLAG) $(OBJ_MAIN)$@

lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c $(FLAG) $(OBJ_LIB)$@

libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c $(FLAG) $(OBJ_LIB)$@

.PHONY: clean

clean:
	$(RM) $(OBJ_LIB)*.o  $(OBJ_MAIN)*.o $(OBJ_TEST)*.o
	$(RM) $(OBJ_LIB)*.d  $(OBJ_MAIN)*.d $(OBJ_TEST)*.d
	$(RM) $(BIN)*.exe $(BIN)*.a
