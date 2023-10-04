#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int input[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int i;
	for(i=0;i<12;i++){
		printf("%d번째:%d\n",i,*(input+i));
		
	}
	
	
	
	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spacecheck(char *input, int *point)// point는 현재 몇번 배열까지 봤는지,cnt는  
{
	int i;
	for(i=*point+1;i<strlen(input);i++)//point 부터 탐색시작 
	{
		if(*(input+i)==' ')//sp가 나왔다면 
		{ 
			*point=i; //현재 위치 
			break;//탈출 
		}
	}
}

int main(void)
{
	char input[70];
	int point=0;
    char maxc[20],midc[20],minc[20];
    double max,mid,min;
    int temp;
    
    printf("실수값 3개 입력 (종료:exit):");
    fgets(input,70,stdin);
     if (strncmp(input,"exit",strlen("exit")) == 0) // exit
    {
	    return 0;
	}
    else
    {
    	while(strlen(input)-1==point) 
    	{
    		spacecheck(input,&point);
    		strncpy(maxc,input,point);
    		temp=point;//현재 위치 저장 
    		spacecheck(input,&point);
    		strncpy(midc,input,point-temp-1);
    		temp=point;//현재 위치 저장 
			spacecheck(input,&point);
    		strncpy(minc,input,point-temp-1);
		}
		max=atod(maxc); 
		mid=atod(midc);
		min=atod(minc);
		printf("sorting 전 max: %.1lf, mid: %.1lf, min : %.1lf\n",max,mid,min);
		
	}
    

    
    
    
    
    
    
    
    
    
    
    
    
    
	return 0;
}


#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sp_calFinder(char *input,int* c,int* e)
{
	int i;//숫자나 문자열이 들어가는 Byte Size 저장하는 변수 
	int count =*c;
	int end =*e;
	printf("함수count값%d,함수end값 %d\n",count,end);
	for(i=count;i<strlen(input);i++)//현재 문자열 내에서 확인한 위치부터 체크 
	{	
	    printf("%d번째 loop: 함수내 cnt값:%d  end값:%d \n",i,count,end);
		if(input[i]!=' ') //현재 문자가 sp가 아님 
		{
			
			if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\n')
			{
				printf("%d에서 기호만남\n",i );
				count=i; *c=count; break;
			}
			else if(input[i]>='0'&&input[i]<'9')
			{
				printf("%d에서 숫자만남\n",i );
				end=i; *e=end; continue;
			}
		}
		else//현재 문자가 sp임
		{
			if(count>end)
			{
				printf("%d에서 sp발견\n",i );
				count++;	
			}
			else
			{
				printf("%d에서 숫자끝남\n",i );
				count;
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
	
	while(1)
	{	
		count=0;
		end=0;
		printf("1+1=,2-2=,1*1=,1/1= (exit:999): ");
		fgets(input_buffer,20,stdin); //입력 문자열 저장
		sp_calFinder(input_buffer,&count,&end); //첫번째 숫자 위치 파악 
		strncpy(aa,input_buffer+count,end);
		
		
	}
	return 0;
}
#endif
