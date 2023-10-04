#include <stdio.h>
#include <string.h>
#define NAME_LEN   20
#define NUM 10 
#define FUNC_NUM 5 
//����ü �迭 -> ����ü �����ͷ� ����
// 
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};	//enum �Ⱦ��� #define���� ������ �� Ÿ���� �ؾߵǴµ� ����ȭ �Ѱ���. �ʱⰪ ���ķ� 1�� ������. 
													//�׷��� deposit���� ���� �Է¾��°� ����
typedef struct 
{
	int acc_id;      // ���¹�ȣ
	int balance;    // ��    ��
	char cus_name[NAME_LEN];   // ���̸�
} t_account;


void show_menu(void);       // �޴����
void make_account(t_account *t,int *n);       // ���°����� ���� �Լ�
void deposit_money(t_account *t,int *n);       // ��    ��
void with_draw_money(t_account *t,int *n);      // ��    ��
void show_all_acc_info(t_account *t,int *n);     // �ܾ���ȸ

//�Լ������� �迭�� ������� ���൵ �ǰ� �Ƚ��൵ ��. ���빰�� ������ �˾Ƽ� �����Ϸ��� �� �����ŭ ¥�� 
void (*fp[FUNC_NUM])(t_account*,int *)=	
{
	NULL,	//1���� �����ϱ� 0���濡�� NULL �־���ߵ�. 
	make_account,
	deposit_money,
	with_draw_money,
	show_all_acc_info
};

/*
	char *temp;
	t_account *acc_arr;
	tmep=(char *)malloc(280);
	acc_arr=(t_account *)temp;
*/


// int main(argc, char *argv[]) �� ���� �� ���� ���� 
int main(void)
{
	char *temp;  //�߰� 
	t_account *acc_arr;   // Account ������ ���� �迭
	temp=(char*)malloc(280);
	acc_arr=(t_account *)temp;
	if(acc_arr==NULL)//�����޸� �Ҵ� ���� ���� �˻�
	{ 
		printf("�޸𸮰� �����մϴ�.\n"); 
		return 1;	
	} 
	int acc_num=0;        // ����� Account ��
	int choice;
	
	while(1)
	{
		show_menu();
		printf("����: ");  
		scanf("%d", &choice);
		printf("\n");
		
		if(choice==9) break;
		if(choice>0&&choice<5)
		{
			fp[choice](acc_arr,&acc_num);
		}
		else
		{
			printf("�� �ٽ� �Է¹ٶ�\n");
		} 
	}
	free(acc_arr);
	return 0;
}

void show_menu(void)
{
	char *menu[]=
	{
		"-----Menu------\n",
		"1. ���°���\n",
		"2. ��    ��\n",
		"3. ��    ��\n",
		"4. �������� ��ü ���\n",
		"9. ��    ��\n"
		
	};
	int i;
	for(i=0;i<6;i++)
	{
		printf("%s",*(menu+i));
	}
}

void make_account(t_account *t,int *n) 
{
	int id;
	char name[NAME_LEN];
	int balance;
	t_account *pt = t+*n;	//�̰� ���ϰ�(pt+*n)->acc_id=id; �̷������� �ص� ��. 
	
	printf("[���°���]\n");
	printf("����ID: ");	
	scanf("%d", &id);
	printf("��  ��: ");	
	scanf("%s", name);
	printf("�Աݾ�: ");	
	scanf("%d", &balance);
	printf("\n");
	
	pt->acc_id=id;
	pt->balance=balance;
	strcpy(pt->cus_name,name);
	*n+=1;
}

void deposit_money(t_account *t,int *n)
{
	int money;
	int id, i;
	t_account *pt=t;
	printf("[��    ��]\n");
	printf("����ID: ");
	scanf("%d", &id);
	printf("�Աݾ�: ");
	scanf("%d", &money);
	
	for (i=0; i<*n; i++)
	{
		pt+=i;
		if(pt->acc_id==id)
		{
			pt->balance += money;
			printf("�ԱݿϷ�\n\n");
			return;//�� �Լ��� ���������°��� ���ι����� �Լ� �����Ұǵ� ���� �������� �Ѿ�� �����ϸ� ��. 
		}
	}
	printf("��ȿ���� ���� ID �Դϴ�.\n\n");
}

void with_draw_money(t_account *t,int *n)
{
	int money;
	int id, i;
	t_account *pt=t;
	
	printf("[��    ��]\n");
	printf("����ID: ");
	scanf("%d", &id);
	printf("��ݾ�: ");
	scanf("%d", &money);
	
	for(i=0; i<*n; i++)
	{
		pt+=i;
		if(pt->acc_id==id)
		{
			if(pt->balance < money)
			{
				printf("�ܾ׺���\n\n");
				return;
			}

			pt->balance -= money;
			printf("��ݿϷ�\n\n");
			return;
		}
	}
	printf("��ȿ���� ���� ID �Դϴ�.\n\n");
}

void show_all_acc_info(t_account *t,int *n)	
{
	int i;
	t_account *pt=t;

	for(i=0; i<*n; i++)
	{
		pt+=i;
		printf("����ID: %d\n", pt->acc_id);
		printf("��  ��: %s\n", pt->cus_name);
		printf("��  ��: %d\n\n", pt->balance);
	}
}
