/*
★ 실행 후 text가 너무 많아서 화면 가득한 경우
실행화면 우클릭 - Layout - Font, Width 크기 조절
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define SPACING 30

int compare(const Item first, const Item second) {
	return strcmp(first.character, second.character);
}

void print_item(Item item) {
	printf("%s (%s)\n", item.character, item.name);
}

// https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// 화면에 tree를 그럴 듯하게 그려주는 함수
void print2DUtil(Node* root, int space) {

	// Increase distance between levels
	space += SPACING;

	if (root == NULL) {
		for (int i = SPACING; i < space; i++)
			printf(" ");
		printf("NULL");
		return;
	}

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = SPACING; i < space; i++)
		printf(" ");
	print_item(root->item);

	// Process left child
	print2DUtil(root->left, space);
}

void print_node(Node* root, int level) {

	if (root == NULL)
		return;

	printf("level : %d\t", level);
	printf("%s (%s) -> ", root->item.character, root->item.name);

	if (root->left == NULL)
		printf("NULL, ");
	else
		printf("%s (%s), ", root->left->item.character, root->left->item.name);

	if (root->right == NULL)
		printf("NULL");
	else
		printf("%s (%s)", root->right->item.character, root->right->item.name);

	printf("\n");

	print_node(root->left, level + 1);
	print_node(root->right, level + 1);

}

void print_tree(Tree* ptree) {
	
	printf("\n------------------------\n");

	Traverse(ptree, print_item);

	printf("\n------------------------\n");

	print2DUtil(ptree->root, 0);

	printf("\n------------------------\n");

	print_node(ptree->root, 0);
}

int main() {

	// Assume that there is no duplicated items

	Item items[] = {
		{"Iron Man", "Tony Stark"},
		{"Thor", "Thor Odinson"},
		{"Ant-Man", "Hank Pym"},
		{"Wasp", "Janet van Dyne"},
		{"Hulk", "Bruce Banner"},
		{"Captain America", "Steve Rogers"},
		{"Scarlet Witch", "Wanda Maximoff"},
		{"Black Widow", "Natasha Romanoff"},
		{"Dr. Strange", "Stephen Strange"},
		{"Daredevil", "Metthew Murdock"},
		{"Punisher", "Frank Castle"},
		{"Batman", "Bruce Wayne"}
	};

	int n = sizeof(items) / sizeof(items[0]);

	Tree tree;
	// compare 함수의 포인터를 받음
	InitializeTree(&tree, &compare);

	for (int i = 0; i < n; ++i)
		AddItem(&items[i], &tree);

	// Try to add duplicated item
	AddItem(&items[2], &tree);
	print_tree(&tree);

	// Searching Test
	Item key = { "Punisher", "" };
	Item* result = TreeSearch(&tree, key);
	if (result == NULL)
		printf("\nSearch failed.\n");
	else
		printf("\n%s is the %s\n", result->name, result->character);

	/*
	Deleting Tests
	★ child 두 개를 가지고 있는 node 삭제 시)
	삭제 노드의 left child의 right child가 NULL 값이 나올 때까지
	left child의 right child를 타고 내려감
	-> NULL인 경우, 해당 자리에 삭제 노드의 right child subtree를 붙임
	*/ 
	{
		Item key = { "Iron Man", "" };
		DeleteItem(&key, &tree);
		print_tree(&tree);
	}

	return 0;
}
