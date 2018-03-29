/*By WOANA Yao Renaud*/
/*This code needs optimisation, all apports are welcome ! */

#include <iostream>
#include <bitset>
#include <vector>
#include <map>
#include <iomanip>
#include <ctime>

typedef std::pair<int, int> p;
typedef std::vector<std::bitset<6> > Matrice;
typedef std::map<p, std::vector<Matrice> > ELE;
typedef std::pair<bool, std::vector<p> > vec_state;
typedef std::vector<int> POS;

Matrice operator+(Matrice& a, Matrice& b){
	Matrice R(5);
	for(int i(0); i<5; i++){
		R[i] = (a[i]^b[i]);
	}
	return R;
}

Matrice operator-(Matrice& a, Matrice& b){
	Matrice R(5);
	for(int i(0); i<5; i++){
		R[i] = (a[i]^b[i]);
	}
	return R;
}

void display(Matrice& a){
	for(unsigned int i(0); i<a.size(); i++){
		std::cout<<a[i]<<std::endl;
	}
}

Matrice nMatrice(std::string a){
	Matrice R(5);
	R[0] = std::bitset<6>(a.substr(0, 6));
	R[1] = std::bitset<6>(a.substr(6, 6));
	R[2] = std::bitset<6>(a.substr(12, 6));
	R[3] = std::bitset<6>(a.substr(18, 6));
	R[4] = std::bitset<6>(a.substr(24, 6));
	return R;
}

std::string stringer(int i, int j){
	std::string str;
	for(int k(1); k<=5; k++){
		for(int l(1); l<=6; l++){
			if(k==i-1 && l==j) str+='1';
			else if(k==i+1 && l==j) str+='1';
			else if(k==i && l==j-1) str+='1';
			else if(k==i && l==j+1) str+='1';
			else if(k==i && l==j) str+='1';
			else str+='0';
		}
	}
	return str;
}

vec_state Calculador(Matrice& A, std::vector<p> v, ELE& Trivial	){
	Matrice B(A);
	for(unsigned int i(0); i<v.size(); i++){
		B = B + Trivial[p(v[i])][1];
	}
	for(int i(0); i<5; i++){
		if(B[i].any()){
			return std::pair<bool, std::vector<p> >(false, v);
		} 
	}
	return std::pair<bool, std::vector<p> >(true, v);
}

void operator++(POS& P){
		int ret;
		if(P[29]==0 ){
			P[29]++;
		}else if(P[29]==1){
			P[29]--;
			P[28]++;
		}
	for(int i(29); i>=0; i--){
		if(P[i]>1 && i!=0){
			ret = P[i]/2;
			P[i] = P[i]%2;
			P[i-1] += ret;
		}else if(P[i]>1 && i==0){
			P[i] = 0;
		}
	}
}

bool end(POS& P){
	for(unsigned int i(0); i<30; i++){
		if(P[i]==1) return false;
	}
	return true;
}

std::vector<p> Vectorize(POS& P){
	std::vector<p> V;
	for(int i(1); i<=5; i++){
		for(int j(1); j<=6; j++){
			if(P[(i-1)*6+(j-1)]==1) V.push_back(p(i, j));
		}
	}
	return V;
}

void ti(long int tt){
	long s = tt%60;
	long m = tt/60;
	long temp = m;
	m = m%60;
	long h = temp/60;
	temp=h/24;
	h = h%24;
	long j =temp;
	std::cout<<j<<"J"<<h<<"H"<<m<<"min"<<s<<"s\n";
}
	
int main(){
	int c, jj=0;
	double elapsed;
	std::FILE *SV;
	SV = std::fopen("SAVE.dat", "r");
	std::cout<<std::setprecision(5)<<std::fixed;

	ELE Trivial;
	for(int i(1); i<=5; i++){
		for(int j(1); j<=6; j++){
			Trivial[p(i, j)].push_back(nMatrice(stringer(-2, -2)));
			Trivial[p(i, j)].push_back(nMatrice(stringer(i, j)));
		}
	}

	long int t = 0;
	POS C(30,0);
	while((c=fgetc(SV))!='\n' && c!=EOF){
		C[jj] = c;
		jj++;
	}
	fscanf(SV, "%d", &t);
	
	Matrice P(5);
	P= nMatrice("011010100111001001100101011100"); ///The puzzle to solve
	if(t==0) ++C;
	std::time_t start = time(0);
	fscanf(SV, "%d", &start);
	SV = std::fopen("SAVE.dat", "w");
	while(!end(C)){
		rewind(SV);
		for(int i(0); i<30; i++){
			fputc(C[i], SV);
		}
		
		fprintf(SV, "\n%d", t);
		fprintf(SV, "\n%d", start);
		
		elapsed = std::difftime(time(0), start);
		t++;
		if(Calculador(P, Vectorize(C) , Trivial).first){
			std::vector<p> A(Calculador(P, Vectorize(C) , Trivial).second);
			break;
		}
		++C;
		system("cls");
		std::cout<<"\n \n\n\t\t \t \t \t\t CRACKING THE PUZZLE\n";
		std::cout<<" \n \n \t\t \t \t \t \t *******************";
		std::cout<<"\n \t \t  \t\t  \t \t *\t\t   *";
		std::cout<<"\n \t \t  \t\t  \t \t *\t\t   *";
		std::cout<<"\n \t \t  \t\t  \t \t *    "<<(t/1073741824.0)<<"% \t   *";
		std::cout<<"\n \t \t  \t\t  \t \t *\t\t   *";
		std::cout<<"\n \t \t  \t\t  \t \t *\t\t   *";
		std::cout<<"\n\t \t \t \t\t \t *******************\n";
		std::cout<<"\n \t\t \t \t \t\t TIME ELAPSED : ";
		ti(elapsed);
		std::cout<<"\n \t\t \t \t \t\t WORST TIME REMAINING : ";
		ti((100.0*elapsed)/(t/1073741824.0));
		std::cout<<"\n \t\t \t \t \t\tCRACKING THE PUZZLE By WOANA Yao Renaud \n"; 
	}
	
	std::cout<<"\n\n\t\t\tPUZZLE CRACKED AFTER ";
	ti(elapsed);
	std::cout<<"\n\t\t\tTHE KEY IS : ";
	for(int i(0); i<30; i++) std::cout<<C[i]<<" ";
	std::cout<<" \n\n\n\t\t\t";
	system("pause");
}
