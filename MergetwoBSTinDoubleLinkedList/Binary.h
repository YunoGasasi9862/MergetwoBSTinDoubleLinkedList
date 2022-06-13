#pragma once
typedef int BType;
typedef struct bnode_s
{
	BType data;
	bnode_s* right;
	bnode_s* left;

}bnode_t;

bnode_t* getBinaryNode(BType data)
{
	bnode_t* root;
	root = (bnode_t*)malloc(sizeof(bnode_t));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;

}
bnode_t* insert(bnode_t* root, BType data) //DONT FORGET THIS NOW BILAL!!!!!
{
	if (root == NULL) //IF THE ROOT IS NULL CREATE A NODE!!!!
	{
		return getBinaryNode(data); //if the root has reached either left dead end, or right dead end, or then create a fucking NODE THERE!
	}
	else
	{

		if (data > root->data)
		{
			root->right = insert(root->right, data); //this is recursion, that is move to the right node, and then check if its null, then add a node there with the help of if(root==NULL) statment!!

		}
		else if (data < root->data) //DONT FORGET THIS CODE NOW
		{

			root->left = insert(root->left, data); //using freaking recursion!!
		}


	}

	return root; 
}