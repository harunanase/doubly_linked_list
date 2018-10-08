#ifndef __LIST_H__
#define __LIST_H__


#define MSG_SIZE 1024



struct block
{
		/* each block of the double linked list */
		char msg[MSG_SIZE];	/* messange storage */
		struct block *prev; /* pointer, points to previous block */
		struct block *next;	/* pointer, points to next block */
};


typedef struct block Block; /* Alias, more readable */


void insertAtHead(char data[MSG_SIZE], Block **head, Block **tail);	/* insert at the head of list */
void insertAtTail(char data[MSG_SIZE], Block **head, Block **tail);	/* insert at the tail of list */
void deleteFromHead(Block **head, Block **tail);	/* delete block from head */
void deleteFromTail(Block **head, Block **tail);	/* delete block from tail */





void print_list(Block **head);	/* print the list */


#endif
