#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

void print_node(const void *, VISIT, int);
struct node{
	char *name;
	int midtest;
	int finaltest;
};

char nametable[100];
struct node nodetable[50];
struct node *root=NULL;

int compare(const void *cp1, const void *cp2){
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

int main(int argc, char *argv[]){
	int stu=0;
	int index=0;

	char *nameptr=nametable;
	struct node *nodeptr=nodetable;
	struct node **ret;

	printf("학생 수 : ");
	scanf("%d", &stu);

	while(index!=stu){
		printf("학생명 : ");
		scanf("%s", nameptr);

		printf("중간고사 점수 : ");
		scanf("%d", &nodeptr->midtest);

		printf("기말고사 점수 : ");
		scanf("%d", &nodeptr->finaltest);

		nodeptr->name=nameptr;

		ret=(struct node **)tsearch((void *)nodeptr, (void **)&root, compare);

		printf(" %s ", (*ret)->name);

		if(*ret==nodeptr){
			printf("학생을 추가했습니다.\n");
			index++;
		}

		else{
			printf("이미 추가되어 있습니다.\n");
		}

		nameptr+=strlen(nameptr)+1;
		nodeptr++;
	}

	printf("\n결과\n");
	twalk((void *)root, print_node);
	return 0;
}

void print_node(const void *nodeptr, VISIT order, int lev){
	if(order==preorder || order==leaf){
		printf("이름 : %s\n중간고사 : %d\n기말고사 : %d\n",
		(*(struct node **)nodeptr)->name,
		(*(struct node **)nodeptr)->midtest,
		(*(struct node **)nodeptr)->finaltest);
	}
}


