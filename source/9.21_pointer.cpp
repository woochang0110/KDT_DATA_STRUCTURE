
#if 1//2023�� �޷��� 3�����迭�� ���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void cal_maker(int cal[14][6][8],int *day, int *sp)
{
	int i,j,k,l;
	for(i=1;i<13;i++)
	{	
		l=1; // ��¥ ���� 
		
		for(j=0;j<6;j++)
		{
			if(j==0)
			{ 
				k = *(sp+i);
			
			}	//�״��� ù ����϶� �Է½��ۿ��� k�� ����
			else{ k=0;}		//�ƴϸ� �ٽ� �Ͽ���(k=0)���� �Է� 
			for(k;k<7;k++)
			{
				
				if(*(day+i)==l-1){break;}		//�ش� ���� �ϼ���ŭ ���Ҵٸ� 
				
				cal[i][j][k]=l;// �޺� �ϼ� ���� 
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
		printf("\n \t%d�� �޷�\n",i);
		printf("  ��  ��  ȭ  ��  ��  ��  ��  \n");
		for(j=0;j<6;j++)
		{
			n=1;
			if(j==0)	//�״��� ù ����϶� ��½��ۿ��� k ����
			{
				k = *(sp+i); 
				for(l=0;l<k;l++)	//ù����϶� ��ĭ��ŭ sp 
				{printf("    ");}
			}
			else
			{ 
				k=0;
			}		//�ƴϸ� �ٽ� �Ͽ���(k=0)���� ��� 
			for(k;k<7;k++)			
			{	
				if(*(day+i)==n+1)
				{
					break;
				} 
				printf("%4d",cal[i][j][k]);	
				n++;	//������Ҵ��� ī��Ʈ 
			}
			printf("\n");			//�������� new line 
		}
	}
	
}


int main(void)
{							//[�޺��� �ϼ� ����][1�޿� 5��][1���Ͽ� 7��]
	int calender[14][6][8];
	int day_of_month[14]={0,31,28,31,30,31,31,30,31,30,31,30,31};	//2023�� �޷��� 3�����迭�� ��� 
	int sp_of_month[14]={0,0,3,3,6,1,4,6,2,5,0,3,5};//�޺��� ����Ҷ� ������ ������� 1������ �Ͽ��Ϻ��ʹ� 0 �Է� 
	
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
	printf("ù ��° �ܾ� : ");    // �迭�� �Էµ� ���ڿ� ���
	scanf("%s", str1);		 
	printf("\n�� ��° �ܾ� : ");    // �迭�� �Էµ� ���ڿ� ���
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
	char *p=a;  //�̷��� ����ߵ�!!!! 
	  
	while(*p++ == ' ')	// *p++�� �ǹ̴�  
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
		//printf("%d��° SP\t ",i);
		if (a[i]!=' ')
		{
		//printf("\n%d��°�� SP�� �ƴ�\t ",i);
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
	char alpha[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};	//27Byte(NULL�� 1����Ʈ ����) 
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










#if 0 //���� 10-3
#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>

void test_func(int *arr);
int main(void)
{
	int ary[5] = { 10, 20, 30,40,50};


	printf("�迭�� �� : ");
	test_func(ary);

	return 0;
	
}


void test_func(int *arr)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d  ", *arr++);   // pa�� ����Ű�� �迭 ��� ���
	}
}

#endif
