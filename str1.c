#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFSIZE 1024
typedef long long unsigned int lint;

int findstr(char *original,char *tmpstr, int *loc)
{
	int len1=strlen(original);
	int len2=strlen(tmpstr);
	int i=0,j=0;
	for(i=0;i<=len1-len2;i++)
	{
		int j ;
		for(j=0;j<len2;j++)
		{
			if(original[i+j]!=tmpstr[j])
				break;

		}
		if(j==len2)
		{
			*loc=i;
			return 1;
		}
	}
	return -1;
}
int main()
{
	lint tc=0;
	lint i=0;
	//Enter TC count
	scanf("%llu",&tc);
	{
		for (i=0;i<tc;i++)
		{
			//Enter String
			char original[BUFSIZE]={'\0',};
			char tmpstr[BUFSIZE]={'\0',};
			int found = -1;
			scanf("%s %s",original,tmpstr);
			if(1==findstr(original,tmpstr,&found))
			{
				printf("Found ,loc is %d\n",found);
			}
			else
				printf("Not found\n");


		}
	}
return 0;
}
