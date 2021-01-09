#include <iostream>

using namespace std;

/*
struct node
	{
		long long mafia;
		node *next;
	};

int main()
	{
		long long n, i;
		int mark = 0;
		node *start, *p;
		start = new node;
		p = start;		
		
		cin>>n;
		
		for(i = 1; i <= n; i++)
			{
				cin>>p->mafia;
				if(i <= n)
					{
						p->next = new node;
						p = p->next;
					}
				else
					p->next = NULL;				
			}
			
		for(i = 1; i <= n; i++)
			{
				p = start;
				while(p != NULL)
					{
						if(p->mafia == i)
							{
								mark = 1;
								break;
							}
						p = p->next;
					}
				
				
				if(mark == 0)
					{
						cout<<i<<" ";
					}
				else 
					mark = 0;
			}
			
		cout<<endl;
		
		return 0;
	}
*/




int main()
	{
		unsigned int n, mafia[100000], mark = 0;
		
		cout<<"Input n"<<endl;
		cin>>n;
		
		if(n > 100000)
			{
				cout<<"Wrong Input"<<endl;
				return 1;
			}
		
		for(int i = 0; i < n; i++)
			cin>>mafia[i];
		cout<<endl;	
		
		for(int i = 1; i <= n; i++)	
			{
				for(int j = 0; j < n; j++)
					{
						if(mafia[j] == i)
							{
								mark = 1;
								break;
							}
					}
				
				if(mark == 0)
					{
						cout<<i<<" ";						
					}
				else
					mark = 0;
			}
			
		cout<<endl;
		
		return 0;
	}


/*int main()
	{
		unsigned int n, mafia[100000], suspect[99999], mark = 0, k = 0;
		
		if(n > 100000)
			{
				cout<<"Wrong Input"<<endl;
				return 1;
			}
		
		cout<<"Input n"<<endl;
		cin>>n;
		
		for(int i = 0; i < n; i++)
			cin>>mafia[i];
		cout<<endl;	
		
		for(int i = 1; i <= n; i++)	
			{
				for(int j = 0; j < n; j++)
					{
						if(mafia[j] == i)
							{
								suspect[k] = i;
								k++;
								mark = 1;
								break;
							}
					}
				
				mark = 0;
			}
		
		for(int i = 0; i < k; i++)
			{
				
			}
			
		cout<<endl;
		
		return 0;
	}
*/
