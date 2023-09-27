// 이중연결리스트 응용코드 <성적표>
         
#if 1
// 이중 연결리스트
// 생성 순서로 연결 리스트에 보관
// 입력 오류에 관한 예외 처리 없음

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>

#define NAME_NUM    10             // 학생 이름 
#define SUBJECT_NUM 3             // 과목 갯수

typedef struct Student             // 구조체 정의
{          
    char name[NAME_NUM + 1];      // 이름
    int num;                   // 학생 번호
    int scores[SUBJECT_NUM];      // 국어 수학 영어 성적
    struct Student *next;
    struct Student *prev;
}Student;

const char *stitles[SUBJECT_NUM] = { "국어","수학","영어" };      // 과목  

Student *head, *tail;

void Initialize();               // 초기화
void Run();                     // 실행 
void Exit();                  // 종료하기 전에 할당한 메모리 해제

int main(void)
{
    Initialize();               // 초기화
    Run();                     // 실행 
    Exit();                     // 종료하기 전에 할당한 메모리 해제
    return 0;
}

void Initialize()                           // 초기화 
{
    head = (Student *)malloc(sizeof(Student));      // 더미 노드 생성
    tail = (Student *)malloc(sizeof(Student));      // 더미 노드 생성
    head->next = tail;                        // 맨 앞 더미노드 next를 tail로 설정
    tail->prev = head;                        // 맨 뒤 더미노드 prev를 head로 설정
    head->prev = tail->next = NULL;
}

int SelectMenu();                           // 메뉴 선택
void AddStudent();                           // 학생 성적 입력
void RemoveStudent();                        // 학생 성적 삭제
void FindStudent();                           // 학생 성적 검색
void ListStudent();                           // 성적표 리스트  보기

void Run()                                 // 실행 
{
    int key = 0;
    while ((key = SelectMenu()) != 0)            // 선택한 메뉴가 0이 아니면 반복
    {
        switch (key)                        // 선택한 key에 따라 기능 수행
        {
        case 1: AddStudent(); break;            // 학생 성적 입력 
        case 2: RemoveStudent(); break;            // 학생 성적 삭제 
        case 3: FindStudent(); break;            // 학생 성적 검색 
        case 4: ListStudent(); break;            // 성적표 리스트 보기 
        default: printf("잘못 선택하였습니다.\n"); break;
        }
    }
    printf("프로그램 종료\n");
}

int SelectMenu()                           // 메뉴 선택 
{
    int key = 0;
      
      int i;
   char *n[] = 
   {
       "<성적표> 모드 선택\n",
      "1. 학생 성적 입력\n",
      "2. 학생 성적 삭제\n",
      "3. 학생 성적 검색\n",
      "4. 성적 리스트 보기\n",
      "0. 종료\n"
   };
   for (i=0; i < 6; i++)
        printf("%s", n[i]); 
   
//    printf("<성적표> (종료 : 0)\n");
//    printf("메뉴 입력(1:학생 성적 입력 2:학생 성적 삭제 3:학생 성적 검색 4:성적 리스트 보기) : \n");
    scanf_s("%d", &key);
    return key;
}

int IsAvailNum(int num);                     // 유효한 학생 번호인지 판별
int IsAvailScore(int score);                  // 유효한 성적인지 판별

void AddStudent()                           // 학생 성적 추가 
{
    int num = 0;
    Student *stu = 0;
    int s = 0;

    printf("추가할 학생 번호: ");
    scanf_s("%d", &num);

    stu = (Student *)malloc(sizeof(Student));      // student 구조체 동적 메모리 할당    
    stu->num = num;
    printf("이름: ");
    scanf_s("%s", stu->name, sizeof(stu->name));

    for (s = 0; s<SUBJECT_NUM; s++)
    {
        printf("%s 성적:", stitles[s]);
        scanf_s("%d", stu->scores + s);

        if (IsAvailScore(stu->scores[s]) == 0)      // 유효한 성적이 아닐 때
        {
            stu->scores[s] = -1;
            printf("입력한 값이 유효하지 않습니다.\n");
        }
    }

    //새로 생성한 노드를 tail 앞에 매달기
    stu->next = tail;
    stu->prev = tail->prev;
    tail->prev->next = stu;
    tail->prev = stu;
}

int IsAvailScore(int score)                       
{
    return (score >= 0) && (score <= 100);         // 입력 가능한 성적 범위
}

void RemoveStudent()                        // 학생 성적 삭제 
{
    int num;
    Student *seek;
    printf("삭제할 학생 번호: ");
    scanf_s("%d", &num);

    for (seek = head->next; seek != tail; seek = seek->next)
    {
        if (seek->num == num)
        {
            //연결리스트에서 링크 조절
            seek->prev->next = seek->next;
            seek->next->prev = seek->prev;
            free(seek);                        // 메모리 해제
            printf("삭제하였습니다.\n");
            return;
        }
    }
    printf("데이터가 없습니다.\n");
}

void ViewStuData(Student *stu);

void FindStudent()                           // 학생 성적 검색 
{
    int num = 0;
    Student *seek = 0;
    printf("검색할 학생 번호: ");
    scanf_s("%d", &num);

    for (seek = head->next; seek != tail; seek = seek->next)
    {
        if (seek->num == num)
        {
            ViewStuData(seek);
            return;
        }
    }
    printf("데이터가 없습니다.\n");
}

void ViewStuData(Student *stu)                  // 검색 성적 출력 
{
    int i = 0;
    int s = 0;

    printf("%4d %10s ", stu->num, stu->name);
    for (s = 0; s<SUBJECT_NUM; s++)
    {   
        printf("%4d ", stu->scores[s]);
    }
    printf("\n");
}

void ListStudent()                           // 성적표 리스트 
{
    int s = 0;
    Student *seek = 0;

//  printf("%4s %10s %4s %4s %4s", "번호", "이름", "국어", "수학", "영어");
//   printf("(성적 미입력은 -1로 표시됨.)\n");

   printf("%4s %10s ", "번호", "이름");   
    for (s = 0; s<SUBJECT_NUM; s++)
    {
        printf("%4s ", stitles[s]);
    }
   printf("(성적 미입력은 -1로 표시됨.)\n");   

    for (seek = head->next; seek != tail; seek = seek->next)
    {
        ViewStuData(seek);
    }
    
}
void Exit()
{
    Student *seek = head;

    while (seek->next)
    {
        seek = seek->next;
        free(seek->prev);
    }
    free(seek);
}

#endif

