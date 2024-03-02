/*
원형큐에서는 포화 상태와 공백 상태 구분을 위해 항상 한칸은 비워둔다.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QSIZE 10

typedef struct{
	int rear;
	int front;
}queuepointer;

queuepointer qp;


bool isEmpty(void)
{
	return qp.front == qp.rear;
}


bool isFull(void)
{
	return qp.front == (qp.rear + 1) % QSIZE;
}

void enqueue(int* queue, int data)
{
	if(!isFull())
	{
		queue[qp.rear] = data;
		printf("Enqueue %d\n",data);
		printf("%d %d\n", qp.front,qp.rear);
		qp.rear = (qp.rear + 1) % QSIZE;
	}
	else
	{
		printf("Queue is FUll\n");
		printf("%d %d\n", qp.front, qp.rear);

	}
}
int dequeue(int* queue)
{
	if (!isEmpty())
	{
		printf("Dequeue %d\n", queue[qp.front]);
		printf("%d %d\n", qp.front, qp.rear);
		int temp = queue[qp.front];
		queue[qp.front] = 0;
		qp.front = (qp.front + 1) % QSIZE;
		return temp;
	}
	else
	{
		printf("Queue is Empty\n");
		printf("%d %d\n", qp.front, qp.rear);

	}
}


int main(void)
{
	qp.rear = QSIZE-1;
	qp.front = QSIZE - 1;
	int queue[QSIZE] = { 0 };
	int data = 0;

	for (size_t i = 0; i < QSIZE; i++)
	{
		enqueue(queue, i);
	}


	for (size_t i = 0; i < QSIZE; i++)
	{
		data=dequeue(queue);
	}

	return 0;
}