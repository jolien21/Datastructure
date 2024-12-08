#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{ 
  string phrase;
  struct node * next;
}
node;

#define LIST_SIZE 2

bool unload(node* list);
void visualizer(node * list);

int main(void)
{
  node *list = NULL;

  //Add items to list
  for (int j  = 0; j < LIST_SIZE; j++)
  {
    string phrase = get_string("Enter a new phrase: ");

    // add phrase to new node in list
    node *n = malloc(sizeof(node));
      if (n == NULL){
        return 1;
      }
    n->phrase = phrase;
    n->next = NULL; //preset it to null so if you don't have another node, it is set at Null

    n->next = list;
    list = n; 

    //Visualiwe list after adding a node
    visualizer(list);
  }

  //free all memory used
  if(!unload(list))
  { 
    printf("Error freeing the list. \n");
    return 1;
  }
  printf("freed the list. \n");
  return 0;
}

bool unload(node *list)
{
  
  node *ptr = list;

  while(ptr != NULL)
  {
    ptr = list->next;
    free(list);
    list = ptr;
  }
  return true;
}

void visualizer(node*list)
{
  printf("\n+--- List Visualizer ---+\n\n");
  while (list != NULL)
  {
    printf("Location %p\nPhrase: \"%s\"\nNext: %p\n\n", list, list->phrase, list->next);
    list = list->next;
  }
  printf("+---------------------+\n\n");
}



