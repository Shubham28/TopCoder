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

class SequenceOfCommands {
public:
	string whatHappens(vector <string>);
};

string SequenceOfCommands::whatHappens(vector <string> com) {
	int hor=0,ver=1;
	int posx=0,posy=0;

	EFOR(mov,1,130){

		FOR(all,0,SZ(com))
			FOR(chk,0,SZ(com[all])){
				switch(com[all][chk])
				{
					case 'S':
						posx+=hor,posy+=ver;
						break;
					case 'L':
						if(ver==1)
							hor=-1,ver=0;
						else if(hor==-1)
							ver=-1,hor=0;
						else if(ver==-1)
							hor=1,ver=0;
						else if(hor==1)
							ver=1,hor=0;
						break;
					case 'R':
						if(ver==1)
							swap(ver,hor);
						else if(hor==1)
							hor=0,ver=-1;
						else if(ver==-1)
							swap(ver,hor);
						else if(hor==-1)
							hor=0,ver=1;
				}
			}

		if(mov>75 && posx==0 && posy==0)
			return "bounded";
	}
	return "unbounded";
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	SequenceOfCommands *obj;
	string answer;
	obj = new SequenceOfCommands();
	clock_t startTime = clock();
	answer = obj->whatHappens(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	string p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "bounded";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"SRSL"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "unbounded";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"SSSS","R"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "bounded";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"SRSL","LLSSSSSSL","SSSSSS","L"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "unbounded";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
