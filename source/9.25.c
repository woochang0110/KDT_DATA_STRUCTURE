

#if 1	//��Ʈ ����Ʈ ���� ������� �ʰ� union����ϱ� 


int main(void)
{
	union
	{						//union�� �����ϸ� 
		unsigned char BYTE;	//���� ��� �� �ּҰ� 1000�������  
		//intel �迭�� little endian, motorola�� big endian �����. 
		/*
		������ �� ���� ����ƮMSB. ��, ū ���� ���� �����ϴ� ���� �� �����(Big Endian), 
		������ �� ���� ����ƮLSB. ��, ���� ���� ���� �����ϴ� ���� ��Ʋ �����(Little Endian)
		*/
		struct				//�ڷᱸ���� �޶����� ����ü�� 1000������.???!!  
		{					//���� BYTE�� ���ϸ� ����ü ���� ���� �����ϰ� ������. �Ϳ�~
			unsigned b0: 1; //1bit
			unsigned b1: 1; //1bit
			unsigned b2: 1; //1bit
			unsigned b3: 1; //1bit
			unsigned lownibble: 4; //4bit
		}s;
	}u;
	
	u.BYTE = 0xff;	//ob 1111 1111
	printf("0x%0x\n",u.BYTE);	// �ʱⰪ 0xff
	u.s.b3 = 0;	//3����Ʈ 0���� 
	printf("0x%0x\n",u.BYTE);	// �ʱⰪ 0xff���� 3����Ʈ 0���� �ٲ� 0xf7 
	
	
}


#endif 

#if 0	//��Ʈ ����Ʈ ���� test 


int main(void)
{
	unsigned char BYTE = 0xff;	//ob 1111 1111
	unsigned char mask;
	printf("0x%0x\n",BYTE);
	//��Ʈ ����Ʈ�� ����ؼ� 3�� bit�� reset�ϴ� ���
	mask = ~(1 << 3);	//1�� 3bit��ŭ ���ʽ���Ʈ �� ��(0000 0100) 1�� ������Ű�� -> 1111 0111 
	BYTE &= mask; 	//mask�� and operation�ϸ� 3�� ��Ʈ�� ���µ�. 
	printf("0x%0x\n",BYTE);	// 3�� ��Ʈ ���µ� 0xf7�� �� ���� 
}


#endif 


#if 0
/////////////////////////////////////////
// �Ʒ��� ���α׷��� 
//  ����ü�� ȭ�� pointer�� fseek, rewind�� ���� 
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>

 
#define NAME_LEN   20

typedef struct 
{
	int acc_id;     // ���¹�ȣ
	int balance;    // ��    ��
	char cus_name[NAME_LEN];   // ���̸�
} t_account;

void show_menu(void);       	// �޴����
void make_account(t_account *t, int *n);       	// ���°����� ���� �Լ�
void deposit_money(t_account *t, int *n);       // ��    ��
void with_draw_money(t_account *t, int *n);		// ��    ��
void show_all_acc_info(t_account *t, int *n);	// �ܾ���ȸ

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};


FILE *filep; //���� ����Ű�� ����ü ������ 
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
	int acc_num=0;        		// ����� Account ��	
	
	t_account acc_arr[10];   	// Account ������ ���� �迭


	void (*fp[]) (t_account *t, int *n) =
	{
		NULL,
	   	make_account,
	   	deposit_money,
	   	with_draw_money,
	   	show_all_acc_info
	};
	
	if ( (filep = fopen("money_file", "wb+")) == NULL)  // ���̳ʸ� ������ ������ ����� �аų� ���� ���� ���� �Ҷ�("wb+") file�� �ȿ����ٸ� 
	{
		fprintf(stderr, "can't Open file wb+ : money_file....\n");//stderr(standard error ���) 
		exit(1);  												  // return 1; ������ �ִ� ���·� ����Ǿ���.  
	}

	while(1)
	{
		show_menu();
		printf("����: ");  
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
	    	printf("enter again: ���� �ʰ�\n");	
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
	 "1. ���°���\n",
	 "2. ��    ��\n",
	 "3. ��    ��\n",
	 "4. �������� ��ü ���\n",
	 "9. ��    ��\n"		
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
	
	printf("[���°���]\n");
	printf("����ID: ");	
	scanf("%d", &id);
	printf("��  ��: ");	
	scanf("%s", name);
	printf("�Աݾ�: ");	
	scanf("%d", &balance);
	printf("\n");
	
	tp = t + *n;
	
	rewind(filep);//file header�� ó�� ��ġ�� ��ġ�����ڰ� ���ư��� ��

	
	for (i=0; ; i++)
	{
		if (fread( (char *) &tp->acc_id, 1, sizeof(t_account), filep) == NULL )	//fread �� t_account size 28 byte��ŭ ���۹�������  �д´ٴ� ��.  
		{
			break;
		}
		else if (tp->acc_id == id)
		{
			printf("Already exist ID %d\n", id); 
			return;  
		}
	
	}
	
	fseek(filep, 0, SEEK_END);	//file header�� ������ ��ġ�� ��ġ�����ڰ� ���ư��� ��

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
		
	printf("[��    ��]\n");
	printf("����ID: ");
	scanf("%d", &id);
	printf("�Աݾ�: ");
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
			
			//�Ʒ� �ڵ尡 Ű����Ʈ�� 
			size = sizeof(t_account); //size �� ����ü 28Byte��ŭ ����ְ� 
			fseek(filep, -size, SEEK_CUR); // ������ġ���� 28Byte��ŭ �ڷ� ��ġ �̵� 
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);	//���������� 28Byte��ŭ �� ��ġ���� ���� ���� id����
			//													// ������ �ִ� id�� ��ġ�� ����� �� 
			printf("�ԱݿϷ�\n\n");
			return;
		}
	}
	printf("��ȿ���� ���� ID �Դϴ�.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
	int money;
	int id, i, size;
	t_account *tp = t;

	printf("[��    ��]\n");
	printf("����ID: ");
	scanf("%d", &id);
	printf("��ݾ�: ");
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
				printf("�ܾ׺���\n\n");
				return;
			}

			tp->balance -= money;
			size = sizeof(t_account); 
			fseek(filep, -size, SEEK_CUR);
			fwrite( (char *) &tp->acc_id, 1, sizeof(t_account), filep);
			printf("��ݿϷ�\n\n");
			return;
		}
	}
	printf("��ȿ���� ���� ID �Դϴ�.\n\n");
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
		printf("����ID: %d\n", tp->acc_id);
		printf("��  ��: %s\n", tp->cus_name);
		printf("��  ��: %d\n\n", tp->balance);
	}
	printf("\n");
}
#endif

#if 0
/////////////////////////////////////////
//  
//  ����ü pointer�� Ȱ���Ͽ�  ���α׷� �ۼ�
/////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#define NAME_LEN   20

typedef struct
{
    int acc_id;     // ���¹�ȣ
    int balance;    // ��    ��
    char cus_name[NAME_LEN];   // ���̸�
} t_account;

void show_menu(void);           // �޴����
void make_account(t_account *t, int *n);           // ���°����� ���� �Լ�
void deposit_money(t_account *t, int *n);       // ��    ��
void with_draw_money(t_account *t, int *n);        // ��    ��
void show_all_acc_info(t_account *t, int *n);    // �ܾ���ȸ

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT=9};
   
int main(void)
{
    int choice;
    int acc_num=0;                // ����� Account ��    
    t_account acc_arr[10];       // Account ������ ���� �迭

    while(1)
    {
        show_menu();
        printf("����: ");  
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
     "1. ���°���\n",
     "2. ��    ��\n",
     "3. ��    ��\n",
     "4. �������� ��ü ���\n",
     "9. ��    ��\n"        
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
   
    printf("[���°���]\n");
    printf("����ID: ");    
    scanf("%d", &id);
    printf("��  ��: ");    
    scanf("%s", name);
    printf("�Աݾ�: ");    
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
       
    printf("[��    ��]\n");
    printf("����ID: ");
    scanf("%d", &id);
    printf("�Աݾ�: ");
    scanf("%d", &money);

    for (i=0; i < *n; i++, tp++)
    {
        if(tp->acc_id==id)
        {
            tp->balance += money;
            printf("�ԱݿϷ�\n\n");
            return;
        }
    }
    printf("��ȿ���� ���� ID �Դϴ�.\n\n");
}

void with_draw_money(t_account *t, int *n)
{
    int money;
    int id, i;
    t_account *tp = t;

    printf("[��    ��]\n");
    printf("����ID: ");
    scanf("%d", &id);
    printf("��ݾ�: ");
    scanf("%d", &money);
   
    for(i=0; i < *n; i++)
    {
        if (tp->acc_id==id)
        {
            if (tp->balance < money)
            {
                printf("�ܾ׺���\n\n");
                return;
            }

            tp->balance -= money;
            printf("��ݿϷ�\n\n");
            return;
        }
    }
    printf("��ȿ���� ���� ID �Դϴ�.\n\n");
}

void show_all_acc_info(t_account *t, int *n)    
{
    int i;
    t_account *tp = t;
   
    for(i=0; i < *n; i++,tp++)
    {
        printf("����ID: %d\n", tp->acc_id);
        printf("��  ��: %s\n", tp->cus_name);
        printf("��  ��: %d\n\n", tp->balance);
    }
}
#endif




























#if 0 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUMBER 10
//����ü�� ���� �޸� �Ҵ� �� ����ڷκ��� �ڷḦ �Է� �޾� ����Ʈ �ϴ� program�� �ۼ��Ѵ�.
//����ü ������ Ȱ�� 

typedef struct _person{
	char name[20];
	int age;
	char address[40];
}t_person;	//���� struct _person�� t_person���� �������ϴ°��� �������Ѵٰ��ؼ� ���� t_�� �ٿ��� 

void print_person(t_person *p, int *n);
void copy_person(t_person *p, t_person *p1 ,int *n);


int main(void)
{
	t_person *p1;
	p1= (t_person*)malloc(sizeof(t_person)*NUMBER);
	//���� ����ü�� �̸��� ���Ƶ� ����ü ���δ� ������� ��-> �浹 X 
	t_person temp;
	
	int i=0;
	
	while(1)
	{
		printf("Enrer name age address (exit: end 0 end) ");
		scanf("%s",&temp.name);
		scanf("%d",&temp.age);
		scanf("%s",&temp.address);
		
		if(!strncmp(temp.name,"end",strlen("end")))//strncmp ���� ������ null�� ���Ϲ��� 
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
	t_person *pt=p;// �׻� ������ �����Ҷ��� ���� ���� �����ɷ� ���� 
	if(*n==0){
		printf("n�� 0�̳�?\n");
	}
	else
	{
		printf("�̸� ���� �ּ�\n");
		printf("=== ==== =======================\n");
		for(i=0; i<*n;i++)
		{
			//printf("%-6s %d    %s\n",*(pt).name,*(pt).age,*(pt).address);
			printf("%-6s %d    %s\n",pt->name,pt->age,pt->address);//��� ����ü ������ ��� ����� ǥ���Ҷ����� �̷��� ǥ���� 
			pt++; 
		}
		printf("====================================\n");
	}

	
}

void copy_person(t_person *p, t_person *p1 ,int *n)
{
	t_person *pt=p+*n;// �׻� ������ �����Ҷ��� ���� ���� �����ɷ� ����
					  // �� ó�� �ϵ��� main�� �ȿ��� copy_person(&p1,&temp,&i);�� �ϵ��� 
	strncpy(pt->name,p1->name,strlen(p1->name)); //strcpy(pt->name,tp1->name)�� ���� 
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
//����ü�� ���� �޸� �Ҵ� �� ����ڷκ��� �ڷḦ �Է� �޾� ����Ʈ �ϴ� program�� �ۼ��Ѵ�.
//����ü ������ Ȱ�� 

typedef struct _person{
	char name[20];
	int age;
	char address[40];
}t_person;	//���� struct _person�� t_person���� �������ϴ°��� �������Ѵٰ��ؼ� ���� t_�� �ٿ��� 

void print_person(t_person *p, int *n);
void copy_person(t_person *p, t_person *p1 ,int *n);


int main(void)
{
	t_person p1[NUMBER];
	//���� ����ü�� �̸��� ���Ƶ� ����ü ���δ� ������� ��-> �浹 X 
	t_person temp;
	
	int i=0;
	
	while(1)
	{
		printf("Enrer name age address (exit: end 0 end) ");
		scanf("%s",&temp.name);
		scanf("%d",&temp.age);
		scanf("%s",&temp.address);
		
		if(!strncmp(temp.name,"end",strlen("end")))//strncmp ���� ������ null�� ���Ϲ��� 
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
	t_person *pt=p;// �׻� ������ �����Ҷ��� ���� ���� �����ɷ� ���� 
	if(*n==0){
		printf("n�� 0�̳�?\n");
	}
	else
	{
		printf("�̸� ���� �ּ�\n");
		printf("=== ==== =======================\n");
		for(i=0; i<*n;i++)
		{
			//printf("%-6s %d    %s\n",*(pt).name,*(pt).age,*(pt).address);
			printf("%-6s %d    %s\n",pt->name,pt->age,pt->address);//��� ����ü ������ ��� ����� ǥ���Ҷ����� �̷��� ǥ���� 
			pt++; 
		}
		printf("====================================\n");
	}

	
}

void copy_person(t_person *p, t_person *p1 ,int *n)
{
	t_person *pt=p+*n;// �׻� ������ �����Ҷ��� ���� ���� �����ɷ� ����
					  // �� ó�� �ϵ��� main�� �ȿ��� copy_person(&p1,&temp,&i);�� �ϵ��� 
	strncpy(pt->name,p1->name,strlen(p1->name)); //strcpy(pt->name,tp1->name)�� ���� 
	pt->age=p1->age;
	strncpy(pt->address,p1->address,strlen(p1->address));
	*n+=1;
}


#endif



