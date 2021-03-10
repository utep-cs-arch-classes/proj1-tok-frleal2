#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

char *copy_str(char *src, short len){
  char *ptr = (char *)malloc(sizeof(char) * (len + 1));
  for(int i = 0; i < len && src[i] != '\0'; i++){
    ptr[i] = src[i];
  }
  ptr[len] = '\0';
  return ptr;
}

/*Evaluates weather a character is valid*/
int space_char(char c){
  switch(c){
    case '\n':
    case '\t':
    case ' ':
      return 1;
    default:
      return 0;
  }
}

/*Evaluates weather a character is invalid*/
int non_space_char(char c){
  if(c != '\t' && c != ' ' && c != '\n'){
     return 1;
  }
  else{
    return 0;
  }  
}

/*Function to find the start of a word*/

char *word_start(char *str){
  while(space_char(*str) == 1){
    str++;
  }  
  return str;
}

/*Function to find the end of a word*/
char *word_end(char *str){
  while(non_space_char(*str) == 1 && *str != '\0'){
    str++;
  }
  return str;
}

/*Function to find the number of words there is in a sentence or sentence*/
int count_words(char *str){
  int counter = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_end(str);
    counter++;
  }
  return counter;
  
}

/* Function that prints all tokens*/
void print_tokens(char** tokens){
  while(*tokens){
    printf("[%s]   ", *tokens);
    tokens++;
  }
}

/*Function that frees all tokens and the array containing the tokens. */
void free_tokens(char** tokens){
  char** temp = tokens;
  while(*tokens){
    free(*tokens);
    tokens++;
  }
  free(temp);
}

/*Function that tokenizes the string that is passed on to the argument into an array of tokens*/
char** tokenize(char* sentence){
  short words_num = count_words(sentence);
  short word_leng =0;
  char** tokens = (char**) malloc((words_num+1)*sizeof(char*));//we allocate memory for the number of pointers needed
  
  for(short i=0;i<words_num;i++){ //we will calculate length of each string and allocate memory for each
    
    char *start = word_start(sentence);
    
    char *end = word_end(sentence);
    
    int word_leng = (int)(end - start) + 1;
    
    tokens[i] =(char *) malloc((word_leng + 1)*sizeof(char));//we allocate one extra for the NULL character
    
    char *word =  word_start(sentence);
    
    for(short j = 0;j < word_leng; j++){
      
      tokens[i][j] = word[j];
      
    }
    
    tokens[i][word_leng] = '0';
    
    index = ((int) word_end(sentence) +1);
  }
  tokens[words_num] = '\0';
  return tokens;
}
