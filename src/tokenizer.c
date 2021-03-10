#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

/*Function to count the number of characters in a string*/

int length_str(char* str){
  int count = 0;
  while(*str++){
    ++count;
  }
  
  return count;
}

/*Evaluates weather a character is valid or invalid*/
char is_valid_character(char c){
  switch(c){
    case '\n':
    case '\t':
    case '\b':
    case '\a':
    case '\f':
    case '\r':
    case '\v':
    case '\\':
    case '\'':
    case '\"':
    case ' ':
    case '\0':
      return 0;
    default:
      return 1;
  }
}

/*Function to find the start of a word*/
int find_word_start(char* sentence, int index){
  if(!is_valid_character(sentence[index])){ //first we check if we are in a valid character, if not we look for one
    while(!is_valid_character(sentence[index])){
      index++;
    }
  }else{//we are in a valid character, so we are the word beginning
    return index;
  }
  return index;

}

/*Function to find the end of a word*/
int find_word_end(char* sentence, int index){
  int beg_of_word = find_word_start(sentence, index);
  //Now having the beginning we can get to the end
  while(is_valid_character(sentence[beg_of_word])){
    beg_of_word++;//when the loop is done this will be the end of the word
  }
  //here we went one over the end so we just return
  beg_of_word--;
  return beg_of_word;

}

/*Function to find the number of words there is in a sentence or sentence*/
int count_words(char* sentence){
    int count = 0;//counts words
    int index = 0;
    short end = 0;
    short length = length_str(sentence);
    while(1){
      index = find_word_start(sentence, index);
      if(index>=length) break;
      count ++;
      end = find_word_end(sentence, index);
      index = end+1;
    }
    return count;
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
  int index = 0;
  char** tokens = (char**) malloc((words_num+1)*sizeof(char*));//we allocate memory for the number of pointers needed
  
  for(short i=0;i<words_num;i++){ //we will calculate length of each string and allocate memory for each
    word_leng = (find_word_end(sentence, index) - find_word_start(sentence, index)) + 1;
    tokens[i] =(char *) malloc((word_leng + 1)*sizeof(char));//we allocate one extra for the NULL character
    index = find_word_start(sentence, index);
    for(short j = 0;j<word_leng;j++){
      tokens[i][j] = sentence[index+j];
    }
    index = (find_word_end(sentence, index) +1);
  }
  tokens[words_num] = (char*) malloc(sizeof(char));
  tokens[words_num] = '\0';
  return tokens;
}
