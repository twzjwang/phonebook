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
        if (cmp == 0)
            return temp;
        else if (cmp < 0)
            temp = temp->pLeft;
        else
            temp = temp->pRight;
    }
    return NULL;
}

//orig append
entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    e->pRight = NULL;
    e->pLeft = NULL;

    return e;
}

entry *new_balance_bst(entry *root, int num)
{
    if(!num)
        return NULL;
    entry *bst_root = NULL;
    bst_root = balance_bst(bst_root, num, root);
    free(root);
    return bst_root;
}


entry *balance_bst(entry *e, int num, entry *root)
{
    static entry *bst_build_cur = NULL;
    if(!num)
        return NULL;
    if(!bst_build_cur)
        bst_build_cur = root;

    if(!e) {
        e = (entry *) malloc(sizeof(entry));
        e->pNext = NULL;
        e->pRight = NULL;
        e->pLeft = NULL;
    }

    int mid = (num +1)/2;
    e->pLeft = balance_bst(e->pLeft, mid - 1, root);
    strcpy(e->lastName, bst_build_cur->lastName);
    bst_build_cur = bst_build_cur->pNext;
    e->pRight = balance_bst(e->pRight, num - mid, root);
    return e;
}

void free_bst(entry *e)
{
    if (e) {
        free_bst(e->pRight);
        free_bst(e->pLeft);
        free(e);
    }
}
