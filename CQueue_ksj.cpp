// circular queue

#include <stdio.h>
#include <string.h>

#define SIZE 20
#define NAME_LEN   40

void show_menu(void);

int main() 
{
   char input[NAME_LEN];
   char queue[SIZE][NAME_LEN];
   
   int front = 0;
   int rear = 0;
   
   int choice;
   
   while(1) {
      show_menu();
      
        printf("선택: ");  
        scanf("%d", &choice);
        printf("\n");
       
       if (choice == 1) {

          if ((rear + 1) % SIZE == front) {
             printf("대기열이 다찼습니다.\n");
         }
         else {
             printf("이름 입력: "); 
//            fgets(input, NAME_LEN, stdin);
            scanf("%s", input);
            
            strcpy(queue[rear], input);
            rear++;
            rear %= SIZE;
            
            printf("현재 대기 번호: %d\n", (rear - front)%SIZE); 
         }
      }
      else if (choice == 2) {
         if (front == rear) {
            printf("대기열이 비었습니다.\n");
         }
         else {
            char pop_value[40];
            strcpy(pop_value, queue[front]);
            front++;
            front %= SIZE;
            
            printf("입장 손님: %s\n", pop_value);
         }
      }
      else if (choice == 3) {
         printf("조회할 이름 입력: "); 
//         fgets(input, 40, stdin);
         scanf("%s", input);
         
         int i = front; 
         while (i != rear) {
            if (strcmp(input, queue[i]) == 0) {
               printf("현재 대기 번호: %d\n", (i - front)%SIZE+1); 
               break; 
            }
            i++;
            i %= SIZE;
         }
         
         
         
      } 
      else if (choice == 4) {
         int i = front; 
         printf("대기열: \n");
         while (i != rear) {
            printf("%d. %s\n", (i - front)%SIZE+1, queue[i]);
            i++;
            i %= SIZE;
         }
      } 
      else if (choice == 0) {
         break;
      }
      else {
         printf("유효하지 않은 선택 입니다.\n");
      }
      
      
      printf("\n\n"); 
   }
   
   return 0;
}


void show_menu(void)
{
    int i;
   
    char *m[] =
    {
     "-----Menu------\n",
     "1. 대기열 추가\n",
     "2. 다음 손님 입장\n",
     "3. 순서 조회\n",
     "4. 전체 대기열 출력\n",
     "0. 종    료\n"  
     "----------------------\n"      
    };

    for (i=0; i < 6; i++)
        printf("%s", m[i]);
}
