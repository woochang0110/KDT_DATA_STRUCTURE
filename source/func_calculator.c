#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculator(int a, int b, char cal)
{
				switch(cal)
			{
				case '+': printf("%d%c%d=%d\n",a,cal,b,a+b); break;
				case '-': printf("%d%c%d=%d\n",a,cal,b,a-b); break;
				case '*': printf("%d%c%d=%d\n",a,cal,b,a*b); break;
				case '/': printf("%d%c%d=%d\n",a,cal,b,a/b); break;
				case '%': printf("%d%c%d=%d\n",a,cal,b,a%b); break;
				default : printf("invalid operator data\n"); break;
			}
}

int sp_calFinder(char *input,int* count,int* end)
{
	int i;//���ڳ� ���ڿ��� ���� Byte Size �����ϴ� ���� 
	for(i=*count;i<strlen(input);i++)//���� ���ڿ� ������ Ȯ���� ��ġ���� üũ 
	{	
	    printf("%d��° loop: �Լ��� cnt��:%d  end��:%d \n",i,*count,*end);
		if(input[i]!=' ') //���� ���ڰ� sp�� 
		{
			
			if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\n')
			{
				printf("%d���� ��ȣ����\n",i );
				*count=i; return *count;
			}
			else if(input[i]>='0'&&input[i]<'9')
			{
				printf("%d���� ���ڸ���\n",i );
				*end=i;
			}
		}
		else//���� ���ڰ� sp�� �ƴ� 
		{
			if(*count>*end)
			{
				printf("%d���� sp�߰�\n",i );
				(*count)++;	
			}
			else
			{
				printf("%d���� ���ڳ���\n",i );
				return *count;
			}
				
		}
		
	}	
} 

int main(void)
{
	
	
	
	
	char input_buffer[20];
	char aa[10];
	char ba[10];
	char cal;
	
	int a,b;
	int count=0;// ���� Array ��ġ �˷��ִ� index ����
	int end=0; 
	int* pc=&count;
	int* pe=&end;

	pc=&count;
	pe=&end;
	
	while(1)
	{	
		*pc=0;
		*pe=0;
		printf("1+1=,2-2=,1*1=,1/1= (exit:999): ");
		fgets(input_buffer,20,stdin); //�Է� ���ڿ� ����
		sp_calFinder(input_buffer,pc,pe); //ù��° ���� ��ġ �ľ� 
		strncpy(aa,input_buffer+(*pc),*pe);
		sp_calFinder(input_buffer,pc,pe);
		cal=input_buffer[*pc];
		sp_calFinder(input_buffer,pc,pe);
		strncpy(ba,input_buffer+(*pc),(*pe));
		a = atoi(aa);
		b = atoi(ba);
		printf("a:%d,b:%d,cal:%c\n",a,b,cal);
		printf("\n");
		if(strncmp(input_buffer,"999",3)==NULL)  //input_buffer�� 4���ڰ� exit�� ��� NULL�� �ο� //4Byte ���� ���Ͽ� exit 
		{
			break;
		}
		else
		{
			calculator(a, b,cal);
			

			printf("\n");
		}
	}
	
	
	return 0;
}


