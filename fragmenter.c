//Dominic Rollo
//
//fragmenter.c
//
//runs the main part of the shell.  breaks down entered data into arguments
// for a process that executes.
#include "fragmenter.h"

//the loop that keeps taking input from user
int init_state(char* start, int size){
  int exit = 0;
  char* buff;
  char** args;
  do{
    printf("%s ", start);
    buff_size = size;
    buff = buffering();
    args = parser(buff);
    int pos=0;
    if(strcmp(args[0],"exit")==0)
      exit=1;
    else
      run(args);
  }while(exit==0);//if exit equall 1 exit
  return 1;
}

//grab the command line input
char* buffering(void){
  int index=0;
  int in_char=getc(stdin);
  char* result = malloc(sizeof(char)*buff_size);
  while(in_char!=EOF && in_char!='\n'){
    result[index]=in_char;
    in_char=getc(stdin);
    index++;
    if(index>=buff_size)
      result=increase_buff(result);
  }
  result[index] ='\0';
  return result;
}
//increase buffer length if it ever gets to short
char* increase_buff(char* buff){
  buff_size+= buff_size;
  char* new= realloc(buff, buff_size);
  return new;
}

//break down the command line input into seperate cells in an array
char** parser(char* buffer){
  char* delim=" \n\r";
  char** fragments=malloc(sizeof(char)*buff_size);
  char* fragment;
  char* marker = buffer;
  int index=0;
  while((fragment=strtok_r(marker, delim, &marker))){
    fragments[index]=fragment;
    index++;
  }
  fragments[index]='\0';
    return fragments;
}

//fork process and run child process with input from user
int run(char** frags){
  pid_t process;
  process=fork();
  if(process == 0){
    execvp(frags[0], frags);
    exit(0);
  }
  else if(process>0)
    wait(NULL);

  return 1;
}

//not helpful ignore 
char** append_char(char** array){
  if(array[1]!='\0'){
    int i =1;
    while(array[i]!='\0'){
      array[i-1] = array[i];
      i++;
    }
    array[i]='\0';
  }
  else{
    array[1]="";
    array[2]='\0';
  }
    return array;
}
