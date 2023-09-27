#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACK_SIZE 20
#define NUM_SIZE 5

int calc(int n1, char *op, int n2) {
   if (strcmp(op, "+") == 0) {
      return n1 + n2;
   }
   if (strcmp(op, "-") == 0) {
      return n1 - n2;
   }
   if (strcmp(op, "*") == 0) {
      return n1 * n2;
   }
   if (strcmp(op, "/") == 0) {
      return n1 / n2;
   }
   
   printf("계산 오류 %d %s %d\n", n1, op, n2);
   return 0;
}

int main()
{

   char stack[STACK_SIZE][NUM_SIZE];
   char input[NUM_SIZE];
   
   int i = -1;
   
   printf("수식 입력: \n"); 
   while(1) {
      scanf("%s", input);
       
      if (strcmp(input, "=") == 0) {
         break;
      }
      else if (i == -1) {
         i++;
         strcpy(stack[i], input);
      }
      else if ((strcmp(stack[i], "*") == 0) || (strcmp(stack[i], "/") == 0)) {
         int n2 = atoi(input);
         char *op = stack[i];
         i--;
         int n1 = atoi(stack[i]);
         int res = calc(n1, op, n2);
         itoa(res, stack[i], 10);
      }
      else {
         i++;
         strcpy(stack[i], input);
      }
      
      printf("%d: ",i);
      int j = 0;
      for(j=0; j <= i; j++)
       {
           printf("%s ", stack[j]);
       }
       printf("\n");
      
   }
   
   int res = atoi(stack[i]);
   int j = i - 1;
   while (j >= 0) {
      char *op = stack[j];
      j--;
      int n1 = atoi(stack[j]);
      j--;
      res = calc(n1, op, res);
   }
   
   printf("결과: %d\n", res);
   
   
   return 0;
}
