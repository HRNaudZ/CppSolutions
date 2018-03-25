#include <iostream>

int main(){
	int a, b;
	char V;
	std::cin>>a;
	std::cin>>b;
	std::cin>>V;
	//A n 5
	//B y 5
	//C n 2
	//D y 2
	if(V=='Y'){
		if(a/5>=b){
			std::cout<<"B"<<std::endl;
		}else if(a/2>=b)
			std::cout<<"D"<<std::endl;
		else
			std::cout<<"NO PIZZA"<<std::endl;
	}else if(V=='N'){
		if(a/5>=b){
			std::cout<<"A"<<std::endl;
		}else if(a/2>=b)
			std::cout<<"C"<<std::endl;
		else
			std::cout<<"NO PIZZA"<<std::endl;		
	}
	
}
