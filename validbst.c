#include <stdio.h>
#include <limits.h>
#define MAX 1000
int stack[1001]={0,};
int top = -1;
void push(int x)
{
	if(top>MAX)
	{
		return;
					         
	}
	else
	{
		top++;
		stack[top]=x;
	}
}
int pop()
{
	if(top<=-1)
	{
		return -1;
	}
	else
	{
		
		int tmp=stack[top];
		top--;
		return top;
	}											
}
int BST(int *pre, int n) 
{ 
  
    int root = -10000; 
  
    for (int i=0; i<n; i++) 
    { 
        if (pre[i] < root) 
            return -1; 
  
        while (top != -1 && stack[top]<pre[i]) 
        { 
            root = stack[top]; 
            pop(); 
        } 
  
        push(pre[i]); 
    } 
    return 0; 

} 
int main()
{
	int tc=0;
	scanf("%d",&tc);
	for(int i=0;i<tc;i++)
	{
		for(int p=0;p<1001;p++)
			stack[p]=0;
		int n=0;
		top = -1;
		int arr[101]={0,};
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[j]);
		}
		int res = BST(arr,n);
		if(res==-1)
			printf("NO\n");
		else if(res == 0)
			printf("YES\n");
	}
	return 0;
}
