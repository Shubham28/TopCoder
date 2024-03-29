#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <bitset>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class AgeEncoding {
public:
	double getRadix(int, string);
};

double AgeEncoding::getRadix(int age, string cLine) {

	double conv=0;
	FOR(i,0,cLine.size())
		conv=conv+( (cLine[i]=='1')?pow(10.0,cLine.size()-1.0-i):0 );

	if(conv==0 || (conv==1 && age!=1) )
		return -1.0;
	else if(conv==1 && age==1)
		return -2.0;
	else if(conv!=1 && cLine[cLine.size()-1]=='1' && age==1)
		return -1.0;

	double start=0.0,end=age+0.0,mid;
	while(true){
	
		double conv=0;
		FOR(i,0,cLine.size())
			conv=conv+( (cLine[i]=='1')?pow(start,cLine.size()-1.0-i):0 );
		if(abs(conv-age)<1e-9)
			return start;
		
		conv=0;
		FOR(i,0,cLine.size())
			conv=conv+( (cLine[i]=='1')?pow(end,cLine.size()-1.0-i):0 );
		if(abs(conv-age)<1e-9)
			return end;
			
		mid=(start+end)/2.0;
		conv=0;
		FOR(i,0,cLine.size())
			conv=conv+( (cLine[i]=='1')?pow(mid,cLine.size()-1.0-i):0 );
		if(abs(conv-age)<1e-9)
			return mid;

		if(conv<age)
			start=mid;
		else
			end=mid;
	}
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, string p1, bool hasAnswer, double p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	AgeEncoding *obj;
	double answer;
	obj = new AgeEncoding();
	clock_t startTime = clock();
	answer = obj->getRadix(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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
	double p2;
	
	{
	// ----- test 0 -----
	p0 = 10;
	p1 = "00010";
	p2 = 10.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 21;
	p1 = "10101";
	p2 = 2.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 6;
	p1 = "10100";
	p2 = 1.414213562373095;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 21;
	p1 = "10111111110111101111111100111111110111111111111100";
	p2 = 0.9685012944510603;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 16;
	p1 = "1";
	p2 = -1.0;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1;
	p1 = "1";
	p2 = -2.0;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 1;
	p1 = "00000101010111100101";
	p2 = -1.0;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
