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
    printf("���� �� : ");
    for(i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr);
    printf("���� �� : ");
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
	int a = 100, b = 150, total;      // ���� ����� �ʱ�ȭ
	double avg;
	test_func(a,b,&total,&avg);
	printf("�� ������ ��: %d, %d\n",a,b);
	printf("�� ������ ��: %d\n",total);
	printf("�� ������ ���: %.1lf\n",avg);
	
	return 0;
}

int test_func(int a,int b,int *t, double *av)
{									//    ��°�� 
	printf("t�� �ּ�: %u\n",t);		//t�� �ּ�: 6487620
	printf("av�� �ּ�: %u\n",av); 	//av�� �ּ�: 6487608
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

 		//�������� (global variable) ���α׷��� ���� �ִ� ���ȿ� �׻� RAM�� �����ϰ� ����.
		//���������� �����ϰ� �����ϰ� ���� ���� �ٸ� ���α׷��� ������ ��ħ
		//��� �Լ������� access (read,write) ���� 

int main(void)
{
	int i;//main���� �������� : stack �޸𸮿� ������~
	char num1,num2;
	char input[100];
	while(1)
	{
		printf("�� ���� �Է��ϼ��� (a b) ����:exit ");
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
		printf("%d��° SP\t ",i);
		if (a[i]!=' ')
		{
		
		printf("\n%d��°�� SP�� �ƴ�\t ",i);
		break;
		}
	}
	printf("\n");
	return i;
} 


#endif




#if 0 //���ڿ� �Է¹ް� space üũ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int space_check(int x);
char input[100];
 		//�������� (global variable) ���α׷��� ���� �ִ� ���ȿ� �׻� RAM�� �����ϰ� ����.
		//���������� �����ϰ� �����ϰ� ���� ���� �ٸ� ���α׷��� ������ ��ħ
		//��� �Լ������� access (read,write) ���� 

int main(void)
{
	int i;//main���� �������� : stack �޸𸮿� ������~
	char num1,num2;

	while(1)
	{
		printf("�� ���� �Է��ϼ��� (a b) ����:exit ");
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
		printf("%d��° SP\t ",i);
		if (input[i]!=' ')
		{
		
		printf("\n%d��°�� SP�� �ƴ�\t ",i);
		break;
		}
	}
	return i;
} 


#endif
