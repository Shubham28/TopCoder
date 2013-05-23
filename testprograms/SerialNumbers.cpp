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

class SerialNumbers {
public:
	vector <string> sortSerials(vector <string>);

	bool digit_sum(string &ser1,string &ser2) {
		int sum1=0,sum2=0;

		FOR(c,0,ser1.size())
			sum1=sum1+( ((int)ser1[c]>=48 && (int)ser1[c]<=57)?((int)ser1[c]-48):0 );

		FOR(c,0,ser2.size())
			sum2=sum2+( ((int)ser2[c]>=48 && (int)ser2[c]<=57)?((int)ser2[c]-48):0 );

		if(sum1>sum2){
			string tmp=ser1;
			ser1=ser2,ser2=tmp;
		} else if(sum1==sum2)
			return true;

		return false;
	}
};

vector <string> SerialNumbers::sortSerials(vector <string> slNmb) {

	FOR(i,0,slNmb.size())
		FOR(j,i+1,slNmb.size())
			if(slNmb[i].size()>slNmb[j].size()){
				string tmp=slNmb[i];
				slNmb[i]=slNmb[j],slNmb[j]=tmp;
			}

	FOR(i,0,slNmb.size()-1)
		FOR(j,i+1,slNmb.size())
			if(slNmb[i].size()==slNmb[j].size()){

				if( digit_sum(slNmb[i],slNmb[j]) ){
					string tmp1=(slNmb[i]<slNmb[j])?slNmb[i]:slNmb[j];
					string tmp2=(slNmb[i]>slNmb[j])?slNmb[i]:slNmb[j];
					slNmb[i]=tmp1,slNmb[j]=tmp2;
				}
			}

	return slNmb;
}

double test0() {
	string t0[] = {"ABCD","145C","A","A910","Z321"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SerialNumbers * obj = new SerialNumbers();
	clock_t start = clock();
	vector <string> my_answer = obj->sortSerials(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"A", "ABCD", "Z321", "145C", "A910" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"Z19", "Z20"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SerialNumbers * obj = new SerialNumbers();
	clock_t start = clock();
	vector <string> my_answer = obj->sortSerials(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"Z20", "Z19" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"34H2BJS6N","PIM12MD7RCOLWW09","PYF1J14TF","FIPJOTEA5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SerialNumbers * obj = new SerialNumbers();
	clock_t start = clock();
	vector <string> my_answer = obj->sortSerials(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"FIPJOTEA5", "PYF1J14TF", "34H2BJS6N", "PIM12MD7RCOLWW09" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"ABCDE", "BCDEF", "ABCDA", "BAAAA", "ACAAA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SerialNumbers * obj = new SerialNumbers();
	clock_t start = clock();
	vector <string> my_answer = obj->sortSerials(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"ABCDA", "ABCDE", "ACAAA", "BAAAA", "BCDEF" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

// Author: Shubham Gupta
// Powered by [KawigiEdit] 2.0!; 
