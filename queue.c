#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

int put(struct node *head, int val){
	struct node *temp;
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL) return -1;

	temp = head;
	head = new;
	head -> val = val;
	head -> next = temp;

	return 0;
}

int get(struct node *head){
	struct node *t = head;

	if (t == NULL) return -1;

	while(t -> next != NULL){
		t = t -> next;
	}

	int p = t -> val;
	free(t);

	return p;
	
}

int delete(struct node *head, int val){
	struct node *s;
	struct node *t = head;

	if (t == NULL) return -1;
	
	//val is in head
	if (t -> val == val){
		head = t -> next;
		free(t);
		return val;
	}

	while(t -> next != NULL && t -> val != val){
		s = t;
		t = t -> next;
	}

	if (t -> val == val){
		s -> next = t -> next;
		free(t);
		return val;
	} else return -1;
}

void display(struct node *head){
	struct node *t = head;

	while(t -> next != NULL){
		display(t -> next);
		printf("%d ", t -> val);
	}
}

int main(){
	
	return 0;
}