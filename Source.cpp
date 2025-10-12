#include "List.h"
#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	
	List List1;

	List1.insert_at_tail(7);
	List1.insert_at_head(10);
	List1.insert_at_head(15);
	List1.insert_at_head(5);
	//List1.search(3);
	//List1.print();
	
	List1.insert_at_target(60,7);
	List1.print();
	List1.remove(10);
	cout<<endl<<endl<<endl;
	List1.print();

	
	

	getch();
	return 0;
}