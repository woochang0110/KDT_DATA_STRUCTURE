#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct NODE {
	int data;
	struct NODE* prev;
	struct NODE* next;
}__NODE;

__NODE* createNode(int data)
{
	__NODE* newNode = (__NODE*)malloc(sizeof(__NODE));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertNode(__NODE** head, int data, __NODE** tail)
{
	__NODE* newNode = createNode(data);
	if (*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
	}
	else
	{
		(*tail)->next = newNode;
		newNode->prev = *tail;
		newNode->next = NULL;
		*tail = newNode;
	}
}

void deleteNode(__NODE** head, int data, __NODE** tail)
{
	__NODE* curr = *head;
	while (curr != NULL)
	{
		if (data == curr->data)
		{
			if (curr->prev != NULL)
				curr->prev->next = curr->next;
			else
				*head = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			else
				*tail = curr->prev;
			
			printf("delete curr->data:%d\n", curr->data);
			free(curr);
			break;
		}
		curr = curr->next;
	}
}


int main(void)
{
	__NODE* head = NULL;
	__NODE* tail = NULL;

	for (size_t i = 0; i < 10; i++)
	{
		insertNode(&head, i, &tail);
	}

	deleteNode(&head, 4, &tail);

	__NODE* curr=head;
	
	
	while(curr != NULL) 
	{
		printf("data: %d\n", curr->data);
		curr = curr->next;
 	} 


	return 0;
}