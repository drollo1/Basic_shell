#ifndef FRAGMENTER_H_
#define FRAGMENTER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int buff_size;
int init_state(char* start, int size);
char* buffering(void);
char* increase_buff(char* buff);
char** parser(char* buffer);
int run(char** frags);
char** append_char(char** array);

#endif //FRAGMENTER_H_
