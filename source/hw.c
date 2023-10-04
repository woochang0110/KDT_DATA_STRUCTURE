#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spacecheck(char *input, int *point);
void swap(double *pa,double *pb);
void line_up(double *maxp,double *midp,double *minp);


int main(void)
{
	char input[70];
	int point=0;
    char maxc[20],midc[20],minc[20];
    double max,mid,min;
    int temp;
    
    printf("실수값 3개 입력 ");
    fgets(input,70,stdin);
    while(strlen(input)-1!=point) 
    {
    	spacecheck(input,&point);
    	strncpy(maxc,input,point);
    	temp=point;//현재 위치 저장
		 
    	spacecheck(input,&point);
    	strncpy(midc,input+temp+1,point-temp-1);
    	temp=point;//현재 위치 저장 
		
		spacecheck(input,&point);
    	strncpy(minc,input+temp+1,point-temp-1);
	}
		printf("descending ordersorting 전 maxc: %s, midc: %s, minc : %s\n",maxc,midc,minc);	
		max=atof(maxc); 
		mid=atof(midc);
		min=atof(minc);
		printf("descending ordersorting 전 max: %.1lf, mid: %.1lf, min : %.1lf\n",max,mid,min);
		line_up(&max,&mid,&min);
		printf("descending ordersorting 전 max: %.1lf, mid: %.1lf, min : %.1lf\n",max,mid,min);
		
    
	return 0;
}

void spacecheck(char *input, int *point)// point는 현재 몇번 배열까지 봤는지  
{
	int i;
	printf("for문 드가자~ %d\n",*point);
	for(i=*point+1;i<strlen(input);i++)//point 부터 탐색시작 
	{
		if(*(input+i)==' '||*(input+i)=='\n')//sp나 \n이 나왔다면 
		{ 
			*point=i; //현재 위치 
			printf("탈출 전 point값은 %d\n",*point);
			break;//탈출 
		} 
	}
}

void swap(double *pa,double *pb)
{
	double temp;
	
	temp = *pa;
	*pa=*pb;
	*pb=temp;
}

void line_up(double *maxp,double *midp,double *minp)
{
	double arr[3];
	*arr=*maxp;
	*(arr+1)=*midp;
	*(arr+2)=*minp;
	int i,j;
    for(i=0; i < 3; i++){
        for(j=0; j<2-i; j++){
            if(arr[j] < arr[j+1]){    // swap
                swap(arr+j,arr+j+1);
            }
        }
    }
	*maxp=*arr;
	*midp=*(arr+1);
	*minp=*(arr+2);
}

