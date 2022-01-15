#include<stdio.h>
#include<stdlib.h>

void push1(int *a,int *top);
void push2(int *a,int *top);
void pop1(int *a,int *top);
void pop2(int *a,int *top);
void disp1(int *a,int top);
void disp2(int *a,int top);
int n=0;
int main()
{
	int *a,top1,top2,ch;

		printf("Enter the size of the combined 2 stacks\n");
			scanf("%d",&n);
		a = (int *)malloc(sizeof(int)*n);
		top1 = top2 = n/2;

		while(1)
		{
			printf("Implementation of the 2 stacks in single memory block growing in opposite direction\n");
			printf("1.Push element to the first stack\n");
			printf("2.Push element to the second stack\n");
			printf("3.Pop element from the first stack\n");
			printf("4.Pop element from the second stack\n");
			printf("5.Display first stack\n");
			printf("6.Display second stack\n");
				scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					push1(a,&top1);
					break;
				case 2:
					push2(a,&top2);
					break;
				case 3:
					pop1(a,&top1);
					break;
				case 4:
					pop2(a,&top2);
					break;
				case 5:
					disp1(a,top1);
					break;
				case 6:
					disp2(a,top2);
					break;
				default:
					exit(1);
			}
		}
}

void push1(int *a,int *top)
{
	int item;
	if(*top==-1)
	{
		printf("The stack is full\n");
		return;
	}
	printf("Enter the element to be pushed\n");
		scanf("%d",&item);
	*top = *top-1;
	*(a+ (*top)) = item;
}

void push2(int *a,int *top)
{
	int item;
	if(*top==n-1)
	{
		printf("The stack is full\n");
		return;
	}
	printf("Enter the element to be pushed\n");
		scanf("%d",&item);
	*top = *top+1;
	*(a+ (*top)) = item;
}

void pop1(int *a,int *top)
{
	if(*top==n/2)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("The element %d is popped\n",*(a+ (*top)));
	*top = *top+1;
}

void pop2(int *a,int *top)
{
	if(*top==n/2)
	{
		printf("The stack is empty\n");
		return;
	}
	printf("The element %d is popped\n",*(a+ (*top)));
	*top = *top-1;
}

void disp1(int *a,int top)
{
	if(top==n/2)
	{
		printf("The stack is empty\n");
		return;
	}
	while(top!=n/2)
	{
		printf("%d\n",*(a+top));
		top++;
	}
}

void disp2(int *a,int top)
{
	if(top==n/2)
	{
		printf("The stack is empty\n");
		return;
	}
	while(top!=n/2)
	{
		printf("%d\n",*(a+top));
		top--;
	}
}