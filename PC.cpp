/**** Code by WOANA Yao Renaud *****/
/*---------woanayr@gmail.com------*/

#include <iostream>
#include <vector>

bool isEndThree(int a){
	return a%10==3;
}

bool isPrime(int a){
	if(a<=1) return false;
	if(a<=3) return true;
	if(a%2==0 || a%3==0) return false;
	for(int i(5); i*i<=a; i+=6){
		if(a%i==0 || a%(i+2)==0) return false;
	}
	return true;
}

bool isTHREE(int a){
	if(isPrime(a)){
		if(isEndThree(a)) return true;
		else return false; 
	}
	
	std::vector<int> factors;
	for(int i(2); i<=(a/2); i++){
		if(a%i==0 && isPrime(i)) factors.push_back(i);
	}
	for(int i(0); i<factors.size(); i++) if(!isEndThree(factors[i])) return false;
	return true;
}

int main(){
	int a;
	do{
		std::cin>>a;
		if(a==-1) break;
		if(isTHREE(a)) std::cout<<a<<" "<<"YES"<<std::endl;
		else std::cout<<a<<" "<<"NO"<<std::endl;
	}while(a!=-1);
}
