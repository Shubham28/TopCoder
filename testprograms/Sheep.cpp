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

int ar[2001];

class Sheep {
public:
	int minCapacity(int, int, vector <string>, vector <string>, vector <string>, vector <string>);

	bool possib(int count,int maxr,int targ){
		multiset<int>shps(ar,ar+count);
		multiset<int>::iterator it;

		if(*(--shps.end())>targ)
			return false;

		int trips=0,capac;
		while(trips<maxr){
			capac=targ;
			while(SZ(shps)){
				it=shps.upper_bound(capac);
				if(it==shps.begin())
					break;
				--it;
				capac-=*it;
				shps.erase(it);
			}
			if(shps.empty())
				return true;
			++trips;
		}
		return false;
	}
};

int Sheep::minCapacity(int numSheep, int maxRuns, vector <string> part1, vector <string> part2, vector <string> part3, vector <string> part4) {
	string shp1="",shp2="",shp3="",shp4="";

	FOR(fir,0,SZ(part1))	shp1+=part1[fir];
	FOR(sec,0,SZ(part2))	shp2+=part2[sec];
	FOR(thr,0,SZ(part3))	shp3+=part3[thr];
	FOR(frt,0,SZ(part4))	shp4+=part4[frt];

	int pos=0;
	string tot=shp1+shp2+shp3+shp4;
	stringstream sconv;
	sconv<<tot;

	int brk;
	while(sconv>>brk)
		ar[pos++]=brk;

	sort(ar,ar+numSheep);
	int lo=ar[numSheep-1],hi=accumulate(ar,ar+numSheep,0);
	while(lo+1<hi){
		int mid=lo+(hi-lo)/2;

		if(possib(numSheep,maxRuns,mid))
			hi=mid;
		else
			lo=mid;
	}
	EFOR(chk,max(0,hi-ar[numSheep-1]),hi)
		if(possib(numSheep,maxRuns,chk))
			return chk;
}
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <string> p2, vector <string> p3, vector <string> p4, vector <string> p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p3[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p5.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p5[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	Sheep *obj;
	int answer;
	obj = new Sheep();
	clock_t startTime = clock();
	answer = obj->minCapacity(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	vector <string> p2;
	vector <string> p3;
	vector <string> p4;
	vector <string> p5;
	int p6;
	/*
	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 2;
	string t2[] = {"26 7 10 30 5 4"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3.clear();
	p4.clear();
	p5.clear()/;
	p6 = 42;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 6;
	p1 = 2;
	string t2[] = {"4 8 15 16 23 42"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3.clear();
	p4.clear();
	p5.clear();
	p6 = 54;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 15;
	p1 = 4;
	string t2[] = {"666 42 7 13 400 511 600 200 202 111 313 94 280"," 72 42"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3.clear();
	p4.clear();
	p5.clear();
	p6 = 896;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 7;
	p1 = 6;
	string t2[] = {"200 2","01 202 203"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {" 204 "};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4.clear();
	string t5[] = {"205"," ","206"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	p6 = 401;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 200;
	p1 = 20;
	string t2[] = {"42 468 335 501 1170 1725 1479 1359 963 465 1706"," 146 1282 828 1962 492 996 1943 828 1437 392 605"," 1903 154 293 383 1422 717 1719 1896 1448 1727"," 772 1539 1870 1913 1668 300 1036 1895 704 1812"," 1323 334 1674 665 1142 1712 254 869 1548 1645"," 663 758 38 860 724 1742 1530 779 317 1036 191"," 1843 289 107 1041 943 1265 649 1447 1806 1891"," 730 371 1351 1007 1102 394 1549 1630 624 85 1955"," 757 1841 967 1377 1932 309 945 440 627 1324 1538"," 1539 119 83 930 542 834 1116 640 1659 705 1931"," 1978 307 1674 387 1022 746 925 1073 271 1830 778"," 1574 1098 513 1987 1291 1162 637 356 768 1656"," 1575 32 53 1351 1151 942 1725 1967 1431 1108 192"," 8 1338 1458 288 1754 384 946 910 210 1759 222"," 589 423 947 1507 1031 414 1169 901 592 763 1656"," 1411 360 1625 538 1549 484 1596 42 1603 351 292"," 837 1375 1021 597 22 1349 1200 1669 485 282 735"," 54 2000 419 1939 901 1789 128 468 1729 894 649"," 484 1808 422 311 618 814 1515"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3.clear();
	p4.clear();
	p5.clear();
	p6 = 9986;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 10;
	p1 = 3;
	string t2[] = {"17 16 10 10 9 8 8 7 6 5"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3.clear();
	p4.clear();
	p5.clear();
	p6 = 32;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}*/
	
	{
	// ----- test 6 -----
	p0 = 2000;
	p1 = 1;
	string t2[] = {"1987 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2"
			" 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 "
			"2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {" 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2"
			" 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"," 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4.clear();
	p5.clear();
	p6 = 5985;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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