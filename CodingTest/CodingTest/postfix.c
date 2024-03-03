/*
괄호 포함 중위 연산자 입력받아서 후위 연산자로 출력해주는 프로그램
*/

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

void push(char* stack, char data)
{
	if (!isFull())
	{
		stack[++top] = data;
		printf("top:%d->data:%d\n", top, stack[top]);
	}
	else
	{
		printf("Full\n");
	}
}

char pop(char* stack)
{
	if (!isEmpty())
	{
		char temp = stack[top];
		stack[top--] = '\0';
		return temp;
	}
	else
	{
		printf("Empty\n");
	}
}

char peek(char* stack)
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


int operatorPriority(char op)
{
	if (op == '+' || op == '-')
		return 2;
	else if (op == '*' || op == '/')
		return 1;
	else if (op == '(')
		return 3;
	else if (op == ')')
		return 0;
	else
		return -1;
}

void convertPostfix(char* midfix, char* postfix)
{
	char opStack[10] = { 0 };
	int postfix_pointer = 0;
	int i = 0;
	//for (size_t i = 0; i < sizeof(midfix); i++)
	while (midfix[i] != '\0')
	{
		if (midfix[i] > 0x30 && midfix[i] < 0x39) {
			postfix[postfix_pointer++] = midfix[i];
		}
		else
		{
			if (isEmpty())
			{
				push(opStack, midfix[i]);
			}
			else
			{
				if (operatorPriority(midfix[i]) == 0)// 닫는 괄호다.
				{
					while (operatorPriority(peek(opStack)) != 3)
					{
						postfix[postfix_pointer++] = pop(opStack);
					}
					if (operatorPriority(peek(opStack)) == 3)
					{
						pop(opStack);//여는괄호는 버리고 
					}
				}
				if (operatorPriority(midfix[i]) == 3)// 여는 괄호다.
				{
					push(opStack, midfix[i]);
					continue;
				}
				if (top != -1)
				{
					while (operatorPriority(peek(opStack)) < operatorPriority(midfix[i]))//스택의 연산자 빼주고
					{
						postfix[postfix_pointer++] = pop(opStack);
					}
					if (operatorPriority(peek(opStack)) > operatorPriority(midfix[i]))//연산자 스택에 PUSH
					{
						push(opStack, midfix[i]);
					}
				}
			}
		}
		i++;
	}

	while (!isEmpty(opStack))
	{
		postfix[postfix_pointer++] = pop(opStack);
	}

}



int main(void)
{
	char midfix[30] = { '(', '2','+' ,'5',')' ,'*','3' };
	char postfix[30] = { 0 };
	printf("midfix: %s\n", midfix);
	convertPostfix(midfix, postfix);
	printf("postfix: %s\n", postfix);
	return 0;
}
