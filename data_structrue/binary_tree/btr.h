#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define getelem(p)	((p)->elem)

// we define 0:false 1:true
struct btreeNode;
typedef struct btreeNode *ptr;
typedef ptr Tree;
struct btreeNode {
	int elem;
	Tree left;
	Tree right;
};

Tree createTree(int e);
int IsEmpty(Tree T);
ptr find(Tree t,int e);
ptr findMax(Tree t);
ptr findMin(Tree t);
int IsLeaf(ptr pt);
int inserttr(Tree t,int e);
Tree deletet(Tree t, int e);
void showTree(Tree t,int depth);
void show(Tree t);
void shownode(Tree t);
ptr inserttree(Tree t, int e);
void printbtr(Tree t);




Tree createTree(int e) {
	Tree t;
	if( (t=malloc(sizeof(struct btreeNode)))==NULL) {
		fprintf(stderr,"malloc false\n");
		return NULL;
	}

	t->elem=e;
	t->left=NULL;
	t->right=NULL;
	return t;

}

void shownode(Tree t) {
	if(IsEmpty(t)) {
		fprintf(stderr,"empty t\n");
		return;
	}
	printf("e is %d\n",t->elem);
	return;
}
		

void show(Tree t) {
	printf("\nshow\n");
	showTree(t,0);
	return;
}

void showTree(Tree t,int depth) {
	//printf("show %d\n",depth);
	if(t==NULL) {
		fprintf(stderr,"empty tree\n");
		return;
	}

	int i;
	//printf("\n");
	for(i=0;i<depth;i++)
		printf("  ");
	printf("%d\n",t->elem);


	printf("|");

	if(t->left)
		showTree(t->left,depth+1);
	if(t->right)
		showTree(t->right,depth+1);
	return;

}

void printbtr(Tree t) {

	if(t!=NULL) {
		printbtr(t->left);
		printf("%d",t->elem);
		printbtr(t->right);
	}
}

int IsEmpty(Tree T) {

	return T==NULL;
}

int IsLeaf(ptr pt) {

	if(pt==NULL) {
		fprintf(stderr,"treenode is null\n");
		return 0;
	}
	if(pt->left||pt->right) 
		return 1;
	return 0;
}

ptr find(Tree t, int e) {

	if(t==NULL)
		return NULL;

	if(t->elem==e)
		return t;
	else if(t->elem>e) 
		return find(t->left,e);
	return find(t->right,e);
}

ptr findMax(Tree t) {
	
	if (t==NULL)
		return NULL;
	if (t->right==NULL) 
		return t;
	return findMax(t->right);

}

ptr findMin(Tree t){
	if (t==NULL)
		return NULL;

	while(t->right)
		t=t->right;
	return t;
}

int inserttr(Tree t, int e) {

	if(t==NULL) {
		Tree tmp;
		//tmp=createTree(e);
		tmp=malloc(sizeof(struct btreeNode));
		if(tmp==NULL) {
			fprintf(stderr,"insert error\n");
			return 0;
		}
		tmp->elem=e;
		tmp->left=tmp->right=NULL;
		*t=*tmp;
		printf("insert %d ok\n",e);
		return 1;
	}
	
	if(e < t->elem) 
		return inserttr(t->left,e);
	else if(e > t->elem)
		return inserttr(t->right,e);
	fprintf(stderr,"insert false\n");
	return 0;

}

ptr inserttree(Tree t, int e) {
	if (t==NULL) {
		if( (t=malloc(sizeof(struct btreeNode)))==NULL) {
			fprintf(stderr,"malloc false\n");
			return NULL;
		}
		t->elem=e;
		t->left=t->right=NULL;
	}
	else 
		if(e < t->elem) 
			t->left=inserttree(t->left,e);
		else if(e > t->elem)
			t->right=inserttree(t->right,e);
	return t;
}

Tree deletet(Tree t, int e) {
	Tree tmp;
	if(t==NULL)
		printf("no exit\n");
	else if (e < t->elem)
		t->left=deletet(t->left,e);
	else if(e > t->elem)
		t->right=deletet(t->right,e);
	/*
	else if(IsLeaf(t)){
		printf("delete node leaf\n");
		Tree tmp;
		tmp=t;
		t=NULL;
		free(tmp);
	}
	*/
	else if(t->right&&t->left) {
		printf("delete full node\n");
		Tree tmp;
		tmp=findMin(t->right);
		t->elem=tmp->elem;
		t->right=deletet(t->right,tmp->elem);
	} else {
		printf("delete one or zero child node\n");
		tmp=t;
		if(t->left==NULL) 
			t=t->right;
		else if(t->right==NULL)
			t=t->left;
		free(tmp);
	}
	printf("end delete\n");
	return t;
}

