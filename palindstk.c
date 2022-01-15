#include<stdio.h>
#include<stdlib.h>
#define size 20

struct stack{
	char *a;
	int top;
};

typedef struct stack STK;
int check(STK *s,char *array);
void push(STK *s,char *array);

int main()
{
	int res;
	char s[10];
	STK st;
	st.top = -1;
	st.a = (char *)malloc(sizeof(char)*size);

		printf("Enter the string\n");
			scanf("%s",s);
		push(&st,s);
		res = check(&st,s);

		if(res==-1)
			printf("The string is not a palindrome\n");
		else
			printf("The string %s is a palindrome\n",s);

}

void push(STK *s,char *array)
{
	int i=0;
	while(*(array+i) != '\0')
	{
		s->top++;
		*(s->a+s->top) = *(array+i);
		i++;
	}
}

int check(STK *s,char *array)
{
	char c;
	int i=0;
	int flag=0;
	if(s->top == -1)
	{
		printf("Invalid\n");
		return 0;
	}
	while(s->top!=-1)
	{
		if(*(s->a+s->top) != *(array+i))
		{
			flag = 1;
			break;
		}
		s->top--;
		i++;
	}
	if(flag==1)
		return -1;
	return 1;

}