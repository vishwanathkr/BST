#include <iostream>

using namespace std;

int sum(int x){
	x++;
	if(x>10){
		return x;
	}
	return sum(x);
}

class ray{
private:
	int b;
public:
	ray(int _b):b(_b){

	}
	void print(){
		cout<<b<<endl;
	}
};

int main(){
	int a =0;
	// cout<<sum(a)<<endl;
	ray* c=new ray(2);
	c->print();
}