#include <stdio.h>  // printf scanf fgets
#include <string.h>  // strcpy strcat strncpy strncmp
#include <stdlib.h>   // atoi, itoa

FILE *fp;

typedef struct _node {
	char roomno[10];
    char name[20];
    char phone[40];
    int  price;
	char address[40];
	char enter_date[20];
    char exit_date[20];
} t_NODE;

t_NODE NODE[10];  // �ӽ÷� ���� ����ü�� ����
                  // �������� double linked list��  
int input_check(int *col, char *buff);
int reservation_management(void);

int num=0;
int main(void)
{
	char input_buff[200];
	char price[20];
	int i;  // input_buff�� �迭 index�� ����Ű�� ���� 
	int j,c;  // ���� ��ū�� ���� ��  
	 
	printf("Sequential file test program !!!!\n");
	
	fp = fopen("reservation.txt", "r");
	if (fp == NULL)   // �ش� ȭ���� ���� ���  
	{
		printf("can't open: reservation.txt\n"); 
		reservation_management();
		// ���� ���� ���α׷� �� ������.  
	}
	else   // ȭ���� ���� �ϸ� 
	{
printf("file open: reservation.txt  OK !!!!!\n"); 
		// d:\temp\reservation.txt�� ���� 1�ٿ� �ִ� 100byte�� �е�
		// \n�� ������ ���� �о  input_buff�� �ִ´�. 
		// ȭ���� �������� ���� �� (NULL) 
		// fgets�� return �޴°�: ���� ���� �� 
		while(fgets(input_buff,100,fp))  // ȭ�Ϸ�  
		{
printf("input_buff:%s\n", input_buff);
			i=0;
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].roomno,input_buff,j);  // &input_buff[0] 
		
			i++;   // �̸��� ��� �ִ� ù������ index
			c=i;
			j=input_check(&i, &input_buff[i]);
			strncpy( (char *)&NODE[num].name,input_buff+c,j); 		

			i++;   // phone�� ��� �ִ� ù������ index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].phone,input_buff+c,j); 

			i++;   // price�� ��� �ִ� ù������ index
			c=i; 
			j=input_check(&i,&input_buff[i]); 
			strncpy(price,input_buff+c,j); 
			NODE[num].price = atoi(price);			
			
			i++;   // address�� ��� �ִ� ù������ index 
			c=i;
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].address,input_buff+c,j);

			i++;   // enter_date�� ��� �ִ� ù������ index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].enter_date,input_buff+c,j);
			
			i++;   // exit_date�� ��� �ִ� ù������ index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].exit_date,input_buff+c,j);	// input_buff+i ==> &input_buff[i] 
			
			num++;  // ���� save�� NODE���� index�� �غ�		
		}
printf("num:%d\n", num);
		//--------------------------
		// !!!!! �̰����� NODE����ü�� ��� �ִ� ������
		// double linked list�� ���� �ִ� ���α׷��� ���� �Ѵ�
		//  
		reservation_management();
		

		printf("���α׷��� ���� �Ǿ����ϴ� !!!!!\n"); 
/*
------------------ < ���� ���� >----------------------
   1. �Է�(����)
   2. ����(���)
   3. ����(���೻������)
   4. ��ȸ(������ȸ)
   5. ��ü��ȸ(������ ������ȸ)

   9. ����

 Select:  1

*/
		// ---- test�� ���ؼ� NODE�� ��� �ִ�
		// 9 �� ���� ��ư�� ������ �Ʒ��� ���α׷��� ���� �ǵ��� �Ѵ�. 
		// ������ reversation.txt�� write�ϴ� ���α׷��� �ۼ� 
		// �� ���ڴ�.  
	}
	return 0;  // 0��resturn �ϴ� ������ no error 
}

int reservation_management(void)
{
	char input_buff[20];
	
	while(1)
	{
		menu_display();
		printf("menu select: "); 
		fgets(input_buff,20,stdin);   // stdin : keybord 
		switch(input_buff[0])   // 1 ~ 9
		{
			case '1':  // �Է�
				printf("�Է�(����)�� ���� �߽��ϴ�.\n");
				// input();	
				break; 
			case '2':  // ����(���)
				printf("����(���)�� ���� �߽��ϴ�.\n");
				// delete();
				break; 		
					
			case '3':  // ���� 
				printf("������ ���� �߽��ϴ�.\n");
				// modify();
				break; 	
					
			case '4':  // ��ȸ(������ȸ)\n
				printf("��ȸ(������ȸ)�� ���� �߽��ϴ�.\n");
				// one_person_display();
			    break; 
			
			case '5':  // ��ü��ȸ(������ ��ü��ȸ)
				printf("��ü��ȸ(������ ��ü��ȸ)�� ���� �߽��ϴ�.\n");
				// all_display();
				break; 
			case '9':  // ���� 
				exit_program();
				printf("���α׷��� ���� �Ǿ����ϴ�.  !!!!\n");
				return; 			
		} 
	}
}
void exit_program()
{
		int i;
		
		fclose(fp);  
		fp = fopen("reservation.txt", "w");
		// ������ ����ִ�reservation.txt�� �� ��������.   
		if (fp == NULL)   // �ش� ȭ���� ���� ���  
		{
			printf("can't open: reservation1.txt\n"); 
		}
		
		for (i=0; i < num; i++)  // node�� ����ִ� ���� ��ŭ loop 
		{
			// �����е��� linked list�� �ִ� node������ �Ʒ��� ���� ��� �ϵ��� �ؾ� �Ѵ�.  
			fprintf(fp, "%s:%s:%s:%d:%s:%s:%s:\n",NODE[i].roomno,NODE[i].name,
			NODE[i].phone,NODE[i].price,NODE[i].address,NODE[i].enter_date,NODE[i].exit_date); 
		} 
		fclose(fp);  //  fclose: ���� ���α׷��� ȭ���� ������� ���� �۾��̴�. 
		            // ��ġ ��ȭ ��ȭ�� �� ���� ��ȭ�����°Ͱ� ����. 
}
char menu[10][50] = {
"------------------ < ���� ���� >----------------------",
"   1. �Է�(����)",
"   2. ����(���)",
"   3. ����(���೻������)",
"   4. ��ȸ(������ȸ)",
"   5. ��ü��ȸ(������ ��ü��ȸ)",
" ",
"   9. ����"
};
void menu_display()
{
	int i;
	
	for (i=0; i < 8; i++)
		printf("%s\n", menu[i]);
}
//301:ȫ�浿:010-3355-1111:200000:��� ����:2023-11-20:1800:2023-11-24 18.00:
// ���� col: 4 
int input_check(int *col, char *buff)
{
	int i,j;
	
	char *p = buff;   // buff�� �ּҰ� p�� ��� ����. 
	i = *col;  // ��ū�� ������ġ �� ������ �����´�. 
	j=0;   // ��ū�� ���̸� count 
	while(*p++ != ':')   // 1) *p != ':'  2)p++
	{
		i++;   // �ش�Ǵ� �ʵ��� ��ġ byte�� count 
		j++;   // ��ū�� ���ڼ� 
	}
	*col = i;   // :�� ��� �ִ� index 
	           // �ش�Ǵ� �ʵ��� byte�� col�� ����
	return j;  // ��ū�� ���ڼ� 
} 


