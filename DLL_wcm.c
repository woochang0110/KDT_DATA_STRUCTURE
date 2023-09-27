#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

typedef struct Node{  //구조체 선언
    struct Node* prev;
    char data[50];
    struct Node* next;
}__NODE;

__NODE* head; //DLL 시작지점에 위치하는 구조체포인터
__NODE* tail;  //DLL 끝 지점에 위치하는 구조체포인터

//노드 생성 함수;


__NODE* makeNode(char* addr)
{
    __NODE* node = (__NODE*)malloc(sizeof(__NODE));
    node->prev = NULL;
    strcpy(node->data, addr);
    node->next = NULL;
    return node;
}

//head출력 함수
void printFromHead() {
     __NODE* current;
     current = head->next;
    while (current->next != tail) {
        printf("%s\n", current->data);
        current = current->next;
    }
    printf("%s\n", current->data);
}

//tail출력 함수
void printFromTail() {
    __NODE* current;
    current = tail->prev;
    while (current->prev != head) {
        printf("%s\n", current->data);
        current = current->prev;
    }
    printf("%s\n", current->data);
}


//초기화 함수
void init() {
    head = (__NODE*)malloc(sizeof(__NODE));
    tail = (__NODE*)malloc(sizeof(__NODE));

    head->prev = NULL;
    head->next = tail; 
    tail->prev = head;
    tail->next = NULL;
}

//tail부터 노드 추가하는 함수
void insertAtTail(char* addr) {
     __NODE* newnode = makeNode(addr);
     __NODE* current;
    current = tail;

    current->prev->next = newnode;
    newnode->prev = current->prev;
    current->prev = newnode;
    newnode->next = current;
    
}

//head부터 노드 추가하는 함수
void insertAtHead(char* addr) {
    __NODE* newnode;
    __NODE* current;
    newnode= makeNode(addr);
    current = head;
    current->next->prev = newnode;
    newnode->next = current->next;
    current->next = newnode;
    newnode->prev = current;
}

void removeNode(char *d){
    __NODE* current;
    current = head->next;
    while(current->next != tail){
        if(!(strcmp(current->data,d))){
            current->next->prev = current->prev;
            current->prev->next = current->next;
            free(current);
            return;
        }
        current = current->next;
    }
}

int selectAction(void) {

    int sel;                                                           //현재 노드 가리키는 포인터 하나 추가해서
    printf("enter num(1:주소 추가(앞) 2:주소 추가(뒤)  3:주소 삭제  4:프린트(앞) 5:프린트(뒤) 9:탈출) :");  //뒤로가기 앞으로가기 기능 추가 current = current->next나 prev
    scanf("%d", &sel);
    return sel;
}
void getAddr(char* addr, int flag) {    //flag (1: 삽입 0: 삭제)

    //현재 노드 가리키는 포인터 하나 추가해서
    if (flag) {
        printf("enter addr to insert: ");  //삽입
        scanf("%s", addr);
    }
    else
    {
        printf("enter addr to delete: ");  //삭제
        scanf("%s", addr);
    }

}


//main함수
int main() {
    init(); //head와 tail 초기화 (data = 0)
    int sel=0;
    char int_addr[50] = { 0 };

    while (1)
    {
        sel = selectAction();
        if (sel == 9) break;
        switch (sel)
        {
        case 1: getAddr(int_addr, 1); insertAtHead(int_addr); break;  //head에서 삽입
        case 2: getAddr(int_addr, 1); insertAtTail(int_addr); break;//tail에서 삽입
        case 3: getAddr(int_addr, 0); removeNode(int_addr); break;    //주소삭제
        case 4: printFromHead(); break;//head부터 프린트
        case 5: printFromTail(); break;//tail부터 프린트
        default: break;
        }
    }
    free(head);
    free(tail);
    return 0;
}
