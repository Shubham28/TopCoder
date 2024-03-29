#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
 
using namespace std;
 
class ColorfulStrings{
public:
	string getKth(int, int);
};

int K,N;
int numb[10];
int prod[4000000];
string ans;
 
int Permut(int dig){

	if(dig==N){
		--K;
		if(K==0){
			for(int j=0;j<N;j++)
				ans+=char(numb[j]+'0');
			return 1;
		}
		return 0;
	}

	for(int j=2;j<10;j++){
		int ok=1,p=1;
		numb[dig]=j;
		for(int l=dig;l>=0;l--){
			p=p*numb[l];
			++prod[p];
			if(prod[p]>1)
				ok=0;
		}
		if(ok && Permut(dig+1))
			return 1;
		p=1;
		for(int l=dig;l>=0;l--){
			p=p*numb[l];
			prod[p]--;
		}
	}
	return 0;
}
 
string ColorfulStrings::getKth(int n, int k){

	if(n==1){
		if(k>=11)
			return "";
		else{
			string tmp;
			tmp.push_back(char(k+47));
			return tmp;
		}
	} else if(n>=9)
		return "";
	else{
		memset(prod,0,sizeof(prod));
		K=k,N=n;
		ans="";

		if(N<10)
			Permut(0);

		return ans;
	}
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	ColorfulStrings *obj;
	string answer;
	obj = new ColorfulStrings();
	clock_t startTime = clock();
	answer = obj->getKth(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 4;
	p2 = "238";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 2000;
	p2 = "";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 1;
	p2 = "23457";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 22;
	p2 = "52";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 6;
	p1 = 464;
	p2 = "257936";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}

	return 0;
}
// END KAWIGIEDIT TESTING
