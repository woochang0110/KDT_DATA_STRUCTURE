#include<stdio.h>

int main(void)
{
	char input[100];
	char *word=input;
	int num=0;

		for(;;)
		{
			printf("�ܾ� �Է�: ");
			scanf("%s",input);
			word=getchar();
			if(num<strlen(word)) num=strlen(word);
			if(*(word)=='^Z') printf("���� �� �ܾ�: %d��",num); return 0;
		}

	
}
