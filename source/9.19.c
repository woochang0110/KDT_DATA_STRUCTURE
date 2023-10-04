#if 1 //함수 계산기 프로그램 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0; // 현재 Array 위치 알려주는 index 변수
int nullFinder(char *input)
{
	int i,cnt=0;//숫자나 문자열이 들어가는 Byte Size 저장하는 변수 
	for(i=count;i<20;i++)
	{
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\0')
		{
			count=i;printf("함수내 cnt값:%d \n",count); return count;
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
	
	while(1)
	{	
		count=0;
		printf("1+1=,2-2=,1*1=,1/1= (exit:999): ");
		fgets(input_buffer,20,stdin); 
		nullFinder(input_buffer);
		strncpy(aa,input_buffer,count+1);
		cal=input_buffer[count];
		strcpy(ba,input_buffer+count+1);
		a = atoi(aa);
		b = atoi(ba);
		printf("a:%d,b:%d,cal:%c\n",a,b,cal);//
		printf("\n");
		if(strncmp(input_buffer,"999",3)==NULL)//input_buffer의 4글자가 exit일 경우 NULL값 부여 //4Byte 내용 비교하여 exit 
		{
			break;
		}
		else
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
			printf("\n");
		}
	}
	
	
	return 0;
}



#endif













#if 0 //bit연산 후 decimal, hexa, binary로 출력 P.138 응용 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	void printBinary(int n)
	{
		int i;
		printf(" Binary: ");
		for(i=8*sizeof(int)-1;i>=0;i--)
		{
			printf("%d",n>>i&1);
			if(i%4==0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	int a, b;
	char input[100];
	unsigned char ca[2],cb[2];
	while(1)
	{
		printf("비트연산이 가능한 두 정수를 입력(exit:999)");
		fgets(input,10,stdin);
		if(strncmp(input,"999",3)==NULL)
		{
			break;
		}
		else
		{
			strncpy(ca,input,2);
			strncpy(cb,input+3,2);
			
			a=atoi(ca);
			b=atoi(cb);
			
			printf("a & b : %d, 0x%08x  ",a&b,a&b);
			printBinary(a&b);
			
			printf("a ^ b : %d, 0x%08x  ",a^b,a^b);
			printBinary(a^b);
			
			printf("a | b : %d, 0x%08x  ",a|b,a|b);
			printBinary(a|b);
			
			printf("~a : %d, 0x%08x  ",~a,~a);
			printBinary(~a);
			
			printf("a << 1 : %d, 0x%08x  ",a<<1,a<<1);
			printBinary(a<<1);			
			
			printf("a >> 1 : %d, 0x%08x  ",a>>1,a>>1);
			printBinary(a>>1);
		}
	}
	
	
	
	
	
	return 0;
}


#endif



#if 0 //2진비트 출력 및 16진수 시프트 연산 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	unsigned char x = 0x33; //0011 0011  	//0110 0110 0x66
	unsigned short us =0xffff; //decimal:65535
	int i;
	
	for(i=8*sizeof(unsigned short)-1; i>=0;i--)
	{
		printf("%d",us>>i&1); //0인지 1인지 상위 비트부터 출력 
		if (i%4==0)
		{
			printf(" ");
		}
	}
	printf("\n%d --> 0x%x\n",x,x);
	printf("x >> 1 --> %d, %08x\n",x>>1,x>>1);// 우측시프트 0x19 
	printf("x >> 2 --> %d, %08x\n",x>>2,x>>2);// 우측시프트 0x0c
	printf("x << 2 --> %d, %08x\n",x<<2,x<<2);// 좌측시프트 0xcc
	return 0;
}


#endif

#if 0
//구구단 프로그램
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i,j=0;
	
	for(i=1;i<10;i++)
	{
		printf("*%d단*\n\n",i);
		for(j=1;j<10;j++)
		{
			printf(" %d*%d=%d ",i,j,i*j);	
		}	
		printf("\n\n");
	} 
	
	
	return 0;
}


#endif


#if 0
//대소문자 변환  프로그램 p.260 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>




int main(void)
{
	int i=0;
	char input[50];
	printf("문장 입력: ");
	fgets(input,100,stdin);
	for(i=0;i<sizeof(input);i++)
	{
		input[i]=tolower(input[i]);
	}
	printf("\n%s\n",input);
	
	
	return 0;
}


#endif










#if 0
//1부터 10까지의 합 계산 (재귀호출사용) 프로그램 p.234 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int res=0;

int rec_func(int n){
	if(n==0)
	{
		return res;
	}
	res+=n;
	n--;
	return rec_func(n);
} 


int main(void)
{
	int k=10;
	printf("%d\n",rec_func(k));
	
	
	
	
	return 0;
}


#endif

#if 0
//이차원배열 별표 출력 프로그램 p.204 3번 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i,j;
	for(i=0;i<5;i++)//1부터  
	{
		for(j=0;j<5;j++)
		{
			if(i==j||i+j==4)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		} 
		printf("\n");
	}
	
	
	
	return 0;
}


#endif





#if 0
//소수출력프로그램 p.205 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPrime(int num) //소수 출력 함수(해당 숫자가 소수가 맞으면 해당 정수값으로 리턴) 
{
	int i;
	
	if(num==1)
	{
		return 0;
	}
	else if(num%2==0&&num!=2)
	{
		return 0;
	}	
	else if(num==2)
	{
		return num;
	}
	for(i=3;i<num;i+=2)
	{
		if(num%i==0)
		{
			return 0;
		}
		else
		{
			return num;
		}
	}
	
}
int main(void)
{
	char input[10];
	char inp[4];
	int i_inp;
	int i;
	printf("isPrime: ");
	fgets(input,10,stdin);
	printf("\n");	
	
	strncpy(inp,input,3);
	i_inp=atoi(inp);
	for(i=1;i<=i_inp;i++)//1부터  
	{
		if(isPrime(i)!=0)
		{
			printf("%5d",isPrime(i));
		}
	}
	
	
	
	return 0;
}


#endif
