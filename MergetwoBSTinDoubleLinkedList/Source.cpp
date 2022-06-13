#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "DoubleLinked.h"
#include "Binary.h"
void ReverseInorder(bnode_t* tree, node_t** List);
node_t* SearchandADD(node_t* hp1, LType data, int *flag)
{
	node_t* temp = hp1;
	
	while (temp->next != NULL && data>temp->next->data  )
	{
		temp = temp->next;
		*flag = 1;
	}
	return temp;
}
node_t* MergeBSTs(bnode_t* tree1, bnode_t* tree2)
{
	node_t* LinkedList1=getNode();
	node_t* LinkedList2=getNode();
	node_t* location = NULL;
	int flag = 0;
	ReverseInorder(tree1, &LinkedList1);
	node_t* temp = LinkedList1;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	
	}
	deleteAfter(temp);
	ReverseInorder(tree2, &LinkedList2);
	temp = LinkedList2;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
		
	}
	deleteAfter(temp);
	
	while (LinkedList1 != NULL && LinkedList2!=NULL)
	{
		location = SearchandADD(LinkedList1, LinkedList2->data, &flag);
		if (LinkedList2->data < LinkedList1->data)
		{
			LinkedList1 = addBeginning(LinkedList1, LinkedList2->data);
		}
		else
		{
			AddAfter(location, LinkedList2->data);

		}
		LinkedList2 = LinkedList2->next;
	}
	//merge tomorrow


	return LinkedList1;
}
void ReverseInorder(bnode_t* tree, node_t** List)
{
	if (tree != NULL)
	{
		ReverseInorder(tree->right, List);
		*List = addBeginning(*List, tree->data);
		ReverseInorder(tree->left, List);
	}

}
void PrintDoubly(node_t* hp)
{
	node_t* temp = hp;
	while (temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
	temp = hp;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp->prev != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->prev;
	}
	printf("NULL\n");
	
}
bnode_t* createTree()
{
	printf("Enter numbers to create Tree (-1 to stop): ");
	int number;
	scanf("%d", &number);
	bnode_t* tree= getBinaryNode(number);

	while (number != -1)
	{
		printf("Enter numbers to create Tree (-1 to stop): ");
		scanf("%d", &number);
		if (number != -1)
		{
			tree = insert(tree, number);
		}

	}
	return tree;

}
int main(void)
{
	bnode_t* tree1 = createTree();
	bnode_t* tree2 = createTree();

	node_t* doublyLinkedList=MergeBSTs(tree1, tree2);
	PrintDoubly(doublyLinkedList);
	return 0;
}