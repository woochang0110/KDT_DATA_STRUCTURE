
#if 1//2023년 달력을 3차원배열로 출력
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void cal_maker(int cal[14][6][8],int *day, int *sp)
{
	int i,j,k,l;
	for(i=1;i<13;i++)
	{	
		l=1; // 날짜 저장 
		
		for(j=0;j<6;j++)
		{
			if(j==0)
			{ 
				k = *(sp+i);
			
			}	//그달의 첫 출력일때 입력시작요일 k에 지정
			else{ k=0;}		//아니면 다시 일요일(k=0)부터 입력 
			for(k;k<7;k++)
			{
				
				if(*(day+i)==l-1){break;}		//해당 월의 일수만큼 돌았다면 
				
				cal[i][j][k]=l;// 달별 일수 저장 
				l++;
			}
		}
		
	}
	
}


void cal_printer(int cal[14][6][8],int *day, int *sp)
{
	int i,j,k,l,n;
	
	for(i=1;i<13;i++)
	{
		printf("\n \t%d월 달력\n",i);
		printf("  일  월  화  수  목  금  토  \n");
		for(j=0;j<6;j++)
		{
			n=1;
			if(j==0)	//그달의 첫 출력일때 출력시작요일 k 지정
			{
				k = *(sp+i); 
				for(l=0;l<k;l++)	//첫출력일때 빈칸만큼 sp 
				{printf("    ");}
			}
			else
			{ 
				k=0;
			}		//아니면 다시 일요일(k=0)부터 출력 
			for(k;k<7;k++)			
			{	
				if(*(day+i)==n+1)
				{
					break;
				} 
				printf("%4d",cal[i][j][k]);	
				n++;	//몇번돌았는지 카운트 
			}
			printf("\n");			//주차마다 new line 
		}
	}
	
}


int main(void)
{							//[달별로 일수 저장][1달에 5주][1주일에 7일]
	int calender[14][6][8];
	int day_of_month[14]={0,31,28,31,30,31,31,30,31,30,31,30,31};	//2023년 달력을 3차원배열로 출력 
	int sp_of_month[14]={0,0,3,3,6,1,4,6,2,5,0,3,5};//달별로 출력할때 어디부터 출력할지 1월달은 일요일부터니 0 입력 
	
	cal_maker(calender,day_of_month,sp_of_month);
	cal_printer(calender,day_of_month,sp_of_month);
	
	return 0;
}





#endif








#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge_func(char *outbuff,char *str1,char *str2);
int main(void)
{
	char outbuff[80];	
	char str1[80];
	char str2[80];
	printf("첫 번째 단어 : ");    // 배열에 입력된 문자열 출력
	scanf("%s", str1);		 
	printf("\n두 번째 단어 : ");    // 배열에 입력된 문자열 출력
	scanf("%s", str2);
	merge_func(outbuff,str1,str2);
	printf("\noutput: %s",outbuff);
	return 0;
}
void merge_func(char *outbuff,char *str1,char *str2)
{
	char *op=outbuff;
	char *sp1=str1;
	char *sp2=str2;
	printf("sp1:%s   sp2:%s\n",sp1,sp2);
	/*
	strncpy(op,sp1,strlen(sp1));
	strncpy(op+strlen(sp1),sp2,strlen(sp2));
	*/
	strcat(outbuff,str1);
	*(outbuff+strlen(str1))='\0';
	strcat(outbuff,str2);
	*(outbuff+strlen(str1)+strlen(str2))='\0';
	printf("op:%s\n",op);
}


#endif







#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void space_check(int *x, char* a);

 		//전역변수 (global variable) 프로그램이 돌고 있는 동안에 항상 RAM을 차지하고 있음.
		//전역변수를 과다하게 점유하고 있을 때는 다른 프로그램에 영향을 미침
		//어느 함수에서나 access (read,write) 가능 

int main(void)
{
	int i;//main안의 지역변수 : stack 메모리에 잡힌다~
	char num1,num2;
	char input[100];
	while(1)
	{
		printf("두 수를 입력하세요 (a b) 종료:exit ");
		fgets(input,100,stdin);
		if(strncmp(input,"exit",strlen("exit"))==0)
		{
			break;
		}
		i=0;
		space_check(&i,input); // 
		num1=*(input+i);
		i++;
		space_check(&i,input); // 
		num2=*(input+i);
		
		printf("num1=%c, num2=%c\n",num1,num2);
	}
	return 0;
}

void space_check(int *x, char* a)
{
	int i=*x;
	char *p=a;  //이렇게 해줘야됨!!!! 
	  
	while(*p++ == ' ')	// *p++의 의미는  
	{
		i++;
	}
	*x=i;

} 


#endif






#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void space_check(int *x, char* a);

 		//전역변수 (global variable) 프로그램이 돌고 있는 동안에 항상 RAM을 차지하고 있음.
		//전역변수를 과다하게 점유하고 있을 때는 다른 프로그램에 영향을 미침
		//어느 함수에서나 access (read,write) 가능 

int main(void)
{
	int i;//main안의 지역변수 : stack 메모리에 잡힌다~
	char num1,num2;
	char input[100];
	while(1)
	{
		printf("두 수를 입력하세요 (a b) 종료:exit ");
		fgets(input,100,stdin);
		if(strncmp(input,"exit",strlen("exit"))==0)
		{
			break;
		}
		i=0;
		space_check(&i,input); // 
		num1=*(input+i);
		i++;
		space_check(&i,input); // 
		num2=*(input+i);
		
		printf("num1=%c, num2=%c\n",num1,num2);
	}
	return 0;
}

void space_check(int *x, char* a)
{
	int i;
	i=*x;
	for(i; i <100; i++)
	{
		//printf("%d번째 SP\t ",i);
		if (a[i]!=' ')
		{
		//printf("\n%d번째는 SP가 아님\t ",i);
		break;
		}
	}
	printf("\n");
	*x=i;
} 


#endif


#if 0 //Alphabet shift
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>

void shift_alpha(char *pa);
int main(void)
{
	char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};	//27Byte(NULL값 1바이트 포함) 
	char *pa=alpha;
	shift_alpha(alpha);
	return 0;
	
}


void shift_alpha(char *pa)
{
	int i,j;
	char temp;
	char *p;
	for(i = 0; i < 27; i++)
	{
		p=pa;
		temp=*pa;
		for (j = 0; j < 25; j++)
		{
		printf("%c", *p);
		*p=*(p+1);
		p++;
		}
		*p=temp;
		
		printf("\n");
	}
	
	
}

#endif










#if 0 //예제 10-3
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>

void test_func(int *arr);
int main(void)
{
	int ary[5] = { 10, 20, 30,40,50};


	printf("배열의 값 : ");
	test_func(ary);

	return 0;
	
}


void test_func(int *arr)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d  ", *arr++);   // pa가 가리키는 배열 요소 출력
	}
}

#endif
