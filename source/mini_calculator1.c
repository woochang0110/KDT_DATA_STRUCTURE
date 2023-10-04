#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;
char* nullFinder(int index, char *a)
{
	char cnum[20];
	int i,j,cnt,num;
	for(i=index;i<20;i++)
	{
		if(a[i]=='\0') 
		{
			count=i;
			break;
		}
	}
	strncpy(cnum,a,cnt);
	return cnum;	
} 


int main(void)
{
	char input_buffer[20];
	char aa[10];
	char ba[10];
	char cal[2];
	int a,b;
	while(1)
	{
		printf("1+1=,2-2=,1*1=,1/1= (exit:999): ");
		fgets(input_buffer,20,stdin); 
		aa=nullFinder(0,input_buffer);
		aa=nullFinder(0,input_buffer);
		strncpy(aa,input_buffer,1);
		strncpy(ba,input_buffer+2,1);
		a = atoi(aa);
		b = atoi(ba);
		printf("\n");
		if(strncmp(input_buffer,"999",3)==NULL)//input_buffer의 4글자가 exit일 경우 NULL값 부여 //4Byte 내용 비교하여 exit 
		{
			break;
		}
		else if(a*b>=0&&a*b<82)
		{
			switch(input_buffer[1])
			{
				case '+': printf("%d%c%d=%d\n",a,input_buffer[1],b,a+b); break;
				case '-': printf("%d%c%d=%d\n",a,input_buffer[1],b,a-b); break;
				case '*': printf("%d%c%d=%d\n",a,input_buffer[1],b,a*b); break;
				case '/': printf("%d%c%d=%d\n",a,input_buffer[1],b,a/b); break;
				case '%': printf("%d%c%d=%d\n",a,input_buffer[1],b,a%b); break;
				default : printf("invalid operator data\n"); break;
			}
			printf("\n");
		}
		
		else
		{
			printf("invalid input data"); 
		}
	}
	return 0;
}
