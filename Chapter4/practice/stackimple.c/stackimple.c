#include<stdio.h>


class stack{
	//properties
	int *arr;
	int size;
	int top;
	
	//Constructor
	stack(int size){
		this->size = size;
		arr = new int[size];
		top = -1;
	}	

	//push Function
	void push(int element){
		if((size - top) > 1){
			top++;
			arr[top] = element;
		}
		else{
			printf("Error: Stack Overflow\n");
		}
	}

	void pop(){
		if(top > 0){
			top--;
		}
		else{
			printf("Error: Stack Undeflow\n");
		}
	}

	int peak(){
		if(top>=0 && top < size){
			return arr[top];
		}
		else{
			printf("Error: Stack Empty\n");
			return -1;
		}
	}
	
};
