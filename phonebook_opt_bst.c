#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "phonebook_opt_bst.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *pHead)
{
    entry *temp = pHead;
    int cmp;
    while (temp) {
        cmp = entry_cmp(lastName, temp->lastName);
        if (cmp == 0)
            return temp;
        else if (cmp < 0)
            temp = temp->pLeft;
        else
            temp = temp->pRight;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    entry *temp = e;

    while (temp->lastName[0]) {
        if (entry_cmp(lastName, temp->lastName) <= 0) {
            if (!temp->pLeft) {
                temp->pLeft = (entry *) malloc(sizeof(entry));
                temp->pLeft->pRight = NULL;
                temp->pLeft->pLeft = NULL;
            }
            temp = temp->pLeft;
        } else {
            if(!temp->pRight) {
                temp->pRight = (entry *) malloc(sizeof(entry));
                temp->pRight->pRight = NULL;
                temp->pRight->pLeft = NULL;
            }
            temp = temp->pRight;
        }
    }
    strcpy(temp->lastName, lastName);
    return e;
}

int entry_cmp(char a[], char b[])
{
    /*if(strlen(a)==strlen(b))
        return strcmp(a, b);*/
    int i, l;
    if (strlen(a) == strlen(b)) {
        l = strlen(a);
        for (i = l-1; i >= 0; i--) {
            if(*(a+i) != *(b+i))
                return *(a+i) - *(b+i);
        }
    }
    return strlen(a) - strlen(b);
}

void free_bst(entry *e)
{
    if (e) {
        free_bst(e->pRight);
        free_bst(e->pLeft);
        free(e);
    }
}
