// 단순연결리스트 (5~6주차)
// 추가 수정 필요 -> search, remove + 원형연결리스트

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결리스트의 노드를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;

// 공백 연결리스트 생성
linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	// malloc : 메모리 공간 확보
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

// 단순 연결리스트 삽입 : 첫 번째 노드로 삽입
void insertFirstNode(linkedList_h* L, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// 단순 연결리스트 삽입 : pre 뒤 중간 노드로 삽입
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	strcpy(newNode->data, x);

	if (L == NULL) {
		// 공백리스트의 경우
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL) {
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 단순 연결리스트 삽입 : 마지막 노드로 삽입
void insertLastNode(linkedList_h* L, char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	newNode->link = NULL;

	// 현재 리스트가 공백 리스트인 경우
	// 새 노드를 시작 노드로 설정
	if (L->head == NULL) {
		L->head = newNode;
		return;
	}

	temp = L->head;
	// 마지막 노드(link가 NULL값인 노드)를 찾으면 while문 종료
	while (temp->link != NULL) temp = temp->link;

	// 마지막 노드 링크 필드에 새 노드 new 주소 저장
	temp->link = newNode;
}

// 단순 연결리스트 역순 변경
void reverse(linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	// 포인터 p를 첫 번째 노드에 설정
	p = L->head;
	q = NULL;
	r = NULL;

	// 첫 번째 노드부터 시작해서 노드 간 연결 바꿈
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

// 단순 연결리스트 순서대로 출력
void printList(linkedList_h* L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s  ", p->data);
		p = p->link;
	}
	printf(") \n");
}

// 단순 연결리스트 탐색
listNode* searchNode(linkedList_h* L, char* x) {
	listNode* temp;
	temp = L->head;

	while (temp != NULL) {
		if (temp->data == x) return temp;
		else temp = temp->link;
	}
	return NULL;
}

// 단순 연결리스트 삭제
// pre가 가리키는 노드의 다음 노드
void deleteNode(linkedList_h* L, listNode* pre) {
	listNode* old;

	// 공백 리스트의 경우
	if (L->head == NULL) return;

	// 공백 리스트가 아닌 경우
	else {
		old = pre->link;

		// pre 다음 노드가 없는 경우
		if (old == NULL) return;

		pre->link = old->link;
	}
}

int main() {
	linkedList_h* L;
	L = createLinkedList_h();

	printf("============= 공백리스트 생성 ============= \n");
	printList(L);

	printf("============= 리스트 첫 노드 삽입 ============= \n");
	insertFirstNode(L, "화");
	printList(L);

	insertFirstNode(L, "월");
	printList(L);

	printf("============= 리스트 마지막 노드 삽입 ============= \n");
	insertLastNode(L, "토");
	printList(L);

	insertLastNode(L, "일");
	printList(L);

	printf("============= 리스트 중간 노드 삽입 ============= \n");

	// "화" 뒤에 "수" 삽입
	insertMiddleNode(L, searchNode(L, "화"), "수");
	printList(L);

	printf("============= 리스트 노드 삭제 ============= \n");
	//deleteNode(L, searchNode(L, "화"));
	//printList(L);


	return 0;
}

