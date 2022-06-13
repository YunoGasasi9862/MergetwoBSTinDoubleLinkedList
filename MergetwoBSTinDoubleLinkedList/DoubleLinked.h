#pragma once
typedef int LType;
typedef struct node_s
{
	LType data;
	node_s* next;
	node_s* prev;

}node_t;

node_t* getNode(void)
{
	node_t* hp;
	hp = (node_t*)malloc(sizeof(node_t));
	hp->next = NULL;
	hp->prev = NULL;
	return hp;


}

node_t* addBeginning(node_t* hp, LType data)
{
	node_t* tp;
	tp = getNode();
	tp->data = data;
	tp->next = hp;
	hp->prev = tp;
	return tp;
}

void AddAfter(node_t* hp, LType data)
{

	node_t* tp;
	tp = getNode();
	tp->data = data;
	tp->next = hp->next;
	tp->prev = hp;
	hp->next = tp;
	if (tp->next != NULL) //this also solves the other problem, both way binary TREES ARE WORKING NOW YEEHAW!!
	{
		tp->next->prev = tp;
	}
	 //THIS LINE IS SO IMPORTANT FOR CONNECTING THE NODES
	//since im deadling with two binary trees their previous would be different.
	//When adding a new node in between, this solves the problem -> connects the next->prev with tp!
}
void deleteAfter(node_t* hp)
{
	node_t* temp;
	temp = hp->next;
	hp->next = temp->next;
	free(temp);
}