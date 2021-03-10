#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

void read_comms();
void tokenizing_mode();


int main(){
  printf("Welcome to Felipe's tokenizer\n");
  printf("/e: will exit the program.\n");
  printf("/t: will enter tokenize mode.\n");
  printf("/h: will print HELP\n");
  read_comms();
}

void read_comms(){
  char c;
  char com[100];
  
  while(1){
    printf("#");
    scanf("%s", com);
    if(com[0]=='/'){
      if(com[1] == 'e'){
        break;
      }
      else if(com[1] == 't'){
        tokenizing_mode();
      }
      else if(com[1] == 'h'){
        printf("/e: will exit the program.\n");
        printf("/t: will enter tokenize mode.\n");
        printf("/h: will print HELP\n");
      }
      else{
        printf("Command not recognized");
        printf("\n");
      }
    }
    else{
      printf("%s \n", com);
    }
    
  }

}

void tokenizing_mode(){
  char com[100];
  List* history = init_history();
  char ** tokens;
  while(1){
    printf("Enter string to tokenize all words or /e to quit or /l# for history access:");
    scanf(" %99[^\n]s",com);
    if(com[0]== '/'){
      if(com[1] == 'e'){
        break;
      }
      else if(com[1] == 'l'){
        printf("Searchng for ID %d \n",com[2]-'0'); //we substract character zero to get the numerical equivalent of the char
        tokens = tokenize(get_history(history,com[2]-'0'));
        print_tokens(tokens);
      }
      else{
        printf("Command not recognized.");printf("\n");
      }
    }
    else{
      tokens = tokenize(com);
      print_tokens(tokens);
      add_history(history,com);
      free_tokens(tokens);
    }
    printf("\n");
  }
  free_history(history);
}
