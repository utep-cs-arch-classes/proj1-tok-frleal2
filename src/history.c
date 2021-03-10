#include "history.h"
#include <stdlib.h>
#include <stdio.h>

/* We need to have a method to copy strings, function to copy string*/

char* str_duplicate(char* string){
    short i = 0;
  while(string[i] != '\0'){
    i++;
  }
  i++;
  char* copy = (char*) malloc(i*sizeof(char));
  i =0;
  while(*string){
    copy[i] = *string;
    i++;
    string++;
  }
  return copy;
}

/* We need a linked list in order to keep track of the history, fuction to initialize a list*/
List* init_history(){
  List* history;
  history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

/* Then we need to be able to add an element to the end of the list, function to add element to a list*/
void add_history(List* list, char* string){
  if(list->root == NULL){//initialize first value
    list->root = (Item*) malloc(sizeof(Item));
    list->root->id = 1;
    list->root->str = str_duplicate(string);
    list->root->next = NULL;
  }
  else{
    Item* temp;
    temp= (list->root);
    while((temp->next) != NULL){
      temp = temp->next;
    }
    temp->next = (Item*)malloc(sizeof(Item));
    (*temp).next->id = ((*temp).id) + 1;
    (*temp).next->str = str_duplicate(string);
    (*temp).next->next = NULL;

  }
}

/* Function to retrieve string stored in node according to id*/
char* get_history(List* list, int ident){
  Item* temp;
  if(list->root == NULL)
    return "List is empty";
  temp = (list->root);
  while(temp!=NULL){
    if((*temp).id == ident){
      return (*temp).str;
    }
    temp = temp->next;
  }
  return "ERROR ID NOT FOUND"; //return an empty string basically

}

/* Function in order to print the entire */
void print_history(List* list){
  Item* temp;
  temp = (list->root);
  while(temp!=NULL){
    printf("Element %d: %s \n", temp->id, temp->str);
    temp = temp->next;
  }

}

/*Function to free the memory allocated in the list along with its elements*/
void free_history(List* list){
  Item* temp;
  Item* node;
  node = list->root;
  while(node!=NULL){
    temp = node;
    node = node->next;
    free(temp);
  }
  free(list);
}
