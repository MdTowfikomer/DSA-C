#include <stdio.h>
#define SIZE 6

int arr[SIZE];
int top = -1;
// global declaration

void push(int x){
	if(top == SIZE-1){
		printf("Stack is full.");
	}
	top++;
	arr[top] = x;
	return;
}

void printStack(void){
	if(top == -1){
		printf("The stack is empty");
	}
	
	for(int i = top; i >= 0; i--){
		printf("%d\n", arr[i]);
	}
	return;
}

void pop(void){
		if(top == -1){
		printf("The stack is empty");
	}
	printf("Delete %d\n", arr[top]);
	top--;
}

int main(){
	push(45);
	push(23);
	push(34);
	push(30);
	printStack();
	pop();
	push(02);
	printStack();
	
	return 0;
}
