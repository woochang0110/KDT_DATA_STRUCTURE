#include <stdio.h>
#include <stdbool.h>
#define MAX_STACK_SIZE 100

typedef struct{
   int num1;
   int num2;
   char cal;
   int res;
}calc; 
 
 

 
int IsEmpty(int top){//top�� -1�̸� ����ִ°� ������ 1�����ϰ� �ƴ� 0���� 
    if(top<0)
        return true;
    else
        return false;
}
int IsFull(int top){						//top�� �迭 �ִ�ġ��ŭ ���ִٸ� 1 ���� �ƴϸ� 0���� 
    if(top>=MAX_STACK_SIZE-1)
        return true;
    else
        return false;
}
 
void push(calc *stack, calc *input,int *top){
    int t=*top;
   if(IsFull(t)==true)
        printf("������ ���� á���ϴ�.\n");
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
   printf("�Է� top����: %d",*top);
    if(IsEmpty(t)==true)
        printf("������ ������ϴ�.\n");
    else 
    {
	
       	printf("�ֱٿ���: %d %c %d = %d\n",(stack+t)->num1,(stack+t)->cal,
	  	(stack+t)->num2,(stack+t)->res);//����Ʈ �� 
       	//�ʱ�ȭ�ϰ� 
      	(stack+t)->num1=0;
      	(stack+t)->cal=0;
      	(stack+t)->num2=0;
      	(stack+t)->res=0;
       	//top ��ĭ �Ʒ��� 
      	t-=1;
      	*top=t;
      	if(t==0){
          printf("���� top����: %d\n",*top);
          printf("�������� ������ ���Դϴ�.\n");
      	}
    	else
        printf("���� top����: %d\n",*top);
    }
}	

void calculation(calc *temp)									//calc ����ü �����͸� �Ű������� �޾Ƽ� ���� 
{

   printf("num1 �Է�: ");
   scanf("%d",&(temp->num1));
   printf("�����ȣ �Է�: ");
   scanf(" %c",&(temp->cal));
   printf("num2 �Է�: ");
   scanf("%d",&(temp->num2));

   switch(temp->cal)
   {
      case '+': add(temp);break;			//temp->res=temp->num1+temp->num2;
      case '-': sub(temp);break;
      case '*': mul(temp);break;
      case '/': div(temp);break;
      default : break;
   }
   printf("�����=%d!\n",temp->res);
    
   return;
}

int get_input(void)
{
   int sel;
   char inp[3][30]={
      "\n1: ���\n",
      "2: �ֱ� ����� ��ȸ\n",
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
      sel=get_input();   							//���θ޴� ȭ�� ǥ���ϰ� sel �� �ޱ�
      if(sel==9){
         printf("�����մϴ�\n");
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
            printf("�߸��� ��\n");
            break;
         }
       } 
   }  
    return 0;
}

