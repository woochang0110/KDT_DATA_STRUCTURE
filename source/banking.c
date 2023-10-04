#include <stdio.h>
#include <string.h>
#define NAME_LEN   20
#define NUM 10 
#define FUNC_NUM 5 
//구조체 배열 -> 구조체 포인터로 변경
// 
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};	//enum 안쓰면 #define으로 일일이 다 타이핑 해야되는데 간소화 한거임. 초기값 이후로 1씩 증가함. 
													//그래서 deposit부터 숫자 입력없는거 ㅇㅇ
typedef struct 
{
	int acc_id;      // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];   // 고객이름
} t_account;


void show_menu(void);       // 메뉴출력
void make_account(t_account *t,int *n);       // 계좌개설을 위한 함수
void deposit_money(t_account *t,int *n);       // 입    금
void with_draw_money(t_account *t,int *n);      // 출    금
void show_all_acc_info(t_account *t,int *n);     // 잔액조회

//함수포인터 배열의 사이즈는 써줘도 되고 안써줘도 됨. 내용물만 있으면 알아서 컴파일러가 그 사이즈만큼 짜줌 
void (*fp[FUNC_NUM])(t_account*,int *)=	
{
	NULL,	//1부터 쓸꺼니까 0번방에는 NULL 넣어줘야됨. 
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


// int main(argc, char *argv[]) 이 형식 곧 배울거 ㅇㅇ 
int main(void)
{
	char *temp;  //추가 
	t_account *acc_arr;   // Account 저장을 위한 배열
	temp=(char*)malloc(280);
	acc_arr=(t_account *)temp;
	if(acc_arr==NULL)//동적메모리 할당 성공 여부 검사
	{ 
		printf("메모리가 부족합니다.\n"); 
		return 1;	
	} 
	int acc_num=0;        // 저장된 Account 수
	int choice;
	
	while(1)
	{
		show_menu();
		printf("선택: ");  
		scanf("%d", &choice);
		printf("\n");
		
		if(choice==9) break;
		if(choice>0&&choice<5)
		{
			fp[choice](acc_arr,&acc_num);
		}
		else
		{
			printf("값 다시 입력바람\n");
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
		"1. 계좌개설\n",
		"2. 입    금\n",
		"3. 출    금\n",
		"4. 계좌정보 전체 출력\n",
		"9. 종    료\n"
		
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
	t_account *pt = t+*n;	//이거 안하고(pt+*n)->acc_id=id; 이런식으로 해도 됨. 
	
	printf("[계좌개설]\n");
	printf("계좌ID: ");	
	scanf("%d", &id);
	printf("이  름: ");	
	scanf("%s", name);
	printf("입금액: ");	
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
	printf("[입    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);
	
	for (i=0; i<*n; i++)
	{
		pt+=i;
		if(pt->acc_id==id)
		{
			pt->balance += money;
			printf("입금완료\n\n");
			return;//이 함수를 빠져나가는거임 메인문에서 함수 실행할건데 다음 라인으로 넘어간다 생각하면 됨. 
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account *t,int *n)
{
	int money;
	int id, i;
	t_account *pt=t;
	
	printf("[출    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);
	
	for(i=0; i<*n; i++)
	{
		pt+=i;
		if(pt->acc_id==id)
		{
			if(pt->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			pt->balance -= money;
			printf("출금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account *t,int *n)	
{
	int i;
	t_account *pt=t;

	for(i=0; i<*n; i++)
	{
		pt+=i;
		printf("계좌ID: %d\n", pt->acc_id);
		printf("이  름: %s\n", pt->cus_name);
		printf("잔  액: %d\n\n", pt->balance);
	}
}
