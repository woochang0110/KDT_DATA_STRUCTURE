#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct __node
{
    int value;
    struct __node *next;
    struct __node *prev;
}Node;

void insertNode(Node* head, int value); // 미구현

Node* getNode(Node* ptr);
void showList(Node* ptr);
int getRandomInt(int from, int to);
void appendFirst(Node* ptr, int data);
void append(Node* ptr, int data);
void deleteList(Node* ptr);
Node* getLastNode(Node* ptr);

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    Node* head = NULL;
    head = getNode(head);

    for (int i = 0; i < 5; i++)
    {
        appendFirst(head, getRandomInt(1, 100));
    }

    showList(head);

    append(head, 999);
    append(head, 777);
    append(head, 222);

    showList(head);

    printf("Last Node Value: %d\n", getLastNode(head)->value);


    showList(head);

    deleteList(head);

    return 0;
}


/* ---------- 함수영역 ---------- */


Node* getLastNode(Node* ptr)
{
    if (ptr == NULL){
        return ptr;
    } else{    
        Node *cur = ptr;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        return cur;
    }
}

void deleteList(Node *ptr){
    Node *cur = ptr;
    Node *next;
    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    printf("-> List deleted...\n");  
}


void append(Node* ptr, int data)
{
    // 새로운 노드
    Node* newNode = malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->value = data;

    if (ptr->next == NULL)
    {
        printf("This is the first node after head\n");
        // 첫번째 노드 연결
        newNode->prev = ptr;
        newNode->next = NULL;

        // 맨앞쪽에 추가, head 의 바로 다음 노드
        ptr->next = newNode;
        // head는 사용안함(명시)
        ptr->value = 0;
        ptr->prev = NULL;
        printf("-> value added(last)... (%d)\n", newNode->value);
    }
    // 노드에 요소가 있는 경우 
    else
    {
        Node* cur = ptr;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        newNode->prev = cur;
        printf("-> value added(last)... (%d)\n", newNode->value);
    }
    
}

void showList(Node* head)
{
    printf("[Showing Doubly List]\n");

    if(head == NULL){
        printf("no element found..\n");
    }
    else
    {
        printf("[");
        Node* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
            if(cur->next == NULL){
                printf("%2d ", cur->value);
            }else{
                printf("%2d, ", cur->value);
            }
        }
        printf("]\n");
    }
}

void appendFirst(Node* head, int data)
{
    //새로운 노드 생성
    Node* newNode = malloc(sizeof(Node));
    newNode->value = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head->next == NULL)
    {
        printf("This is the first node after head\n");
        // 첫번째 노드 연결
        newNode->prev = head;
        newNode->next = NULL;

        // 맨앞쪽에 추가, head 의 바로 다음 노드
        head->next = newNode;
        // head는 사용안함(명시)
        head->value = 0;
        head->prev = NULL;
        printf("-> value added(first)... (%d)\n", newNode->value);
    }
    // 노드에 요소가 있는 경우
    else 
    {
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        printf("-> value added(first)... (%d)\n", newNode->value);
    }
}

Node* getNode(Node* ptr)
{
    if(ptr == NULL)
    {
        ptr = malloc(sizeof(Node));
        ptr->value = 0;
        ptr->next = NULL;
        ptr->prev = NULL;
        printf("node created..\n");
        return ptr;
    }
    printf("node creation failed..");
}

int getRandomInt(int from, int to)
{
    int random = rand() % (to-from+1) + from;
    return random;
}
