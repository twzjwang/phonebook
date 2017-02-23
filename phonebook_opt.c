#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phonebook_opt_bst.h"

//search by bst
entry *findName(char lastName[], entry *pHead)
{
    entry *temp = pHead;
    int cmp;
    while (temp) {
        cmp = strcmp(lastName, temp->lastName);
        if (!cmp)
            return temp;
        temp = (cmp < 0) ? temp->pLeft : temp->pRight;
    }
    return NULL;
}

//recursively create balanced bst
entry *new_balance_bst(entry *root, int num, FILE *fp)
{
    if(!num)
        return NULL;

    //new tree root
    entry *bst_root = NULL;
    bst_root = balance_bst(bst_root, num, root, fp);
    return bst_root;
}

entry *balance_bst(entry *e, int num, entry *root, FILE *fp)
{
    //return if current node is leaf
    if(!num)
        return NULL;

    //malloc e if NULL
    if(!e) {
        e = (entry *) malloc(sizeof(entry));
        e->pRight = NULL;
        e->pLeft = NULL;
    }

    int mid = (num +1)/2;
    int i;
    char line[MAX_LAST_NAME_SIZE];

    //making link between *e and left child
    e->pLeft = balance_bst(e->pLeft, mid - 1, root, fp);

    //read file and copy
    if(fgets(line, sizeof(line), fp)) {
        i = 0;
        while (line[i] != '\0')
            i++;
        line[i - 1] = '\0';
        strcpy(e->lastName, line);
    }

    // making link between *e and right child
    e->pRight = balance_bst(e->pRight, num - mid, root, fp);

    return e;
}

//recursively free bst memory
void free_bst(entry *e)
{
    if (e) {
        free_bst(e->pRight);
        free_bst(e->pLeft);
        free(e);
    }
}
