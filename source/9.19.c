#if 1 //�Լ� ���� ���α׷� 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0; // ���� Array ��ġ �˷��ִ� index ����
int nullFinder(char *input)
{
	int i,cnt=0;//���ڳ� ���ڿ��� ���� Byte Size �����ϴ� ���� 
	for(i=count;i<20;i++)
	{
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\0')
		{
			count=i;printf("�Լ��� cnt��:%d \n",count); return count;
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
		if(strncmp(input_buffer,"999",3)==NULL)//input_buffer�� 4���ڰ� exit�� ��� NULL�� �ο� //4Byte ���� ���Ͽ� exit 
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













#if 0 //bit���� �� decimal, hexa, binary�� ��� P.138 ���� 
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
		printf("��Ʈ������ ������ �� ������ �Է�(exit:999)");
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



#if 0 //2����Ʈ ��� �� 16���� ����Ʈ ���� 
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
		printf("%d",us>>i&1); //0���� 1���� ���� ��Ʈ���� ��� 
		if (i%4==0)
		{
			printf(" ");
		}
	}
	printf("\n%d --> 0x%x\n",x,x);
	printf("x >> 1 --> %d, %08x\n",x>>1,x>>1);// ��������Ʈ 0x19 
	printf("x >> 2 --> %d, %08x\n",x>>2,x>>2);// ��������Ʈ 0x0c
	printf("x << 2 --> %d, %08x\n",x<<2,x<<2);// ��������Ʈ 0xcc
	return 0;
}


#endif

#if 0
//������ ���α׷�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i,j=0;
	
	for(i=1;i<10;i++)
	{
		printf("*%d��*\n\n",i);
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
//��ҹ��� ��ȯ  ���α׷� p.260 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>




int main(void)
{
	int i=0;
	char input[50];
	printf("���� �Է�: ");
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
//1���� 10������ �� ��� (���ȣ����) ���α׷� p.234 
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
//�������迭 ��ǥ ��� ���α׷� p.204 3�� 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
	int i,j;
	for(i=0;i<5;i++)//1����  
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
//�Ҽ�������α׷� p.205 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPrime(int num) //�Ҽ� ��� �Լ�(�ش� ���ڰ� �Ҽ��� ������ �ش� ���������� ����) 
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
	for(i=1;i<=i_inp;i++)//1����  
	{
		if(isPrime(i)!=0)
		{
			printf("%5d",isPrime(i));
		}
	}
	
	
	
	return 0;
}


#endif
