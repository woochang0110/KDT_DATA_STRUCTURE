#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

struct NODE //구조체 선언
{
    struct NODE* llink;
    char data[50];
    struct NODE* rlink;
};
struct NODE* head;
struct NODE* tail;

//노드 생성 함수
struct NODE* makenode(char *d){
    struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
    node->llink = NULL;
    strcpy(newNode->data, d); 
    node->rlink = NULL;
    return node;
}

//출력 함수
void print(){
    struct NODE *p;
    p = head;
    while(p->rlink != tail){
        printf("%s-->",p->data);
        p = p->rlink;
    }
    printf("%d",p->data);
}

//초기화 함수
void init(){
    head = (struct NODE*)malloc(sizeof(struct NODE));
    tail = (struct NODE*)malloc(sizeof(struct NODE));
    head->data = 0;
    tail->data = 0;

    head->rlink = tail;
    head->llink = head;
    tail->rlink = tail;
    tail->llink = head;
}

//뒤로부터 노드 추가하는 함수
void push_back(int value){ 
    struct NODE* newnode = makenode(value);
    struct NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

//main함수
int main(){
    init(); //head와 tail 초기화 (data = 0)
    push_back(10); //10 추가
    push_back(30); //30 추가
    push_back(50); //50 추가
    print();  //출력
    return 0;
}
[출처] C로 배우는 자료구조 5) 이중 연결 리스트(+삽입, 삭제)|작성자 holy_joon


