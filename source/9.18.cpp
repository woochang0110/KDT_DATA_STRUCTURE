#if 1

/*
	���� �Է�(1+1=, exit�� ����)
	���: 1+1=2 3-1=2 2*3=6 9/3=3 9%2=1
	1. ����: ASCII�ڵ��� �����Է� �ʵ忡�� 0~9���� �ۿ� ���� �� ���� ���� �ԷµǸ� �߸��ԷµǾ��ٰ� �˷��ְ� �ٽ� �Է��Ѵ�.
			printf("invalid input data");   
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char input_buffer[6];
	int a,b;
	while(1)
	{
		printf("Enter (1+1, ����:exit): ");
		fgets(input_buffer,100,stdin); 
//		strncpy(a,input_buffer,1);
//		strncpy(b,+2,1);
		a = atoi(input_buffer[0]);
		b = atoi(input_buffer[2]);
		printf("\n");
		if(strncmp(input_buffer,"exit",4)==NULL)//input_buffer�� 4���ڰ� exit�� ��� NULL�� �ο� //4Byte ���� ���Ͽ� exit 
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
				case '%': pprintf("%d%c%d=%d\n",a,input_buffer[1],b,a%b); break;
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

#endif







#if 0

#include <stdio.h>
#include <stdlib.h>
#include<string.h>	//strncmp
int main(void)
{
	char input_buffer[6];
	
	while(1)
	{
		printf("Enter Score(A~F) exit: ");
		fgets(input_buffer,100,stdin); 
		printf("\n");
		if(strncmp(input_buffer,"exit",4)==NULL)//input_buffer�� 4���ڰ� exit�� ��� NULL�� �ο� //4Byte ���� ���Ͽ� exit 
		{
			break;
		}
		else
		{
			switch(input_buffer[0])
			{
				case 'A': printf("Your Score is A\n"); break;
				case 'B': printf("Your Score is B\n"); break;
				case 'C': printf("Your Score is C\n"); break;
				case 'D': printf("Your Score is D\n"); break;
				case 'F': printf("Your Score is F\n"); break;
				default : printf("Enter Again\n"); break;
			}
			printf("\n");
		}
	}
	return 0;
}
#else
		if(input_buffer[0]=='e'&&input_buffer[1]=='x'&&input_buffer[2]=='i'&&input_buffer[3]=='t')
		{
			break;		
		}

#endif





#if 0
/*
 �Է�����: ���� ���� ���� ���� �̸�(A 4.1 100 100 wcm)
 1. ���� ���� F�� ���α׷� ����
 2. ���� 4.4 �̻� ���� 95�̻� ���� 95�̻��� Excellent!�� �Է°� ��� 
 3. ���� 4.0 �̻� ���� 90�̻� ���� 90�̻��� Good!�� �Է°� ���
 4. ���� 3.0 �̻� ���� 85�̻� ���� 85�̻��� Normal!�� �Է°� ���


*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(void)
{
	char input_buffer[34];
	char grade;
	char score[4]; //3.4\0 Ascii ������ ������� 
	char name[20];
	char eng[4];	//99�����ϱ� ASCII ���� 2��=2Byte�� \0 NULL�� 1Byte�ؼ� 3����Ʈ �ʿ��ѵ� ¦�� ����ߵǴϱ� 4Byte  
	char math[4];	//3����Ʈ �ʿ��ѵ� ¦�� ����ߵǴϱ� 4 
	double d_score;
	int i_eng,i_math;
	
	while(1)
	{
		printf("���� ���� ���� ���� �̸�: (A 4.1 99 99 wcm)");
		fgets(input_buffer,100,stdin);
		printf("\n");
		if(input_buffer[0]=='F')
		{
			return 0;		
		}
		
		else
		{
			grade = input_buffer[0]; //input_buffer������ grade�� ����
			
			strncpy(score,input_buffer+2,3);
			d_score=atof(score);
			
			strncpy(eng,input_buffer+6,2);
			i_eng=atoi(eng);
			
			strncpy(math,input_buffer+9,2);
			i_math=atoi(math);
			
			strcpy(name,input_buffer+12);
			
			if(d_score>=4.4&&i_math>94&&i_eng>94)
			{
				printf("Excellent! ");
			}
			else if(d_score>=4.0&&i_math>89&&i_eng>89)
			{
				printf("Good~ ");
			}
			else if(d_score>=3.0&&i_math>84&&i_eng>84)
			{
				printf("Normal... ");
			}			
			else 
			{
				return 0;
			}
			printf("����: %c ����: %.1lf ����: %d ����: %d �̸�:%s \n",grade,d_score,i_eng,i_math,name);

		}
	}
	return 0;
}


#endif


#if 0
#include <stdio.h>
#include <stdlib.h> //rand, atoi(Ascii->int), atof(Ascii-float), atol(Ascii->long) itoa(int->Ascii)�Լ� �� ���� 
					//atoi ��ȯ������ ���� keyboard�� ASCII�Է��� �޸� �� int�� �Է��ϰ� �ٽ� ASCII�� ��� 
#include<string.h>  // strncpy, strcpy,strcat ���� �Լ��� ������� 
int main(void)
{
	char grade;
	char score[4]; //3.4\0 Ascii ������ ������� 
	char name[20];
	char input_buffer[100];
	int i=0;
	char eng[]="900"; 
	int i_eng=0;
	char math[]="100"; // 1�� ASCII �ڵ尪: 0x31  0�� ASCII �ڵ尪: 0x30 
	//��, math[0]=0011 0001, math[1]=0011 0000, math[2]=0011 0000
	int i_math=0;
	int sum=0;
	char opt[100];
	while(1)
	{
		printf("���� ���� ���� ���� �̸�: (A 4.1 100 100 wcm)");
		fgets(input_buffer,100,stdin);
		if(input_buffer[0]=='F')
		{
			return 0;		
		}
		
		else
		{
			grade = input_buffer[0]; //input_buffer������ grade�� ����
//			score[0] = input_buffer[2];
//			score[1] = input_buffer[3];
//			score[2] = input_buffer[4];
//			score[3] = '\0';

			strncpy(score,input_buffer+2,3); //���̾��� 
			//strncpy(�Է¹��������ּ�,�Է³��� �����ּ�,�����ּҺ��� �Է³��� ������)
			
			strncpy(eng,input_buffer+6,3); //���̾��� 
			//strncpy(�Է¹��������ּ�,�Է³��� �����ּ�,�����ּҺ��� �Է³��� ������)
			i_eng=atoi(eng);
			
			strncpy(math,input_buffer+10,3); //���̾��� 
			//strncpy(�Է¹��������ּ�,�Է³��� �����ּ�,�����ּҺ��� �Է³��� ������)
			i_math=atoi(math);
			sum=i_eng+i_math;
			itoa(sum,opt,10);
			
			strcpy(name,input_buffer+14);
			//strncpy(�Է¹��������ּ�,�Է³��� �����ּ�)  NULL ���� ������ ����� 
			
			
			printf("����: %c\n",grade);
			//printf("����: %s\n",score);
			printf("����: %lf\n",atof(score));
			printf("����: %d\n",i_eng);
			printf("����: %d\n",i_math);

			printf("���п��� �� ASCII��: %s\n",opt);
			printf("�̸�: %s\n",name);
			
		
		}
	
	}
	return 0;
}



#endif


#if 0
#include<stdio.h>
#define SQ(x) ((x)*(x))  //�ŵ����� SQUARE�� ���� ��ũ����. 
#define CUBE(x) (SQ(x)*(x)) //3���� 
enum{
	SUN=7,MON=1,TUE=2,WED=3,THU=4,FRI=5,SAT=6
};

int sq(int n)
{
	return n*n;
}

int main(void)
{
	int n=2;
	printf("Macro ����:%d�� ������ %d \n",n,SQ(n) ); //SQ�� ��ũ���̱� ������ ������ �ÿ� SQ(n)�� ((n)*(n))���� �ٲ� 
	printf("Macro ����:%d�� �������� %d \n",n,CUBE(n) ); //SQ�� ��ũ���̱� ������ ������ �ÿ� SQ(n)�� ((n)*(n))���� �ٲ� 
	printf("�Լ� ����:%d�� ������ %d \n",n,sq(n) ); //SQ�� ��ũ���̱� ������ ������ �ÿ� SQ(n)�� ((n)*(n))���� �ٲ� 
	printf("ENUM ���:%d,%d,%d \n",SUN,MON,THU ); 
	
	return 0;
}



#endif
