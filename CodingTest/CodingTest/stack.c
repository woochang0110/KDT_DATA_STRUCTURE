#include <stdio.h>
#include <stdbool.h>

#define STACKSIZE 10

int top = -1;

bool isEmpty(void)
{
	return top == -1;
}

bool isFull(void)
{
	return top == STACKSIZE - 1;
}

void push(int* stack, int data)
{
	if (!isFull())
	{
		stack[++top] = data;
		printf("top:%d->data:%d\n",top,stack[top]);
	}
	else
	{
		printf("Full\n");
	}
}

int pop(int* stack)
{
	if (!isEmpty())
	{
		return stack[top--];
	}
	else
	{
		printf("Empty\n");
	}
}

int peek(int* stack)
{
	if (!isEmpty())
	{
		return stack[top];
	}
	else
	{
		printf("Empty\n");
	}

}

int main(void)
{
	int stack[10] = { 0 };
	for (size_t i = 0; i < STACKSIZE; i++)
	{
		push(stack, i);
	}
	printf("peek!: %d\n", peek(stack));
	for (size_t i = 0; i < STACKSIZE; i++)
	{
		printf("pop!: %d\n",pop(stack));
	}

	return 0;
}