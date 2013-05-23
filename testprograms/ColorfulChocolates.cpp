#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <numeric>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))
#define SZ(A) int(A.size())
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define LL long long

using namespace std;

class ColorfulChocolates {
public:
	int maximumSpread(string, int);
};

int ColorfulChocolates::maximumSpread(string choc, int max) {
	map<char, VI >pos;

	FOR(a,0,SZ(choc))
		PB(pos[choc[a]],a);

	int ret=1;
	int tmp[51];

	for(map<char, VI >::iterator it=pos.begin();it!=pos.end();it++){
		int N=SZ((*it).second);

		if(N>1){
			RFOR(chk,N,2){

				EFOR(st,0,N-chk){

					FOR(c,0,chk)		tmp[c]=(*it).second[st+c];

					int req=0;
					if(chk&1){
						int half=chk>>1;
						int median=tmp[half];

						FOR(c,0,chk){
							if(c<median)
								req+=abs(median+c-half-tmp[c]);
							else
								req+=abs(tmp[c]-(median+c-half));
						}
					} else {
						int half=chk>>1;
						int median=(tmp[half-1]+tmp[half])/2;

						FOR(c,0,chk){
							if(c<half)
								req+=abs(median+c+1-half-tmp[c]);
							else
								req+=abs(tmp[c]-(median+c+1-half));
						}
					}
					if(req<=max){
						ret>?=chk;
						break;
					}
				}
			}
		}
	}
	return ret;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << p1;
	cout << "]" << endl;
	ColorfulChocolates *obj;
	int answer;
	obj = new ColorfulChocolates();
	clock_t startTime = clock();
	answer = obj->maximumSpread(p0, p1);
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
	
	string p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = "ABCDCBC";
	p1 = 1;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "ABCDCBC";
	p1 = 2;
	p2 = 3;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "ABBABABBA";
	p1 = 3;
	p2 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "ABBABABBA";
	p1 = 4;
	p2 = 5;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "QASOKZNHWNFODOQNHGQKGLIHTPJUVGKLHFZTGPDCEKSJYIWFOO";
	p1 = 77;
	p2 = 5;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "ABCBABCBABCBABCBABCBABABAAABBCCCCCCCCAABBBB";
	p1 = 50;
	p2 = 13;
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
