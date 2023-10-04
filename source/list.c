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

t_NODE NODE[10];  // 임시로 정적 구조체로 구현
                  // 여러분은 double linked list로  
int input_check(int *col, char *buff);
int reservation_management(void);

int num=0;
int main(void)
{
	char input_buff[200];
	char price[20];
	int i;  // input_buff의 배열 index를 가리키는 변수 
	int j,c;  // 현재 토큰의 문자 수  
	 
	printf("Sequential file test program !!!!\n");
	
	fp = fopen("reservation.txt", "r");
	if (fp == NULL)   // 해당 화일이 없을 경우  
	{
		printf("can't open: reservation.txt\n"); 
		reservation_management();
		// 객실 관리 프로그램 을 돌린다.  
	}
	else   // 화일이 존재 하면 
	{
printf("file open: reservation.txt  OK !!!!!\n"); 
		// d:\temp\reservation.txt로 부터 1줄에 최대 100byte를 읽되
		// \n을 만날떄 까지 읽어서  input_buff에 넣는다. 
		// 화일의 마지막을 만나 면 (NULL) 
		// fgets가 return 받는것: 읽은 문자 수 
		while(fgets(input_buff,100,fp))  // 화일로  
		{
printf("input_buff:%s\n", input_buff);
			i=0;
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].roomno,input_buff,j);  // &input_buff[0] 
		
			i++;   // 이름이 들어 있는 첫번방의 index
			c=i;
			j=input_check(&i, &input_buff[i]);
			strncpy( (char *)&NODE[num].name,input_buff+c,j); 		

			i++;   // phone이 들어 있는 첫번방의 index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].phone,input_buff+c,j); 

			i++;   // price이 들어 있는 첫번방의 index
			c=i; 
			j=input_check(&i,&input_buff[i]); 
			strncpy(price,input_buff+c,j); 
			NODE[num].price = atoi(price);			
			
			i++;   // address이 들어 있는 첫번방의 index 
			c=i;
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].address,input_buff+c,j);

			i++;   // enter_date이 들어 있는 첫번방의 index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].enter_date,input_buff+c,j);
			
			i++;   // exit_date이 들어 있는 첫번방의 index
			c=i; 
			j=input_check(&i, &input_buff[i]); 
			strncpy( (char *)&NODE[num].exit_date,input_buff+c,j);	// input_buff+i ==> &input_buff[i] 
			
			num++;  // 다음 save할 NODE방의 index를 준비		
		}
printf("num:%d\n", num);
		//--------------------------
		// !!!!! 이곳에다 NODE구조체에 들어 있는 정보를
		// double linked list로 집어 넣는 프로그램을 구현 한다
		//  
		reservation_management();
		

		printf("프로그램이 종료 되었습니다 !!!!!\n"); 
/*
------------------ < 객실 관리 >----------------------
   1. 입력(예약)
   2. 삭제(퇴실)
   3. 수정(예약내역수정)
   4. 조회(개별조회)
   5. 전체조회(예약자 전쳬조회)

   9. 종료

 Select:  1

*/
		// ---- test를 위해서 NODE에 들어 있는
		// 9 번 종료 버튼을 누르면 아래의 프로그램이 동작 되도록 한다. 
		// 정보를 reversation.txt에 write하는 프로그램을 작성 
		// 해 보겠다.  
	}
	return 0;  // 0를resturn 하는 이유는 no error 
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
			case '1':  // 입력
				printf("입력(예약)을 선택 했습니다.\n");
				// input();	
				break; 
			case '2':  // 삭제(퇴실)
				printf("삭제(퇴실)을 선택 했습니다.\n");
				// delete();
				break; 		
					
			case '3':  // 수정 
				printf("수정을 선택 했습니다.\n");
				// modify();
				break; 	
					
			case '4':  // 조회(개별조회)\n
				printf("조회(개별조회)를 선택 했습니다.\n");
				// one_person_display();
			    break; 
			
			case '5':  // 전체조회(예약자 전체조회)
				printf("전체조회(예약자 전체조회)를 선택 했습니다.\n");
				// all_display();
				break; 
			case '9':  // 종료 
				exit_program();
				printf("프로그램이 종료 되었습니다.  !!!!\n");
				return; 			
		} 
	}
}
void exit_program()
{
		int i;
		
		fclose(fp);  
		fp = fopen("reservation.txt", "w");
		// 기존에 들어있는reservation.txt가 다 없어진다.   
		if (fp == NULL)   // 해당 화일이 없을 경우  
		{
			printf("can't open: reservation1.txt\n"); 
		}
		
		for (i=0; i < num; i++)  // node에 들어있느 갯수 만큼 loop 
		{
			// 여러분들은 linked list에 있는 node정보를 아래와 같이 출력 하도록 해야 한다.  
			fprintf(fp, "%s:%s:%s:%d:%s:%s:%s:\n",NODE[i].roomno,NODE[i].name,
			NODE[i].phone,NODE[i].price,NODE[i].address,NODE[i].enter_date,NODE[i].exit_date); 
		} 
		fclose(fp);  //  fclose: 현재 프로그램과 화일의 연결고리를 끊는 작업이다. 
		            // 마치 전화 통화를 자 한후 전화를끊는것과 같다. 
}
char menu[10][50] = {
"------------------ < 객실 관리 >----------------------",
"   1. 입력(예약)",
"   2. 삭제(퇴실)",
"   3. 수정(예약내역수정)",
"   4. 조회(개별조회)",
"   5. 전체조회(예약자 전체조회)",
" ",
"   9. 종료"
};
void menu_display()
{
	int i;
	
	for (i=0; i < 8; i++)
		printf("%s\n", menu[i]);
}
//301:홍길동:010-3355-1111:200000:경기 용인:2023-11-20:1800:2023-11-24 18.00:
// 현재 col: 4 
int input_check(int *col, char *buff)
{
	int i,j;
	
	char *p = buff;   // buff의 주소가 p에 들어 간다. 
	i = *col;  // 토큰의 시작위치 의 내용을 가져온다. 
	j=0;   // 토큰의 길이를 count 
	while(*p++ != ':')   // 1) *p != ':'  2)p++
	{
		i++;   // 해당되는 필드의 위치 byte를 count 
		j++;   // 토큰의 문자수 
	}
	*col = i;   // :이 들어 있는 index 
	           // 해당되는 필드의 byte수 col에 저장
	return j;  // 토큰의 문자수 
} 


