#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int check_plus(char* input)
{
	int t;
	char p[]="plus";
	for(t=0;t<4;t++)
	{
		if(input[t]!=p[t]) return 0;
	}
	
	if(t!=strlen(input)) return 0;
	return 1;
}
int check_minus(char* input)
{
	int t;
	char p[]="minus";
	for(t=0;t<5;t++)
	{
		if(input[t]!=p[t]) return 0;
	}
	
	if(t!=strlen(input)) return 0;
	return 1;
}
int check_times(char* input)
{
	int t;
	char p[]="times";
	for(t=0;t<5;t++)
	{
		if(input[t]!=p[t]) return 0;
	}
	
	if(t!=strlen(input)) return 0;
	return 1;
}
int check_divide(char* input)
{
	int t;
	char p[]="divided_by";
	for(t=0;t<10;t++)
	{
		if(input[t]!=p[t]) return 0;
	}
	
	if(t!=strlen(input)) return 0;
	return 1;
}

int main()
{
	
	double a,b;
	char input[2000];
	while(printf("Please enter two float number n,k and one operation like 100.5 plus 100.3 :\n") && fgets(input,sizeof(input),stdin) )
	{
		if(input[strlen(input)-1]=='\n') input[strlen(input)-1]='\0';
		
		int t;
		
		int fin1=0;
		int fin2=0;
		int fin3=0;
		
		
		int c1=0; /* 1=+ 2=- */
		int c2=0; /* 1=xxx. 2=.xxxx */
		int index=0;
		double a=0.0,b=0.0;
		while(index<strlen(input) && input[index]==' ') index++;
		
		double s=1.0;
		int flag=1;
		
		if(input[index]=='-') c1=2,index++;
		while(index<strlen(input))
		{
			if(input[index]>='0' && input[index]<='9')
			{
				if(!c1) c1=1;
				a=a*10+input[index++]-'0';
			}
			else if(input[index]=='.')
			{
				c2=1;
				index++;
				break;
			}
			else if(c2==0 && input[index]==' ')
			{
				fin1=1;
				index++;
				break;
			}
			else
			{
				flag=0;
				break;
			}
		}
		
		
		if(c2) /* have .xxxx */
		{
			while(index<strlen(input) && flag)
			{
				if(input[index]>='0' && input[index]<='9')
				{
					a+=(s/10)*(input[index++]-'0');
					s/=10;
				}
				else if(input[index]==' ')
				{
					fin1=1;
					index++;
					break;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		
		if(c1==2) a*=-1;
		
		
		
		/* do string  */
		while(index<strlen(input) && input[index]==' ') index++;
		
		int type_p=0;
		int type_m=0;
		int type_t=0;
		int type_d=0;
		// p m t d
		switch(input[index])
		{
			case 'p':
				type_p=1;
				break;
			case 'm':
				type_m=1;
				break;
			case 't':
				type_t=1;
				break;
			case 'd':
				type_d=1;
				break;
			default:
				flag=0;
				break;
		}
		index++;
		
		
		if(!(type_p||type_m||type_t||type_d)) flag=0;
		
		/* plus */
		if(type_p)
		{
			char aa[]="lus";
			for(t=0;t<3;t++)
			{
			
				if(input[index+t]!=aa[t]) flag=0;
			}
			
			if(flag) index+=3;	
		}
		
		/* minus */
		if(type_m)
		{
			char aa[]="inus";
			for(t=0;t<4;t++)
			{
				if(input[index+t]!=aa[t]) flag=0;
			}
			if(flag) index+=4;	
		}
		
		/* times */
		if(type_t)
		{
			char aa[]="imes";
			for(t=0;t<4;t++)
			{
				if(input[index+t]!=aa[t]) flag=0;
			}
			if(flag) index+=4;	
		}
		
		/* divided_by */
		if(type_d)
		{
			char aa[]="ivided_by";
			for(t=0;t<9;t++)
			{
				if(input[index+t]!=aa[t]) flag=0;
			}
			if(flag) index+=9;	
		}
		
		if(flag) fin2=1;
		
		/* do second number */
		while(index<strlen(input) && input[index]==' ') index++;
		
		c1=0,c2=0;
		
		if(input[index]=='-') c1=2,index++;
		while(index<strlen(input) && flag)
		{
		
			if(input[index]>='0' && input[index]<='9')
			{
				if(!c1) c1=1;
				b=b*10+input[index++]-'0';
			}
			else if(input[index]=='.')
			{
				c2=1;
				index++;
				break;
			}
			else if(c2==0 && input[index]==' ' )
			{
				fin3=1;
				index++;
				break;
			}
			else
			{
				flag=0;
				break;
			}
		}
		
		
		s=1.0;
		if(c2) /* have .xxxx */
		{
			while(index<strlen(input) && flag)
			{
				if(input[index]>='0' && input[index]<='9')
				{
					b+=(s/10)*(input[index++]-'0');
					s/=10;
				}
				else if(input[index]==' ')
				{
					fin3=1;
					index++;
					break;
				}
				else
				{
					flag=0;
					break;
				}
			}
		}
		
		while(index<strlen(input) && input[index]==' ') index++;
		
		if(fin3 && index<strlen(input)) flag=0;
		if(fin3==0 && index==strlen(input)) fin3=1;
		
		
		if(c1==2) b*=-1;
		
		
		if(flag && fin1 && fin2 && fin3)
		{
		
			if(type_p) printf("The answer is : %lf\n\n\n",a+b);
			if(type_m) flag=1,printf("The answer is : %lf\n\n\n",a-b);
			if(type_t) flag=1,printf("The answer is : %lf\n\n\n",a*b);
			if(type_d) flag=1,printf("The answer is : %lf\n\n\n",a/b);
		}
		else printf("Input format error, please input again!\n\n\n");
		
	}
	return 0;
}
