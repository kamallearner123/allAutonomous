#include <stdio.h>

struct node {
	void *data;
	struct node *next;
};

struct node *head =NULL;

void push(void *new)
{
	if (head == NULL) {
		head = new;
		return;
	}

	head->next = head;
	head = new;
	return;
}

void *pop(void)
{
	void *tmp = NULL;;
	if (head == NULL) {
		return tmp;
	}

	tmp = head;

	head=head->next;
	return tmp;
}
