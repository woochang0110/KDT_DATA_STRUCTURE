#if 1

#include <stdio.h>  // printf scanf fgets
#include <string.h>  // strcpy strcat strncpy strncmp
#include <stdlib.h>   // atoi, itoa
#include <time.h>
#pragma warning(disable:4996
#pragma warning(disable:6011)
#pragma warning(disable:6031)
#define FUNC_NUM 6



//301:홍길동:010-3355-1111:200000:경기 용인:2023-11-20:1800:2023-11-24 18.00:
typedef struct {
	int year;
	int month;
	int day;
	int hour;
	int min;
}_stDate;

typedef struct _node {
	int roomno;
	char name[20];
	char phone[40];
	double price;
	char address[40];
	_stDate enter_time;
	_stDate exit_time;
	struct _node* prev;
	struct _node* next;
} __NODE;

typedef struct {
	__NODE* head;
	__NODE* tail;
	__NODE* curr;
	int numOfData;
} LIST;

void init(LIST* list);
void first_insert(LIST* list, __NODE* newnode);
int input_check(int* col, int* flag, char* buff);
void getDataFromTxtFile(LIST* list);
void menu_display();
int reservation_management(LIST* list);
__NODE* makeNode();
void insert_node(LIST* list);
void delete_node(LIST* list);
void modify_node(LIST* list);
void display_one(LIST* list);
void display_all(LIST* list);
void exit_program(LIST* list);


//함수포인터
void (*funcp[FUNC_NUM])(LIST*) =
{
	NULL,	//안쓰는 방에는 NULL 넣어줘야됨.
	insert_node,
	delete_node,
	modify_node,
	display_one,
	display_all
};

FILE* fp;



int main(void)
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	//head tail curr 생성하는 과정 안하면 init이 안됨 
	__NODE *h = (__NODE*)malloc(sizeof(__NODE));
	__NODE* t = (__NODE*)malloc(sizeof(__NODE));
	__NODE* c = (__NODE*)malloc(sizeof(__NODE));
	list->head = h;
	list->tail = t;
	list->curr = c;
	//head tail curr 생성하는 과정 안하면 가리킬 주소가 없어서 그런건지 init이 안됨 

	init(list);//head와 tail이 서로를 가리키게 만들고 초기화
	
	printf("파일 열기 전\n");
	fp = fopen("reservation.txt", "r");
	if (fp == NULL)   // 해당 화일이 없을 경우  
	{
		printf("can't open: reservation.txt\n");
		return 0;//종료
	}
	else   // 화일이 존재 하면 
	{
		printf("file open: reservation.txt  OK !!!!!\n");

		getDataFromTxtFile(list);
		reservation_management(list);
		exit_program(list);
		printf("프로그램이 종료 되었습니다 !!!!!\n");

	}
	free(list);
	return 0;  // 0를return 하는 이유는 no error 
}



//list 내부 head와 tail, curr,numOfData 초기화
void init(LIST* list) {
	
	list->head->prev = NULL;
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->tail->next = NULL;
	list->curr = list->head;
	list->numOfData = 0;
}


//getDataFromTxtFile에 들어가는 함수
//insert_node에는 사용자 입력 받는 항목이 있어서 따로 만듬
void first_insert(LIST* list, __NODE *newnode)
{
	
	//tail쪽에 연결
	list->curr = list->tail;
	list->curr->prev->next = newnode;
	newnode->prev = list->curr->prev;
	list->curr->prev = newnode;
	newnode->next = list->curr;
	list->curr = newnode;
	//tail쪽에 연결 완료
}



//301:aaaa:010-3355-1111:200000:aaaaaa:2023.11.20.15.23:2023.11.24.18.00:
int input_check(int* startpoint, int* flag, char* input_buff)
{

	int sp, len;
	char* p = input_buff;   // buff의 주소가 p에 들어 간다. 
	sp = *startpoint;  // 토큰의 시작위치 
	len = 0;   // 토큰의 길이 
	if (*flag == 0)//flag가 0이면 : 을 기준으로 parsing
	{
		while (*p++ != ':')   // 1) *p != ':'  2)p++
		{
			sp++;   // 해당되는 필드의 위치 byte를 count 
			len++;   // 토큰의 문자수 
		}
	}
	else if (*flag == 1)//flag가 1이면 . 을 기준으로 parsing
	{
		while (*p++ != '.')
		{
			sp++;   // 해당되는 필드의 위치 byte를 count 
			len++;   // 토큰의 문자수 
		}
	}
	*startpoint = sp;   // :이 들어 있는 index 
	// 해당되는 필드의 byte수 col에 저장
	return len;  // 토큰의 문자수 
}

/*
* fgets
// d:\temp\reservation.txt로 부터 1줄에 최대 100byte를 읽되
// \n을 만날떄 까지 읽어서  input_buff에 넣는다.
// 화일의 마지막을 만나 면 (NULL)
// fgets가 return 받는것: 읽은 문자 수
*/




//main 초기에 txt파일 읽고 string parsing해서 DLL내부에 넣어줌
void getDataFromTxtFile(LIST* list)//main 내부에 file 존재시 동작 로직을 여기다 옮김
{
	char input_buff[400] = { 0 };
	char room[4];
	char pr[20];
	char y[6];
	char mo[4];
	char d[4];
	char h[4];
	char mi[4];
	
	int nextsp;	//nextsp는 inputcheck 함수에 들어간 후 다음 sp를 가리키게 됨. 
	int len;	//len는 inputcheck 리턴값으로 단어의 길이를 뜻하고, 
	int sp;		//sp는 현재 parsing할 단어의 길이
	int flag = 0;	//flag는 날짜 전 까지 parsing이 끝났는지 체크 0이면 날짜 이전, 1이면 날짜부분
	while (fgets(input_buff, 400, fp))
	{
		__NODE* newnode = makeNode();//노드 생성
		printf("input_buff:\n%s\n", input_buff);
		first_insert(list,newnode);

		nextsp = 0;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);

		strncpy(room, input_buff, len);
		newnode->roomno = atoi(room);
		nextsp++;   // 이름이 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		newnode->name[len] = '\0';//초기화대신사용
		strncpy((char*)newnode->name, input_buff + sp, len);


		nextsp++;   // phone이 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		
		newnode->phone[len] = '\0';//초기화대신사용
		strncpy(newnode->phone, input_buff + sp, len);


		nextsp++;   // price이 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		pr[len] = '\0';//초기화대신사용
		strncpy(pr, input_buff + sp, len);
		newnode->price = atof(pr);

		nextsp++;   // address이 들어 있는 첫번방의 index 
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		newnode->address[len] = '\0';//초기화대신사용
		strncpy(newnode->address, input_buff + sp, len);


		flag = 1;//여기부터 입실날짜고 .기준으로 parsing

		//printf("sp:%d len:%d nextsp:%d\n", sp, len, nextsp);//여기까지 ok


		nextsp++;   // enter_date의 year이 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(y, input_buff + sp, len);
		newnode->enter_time.year = atoi(y);

		nextsp++;   // enter_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(mo, input_buff + sp, len);
		newnode->enter_time.month = atoi(mo);


		nextsp++;   // enter_date day 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(d, input_buff + sp, len);
		newnode->enter_time.day = atoi(d);

		nextsp++;   // enter_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(h, input_buff + sp, len);
		newnode->enter_time.hour = atoi(h);


		flag = 0;//enter time min 까지 입력 되었다면 exit time 과의 구분자인 :를 기준으로 parsing하기 위해 flag 0으로 바꿨다가 다시 1로 변경


		nextsp++;   // enter_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(mi, input_buff + sp, len);
		newnode->enter_time.min = atoi(mi);
		
		flag = 1;//여기부터 퇴실날짜고 .기준으로 parsing

		nextsp++;   // exit_date의 year이 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(y, input_buff + sp, len);
		newnode->exit_time.year = atoi(y);

		nextsp++;   // exit_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(mo, input_buff + sp, len);
		newnode->exit_time.month = atoi(mo);

		nextsp++;   // exit_date day 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(d, input_buff + sp, len);
		newnode->exit_time.day = atoi(d);

		nextsp++;   // exit_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(h, input_buff + sp, len);
		newnode->exit_time.hour = atoi(h);


		flag = 0;//exit time min 까지 입력 되었다면 exit time 과의 구분자인 :를 기준으로 parsing하기 위해 flag 0으로 바꿨다가 다시 1로 변경


		nextsp++;   // exit_date month 들어 있는 첫번방의 index
		sp = nextsp;
		len = input_check(&nextsp, &flag, &input_buff[nextsp]);
		strncpy(mi, input_buff + sp, len);
		list->curr->exit_time.min = atoi(mi);


		list->curr = newnode;
		/*
		printf("\ntestprint\n\n%d:%s:%s:%lf:%s:%d.%d.%d.%d.%d:%d.%d.%d.%d.%d:\n\ntestprint end\n\n", list->curr->roomno,list->curr->name, list->curr->phone,
			list->curr->price, list->curr->address, list->curr->enter_time.year, list->curr->enter_time.month, list->curr->enter_time.day,
			list->curr->enter_time.hour, list->curr->enter_time.min, list->curr->exit_time.year, list->curr->exit_time.month, list->curr->exit_time.day,
			list->curr->exit_time.hour, list->curr->exit_time.min);
		*/
		list->numOfData += 1;//노드 갯수 카운트
	}
}




//메뉴 띄우는 함수
void menu_display()
{
	int i;
	char menu[8][60] = {
	"------------------ < 객실 관리 >----------------------",
	"   1. 입력(예약)",
	"   2. 삭제(퇴실)",
	"   3. 수정(예약내역수정)",
	"   4. 조회(개별조회)",
	"   5. 전체조회(예약자 전체조회)\n\n",
	"   9. 종료"
	};
	for (i = 0; i < 8; i++)
		printf("%s\n", menu[i]);
}


int reservation_management(LIST* list)
{
	int choice = 0;
	while (1) 
	{
		menu_display();
		scanf("%d", &choice);
		getchar();

		if (choice == 9)
		{
			break;
		}
		else if (choice > 0 && choice < 6)
		{
			printf("입력:%d\n", choice);
			funcp[choice](list);
		}
		else
		{
			printf("값 다시 입력바람\n");
		}


	}


}


//node 동적할당하고 노드구조체 리턴 
__NODE* makeNode()
{
	__NODE* node = (__NODE*)malloc(sizeof(__NODE));
	node->prev = NULL;
	node->next = NULL;
	//나머지 값들 초기화는 패스..
	return node;
}

//node tail부터 삽입(완료)
void insert_node(LIST* list) {
	__NODE* newnode = makeNode();
	char input_buffer[40] = { 0 };
	int room;
	int stay;
	char yorn;
	//*사용자입력 fgets를 쓰고있기 때문에 scanf쓰면 안됨->scanf 사용후 getchar()로 해결가능!
	printf("enter room no: ");
	scanf("%d", &room);
	getchar();
	//%%%사용자 다른 입력 추가 필요!!
	//%%%사용자 다른 입력 추가 필요!!

	printf("확인(y/n): ");
	scanf("%c",&yorn);
	getchar();//scanf와 fgets 같이 쓰려면 scanf 사용후에 getchar를 사용해서 버퍼에 남은 개행문자\n을 없애줘야됨 
	if (yorn == 'y')
	{
		
		//리스트를 쭉 돌려보면서 
		list->curr = list->head;
		do
		{
			list->curr = list->curr->next;
			if (room == list->curr->roomno)//동일 roomno가 발견된다면
			{
				printf("이미 예약된 객실입니다\n");//이미예약되었다고 출력하고 탈출
				return;
			}
			
		} while (list->curr->next != list->tail);//이 조건으로 돌렸을때 마지막 값까지 체크하려면 do while 써야됨
		
		if (list->curr->next == list->tail)//while문을 나온 값이 tail까지 정상적으로 돌고 나왔다면
		{
			
			//기존 리스트에 연결
			list->curr = list->tail;
			list->curr->prev->next = newnode;
			newnode->prev = list->curr->prev;
			list->curr->prev = newnode;
			newnode->next = list->curr;
			//기존 리스트에 연결 완료
			
			//사용자 입력 추가 필요
			newnode->roomno = room;
			printf("enter name: ");
			scanf("%s", newnode->name);
			printf("enter phone no: ");
			scanf("%s", newnode->phone);
			printf("enter price: ");
			scanf("%lf", &(newnode->price));
			printf("enter address: ");
			scanf("%s", newnode->address);
			printf("enter how many day do you stay: ");
			scanf("%d", &stay);
			getchar();//scanf와 fgets 같이 쓰려면 scanf 사용후에 getchar를 사용해서 버퍼에 남은 개행문자\n을 없애줘야됨
			//unix시간 get
			time_t sec = time(NULL);		//time.h 라이브러리 활용
			struct tm* now = localtime(&sec);//unix타임 기준으로 받아온다
			//입실시간
			newnode->enter_time.year = 1900 + now->tm_year;//그래서 현재 시간 출력하려면 일정 값을 더해줘야함
			newnode->enter_time.month = 1 + now->tm_mon;
			newnode->enter_time.day = now->tm_mday;
			newnode->enter_time.hour = now->tm_hour;
			newnode->enter_time.min = now->tm_min;
			//퇴실예정시간
			newnode->exit_time.year = newnode->enter_time.year;
			newnode->exit_time.month = newnode->enter_time.month;
			newnode->exit_time.day = newnode->enter_time.day+stay;//머물 날짜만큼 더해줌
			newnode->exit_time.hour = 11;//check out은 11시정각
			newnode->exit_time.min = 0;

			printf("정상 예약되었습니다\n");// 정상예약되었다고 출력

			//*사용자 입력 완료
			list->curr = list->head;//curr을 다시 head를 가리키게 함으로써 다음 사용을 위해 초기화 해줌
			list->numOfData += 1;
		}

		
	}
	else
	{
		printf("예약 도중 종료되었습니다\n");
		return;
	}

}

//node head부터 탐색 후 삽입(완료)
void delete_node(LIST* list) {
	__NODE* temp = makeNode();//사용자 입력 임시 저장용
	char input_buffer[40];
	int room;
	char yorn;

	printf("enter room no: ");
	scanf("%d", &room);
	getchar();
	//%%%사용자 다른 입력 추가 필요!!
	//%%%사용자 다른 입력 추가 필요!!

	printf("확인(y/n): ");
	scanf("%c", &yorn);
	getchar();
	if (yorn == 'y')
	{

		//리스트를 쭉 돌려보면서 
		list->curr = list->head->next;
		while (list->curr->next != list->tail)
		{
			if (room == list->curr->roomno)//동일 roomno가 발견된다면
			{
				printf("퇴실처리되었습니다\n");//이미예약되었다고 출력하고 탈출
				//리스트 연결 재설정
				list->curr->next->prev = list->curr->prev;
				list->curr->prev->next = list->curr->next;
				//리스트 연결 재설정 완료
				list->numOfData -= 1;
				break;
			}
			list->curr = list->curr->next;
		}
		if (list->curr->next == list->tail)//while문을 나온 값이 tail까지 정상적으로 돌고 나왔다면
		{
			printf("없는 객실입니다\n");// 없는객실이라고 출력

		}

		//*사용자 입력 완료
	}
	else
	{
		printf("퇴실 도중 종료되었습니다\n");

	}
	free(temp);
}


//수정(완료)
void modify_node(LIST* list) {
	char input_buffer[40] = { 0 };
	int room;
	int stay;
	char yorn;
	//*사용자입력 fgets를 쓰고있기 때문에 scanf쓰면 안됨->scanf 사용후 getchar()로 해결가능!
	printf("enter room no: ");
	scanf("%d", &room);
	getchar();
	//%%%사용자 다른 입력 추가 필요!!
	//%%%사용자 다른 입력 추가 필요!!

	printf("확인(y/n): ");
	scanf("%c", &yorn);
	getchar();//scanf와 fgets 같이 쓰려면 scanf 사용후에 getchar를 사용해서 버퍼에 남은 개행문자\n을 없애줘야됨 
	if (yorn == 'y')
	{

		//리스트를 쭉 돌려보면서 
		list->curr = list->head;
		do
		{
			list->curr = list->curr->next;
			if (room == list->curr->roomno)//동일 roomno가 발견된다면
			{
				printf("객실번호가 확인되었습니다\n");//이미예약되었다고 출력하고 다음으로
				//사용자 입력 추가 필요
				list->curr->roomno = room;
				printf("enter name: ");
				scanf("%s", list->curr->name);
				printf("enter phone no: ");
				scanf("%s", list->curr->phone);
				printf("enter price: ");
				scanf("%lf", &(list->curr->price));
				printf("enter address: ");
				scanf("%s", list->curr->address);
				printf("enter how many day you will stay: ");
				scanf("%d", &stay);
				getchar();//scanf와 fgets 같이 쓰려면 scanf 사용후에 getchar를 사용해서 버퍼에 남은 개행문자\n을 없애줘야됨

				list->curr->exit_time.day = list->curr->enter_time.day + stay;//머물 날짜만큼 더해줌

				printf("정상 수정되었습니다\n");// 정상예약되었다고 출력

				//*사용자 입력 완료
				list->curr = list->head;//curr을 다시 head를 가리키게 함으로써 다음 사용을 위해 초기화 해줌

				break;
			}

		} while (list->curr->next != list->tail);//이 조건으로 돌렸을때 마지막 값까지 체크하려면 do while 써야됨
	if(list->curr->next == list->tail)
	{
		printf("없는 객실번호 입니다\n");
		list->curr = list->head;//curr을 다시 head를 가리키게 함으로써 다음 사용을 위해 초기화 해줌
		return;
	}

	}
	else
	{
		printf("수정 도중 취소되었습니다\n");
		list->curr = list->head;//curr을 다시 head를 가리키게 함으로써 다음 사용을 위해 초기화 해줌
		return;
	}

}



//원하는 객실 하나만 diplay(완료)
void display_one(LIST* list)
{
	int room;//사용자 입력 임시 저장용
	//*사용자입력 fgets를 쓰고있기 때문에 scanf쓰면 안됨
	printf("enter room no: ");
	scanf("%d", &room);
	getchar();
	//리스트를 쭉 돌려보면서 
	list->curr = list->head->next;
	while (list->curr->next != list->tail)
	{
		if (room == list->curr->roomno)//동일 roomno가 발견된다면
		{
			printf("입력한 room no의 정보입니다\n");//해당 노드의 정보 출력하고 탈출

			printf("%s:%s:%lf:%s:%d.%d.%d.%d.%d:%d.%d.%d.%d.%d:\n", list->curr->name, list->curr->phone,
				list->curr->price, list->curr->address, list->curr->enter_time.year, list->curr->enter_time.month, list->curr->enter_time.day,
				list->curr->enter_time.hour, list->curr->enter_time.min, list->curr->exit_time.year, list->curr->exit_time.month, list->curr->exit_time.day,
				list->curr->exit_time.hour, list->curr->exit_time.min);
			break;
		}
		list->curr = list->curr->next;
	}
	if (list->curr->next == list->tail)//while문을 나온 값이 tail까지 정상적으로 돌고 나왔다면
	{
		printf("없는 객실입니다\n");// 없는객실이라고 출력
	}

	//*사용자 입력 완료
}

//모든 객실 display(완료)
void display_all(LIST* list)
{
	list->curr = list->head->next;
	//리스트를 쭉 돌려보면서 
	while (list->curr->next != list->tail)
	{
		printf("%d:%s:%s:%.1lf:%s:%d.%d.%d.%d.%d:%d.%d.%d.%d.%d:\n", list->curr->roomno, list->curr->name, list->curr->phone,
			list->curr->price, list->curr->address, list->curr->enter_time.year, list->curr->enter_time.month, list->curr->enter_time.day,
			list->curr->enter_time.hour, list->curr->enter_time.min, list->curr->exit_time.year, list->curr->exit_time.month, list->curr->exit_time.day,
			list->curr->exit_time.hour, list->curr->exit_time.min);

		list->curr = list->curr->next;
	}
	printf("%d:%s:%s:%.1lf:%s:%d.%d.%d.%d.%d:%d.%d.%d.%d.%d:\n", list->curr->roomno, list->curr->name, list->curr->phone,
		list->curr->price, list->curr->address, list->curr->enter_time.year, list->curr->enter_time.month, list->curr->enter_time.day,
		list->curr->enter_time.hour, list->curr->enter_time.min, list->curr->exit_time.year, list->curr->exit_time.month, list->curr->exit_time.day,
		list->curr->exit_time.hour, list->curr->exit_time.min);


}


//지금까지 사용한 리스트 데이터를 txt에 다시 넣어주고 파일 연결 해제(완료)
void exit_program(LIST* list)
{

	fclose(fp);
	fp = fopen("reservation.txt", "w");
	// 기존에 들어있는reservation.txt가 다 없어진다.   
	if (fp == NULL)   // 해당 화일이 없을 경우  
	{
		printf("can't open: reservation1.txt\n");
	}


	list->curr = list->head;
	do//list->numOfData로 바꿔도됨 대신 삽입,삭제에다 numOfData 증가,감소시키는 로직 추가해야됨
	{
		list->curr = list->curr->next;//출력 끝났으니 다음 노드로 이동
		//정해둔 양식에 맞춰서 메모장에 입력
		fprintf(fp, "%d:%s:%s:%lf:%s:%d.%d.%d.%d.%d:%d.%d.%d.%d.%d:\n", list->curr->roomno, list->curr->name, list->curr->phone,
			list->curr->price, list->curr->address, list->curr->enter_time.year, list->curr->enter_time.month, list->curr->enter_time.day,
			list->curr->enter_time.hour, list->curr->enter_time.min, list->curr->exit_time.year, list->curr->exit_time.month, list->curr->exit_time.day,
			list->curr->exit_time.hour, list->curr->exit_time.min);
		
	} while (list->curr->next != list->tail);
	fclose(fp);
}







#endif