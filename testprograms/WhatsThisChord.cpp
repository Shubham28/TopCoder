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

class WhatsThisChord {
public:
	string classify(vector <int>);
};

string WhatsThisChord::classify(vector <int> chord) {
	set<string>note;
	string place[]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
	int clas[]={4,9,2,7,11,4};

	FOR(pos,0,6){
		if(chord[pos]==-1)
			continue;
		int postion=clas[pos]+chord[pos];

		if(postion>=12)
			postion-=12;
		if(postion<0)
			postion+=12;

		note.insert(place[postion]);
	}

	if(SZ(note)!=3)
		return "";

	int cMaj[]={0,4,7};

	FOR(shft,0,14){
		set<string>tmp;
		FOR(pos,0,3){
			int conv=shft+cMaj[pos];
			conv=conv-((conv>=12)?12:0);
			tmp.insert(place[conv]);
		}
		if(tmp==note){
			int ans=shft+cMaj[0];
			ans=ans-((ans>=12)?12:0);
			return place[ans]+" Major";
		}
	}

	int cMin[]={0,3,7};

	FOR(shft,0,14){
		set<string>tmp;
		FOR(pos,0,3){
			int conv=shft+cMin[pos];
			conv=conv-((conv>=12)?12:0);
			tmp.insert(place[conv]);
		}
		if(tmp==note){
			int ans=shft+cMin[0];
			ans=ans-((ans>=12)?12:0);
			return place[ans]+" Minor";
		}
	}
	return "";
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	WhatsThisChord *obj;
	string answer;
	obj = new WhatsThisChord();
	clock_t startTime = clock();
	answer = obj->classify(p0);
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {-1,3,2,0,1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "C Major";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {3,2,0,0,0,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "G Major";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {-1,0,2,2,1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "A Minor";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {-1,4,3,1,2,1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "C# Major";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {8,10,10,9,8,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "C Major";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {0,0,0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {-1,-1,4,-1,-1,7};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 7 -----
	int t0[] = {-1,-1,2,0,1,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "C Major";
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
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
