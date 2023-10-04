#if 1// bubble sort 
#include <stdio.h>
#define BUF_SIZE 5


void swap(int *pa, int *pb);



void bubbleSort(int* arr){
    int i,j;
    for(i=0; i < LEN; i++){
        for(j=0; j<LEN-i-1; j++){
            if(arr[j] > arr[j+1]){    // swap
                swap(arr+j,arr+j+1);
            }
        }
    }
}
 
int main(){
    int arr[BUF_SIZE] = {7,5,1,4,3};
    int i;
    printf("정렬 전 : ");
    for(i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr);
    printf("정렬 후 : ");
    for(i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");    
    
    return 0; 
}
void swap(int *pa, int *pb)
{
	int temp;
	temp =*pa;
	*pa = *pb;
	*pb = temp;
}
#endif 



#if 0
#include <stdio.h>


int test_func(int a,int b,int *t, double *av);

int main(void)
{
	int a = 100, b = 150, total;      // 변수 선언과 초기화
	double avg;
	test_func(a,b,&total,&avg);
	printf("두 정수의 값: %d, %d\n",a,b);
	printf("두 정수의 합: %d\n",total);
	printf("두 정수의 평균: %.1lf\n",avg);
	
	return 0;
}

int test_func(int a,int b,int *t, double *av)
{									//    출력결과 
	printf("t의 주소: %u\n",t);		//t의 주소: 6487620
	printf("av의 주소: %u\n",av); 	//av의 주소: 6487608
//	*t=a+b;
	
	*(int*) 6487620 = a+b;
	*av=*t/2;
	return 0;
}

#endif 



#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int space_check(int x, char* a);

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
		i=space_check(i,input); // 
		num1=input[i];
		i++;
		i=space_check(i,input); // 
		num2=input[i];
		
		printf("num1=%c, num2=%c\n",num1,num2);
	}
	return 0;
}

int space_check(int x, char* a)
{
	int i;
	i=x;
	for(i; i <100; i++)
	{
		printf("%d번째 SP\t ",i);
		if (a[i]!=' ')
		{
		
		printf("\n%d번째는 SP가 아님\t ",i);
		break;
		}
	}
	printf("\n");
	return i;
} 


#endif




#if 0 //문자열 입력받고 space 체크 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int space_check(int x);
char input[100];
 		//전역변수 (global variable) 프로그램이 돌고 있는 동안에 항상 RAM을 차지하고 있음.
		//전역변수를 과다하게 점유하고 있을 때는 다른 프로그램에 영향을 미침
		//어느 함수에서나 access (read,write) 가능 

int main(void)
{
	int i;//main안의 지역변수 : stack 메모리에 잡힌다~
	char num1,num2;

	while(1)
	{
		printf("두 수를 입력하세요 (a b) 종료:exit ");
		fgets(input,100,stdin);
		if(strncmp(input,"exit",strlen("exit"))==0)
		{
			break;
		}
		i=0;
		i=space_check(i); // 
		num1=input[i];
		i++;
		i=space_check(i); // 
		num2=input[i];
		
		printf("num1=%c, num2=%c\n",num1,num2);
	}
	return 0;
}

int space_check(int x)
{
	int i;
	i=x;
	for(i; i <100; i++)
	{
		printf("%d번째 SP\t ",i);
		if (input[i]!=' ')
		{
		
		printf("\n%d번째는 SP가 아님\t ",i);
		break;
		}
	}
	return i;
} 


#endif
