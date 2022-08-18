#include <iostream>

using namespace std;

int max(int x, int y)
{
	if(x > y){
		cout<<"x is greater than y";
		return 0;
	}else if(x < y){
		cout<<"x is smaller than y";
		return 0;
	}else{
		cout<<"x is equal to y";
		return 0;
	}
	
}

int main()
{
	int a;
	cin>>a;
	int b;
	cin>>b;

	int m = max(a, b);
	return 0;
}


