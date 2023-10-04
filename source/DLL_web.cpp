#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

struct NODE //����ü ����
{
    struct NODE* llink;
    char data[50];
    struct NODE* rlink;
};
struct NODE* head;
struct NODE* tail;

//��� ���� �Լ�
struct NODE* makenode(char *d){
    struct NODE *node = (struct NODE*)malloc(sizeof(struct NODE));
    node->llink = NULL;
    strcpy(newNode->data, d); 
    node->rlink = NULL;
    return node;
}

//��� �Լ�
void print(){
    struct NODE *p;
    p = head;
    while(p->rlink != tail){
        printf("%s-->",p->data);
        p = p->rlink;
    }
    printf("%d",p->data);
}

//�ʱ�ȭ �Լ�
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

//�ڷκ��� ��� �߰��ϴ� �Լ�
void push_back(int value){ 
    struct NODE* newnode = makenode(value);
    struct NODE* p;
    p = tail;
    p->llink->rlink = newnode;
    newnode->llink = p->llink;
    p->llink = newnode;
    newnode->rlink = p;
}

//main�Լ�
int main(){
    init(); //head�� tail �ʱ�ȭ (data = 0)
    push_back(10); //10 �߰�
    push_back(30); //30 �߰�
    push_back(50); //50 �߰�
    print();  //���
    return 0;
}
[��ó] C�� ���� �ڷᱸ�� 5) ���� ���� ����Ʈ(+����, ����)|�ۼ��� holy_joon


