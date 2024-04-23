#include <iostream>

struct person {
	typedef person* Person;
	int info;
	Person next;
	void high(int a);
	void operator=(person l);
	void operator+(person l);
};

void person::operator=(person l){
	std::cout<<"call fuckyou";
	{
		info = l.info;
	
	}
}
void person::operator+(person l){
	info += l.info;
}
void person::high(int a){
	info = a;
}

std::ostream& operator<<(std::ostream& os, person const& l){
	os << l.info << std::endl;
	return os;
}

int main(){
	person p;
	p.high(8);
	person h;
	h = p;
	h = h + p;
	std::cout<<p;
	std::cout<<h;
	return 0;
}