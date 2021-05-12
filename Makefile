LIB_DIR = src/lib/
LIB_TEST = src/test/
LIB_MAIN = src/main/
RM = rm -Force
CC = gcc
AR = ar rc
FLAG = -lm -o
O_FLAG = -Wall -Wextra -I src -c -MP -MMD
BIN = bin/
OBJ_LIB = obj/$(LIB_DIR)
OBJ_MAIN = obj/$(LIB_MAIN)
OBJ_TEST = obj/$(LIB_TEST)

all: $(BIN)geometry.exe $(BIN)test.exe

calc: $(BIN)geometry.exe

test: $(BIN)test.exe

$(BIN)geometry.exe: clean $(BIN)calc.a
	$(CC) $(BIN)calc.a $(FLAG) $@

$(BIN)test.exe: test.a
	$(CC) $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o $(FLAG) $@

$(BIN)test.a: test_main.o test.o libmainchek.o
	$(AR) $@ $(OBJ_TEST)test_main.o $(OBJ_TEST)test.o $(OBJ_LIB)libmainchek.o

$(BIN)calc.a: $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o
	$(AR) $@ $(OBJ_LIB)lib_calc_trans.o $(OBJ_LIB)libmainchek.o $(OBJ_MAIN)geometry.o

$(OBJ_TEST)test_main.o: $(LIB_TEST)test_main.c
	$(CC) $(O_FLAG) $(LIB_TEST)test_main.c -o $@

$(OBJ_TEST)test.o: $(LIB_TEST)test.c
	$(CC) $(O_FLAG) $(LIB_TEST)test.c -o $@

$(OBJ_MAIN)geometry.o: $(LIB_MAIN)geometry.c
	$(CC) $(O_FLAG) $(LIB_MAIN)geometry.c $(FLAG) $@

$(OBJ_LIB)lib_calc_trans.o: $(LIB_DIR)lib_calc_trans.c
	$(CC) $(O_FLAG) $(LIB_DIR)lib_calc_trans.c $(FLAG) $@

$(OBJ_LIB)libmainchek.o: $(LIB_DIR)libmainchek.c
	$(CC) $(O_FLAG) $(LIB_DIR)libmainchek.c $(FLAG) $@

.PHONY: clean
clean:
	$(RM) $(OBJ_LIB)*.o $(OBJ_MAIN)*.o $(OBJ_TEST)*.o
	$(RM) $(OBJ_LIB)*.d $(OBJ_MAIN)*.d $(OBJ_TEST)*.d
	$(RM) $(BIN)*.exe $(BIN)*.a
