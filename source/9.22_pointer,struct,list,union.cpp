#if 1	//sdd에 저장되어있는 텍스트 파일을 받아서 프로그램 상에서 텍스트 파일로 열어주고 내용 복사해서 옮겨주기 

#include <stdio.h>
fseek()
int main(void)
{
	FILE* inp;                   // 파일 포인터 선언
	FILE* outp;
	char input[100];                     // 입력한 문자를 저장할 변수

	inp = fopen("input.txt", "r");   // 읽기 전용으로 파일 개방
	if (inp == NULL)             // 파일이 개방되었는지 확인
	{
		printf("파일이 열리지 않았습니다.:input.txt\n");
		return 1;	//에러가 있다!  에러코드를 1로 정의한거임, 
					//이건 사용자가 정의하기 나름 
	}
	
	outp = fopen("output.txt", "w");//파일이 없으니까 파일을 만들어줌 
	
	while (fgets(input,100,inp))
	{
		printf("%s",input);
		fputs(input,outp);	//char배열을  
		
	}
	fclose(inp);                 // 파일 닫음
	fclose(outp);
	return 0;
}

#endif




#if 0 //함수 포인터 배열 
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


void (*fp[])(int,int)=//포인터 배열과 함수 포인터를 접목시킨거 ㄷㄷ; 
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
	
	ip = (char *)malloc(100);		       // 메모리 동적 할당 후 포인터 연결
	sprintf(ip,"%s","함수 포인터 배열 계산기");
	printf("%s: 시작",ip);

	
	while(1)
	{	
		printf("\nselect(0:+, 1:-, 2:x, 3:/ 9:exit):");
		scanf("%d",&sel);
		if(sel==9) return 0;
		printf("두수 입력");
		scanf("%d %d",&a,&b);
		fp[sel](a,b);
	}
	
	printf("%s: 종료\n",ip);
	free(ip);                             // 동적 할당 영역 반환
}






#endif




































#if 0	//p.441 도전실전예제 
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














#if 0 //함수 포인터 배열 
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


void (*fp[])(int,int)=//포인터 배열과 함수 포인터를 접목시킨거 ㄷㄷ; 
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
		printf("두수 입력");
		scanf("%d %d",&a,&b);
		fp[sel](a,b);
	}
	
	
}






#endif



