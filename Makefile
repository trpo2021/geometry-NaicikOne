LIB_DIR = src/lib/
LIB_MAIN = src/main/
CC = gcc
AR = ar rc
RM = rm -Force
FLAG = -lm -o
O_FLAG = -Wall -Wextra  -I src -c -MP -MMD
BIN = bin/
OBJ_LIB = obj/$(LIB_DIR)
OBJ_MAIN = obj/$(LIB_MAIN)


all: $(BIN)geometry.exe

$(BIN)geometry.exe: $(BIN)calc.a
	$(CC) $(BIN)calc.a $(FLAG) $@

$(BIN)calc.a: $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o
	$(AR) $@ $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

$(OBJ_MAIN)geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c $(FLAG) $@

$(OBJ_LIB)lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c $(FLAG) $@

$(OBJ_LIB)libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c $(FLAG) $@

.PHONY: clean
clean:
	$(RM) $(OBJ_LIB)*.o
	$(RM) $(OBJ_MAIN)*.o
	$(RM) $(OBJ_LIB)*.d
	$(RM) $(OBJ_MAIN)*.d
	$(RM) $(BIN)*.exe
	$(RM) $(BIN)*.a
