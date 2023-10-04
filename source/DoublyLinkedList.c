#if 1

//새로운 웹페이지가 열리면 이중연결리스트 제일 앞에다 저장
//출력은 head가 가리키고 있는 제일 앞부터 출력(즉 제일 최근 값부터 출력한다는 뜻)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)


// Define the structure for a node in the doubly linked list
typedef struct __Node {
    char data[50];
    struct __Node* next;
    struct __Node* prev;
}__Node;

// Function to create a new node
__Node * createNode(char *data) {
    // Allocate memory for a new node
    __Node* newNode = (struct __Node*)malloc(sizeof(struct __Node));
    // Initialize node data, next, and prev pointers
    strcpy(newNode->data, data);   //입력 들어오는 문자열 생성한 노드에 입력
    newNode->next = NULL;
    newNode->prev = NULL;
    // Return the newly created node
    return newNode;
}

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct __Node** head, char *data,__Node** cur) {
    // Create a new node with the given data
    __Node* newNode = createNode(data);
    // 리스트가 비어있을때 헤드가 새로운 노드를 가리킴
    if (*head == NULL) {
        *head = newNode;
        *cur = newNode;	//현재 위치 
    }
    else {
        // Adjust pointers to insert the new node at the beginning
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        *cur = newNode;  //현재 위치
    }
}


// 이 프로그램에서는 앞에
/*
// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);
    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        // Traverse to the end of the list to insert the new node
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}
*/
// Function to delete a node with a given value from the list
void deleteNode(__Node** head, char *data,__Node **cur) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    // Start with the first node
    __Node* current = *head;

    // If the node to be deleted is the first node
    if (!(strcmp(current->data, data))) {	//삭제하고자 하는 데이터와 현재 가리키고 있는 데이터가 같다면 포인터 리셋 후 free 
        // Update the head pointer and free the node
        *head = current->next;
        *cur = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    // Search for the node with the given data
    while (current != NULL && !(strcmp(current->data , data))) {
        current = current->next;	
    }

    // If the node was not found
    if (current == NULL) {
        printf("Node with data %s not found in the list.\n", data);
        return;
    }

    // Adjust the pointers to remove the node
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    // Free the memory occupied by the node
    free(current);
}

// Function to print the doubly linked list
void printList(__Node* head,__Node *cur) {	//cur은 현재 서핑중인 웹사이트 
    // Start with the head of the list
    __Node *current = head;	//list 프린트를 위해 선언 
    int i=0;
    // Print the elements of the list in both directions
    printf("\n현재 웹주소: %s \n", cur->data);
    while (current != NULL) {
        printf("%d번 웹주소:%s \n",i++, current->data);
        current = current->next;//시작부터 끝까지
    }
    //printf("NULL\n");//어차피 마지막은 NULL 
}

void moveCurNodeNext(__Node **cur){
	if(*cur==NULL) {
		printf("NULL\n");
	}
	else if ((*cur)->next != NULL) {
            *cur = (*cur)->next;
            printf("cur 이전 노드이동\n");
        }
}
void moveCurNodePrev(__Node **cur){
	if(*cur==NULL) {
		printf("NULL\n");
	}
	if ((*cur)->next != NULL) {
            *cur = (*cur)->prev;
            printf("cur 다음 노드이동\n");
    }
}

int selectAction(void) {

    int sel;                                                           //현재 노드 가리키는 포인터 하나 추가해서
    printf("enter num(1:주소 추가 2: 주소 삭제 3: 프린트 4:뒤로이동 5:앞으로이동 9:탈출) :");  //뒤로가기 앞으로가기 기능 추가 current = current->next나 prev
    scanf("%d", &sel);
    return sel;
}
void getAddr(char *addr,int flag) {
                                
                      //현재 노드 가리키는 포인터 하나 추가해서
    if (flag) {
        printf("enter addr to insert: ");  //뒤로가기 앞으로가기 기능 추가 current = current->next나 prev
        scanf("%s", addr);
    }
    else
    {
        printf("enter addr to delete: ");  //뒤로가기 앞으로가기 기능 추가 current = current->next나 prev
        scanf("%s", addr);
    }

}



int main() {
    // Initialize the head of the list as NULL
    __Node *head = NULL;
    int sel;
    char addr[50];
	__Node *cur = head;
	
    while (1)
    {
        sel = selectAction();
        if (sel == 9) break;
        switch (sel)
        {
        case 1: getAddr(addr, 1); insertAtBeginning(&head, addr,&cur); break;
        case 2: getAddr(addr, 0); deleteNode(&head, addr,&cur); break;
        case 3: printList(head,cur); break;
        case 4: moveCurNodeNext(&cur); break;
		case 5: moveCurNodePrev(&cur); break;
        default: break;
        }
    }

    // Insert nodes at the end and beginning
    /*
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    
    insertAtBeginning(&head, 0);

    // Print the list
    printList(head);

    // Delete a node from the list
    deleteNode(&head, 2);

    // Print the modified list
    printList(head);

    // Delete a node that does not exist in the list
    deleteNode(&head, 0);

    // Print the modified list
    printList(head);

    // Delete a node from an empty list
    deleteNode(&head, 4);
    */




    return 0;
}


#endif

