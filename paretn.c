#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	char items[20];
	int top;
}STK;
int check(char e[],STK s);
int paracheck(char c);
void push(STK *s,char c);
int main()
{
	STK S;
	S.top = -1;
	char exp[20];
	int res;
	printf("Enter the parenthesized expression\n");
		scanf("%s",exp);
	res = check(exp,S);
	if(res == -111)
		printf("Error!!!\n");
	else
		printf("Correct expression");

}

int paracheck(char c)
{
	switch(c)
	{
		case '(':
			return 1;
			break;
		case ')':
			return -1;
			break;
		case '{':
			return 2;
			break;
		case '}':
			return -2;
			break;
		case '[':
			return 3;
			break;
		case ']':
			return -3;
			break;
		default:
			return 4;
	}
}

void push(STK *s,char c)
{
	s->top++;
	*(s->items+s->top) = c;
}
int check(char e[],STK s)
{
	int i,res;
	for(i=0;e[i]!='\0';i++)
	{
		res = paracheck(e[i]);
		switch(res)
		{
			case 1:
			case 2:
			case 3:
				push(&s,e[i]);
				break;
			case -1:
			case -2:
			case -3:
				if(s.top==-1)
					return -111;
				else
				{
					if((paracheck(e[i]) + paracheck(s.items[s.top])) == 0)
					{
						s.top--;
						continue;
					}
					else
						return -111;
				}
				break;
			default:
				continue;
		}

	}
	if(s.top==-1)
		return 1;
	else
		return -111;
}