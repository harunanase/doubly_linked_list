#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertAtHead(char data[MSG_SIZE], Block **head, Block **tail)
{
		Block *nblock = malloc(sizeof(Block));	/* allocate new block */
		strncpy(nblock->msg, data, MSG_SIZE);	/* copy data from argument */
		nblock->prev = NULL;	/* No previous block */

		if( (*head) != NULL )
		{
				(*head)->prev = nblock;	/* let "head" previous points to new add block */
				nblock->next = (*head);	/* let new block points to the "head" block */
				(*head) = nblock;	/* update head */
		}
		else
		{
				/* empty list */
				(*head) = nblock;	
				(*tail) = nblock;	
				nblock->next = NULL;	/* No next block */
		}
}

void insertAtTail(char data[MSG_SIZE], Block **head, Block **tail)
{
		Block *nblock = malloc(sizeof(Block));	/* allocate new block */
		strncpy(nblock->msg, data, MSG_SIZE);	/* copy data from argument */
		nblock->next = NULL;	/* No next block */

		if( (*tail) != NULL )
		{
				(*tail)->next = nblock;	/* let "tail" next points to the new block */
				nblock->prev = (*tail);	/* let new block prev pointer points to the "tail" */
				(*tail) = nblock;	/* update tail */
		}
		else
		{
				/* empty list */
				(*head) = nblock;
				(*tail) = nblock;
				nblock->prev = NULL; /* No previous block */
		}
}

void deleteFromHead(Block **head, Block **tail)
{
		if( (*head) != NULL )
		{
				Block *temp = (*head);
				if( *head == *tail )
				{
						/* one-element list */
						*head = NULL;
						*tail = NULL;
				}
				else
				{
						(*head)->next->prev = NULL;	/* the second block doesn't need to point to the delete block anymore */
						(*head) = (*head)->next;	/* update head */
				}	
				free(temp);	/* delete block */
		}
		else
		{
				printf("ERROR: empty list\n");
		}
}


void deleteFromTail(Block **head, Block **tail)
{
		if( (*tail) != NULL )
		{
				Block *temp = (*tail);
				if( *head == *tail )
				{
						/* one-element list */
						*head = NULL;
						*tail = NULL;
				}
				else
				{
						(*tail)->prev->next = NULL;	/* the second block doesn't need to point to the delete block anymore */
						(*tail) = (*tail)->prev;	/* update head */
				}	
				free(temp);	/* delete block */
		}
		else
		{
				printf("ERROR: empty list\n");
		}

}

void print_list(Block **head)
{
		/* print the whole list */

		if((*head) == NULL)
		{
				/* list empty, exit. */
				printf("The list is empty.\n");
				return ;	
		}
		else
		{
				/* not empty, iteratively print it */
				printf("The list:\n");
				Block *temp = (*head);
				while( temp != NULL )
				{
						printf("%s", temp->msg);
						if(temp->next != NULL)
						{
								printf(" -> ");
						}
						else
						{
								printf("\n");
						}
						temp = temp->next;
				}
		}

}
