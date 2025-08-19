/* A study of structs                               */
/* This program parses a file, counts the words,    */
/* and prints [count]: [word] in alphabetical order */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

char *getword(FILE *);
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
void treefree(struct tnode *);

int main(int argc, char *argv[]){
	FILE *fptr;
	char *word;
	struct tnode *root;

	root = NULL;

	fptr = fopen(argv[argc-1], "r");

	if(!fptr){
		printf("error opening file\n");
		exit(1);
	}

	while ((word = getword(fptr)) != NULL){
		root = addtree(root, word);
	}
	treeprint(root);
	treefree(root);

	fclose(fptr);
}

struct tnode *addtree(struct tnode *p, char *w){
	int cond;

	if (p == NULL){
		p = (struct tnode *) malloc(sizeof(struct tnode));
		if(p == NULL){
			printf("error allocating memory in addtree func\n");
			exit(1);
		}
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}else if((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if(cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

void treefree(struct tnode *p){
	if(p != NULL){
		treefree(p->left);
		treefree(p->right);
		free(p->word);
		free(p);
	}
}

char *getword(FILE *fptr){
	int c;
	char *word = (char *) malloc(20);
	char *w = word;
	
	while ((c = fgetc(fptr)) != EOF && isspace(c))
		;

	if (c == EOF)
		return NULL;

	*w++ = c;

	while(isalpha(c = fgetc(fptr)))
		*w++ = c;

	*w = '\0';
	return word;
}
