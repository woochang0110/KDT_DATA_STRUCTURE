#if 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int input[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
	int i;
	for(i=0;i<12;i++){
		printf("%d��°:%d\n",i,*(input+i));
		
	}
	
	
	
	return 0;
}

#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int spacecheck(char *input, int *point)// point�� ���� ��� �迭���� �ô���,cnt��  
{
	int i;
	for(i=*point+1;i<strlen(input);i++)//point ���� Ž������ 
	{
		if(*(input+i)==' ')//sp�� ���Դٸ� 
		{ 
			*point=i; //���� ��ġ 
			break;//Ż�� 
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
    
    printf("�Ǽ��� 3�� �Է� (����:exit):");
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
    		temp=point;//���� ��ġ ���� 
    		spacecheck(input,&point);
    		strncpy(midc,input,point-temp-1);
    		temp=point;//���� ��ġ ���� 
			spacecheck(input,&point);
    		strncpy(minc,input,point-temp-1);
		}
		max=atod(maxc); 
		mid=atod(midc);
		min=atod(minc);
		printf("sorting �� max: %.1lf, mid: %.1lf, min : %.1lf\n",max,mid,min);
		
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
	int i;//���ڳ� ���ڿ��� ���� Byte Size �����ϴ� ���� 
	int count =*c;
	int end =*e;
	printf("�Լ�count��%d,�Լ�end�� %d\n",count,end);
	for(i=count;i<strlen(input);i++)//���� ���ڿ� ������ Ȯ���� ��ġ���� üũ 
	{	
	    printf("%d��° loop: �Լ��� cnt��:%d  end��:%d \n",i,count,end);
		if(input[i]!=' ') //���� ���ڰ� sp�� �ƴ� 
		{
			
			if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='\n')
			{
				printf("%d���� ��ȣ����\n",i );
				count=i; *c=count; break;
			}
			else if(input[i]>='0'&&input[i]<'9')
			{
				printf("%d���� ���ڸ���\n",i );
				end=i; *e=end; continue;
			}
		}
		else//���� ���ڰ� sp��
		{
			if(count>end)
			{
				printf("%d���� sp�߰�\n",i );
				count++;	
			}
			else
			{
				printf("%d���� ���ڳ���\n",i );
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
	int count=0;// ���� Array ��ġ �˷��ִ� index ����
	int end=0; 
	
	while(1)
	{	
		count=0;
		end=0;
		printf("1+1=,2-2=,1*1=,1/1= (exit:999): ");
		fgets(input_buffer,20,stdin); //�Է� ���ڿ� ����
		sp_calFinder(input_buffer,&count,&end); //ù��° ���� ��ġ �ľ� 
		strncpy(aa,input_buffer+count,end);
		
		
	}
	return 0;
}
#endif
