#include <iostream>

long long pgcd(long long a, long long b){
  if(a<b){long long c=a;a=b;b=c;}

	return a%b==0? b : pgcd(b, (a%b)); 
}
int main(){

	int n;

	long long a, b, c;

	std::cin>>n;

	for(int i(1); i<=n; i++){

		std::cin>>a;

		std::cin>>b;

		std::cin>>c;

		for(long long i(1); i<=pgcd(b , c); i++)

			std::cout<<a;

		std::cout<<std::endl;
	}
}

