#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CirclesCountry {
public:
	int leastBorders(vector <int>, vector <int>, vector <int>, int, int, int, int);
};

int CirclesCountry::leastBorders(vector <int> X, vector <int> Y, vector <int> R, int x1, int y1, int x2, int y2) {
	
	int count=0;
	for(long long int i=0;i<X.size();i++){
		long long int cal1,cal2;
		cal1= (x1-X[i])*(x1-X[i]) + (y1-Y[i])*(y1-Y[i]) - R[i]*R[i];
		cal2= (x2-X[i])*(x2-X[i]) + (y2-Y[i])*(y2-Y[i]) - R[i]*R[i];
		
		if(cal1*cal2<0)
			++count;
	}
	return count;
}


double test0() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = -5;
	int p4 = 1;
	int p5 = 5;
	int p6 = 1;
	CirclesCountry * obj = new CirclesCountry();
	clock_t start = clock();
	int my_answer = obj->leastBorders(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0,-6,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,2,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = -5;
	int p4 = 1;
	int p5 = 5;
	int p6 = 1;
	CirclesCountry * obj = new CirclesCountry();
	clock_t start = clock();
	int my_answer = obj->leastBorders(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,-3,2,5,-4,12,12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,-1,2,5,5,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8,1,2,1,1,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = -5;
	int p4 = 1;
	int p5 = 12;
	int p6 = 1;
	CirclesCountry * obj = new CirclesCountry();
	clock_t start = clock();
	int my_answer = obj->leastBorders(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {-3,2,2,0,-4,12,12,12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-1,2,3,1,5,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3,1,7,1,1,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	int p4 = 3;
	int p5 = 13;
	int p6 = 2;
	CirclesCountry * obj = new CirclesCountry();
	clock_t start = clock();
	int my_answer = obj->leastBorders(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {135,42,70,39,89,39,43,150,10,120,16,8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 102;
	int p4 = 16;
	int p5 = 19;
	int p6 = -108;
	CirclesCountry * obj = new CirclesCountry();
	clock_t start = clock();
	int my_answer = obj->leastBorders(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
