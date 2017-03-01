#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
/*****************first approach********************/
void print_middle(struct node* head)
{
	struct node* mid = head;
	int count =0;
	while (head != NULL)
	{
		if(count & 1)
			mid = mid->next;
		++count;
		head = head->next;

	}
		printf("middle element is %d\n ",mid->data);
}
/*********************second approach****************/
void middle_print(struct node* head)
{
	struct node* first_end = head;
	struct node* last_end = head;
	if(head !=NULL)
	{
		while(first_end !=NULL && first_end->next !=NULL)
		{
			first_end = first_end->next->next;
			last_end = last_end->next;
		}
	}
	printf("\nmiddle  node is %d\n",last_end->data);
}


void print_list(struct node* head)
{
	while(head != NULL)
		{
		printf(" %d -> ",head->data);
		head = head->next;
		}
	printf("NULL \n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref); 
    (*head_ref)    = new_node;
}

int main()
{
    struct node* head = NULL;
    int i;
 
    for (i=5; i>0; i--)
    {
        push(&head, i);

    }
 
        print_list(head);
        print_middle(head);
	middle_print(head);
    return 0;
}
