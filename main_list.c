#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
		Block *head = NULL;	/* initialize list */
		Block *tail = NULL;
	
		while(1)
		{
				printf("\n\n\n==== List ====\n");
				printf("1) insert at head\t2) insert at tail\t3) delete from head\t4) delete from tail\n");
				printf("5) print the list\t6) exit\nEnter option: ");


				char msg[MSG_SIZE];

				/* get option from stdin */
				int option = 0;
				char enterFilter;
				scanf("%d%c", &option, &enterFilter);
				
				switch(option)
				{
					case 1:	
							printf("Enter some messange: ");
							scanf("%s", msg);
							insertAtHead(msg, &head, &tail);
							break;
					case 2:
							printf("Enter some messange: ");
							scanf("%s", msg);
							insertAtTail(msg, &head, &tail);
							break;
					case 3:
							deleteFromHead(&head, &tail);
							break;
					case 4:
							deleteFromTail(&head, &tail);
							break;
					case 5:
							print_list(&head);
							break;
					case 6:
							exit(0);
							break;
					default:
							printf("ERROR: wrong option, please enter again.\n");
				}
		}
		return 0;
}


