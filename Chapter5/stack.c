#include <stdio.h>
#include <stdlib.h>  // Correct header for dynamic memory allocation

struct node {
    int data;
    struct node *link;
};

// Function prototypes
void append(struct node **q, int num);
void display(struct node *q);
void addatbeg(struct node **q, int num);
void addafter(struct node *q, int loc, int num);
void delete(struct node **q, int num);
void Reverse(struct node **q);

int main() {
    struct node *p = NULL;

    // Append some nodes to the list
    append(&p, 1);
    append(&p, 2);
    append(&p, 3);
    append(&p, 4);
    append(&p, 17);
    addatbeg(&p,10);
    addafter(p,3,99);
    // Display the list
    display(p);
    Reverse(&p);
    display(p);
    return 0;
}

// Function definitions

void append(struct node **q, int num) {
    struct node *temp , *r;
    temp = *q;

    if(*q == NULL){
    	temp = malloc(sizeof(struct node));
	temp -> data = num;
	temp -> link = NULL;
	*q = temp;
    }
    else{
    	
	temp = *q;
	while(temp ->link != NULL){
		temp = temp->link;
	}
	r = malloc(sizeof(struct node));
	r ->data = num;
	r -> link = NULL;
	temp -> link = r;
    }
}

void display(struct node *q) {
    struct node *temp = q;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void addatbeg(struct node **q , int num){

	struct node *temp;
	temp = malloc(sizeof(struct node));

	temp ->data = num;
	temp ->link = *q;
	*q = temp ; 
}

void addafter(struct node *q, int loc, int num){
	struct node *temp , *r;
	temp = malloc(sizeof(struct node));
	temp = q;

	for(int i=1;i<loc;i++){
		temp = temp->link;
	}
	r = malloc(sizeof(struct node));
	r -> data = num;
	r -> link = temp ->link;
	temp ->link = r;

}

void delete(struct node **q,int num){
	
	struct node *temp, *r;

	temp = malloc(sizeof(struct node));
	r = malloc(sizeof(struct node));
	temp = *q;
	r = temp;
	if (temp != NULL && temp -> data == num){
		temp  = temp -> link;
		free(r);
		*q = temp;
	}
	else{
	while(temp -> data != num){
		r = temp;
		temp = temp ->link ; 
	}
	r ->link = temp ->link;
	temp -> link = NULL;

	free(temp);

	}

}

void Reverse(struct node **q){
	struct node *temp , *r , *c;
	temp = malloc(sizeof(struct node));
	r = malloc(sizeof(struct node));
	c = malloc(sizeof(struct node));
	temp = *q;
	if(temp->link != NULL){
		r = temp;
		temp = temp ->link;
		
	}
	while(temp ->link != NULL){	
			c = temp ->link;
			temp->link = r;
			r = temp;
			temp = c;
			
	}
	temp ->link = r;
	c = *q;
	c->link = NULL;
	*q = temp;
	

	
	

}
