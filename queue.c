#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

int put(struct node *head, int val){
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	if (new == NULL) return -1;

	if (head -> val == -1){
		head -> val = val;
		head -> next = NULL;
	} else {
		new -> val = head -> val;
		new -> next = head -> next;
		head -> val = val;
		head -> next = new;
	}

	return 0;
}

int get(struct node *head){
	struct node *t = head;

	if (t == NULL) return -1;

	while((t -> next) -> next != NULL){
		t = t -> next;
	}

	int p = (t -> next) -> val;
	t -> next = NULL;
	free(t -> next);

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

	if(head -> next == NULL){
		printf("%d ", head -> val);
	} else {
		display(head -> next);
		printf("%d ", head -> val);
	}
}

int main(){
	struct node head = {-1, NULL};
	int nums[] = {0, 1, 2, 3, 4, 5, 43, 7, 8, 9};
	int i, res;

	for(i = 0; i < 10; i++){
		printf("put %d\n", nums[i]);
		res = put(&head, nums[i]);
		if(res != 0) return 1;
	}

	printf("queue: ");
	display(&head);
	printf("\n");

	for (i = 0; i < 3; i++){
		res = get(&head);
		printf("get %d\n", res);
	}

	printf("queue: ");
	display(&head);
	printf("\n");

	res = delete(&head, 7);
	printf("delete %d\n", res);

	printf("queue: ");
	display(&head);
	printf("\n");
}