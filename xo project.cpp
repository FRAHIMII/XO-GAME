#include <iostream>
using namespace std;



void print(char *table ,int size);
char Winner (char *table ,int size);
char InsertParamToTable(char *table,int size,int c,int r,char x_or_o);




int main(void)
{
	int size=0;
	int column=0,row=0;
	cout<<"Please Insert Table Size :";
	cin>>size;
	char Table[size][size]={0};
	cout<<"------------------------------(START GAME)--------------------------------------"<<endl;
	print(&Table[0][0],size);
	
	for(int i=0;i<size*size;i++)
	{
		cout<<"------------------------------"<<" (PLAYER:"<<i%2+1<<")--------------------------------------"<<endl;
		cout<<"PLAYER"<<i%2+1<<":"<<"  please,insert Column between 1 and " <<size<< " then press <enter> :";
		cin>>column;
		cout<<"PLAYER"<<i%2+1<<":"<<"  please,insert Row    between 1 and " <<size<< " then press <enter> :";
		cin>>row;
		if(i%2==0)
		{
			if(InsertParamToTable(&Table[0][0],size,column,row,'x')!=1)
			{
				i--;
				cout<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
				cout<<endl;
			}
		}
		else
		{
			if(InsertParamToTable(&Table[0][0],size,column,row,'o')!=1)
			{
				i--;
				cout<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
				cout<<"               !!!!!!!!!   Invalid Number   !!!!!!!!!"<<endl;
			}
			
		}	
		print(&Table[0][0],size);
		if(Winner(&Table[0][0],size)=='x')
		{
			cout<<endl;
			cout<<"**Congratulation**Player1 Is Winner";
			return 0;
		}
	   	
		else if(Winner(&Table[0][0],size)=='o')
		{
			cout<<endl;
			cout<<"**Congratulation**Player2 Is Winner";
			return 0;
		}	
		
	}
	cout<<"NO Winner";
    return 0;   
}

char InsertParamToTable(char *table,int size,int c,int r,char x_or_o)
{
	if(c>size || r>size)
		return 0;
	
	c=c-1;
	r=r-1;
	if(*(table+((r*size)+c))=='x' || *(table+((r*size)+c))=='o') return 0;
	*(table+((r*size)+c))=x_or_o;	
	return 1;
}
char Winner (char *table ,int size)
{
	int XWinCnt=0,OWinCnt;
	int t=0;
	//row Check
	t=0;
	XWinCnt=0;
	OWinCnt=0;
	for(int i=0;i<size;i++)
	{
	    XWinCnt=0;
		OWinCnt=0;	
		for(int j=0;j<size;j++)
		{
			if(*(table+t)=='x')	XWinCnt++;
			else if(*(table+t)=='o') OWinCnt++;
			t++;
		}
		if(XWinCnt==size) return 'x';
	    else if(OWinCnt==size) return 'o';	
	}
	 //Column check
	t=0;
	XWinCnt=0;
	OWinCnt=0;
	for(int i=0;i<size;i++)
	{
		XWinCnt=0;
		OWinCnt=0;
		t=i;
		for(int j=0;j<size;j++)
		{
			if(*(table+t)=='x')	XWinCnt++;
			else if(*(table+t)=='o') OWinCnt++;
			t=t+size;
		}
		if(XWinCnt==size) return 'x';
	    else if(OWinCnt==size) return 'o';
	}
	//diagonal check
	t=0;
	XWinCnt=0;
	OWinCnt=0;
    for(int i=0;i<size;i++)
	{
		if(*(table+t)=='x')	XWinCnt++;
		else if(*(table+t)=='o') OWinCnt++;	
	    t=t+size+1;
	}
	if(XWinCnt==size) return 'x';
	else if(OWinCnt==size) return 'o';
	//invers diagonal check
	XWinCnt=0;
	OWinCnt=0;
	t=size-1;
    for(int i=0;i<size;i++)
	{
		if(*(table+t)=='x')	XWinCnt++;
		else if(*(table+t)=='o') OWinCnt++;	
	    t=t+(size-1);	
	}
	if(XWinCnt==size) return 'x';
	else if(OWinCnt==size) return 'o';
}

void print(char *table ,int size)
{
	cout<<endl;
	int t=0;
	for(int i=0;i<size;i++)
	{
		for(int k=0;k<size;k++)
		{
			cout<<"+---";
		}
		cout<<"+";
		cout<<endl;
		for(int j=0;j<size;j++)
		{
			if(*(table+t)=='x')
			{
				cout<<"|"<<" X ";
			}
			else if(*(table+t)=='o')
			{
				cout<<"|"<<" O ";	
			}
			else
			{
				cout<<"|"<<"   ";
			}
			t++;
		}
		cout<<"|";
		cout<<endl;
	}
	for(int k=0;k<size;k++)
	{
		cout<<"+---";
	}
	cout<<"+";
	cout<<endl;
	cout<<endl;
}
