

#if 1	//비트 시프트 연산 사용하지 않고 union사용하기 


int main(void)
{
	union
	{						//union을 선언하면 
		unsigned char BYTE;	//예를 들어 이 주소가 1000번지라면  
		//intel 계열은 little endian, motorola는 big endian 기반임. 
		/*
		저장할 때 상위 바이트MSB. 즉, 큰 쪽을 먼저 저장하는 것을 빅 엔디안(Big Endian), 
		저장할 때 하위 바이트LSB. 즉, 작은 쪽을 먼저 저장하는 것을 리틀 엔디안(Little Endian)
		*/
		struct				//자료구조가 달라지는 구조체도 1000번지다.???!!  
		{					//위에 BYTE가 변하면 구조체 내부 값도 동일하게 변동됨. 와우~
			unsigned b0: 1; //1bit
			unsigned b1: 1; //1bit
			unsigned b2: 1; //1bit
			unsigned b3: 1; //1bit
			unsigned lownibble: 4; //4bit
		}s;
	}u;
	
	u.BYTE = 0xff;	//ob 1111 1111
	printf("0x%0x\n",u.BYTE);	// 초기값 0xff
	u.s.b3 = 0;	//3번비트 0으로 
	printf("0x%0x\n",u.BYTE);	// 초기값 0xff에서 3번비트 0으로 바뀜 0xf7 
	
	
}


#endif 

#if 0	//비트 시프트 연산 test 


int main(void)
{
	unsigned char BYTE = 0xff;	//ob 1111 1111
	unsigned char mask;
	printf("0x%0x\n",BYTE);
	//비트 시프트를 사용해서 3번 bit를 reset하는 기능
	mask = ~(1 << 3);	//1을 3bit만큼 왼쪽시프트 한 후(0000 0100) 1의 보수시키면 -> 1111 0111 
	BYTE &= mask; 	//mask와 and operation하면 3번 비트만 리셋됨. 
	printf("0x%0x\n",BYTE);	// 3번 비트 리셋된 0xf7이 잘 나옴 
}


#endif 


#if 0
/////////////////////////////////////////
// 아래의 프로그램을 
//  구조체를 화일 pointer및 fseek, rewind로 구현 
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>

 
#define NAME_LEN   20

typedef struct 
{
	int acc_id;     // 계좌번호
	int balance;    // 잔    액
	char cus_name[NAME_LEN];   // 고객이름
} t_account;

void show_menu(void);       	// 메뉴출력
void make_account(t_account *t, int *n);       	// 계좌개설을 위한 함수
void deposit_money(t_account *t, int *n);       // 입    금
void with_draw_money(t_account *t, int *n);		// 출    금
void show_all_acc_info(t_account *t, int *n);	// 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};


FILE *filep; //파일 가르키는 구조체 포인터 
/*
#ifndef _FILE_DEFINED
  struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
#define _FILE_DEFINED

*/
int main(void)
{
	int choice;
	int acc_num=0;        		// 저장된 Account 수	
	
	t_account acc_arr[10];   	// Account 저장을 위한 배열


	void (*fp[]) (t_account *t, int *n) =
	{
		NULL,
	   	make_account,
	   	deposit_money,
	   	with_draw_money,
	   	show_all_acc_info
	};
	
	if ( (filep = fopen("money_file", "wb+")) == NULL)  // 바이너리 파일의 내용을 지우고 읽거나 쓰기 위해 개방 할때("wb+") file이 안열린다면 
	{
		fprintf(stderr, "can't Open file wb+ : money_file....\n");//stderr(standard error 출력) 
		exit(1);  												  // return 1; 에러가 있는 상태로 종료되었다.  
	}

	while(1)
	{
		show_menu();
		printf("선택: ");  
		scanf("%d", &choice);
		printf("\n");
		
		if (choice == EXIT) 
		{
			fclose(filep);
			return 0;
		}
		if(choice>0&&choice<5){
			fp[choice](acc_arr, &acc_num);	
		} 
	    else
		{
	    	printf("enter again: 범위 초과\n");	
		}
		
	}
	return 0;
}

void show_menu(void)
{
	int i;
	
	char *m[] = 
	{
	 "-----Menu------\n",
	 "1. 계좌개설\n",
	 "2. 입    금\n",
	 "3. 출    금\n",
	 "4. 계좌정보 전체 출력\n",
	 "9. 종    료\n"		
	};

	for (i=0; i < 6; i++)
		printf("%s", m[i]);
}

void make_account(t_account *t, int *n) 
{
	int id,i;
	int balance;
	char name[NAME_LEN];
	t_account *tp;
	
	printf("[계좌개설]\n");
	printf("계좌ID: ");	
	scanf("%d", &id);
	printf("이  름: ");	
	scanf("%s", name);
	printf("입금액: ");	
	scanf("%d", &balance);
	printf("\n");
	
	tp = t + *n;
	
	rewind(filep);//file header의 처음 위치로 위치지시자가 돌아가는 것

	
	for (i=0; ; i++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == NULL )	//fread 는 t_account size 28 byte만큼 시작번지부터  읽는다는 뜻.  
		{
			break;
		}
		else if (tp->acc_id == id)
		{
			printf("Already exist ID %d\n", id); 
			return;  
		}
	
	}
	
	fseek(filep, 0, SEEK_END);	//file header의 마지막 위치로 위치지시자가 돌아가는 것

	tp->acc_id=id;
	tp->balance=balance;
	strcpy(tp->cus_name,name);
	fwrite( (char *) &tp->acc_id, 1,sizeof(t_account), filep);//fwrite

	*n = *n+1;
	 
}

void deposit_money(t_account *t, int *n)
{
	int money;
	int id, i, size;
	t_account *tp=t;
		
	printf("[입    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("입금액: ");
	scanf("%d", &money);

	rewind(filep);
	
	for (i=0; i < *n; i++, tp++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == NULL )
		{
			break;
		}
		else if(tp->acc_id==id)
		{
			tp->balance += money;
			
			//아래 코드가 키포인트임 
			size = sizeof(t_account); //size 는 구조체 28Byte만큼 잡아주고 
			fseek(filep, -size, SEEK_CUR); // 현재위치에서 28Byte만큼 뒤로 위치 이동 
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);	//마지막에서 28Byte만큼 뒤 위치에서 새로 들어온 id값을
			//													// 기존에 있던 id값 위치에 덮어쓰는 것 
			printf("입금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
	int money;
	int id, i, size;
	t_account *tp = t;

	printf("[출    금]\n");
	printf("계좌ID: ");
	scanf("%d", &id);
	printf("출금액: ");
	scanf("%d", &money);
	
	rewind(filep);
	
	for(i=0; i < *n; i++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == NULL )
		{
			break;
		}
		else if(tp->acc_id==id)
		{
			if (tp->balance < money)
			{
				printf("잔액부족\n\n");
				return;
			}

			tp->balance -= money;
			size = sizeof(t_account); 
			fseek(filep, -size, SEEK_CUR);
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);
			printf("출금완료\n\n");
			return;
		}
	}
	printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account *t, int *n)	
{
	int i;
	t_account *tp = t;
	
	rewind(filep);
	
	for(i=0; i < *n; i++,tp++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == NULL )
		{
			break;
		}
		printf("계좌ID: %d\n", tp->acc_id);
		printf("이  름: %s\n", tp->cus_name);
		printf("잔  액: %d\n\n", tp->balance);
	}
	printf("\n");
}
#endif

#if 0
/////////////////////////////////////////
//  
//  구조체 pointer를 활용하여  프로그램 작성
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#define NAME_LEN   20

typedef struct
{
    int acc_id;     // 계좌번호
    int balance;    // 잔    액
    char cus_name[NAME_LEN];   // 고객이름
} t_account;

void show_menu(void);           // 메뉴출력
void make_account(t_account *t, int *n);           // 계좌개설을 위한 함수
void deposit_money(t_account *t, int *n);       // 입    금
void with_draw_money(t_account *t, int *n);        // 출    금
void show_all_acc_info(t_account *t, int *n);    // 잔액조회

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};
   
int main(void)
{
    int choice;
    int acc_num=0;                // 저장된 Account 수    
    t_account acc_arr[10];       // Account 저장을 위한 배열

    while(1)
    {
        show_menu();
        printf("선택: ");  
        scanf("%d", &choice);
        printf("\n");
       
        switch(choice)
        {
        case MAKE:
            make_account(acc_arr, &acc_num);
            break;
        case DEPOSIT:
            deposit_money(acc_arr, &acc_num);
            break;
        case WITHDRAW:
            with_draw_money(acc_arr, &acc_num);
            break;
        case INQUIRE:
            show_all_acc_info(acc_arr, &acc_num);
            break;
        case EXIT:
            return 0;
        default:
            printf("Illegal selection..\n");
        }
    }
    return 0;
}

void show_menu(void)
{
    int i;
   
    char *m[] =
    {
     "-----Menu------\n",
     "1. 계좌개설\n",
     "2. 입    금\n",
     "3. 출    금\n",
     "4. 계좌정보 전체 출력\n",
     "9. 종    료\n"        
    };

    for (i=0; i < 6; i++)
        printf("%s", m[i]);
}

void make_account(t_account *t, int *n)
{
    int id;
    int balance;
    char name[NAME_LEN];
    t_account *tp;
   
    printf("[계좌개설]\n");
    printf("계좌ID: ");    
    scanf("%d", &id);
    printf("이  름: ");    
    scanf("%s", name);
    printf("입금액: ");    
    scanf("%d", &balance);
    printf("\n");
   
    tp = t + *n;
   
    tp->acc_id=id;
    tp->balance=balance;
    strcpy(tp->cus_name,name);
    *n = *n+1;
}

void deposit_money(t_account *t, int *n)
{
    int money;
    int id, i;
    t_account *tp=t;
       
    printf("[입    금]\n");
    printf("계좌ID: ");
    scanf("%d", &id);
    printf("입금액: ");
    scanf("%d", &money);

    for (i=0; i < *n; i++, tp++)
    {
        if(tp->acc_id==id)
        {
            tp->balance += money;
            printf("입금완료\n\n");
            return;
        }
    }
    printf("유효하지 않은 ID 입니다.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
    int money;
    int id, i;
    t_account *tp = t;

    printf("[출    금]\n");
    printf("계좌ID: ");
    scanf("%d", &id);
    printf("출금액: ");
    scanf("%d", &money);
   
    for(i=0; i < *n; i++)
    {
        if (tp->acc_id==id)
        {
            if (tp->balance < money)
            {
                printf("잔액부족\n\n");
                return;
            }

            tp->balance -= money;
            printf("출금완료\n\n");
            return;
        }
    }
    printf("유효하지 않은 ID 입니다.\n\n");
}

void show_all_acc_info(t_account *t, int *n)    
{
    int i;
    t_account *tp = t;
   
    for(i=0; i < *n; i++,tp++)
    {
        printf("계좌ID: %d\n", tp->acc_id);
        printf("이  름: %s\n", tp->cus_name);
        printf("잔  액: %d\n\n", tp->balance);
    }
}
#endif




























#if 0 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBER 10
//구조체를 정적 메모리 할당 후 사용자로부터 자료를 입력 받아 프린트 하는 program을 작성한다.
//구조체 포인터 활용 

typedef struct _person{
	char name[20];
	int age;
	char address[40];
}t_person;	//위에 struct _person을 t_person으로 재정의하는거임 재정의한다고해서 보통 t_를 붙여줌 

void print_person(t_person *p, int *n);
void copy_person(t_person *p, t_person *p1 ,int *n);


int main(void)
{
	t_person *p1;
	p1= (t_person*)malloc(sizeof(t_person)*NUMBER);
	//위에 구조체랑 이름이 같아도 구조체 내부는 블록으로 봄-> 충돌 X 
	t_person temp;
	
	int i=0;
	
	while(1)
	{
		printf("Enrer name age address (exit: end 0 end) ");
		scanf("%s",&temp.name);
		scanf("%d",&temp.age);
		scanf("%s",&temp.address);
		
		if(!strncmp(temp.name,"end",strlen("end")))//strncmp 값이 같으면 null을 리턴받음 
		{
			break;
		}
		else
		{
			copy_person(&p1,&temp,&i);
		}
		
	}
	print_person(&p1,&i);
	free(p1);
}

void print_person(t_person *p, int *n)
{
	int i;
	t_person *pt=p;// 항상 포인터 조작할때는 새로 만들어서 덮어씌운걸로 조작 
	if(*n==0){
		printf("n이 0이네?\n");
	}
	else
	{
		printf("이름 나이 주소\n");
		printf("=== ==== =======================\n");
		for(i=0; i<*n;i++)
		{
			//printf("%-6s %d    %s\n",*(pt).name,*(pt).age,*(pt).address);
			printf("%-6s %d    %s\n",pt->name,pt->age,pt->address);//통상 구조체 포인터 멤버 편수를 표현할때에는 이렇게 표현함 
			pt++; 
		}
		printf("====================================\n");
	}

	
}

void copy_person(t_person *p, t_person *p1 ,int *n)
{
	t_person *pt=p+*n;// 항상 포인터 조작할때는 새로 만들어서 덮어씌운걸로 조작
					  // 위 처럼 하든지 main문 안에서 copy_person(&p1,&temp,&i);를 하든지 
	strncpy(pt->name,p1->name,strlen(p1->name)); //strcpy(pt->name,tp1->name)도 가능 
	pt->age=p1->age;
	strncpy(pt->address,p1->address,strlen(p1->address));
	*n+=1;
}


#endif


#if 0 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBER 10
//구조체를 정적 메모리 할당 후 사용자로부터 자료를 입력 받아 프린트 하는 program을 작성한다.
//구조체 포인터 활용 

typedef struct _person{
	char name[20];
	int age;
	char address[40];
}t_person;	//위에 struct _person을 t_person으로 재정의하는거임 재정의한다고해서 보통 t_를 붙여줌 

void print_person(t_person *p, int *n);
void copy_person(t_person *p, t_person *p1 ,int *n);


int main(void)
{
	t_person p1[NUMBER];
	//위에 구조체랑 이름이 같아도 구조체 내부는 블록으로 봄-> 충돌 X 
	t_person temp;
	
	int i=0;
	
	while(1)
	{
		printf("Enrer name age address (exit: end 0 end) ");
		scanf("%s",&temp.name);
		scanf("%d",&temp.age);
		scanf("%s",&temp.address);
		
		if(!strncmp(temp.name,"end",strlen("end")))//strncmp 값이 같으면 null을 리턴받음 
		{
			break;
		}
		else
		{
			copy_person(&p1,&temp,&i);
		}
		
	}
	print_person(&p1,&i);
	
}

void print_person(t_person *p, int *n)
{
	int i;
	t_person *pt=p;// 항상 포인터 조작할때는 새로 만들어서 덮어씌운걸로 조작 
	if(*n==0){
		printf("n이 0이네?\n");
	}
	else
	{
		printf("이름 나이 주소\n");
		printf("=== ==== =======================\n");
		for(i=0; i<*n;i++)
		{
			//printf("%-6s %d    %s\n",*(pt).name,*(pt).age,*(pt).address);
			printf("%-6s %d    %s\n",pt->name,pt->age,pt->address);//통상 구조체 포인터 멤버 편수를 표현할때에는 이렇게 표현함 
			pt++; 
		}
		printf("====================================\n");
	}

	
}

void copy_person(t_person *p, t_person *p1 ,int *n)
{
	t_person *pt=p+*n;// 항상 포인터 조작할때는 새로 만들어서 덮어씌운걸로 조작
					  // 위 처럼 하든지 main문 안에서 copy_person(&p1,&temp,&i);를 하든지 
	strncpy(pt->name,p1->name,strlen(p1->name)); //strcpy(pt->name,tp1->name)도 가능 
	pt->age=p1->age;
	strncpy(pt->address,p1->address,strlen(p1->address));
	*n+=1;
}


#endif



