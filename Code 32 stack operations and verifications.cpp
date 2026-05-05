#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node *top=NULL;

void push()
{
	int val;
	printf("Enter the element: ");
	scanf("%d",&val);
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
	printf("%d pushed successfully\n",val);
}
void pop()
{
	if(top=NULL)
	{
		printf("Stack Underflow\n");
		return;
	}
	struct node*temp=top;
	printf("%d popped from stack\n",top->data);
	top=top->next;
	free(temp);
}
void peek()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Top element: %d\n",top->data);
}
void display()
{
	if(top==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	struct node*temp=top;
	printf("Stack (top to bottom): ");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void search()
{
	int val,pos=1,found=0;
	printf("Enter the element you want to search: ");
	scanf("%d",&val);
	struct node*temp=top;
	while(temp!=NULL)
	{
		if(temp->data==val)
		{
			printf("%d found atposition %d from top\n",val,pos);
			found =1;
			break;
		}
		temp=temp->next;
		pos++;
	}
	if(!found)
	{
		printf("%d not found in stack\n",val);
	}
}
void SortStack()
{
	int arr[100],n=0,i,j,temp;
	struct node*t=top;
	while(t!=NULL)
	{
		arr[n++]=t->data;
		t=t->next;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	t=top;
	for(i=0;i<n;i++)
	{
		t->data=arr[i];
		t=t->next;
	}
	printf("Stack is sorted in descending order\n");
	display();
}
void size()
{
	int count =0;
	struct node*temp=top;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	printf("Size of stack: %d\n",count);
}
int main()
{
	int choice;
	while(1)
	{
		printf("STACK USING Linked list MENUE\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek(Top Element)\n");
		printf("4. Display\n");
		printf("5. Search\n");
		printf("6. Sort\n");
		printf("7. Size\n");
		printf("8. Exit\n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
	
	switch (choice)
	{
		case 1: push();
		break;
		case 2: pop();
		break;
		case 3: peek();
		break;
		case 4: display();
		break;
		case 5: search();
		break;
		case 6: SortStack();
		break;
		case 7: size();
		break;
		case 8: printf("Exiting....\n");exit(0);
		default: printf("Invalid choice\n");
	}
}
}
