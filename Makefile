LIB_DIR = src/lib/
LIB_MAIN = src/main/
CC = gcc
AR = ar rc
FLAG = -lm -o
O_FLAG = -Wall -Wextra  -I src -c -MP -MMD
BIN = bin/
OBJ_LIB = obj/src/lib/
OBJ_MAIN = obj/src/main/

all: geometry.exe clean

geometry.exe: calc_ar
	$(CC) $(BIN)calc.a $(FLAG) $(BIN)geometry.exe

calc_ar: lib_calc_trans.o libmainchek.o geometry.o
	$(AR) $(BIN)calc.a $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c -o obj/$(LIB_MAIN)$@

lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c -o obj/$(LIB_DIR)$@

libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c -o obj/$(LIB_DIR)$@

.PHONY: clean

clean:
	$(RM) $(OBJ_LIB)*.o  $(OBJ_MAIN)*.o $(OBJ_TEST)*.o
	$(RM) $(OBJ_LIB)*.d  $(OBJ_MAIN)*.d $(OBJ_TEST)*.d
