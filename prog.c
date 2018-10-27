#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct node{   
  int value;   
  struct node* next;   
  struct node* prev; 
}; 
struct list{   
  struct node* head;   
  struct node* last;   
  int size; 
}; 
struct list List; 
int pushfront(int value){   
  if(List.size == 0){     
    struct node *head = NULL;     
    head = malloc(sizeof(struct node));     
    head->value = value;     
    head->next = NULL;     
    List.head = head;     
    List.last = head;   
  }else{     
    struct node *node = NULL;     
    node = malloc(sizeof(struct node));     
    List.last->next = node;     
    node->prev = List.last;     
    List.last = node;     
    List.last->value = value;     
    List.last->next = NULL;   
  }   
  List.size += 1;   
  return value; 
} 
int peekback(struct node Node){   
  if(Node.next == NULL){     
    return Node.value;   
  }else{     
    return peekback(*Node.next);   
  } 
} 
void freeall(struct node *Node){   
  while(Node->next != NULL){     
    struct node *last = NULL;     
    last = malloc(sizeof(struct node));     
    last = Node;     
    Node = Node->next;     
    free(last);   
  } 
} 
void reserved(struct node Node){   
  if(Node.prev == NULL){     
    printf("%d\n", Node.value);   
  }else{     
    printf("%d ", Node.value);     
    reserved(*Node.prev);   
  } 
} 
void dump(struct node Node){   
  if(Node.next == NULL){     
    printf("%d\n", Node.value);   
  }else{     
    printf("%d ", Node.value);     
    dump(*Node.next);   
  } 
} 
int main() {   
  List.size = 0;   
  char str[100];   
  while(scanf("%s", str) != EOF){    
    if(strcmp(str,"push-back")==0){      int a;      scanf("%d", &a);      printf("%d\n", pushfront(a));    }else if(strcmp(str,"pop-front")==0){     if(List.size==0){       printf("empty\n");     }else{       printf("%d\n", List.head->value);       List.head = List.head->next;       List.head->prev = NULL;       List.size--;     }    }else if(strcmp(str,"push-front")==0){      int a;      scanf("%d", &a);      printf("%d\n", a);      struct node *last = NULL;      last = malloc(sizeof(struct node));      List.head->prev = last;      last->next = List.head;      last->value = a;      last->prev = NULL;      List.head = last;      List.head->next->prev = List.head;      List.size++;    }else if(strcmp(str,"peek-front")==0){      if(List.size==0){         printf("empty\n");      }else{         printf("%d\n", List.head->value);      }    }else if(strcmp(str,"peek-back")==0){      if(List.size == 0){        printf("empty\n");      }else{        printf("%d\n", peekback(*List.head));      }    }else if(strcmp(str,"size")==0){      printf("%d\n", List.size);    }else if(strcmp(str,"clear")==0){      freeall(List.head);      List.size = 0;      List.head = NULL;      printf("empty\n");    }else if(strcmp(str,"dump")==0){      if(List.size == 0){       printf("empty\n");      }else{        dump(*List.head);      }    }else if(strcmp(str,"pop-back")==0){     List.last->prev->next = NULL;     printf("%d", List.last->value);     List.last = List.last->prev;    }else if(strcmp(str,"dump-reversed")==0){      reserved(*List.last);    }else{      printf("error");    }   } }
