#include<stdio.h>

int main(void)
{
	char input[100];
	char *word=input;
	int num=0;

		for(;;)
		{
			printf("단어 입력: ");
			scanf("%s",input);
			word=getchar();
			if(num<strlen(word)) num=strlen(word);
			if(*(word)=='^Z') printf("제일 긴 단어: %d자",num); return 0;
		}

	
}
