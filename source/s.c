#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

typedef struct{
   int num1;
   int num2;
   char cal;
   int res;
}calc; 
 
 

 
int IsEmpty(int top){//top이 -1이면 비어있는게 맞으니 1리턴하고 아님 0리턴 
    if(top<0)
        return true;
    else
        return false;
}
int IsFull(int top){						//top이 배열 최대치만큼 차있다면 1 리턴 아니면 0리턴 
    if(top>=MAX_STACK_SIZE-1)
        return true;
    else
        return false;
}
 
void push(calc *stack, calc *input,int *top){
    int t=*top;
   if(IsFull(t)==true)
        printf("스택이 가득 찼습니다.\n");
    else
    {   
      t++;
       stack[t].num1=input->num1;
        stack[t].cal=input->cal;
        stack[t].num2=input->num2;
        stack[t].res=input->res;
        *top=t;
   }

}
 
void pop(calc *stack,int *top){
   int t=*top;
   printf("입력 top값은: %d",*top);
    if(IsEmpty(t)==true)
        printf("스택이 비었습니다.\n");
    else 
    {
	
       	printf("최근연산: %d %c %d = %d\n",(stack+t)->num1,(stack+t)->cal,
	  	(stack+t)->num2,(stack+t)->res);//프린트 후 
       	//초기화하고 
      	(stack+t)->num1=0;
      	(stack+t)->cal=0;
      	(stack+t)->num2=0;
      	(stack+t)->res=0;
       	//top 한칸 아래로 
      	t-=1;
      	*top=t;
      	if(t==0){
          printf("현재 top값은: %d\n",*top);
          printf("다음값이 마지막 값입니다.\n");
      	}
    	else
        printf("현재 top값은: %d\n",*top);
    }
}	

void calculation(calc *temp)									//calc 구조체 포인터를 매개변수로 받아서 연산 
{

   printf("num1 입력: ");
   scanf("%d",&(temp->num1));
   printf("연산기호 입력: ");
   scanf(" %c",&(temp->cal));
   printf("num2 입력: ");
   scanf("%d",&(temp->num2));

   switch(temp->cal)
   {
      case '+': add(temp);break;			//temp->res=temp->num1+temp->num2;
      case '-': sub(temp);break;
      case '*': mul(temp);break;
      case '/': div(temp);break;
      default : break;
   }
   printf("계산결과=%d!\n",temp->res);
    
   return;
}

int get_input(void)
{
   int sel;
   char inp[3][30]={
      "\n1: 계산\n",
      "2: 최근 계산기록 조회\n",
      "9: exit\n"
   };
   printf("%s%s%s",inp,inp+1,inp+2);
   scanf("%d",&sel);
   return sel;
}


void add(calc *input)
{
   input->res = input->num1 + input->num2;
}

void sub(calc *input)
{
   input->res=input->num1-input->num2;
}

void mul(calc *input)
{
   input->res=input->num1*input->num2;
}
void div(calc *input)
{
   input->res=input->num1/input->num2;
}


int main(void){
    
    int top=-1;
    int sel=0;
    calc temp={0};
    calc stack[MAX_STACK_SIZE];

    while(1)
   {
      sel=get_input();   							//메인메뉴 화면 표시하고 sel 값 받기
      if(sel==9){
         printf("종료합니다\n");
         return 0;
      } 
      switch(sel)
      {
         case 1: {
            calculation(&temp); 
            push(stack,&temp,&top);
            break;
         }
         case 2: {
            pop(stack,&top);
            break;
         }   
         default:{
            printf("잘못된 값\n");
            break;
         }
       } 
   }  
    return 0;
}

