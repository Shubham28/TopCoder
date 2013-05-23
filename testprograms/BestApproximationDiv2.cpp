#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

class BestApproximationDiv2 {
public:
	string findFraction(int, string);

	int matches(int num,int den,string &numb){
		num*=10;
		int ret=0;
		FOR(pos,2,SZ(numb)){
			int rem=num/den;
			if(rem==(numb[pos]-'0'))
				++ret,num%=den,num*=10;
			else
				break;
		}
		return ret+1;
	}
};

string BestApproximationDiv2::findFraction(int maxDen, string number) {
	double aver=atof(number.c_str());
	int cost=-1,numer,denom;

	EFOR(den,1,maxDen){
		int strt=int((den+0.)*aver)-10,fin=int((den+0.)*aver)+10;
		EFOR(num,max(0,strt),min(den-1,fin)){
			int tmp=matches(num,den,number);
			if(cost<tmp)
				cost=tmp,numer=num,denom=den;
		}
	}
	char ret[30];
	sprintf(ret,"%d/%d has %d exact digits",numer,denom,cost);

	return string(ret);
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	BestApproximationDiv2 *obj;
	string answer;
	obj = new BestApproximationDiv2();
	clock_t startTime = clock();
	answer = obj->findFraction(p0, p1);
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
	string p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = 42;
	p1 = "0.141592658";
	p2 = "1/7 has 3 exact digits";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = "0.1337";
	p2 = "0/1 has 1 exact digits";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 80000;
	p1 = "0.1234567891011121314151617181920";
	p2 = "10/81 has 8 exact digits";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 1000;
	p1 = "0.42";
	p2 = "3/7 has 3 exact digits";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100;
	p1 = "0.420";
	p2 = "21/50 has 4 exact digits";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 115;
	p1 = "0.141592658";
	p2 = "16/113 has 7 exact digits";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
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
// Author: Shubham Gupta
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
