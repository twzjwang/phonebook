#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define OPT_BST 1
typedef struct __PHONE_BOOK_ENTRY_INFO {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry_info;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_info *pInfo;
    struct __PHONE_BOOK_ENTRY *pRight;
    struct __PHONE_BOOK_ENTRY *pLeft;
} entry;

//search by bst
entry *findName(char lastName[], entry *pHead);

//recursively create balanced bst
entry *new_balance_bst(entry *root, int num, FILE *fp);
entry *balance_bst(entry *e, int num, entry *root, FILE *fp);

//recursively free bst memory
void free_bst(entry *e);

#endif
