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
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

class Thirteen {
public:
	int calcTime(vector <string>);
};

int Thirteen::calcTime(vector <string> city) {
	int N=SZ(city);
	VB trav(N,false);
	VI wght(N,9999999);
	trav[0]=true,wght[0]=0;

	while(true){

		FOR(pos,0,N){
			if(trav[pos]){

				int minim=99999999,node;
				FOR(all,0,N){
					if('A'<=city[pos][all] && city[pos][all]<='Z'  && !trav[all])
						if(minim>=(city[pos][all]-'A'+1))
							minim=city[pos][all]-'A'+1,node=all;
					else if('a'<=city[pos][all] && city[pos][all]<='z' && !trav[all])
						if(minim>=(city[pos][all]-'a'+27))
							minim=city[pos][all]-'a'+27,node=all;
				}
				if(minim+wght[pos]%13==0)
					continue;
				else
					wght[node]=wght[pos]+minim,trav[pos]=true;
			}
		}

	}

	if(wght[N-1]==9999999)
		return -1;
	return wght[N-1];
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Thirteen *obj;
	int answer;
	obj = new Thirteen();
	clock_t startTime = clock();
	answer = obj->calcTime(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"#AB##","###A#","###C#","####K","#####"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 16;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"#Z","Z#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -1;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"#A#C##","##FA#K","###D#D","A###A#","##C###","####A#"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"Good#####","#Luck####","##and####","##Have###","####Fun##","#####in##","#####the#","CHALLENGE","##PHASE##"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 137;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"###No#####","####Zaphod","#####Just#","######very","####very##","improbable","##########","##########","##########","##########"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 103;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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