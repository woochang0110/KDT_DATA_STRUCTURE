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
	int i;//숫자나 문자열이 들어가는 Byte Size 저장하는 변수 
	for(i=*count;i<strlen(input);i++)//현재 문자열 내에서 확인한 위치부터 체크 
	{	
	    printf("%d번째 loop: 함수내 cnt값:%d  end값:%d \n",i,*count,*end);
		if(input[i]!=' ') //현재 문자가 sp임 
		{
			
			if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\n')
			{
				printf("%d에서 기호만남\n",i );
				*count=i; return *count;
			}
			else if(input[i]>='0'&&input[i]<'9')
			{
				printf("%d에서 숫자만남\n",i );
				*end=i;
			}
		}
		else//현재 문자가 sp가 아님 
		{
			if(*count>*end)
			{
				printf("%d에서 sp발견\n",i );
				(*count)++;	
			}
			else
			{
				printf("%d에서 숫자끝남\n",i );
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
	int count=0;// 현재 Array 위치 알려주는 index 변수
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
		fgets(input_buffer,20,stdin); //입력 문자열 저장
		sp_calFinder(input_buffer,pc,pe); //첫번째 숫자 위치 파악 
		strncpy(aa,input_buffer+(*pc),*pe);
		sp_calFinder(input_buffer,pc,pe);
		cal=input_buffer[*pc];
		sp_calFinder(input_buffer,pc,pe);
		strncpy(ba,input_buffer+(*pc),(*pe));
		a = atoi(aa);
		b = atoi(ba);
		printf("a:%d,b:%d,cal:%c\n",a,b,cal);
		printf("\n");
		if(strncmp(input_buffer,"999",3)==NULL)  //input_buffer의 4글자가 exit일 경우 NULL값 부여 //4Byte 내용 비교하여 exit 
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


