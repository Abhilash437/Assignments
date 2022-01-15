#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int num[100];
	int top;
}stk;
void push(stk *s,int n);
int main()
{
	stk s;
	s.top = -1;
	int i,temp,k,n;
	printf("Enter a decemial number\n");
		scanf("%d",&n);
	while(n>0)
	{
		temp = n%2;
		n = n/2;
		push(&s,temp);
	}
	printf("Displaying the binary equivalent\n");
	k = s.top;
	for(;k>=0;)
		printf("%d",s.num[k--]);
	printf("\n");
}

void push(stk *s,int n)
{
	if(s->top==100-1)
	{
		printf("Stack overflow\n");
		return;
	}
	s->top++;
	s->num[s->top] = n;
}