#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

bool search_brecket(char* MARK);
bool search_comma(char* MARK);
bool search_brecket2(char* MARK);
bool word_chek(char* WR, char* MARK);
int chek(char* MARK, int max, char* WR, char* MARK2);
int mainchek(char* MARK, int max, char* WR, char* MARK2);
