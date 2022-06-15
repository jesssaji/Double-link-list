#include<stdio.h>
#include<stdlib.h>

void main()
{
	struct node
	{
		struct node *prev;
		int data;
		struct node *next;
	};
	
	struct node *head=NULL,*pos=NULL,*tail=NULL,*temp;
	
	int ch, entry,i;
	printf("\n\n\t\tNAMASTE!!\n\nWhat would you like to do ?");
	
	while(1)
	{
		printf("\n\n1:Insert(At front)\n2:Insert(At back)\n3:Display(forward)\n4:Display(reverse)\n5:Delete(From front)\n6:Delete(From back)  \n7:Exit\n");
		printf("\nEnter your choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{
				printf("\nEnter data");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					head->prev=(struct node*)malloc(sizeof(struct node));
					head->prev->next=head;
					head->prev->data=entry;
					head->prev->prev=NULL;
					head=head->prev;
				}
				break;
			}
			
		
			case 2:
			{
				printf("\nEnter data");
				scanf("%d",&entry);
				if(head==NULL)
				{
					head=(struct node*)malloc(sizeof(struct node));
					head->prev=NULL;
					head->data=entry;
					head->next=NULL;
					pos=head;
					tail=head;
				}
				else
				{
					tail->next=(struct node*)malloc(sizeof(struct node));
					tail->next->prev=tail;
					tail->next->data=entry;
					tail->next->next=NULL;
					tail=tail->next;
				}
				break;
			}
			
			case 3:
			{
				pos=head;
				if(head==NULL)
				{
					printf("\nEmpty list");
					break;
				}
				printf("\n\nElements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->next;
				}
				break;
			}
			case 4:
			{
				pos=tail;
				if(head==NULL)
				{
					printf("\nEmpty list");
					break;
				}
				printf("\nElements are: ");
				while(pos!=NULL)
				{
					printf("\t%d",pos->data);
					pos=pos->prev;
				}
				break;
			}
		
			case 5:
			{
				if(head==NULL)
				{
					printf("\nUnderflow");
					break;
				}
				
				if(head->next==NULL)
				{
					printf("\nElement deleted is %d",head->data);
					head=NULL;
					break;
				}
				temp=head;
				head=head->next;
				temp->next=NULL;
				head->prev=NULL;
				printf("\nElement deleted is %d",temp->data);
				free(temp);
				break;
			}
			
			case 6:
			{
				if(head==NULL)
				{
					printf("\nUnderflow");
					break;
				}
				if(head->next==NULL)
				{
					printf("\nElement deleted is %d",head->data);
					head=NULL;
					break;
				}
				temp=tail;
				tail=tail->prev;
				temp->prev=NULL;
				tail->next=NULL;
				printf("\nElement deleted is %d",temp->data);
				free(temp);
				break;
			}
			
			/*exit*/
			case 7:
			{
				printf("\nThank you visit again!!\n\n");
				exit(0);
			}
			
			default :
			{
				printf("\nINVALID CHOICE");
				break;
			}
		}
	}
}
				
