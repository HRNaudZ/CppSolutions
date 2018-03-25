#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int n, a, b;
	long long c;
	std::cin>>n;
	for(int i(1); i<=n; i++){
		std::cin>>a;
		std::cin>>b;
		std::cin>>c;
		std::vector<long long> v;
		for(long long i(1); i<=c; i++){
			if(find(v.begin(), v.end(), a*i)==v.end()) v.push_back(a*i);
			if(find(v.begin(), v.end(), b*i)==v.end()) v.push_back(b*i);
		}		
		sort(v.begin(), v.end());
		std::cout<<v[c-1];
		std::cout<<std::endl;
	}
}
