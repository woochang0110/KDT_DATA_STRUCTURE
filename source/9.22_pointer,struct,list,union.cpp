#if 1	//sdd�� ����Ǿ��ִ� �ؽ�Ʈ ������ �޾Ƽ� ���α׷� �󿡼� �ؽ�Ʈ ���Ϸ� �����ְ� ���� �����ؼ� �Ű��ֱ� 

#include <stdio.h>
fseek()
int main(void)
{
	FILE* inp;                   // ���� ������ ����
	FILE* outp;
	char input[100];                     // �Է��� ���ڸ� ������ ����

	inp = fopen("input.txt", "r");   // �б� �������� ���� ����
	if (inp == NULL)             // ������ ����Ǿ����� Ȯ��
	{
		printf("������ ������ �ʾҽ��ϴ�.:input.txt\n");
		return 1;	//������ �ִ�!  �����ڵ带 1�� �����Ѱ���, 
					//�̰� ����ڰ� �����ϱ� ���� 
	}
	
	outp = fopen("output.txt", "w");//������ �����ϱ� ������ ������� 
	
	while (fgets(input,100,inp))
	{
		printf("%s",input);
		fputs(input,outp);	//char�迭��  
		
	}
	fclose(inp);                 // ���� ����
	fclose(outp);
	return 0;
}

#endif




#if 0 //�Լ� ������ �迭 
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 


void add(int a,int b)
{
	printf("%d+%d=%d",a,b,a+b);
}
void sub(int a,int b)
{
	printf("%d-%d=%d",a,b,a-b);
}
void mul(int a,int b)
{
	printf("%d*%d=%d",a,b,a*b);
}
void div1(int a,int b)
{
	printf("%d/%d=%d",a,b,a/b);
}


void (*fp[])(int,int)=//������ �迭�� �Լ� �����͸� �����Ų�� ����; 
{
	add,
	sub,
	mul,
	div1
};

int main(void) 
{
	int a,b,sel;
	char *ip; 
	
	ip = (char *)malloc(100);		       // �޸� ���� �Ҵ� �� ������ ����
	sprintf(ip,"%s","�Լ� ������ �迭 ����");
	printf("%s: ����",ip);

	
	while(1)
	{	
		printf("\nselect(0:+, 1:-, 2:x, 3:/ 9:exit):");
		scanf("%d",&sel);
		if(sel==9) return 0;
		printf("�μ� �Է�");
		scanf("%d %d",&a,&b);
		fp[sel](a,b);
	}
	
	printf("%s: ����\n",ip);
	free(ip);                             // ���� �Ҵ� ���� ��ȯ
}






#endif




































#if 0	//p.441 ������������ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void makeNum(int sq[5][6]);
void calNum(int sq[5][6]);
void printNum(int sq[5][6]);
int main(void)
{
	int sq[5][6]={0};	
	makeNum(sq);
	calNum(sq);
	printNum(sq);
	
	return 0;
}

void makeNum(int sq[5][6])
{
	int i,j,n=1;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			sq[i][j]=n++;	
		}
	}
}
void calNum(int sq[5][6])
{
	int i,j,tmp;
	for(i=0;i<5;i++)
	{
		for(j=0;j<4;j++)
		{
			sq[4][j]+=sq[i][j];
			sq[i][5]+=sq[i][j];
			sq[5][5]+=sq[i][j];
		}
	}
	
}
void printNum(int sq[5][6])
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%4d",sq[i][j]);
		}
		printf("\n");
	}
}


#endif














#if 0 //�Լ� ������ �迭 
#include <stdio.h>

void add(int a,int b)
{
	printf("%d+%d=%d",a,b,a+b);
}
void sub(int a,int b)
{
	printf("%d-%d=%d",a,b,a-b);
}
void mul(int a,int b)
{
	printf("%d*%d=%d",a,b,a*b);
}
void div(int a,int b)
{
	printf("%d/%d=%d",a,b,a/b);
}


void (*fp[])(int,int)=//������ �迭�� �Լ� �����͸� �����Ų�� ����; 
{
	add,
	sub,
	mul,
	div
};

int main(void) 
{
	int a,b,sel;
	while(1)
	{	
		printf("select(0:+, 1:-, 2:x, 3:/ 9:exit):");
		if(sel==9) return 0;
		scanf("%d",&sel);
		printf("�μ� �Է�");
		scanf("%d %d",&a,&b);
		fp[sel](a,b);
	}
	
	
}






#endif



