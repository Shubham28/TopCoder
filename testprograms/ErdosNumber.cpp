#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <set>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() );
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VL vector<long>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>

using namespace std;

class ErdosNumber {
public:
	vector <string> calculateNumbers(vector <string>);

	string conv(int num) {
		if(num==0)
			return "0";
			
		string ret="";
		while(num!=0){
			ret+= (char)( (num%10) + 48 );
			num/=10;
		}
		reverse( ret.begin(),ret.end() );
		return ret;
	}
};

vector <string> ErdosNumber::calculateNumbers(vector <string> publications) {
	vector< VS >pair;
	map<string,bool>ch;
	map<string,int>num;
	
	VS ret;
	string tmp="";
	
	FOR(i,0,publications.size()){
		publications[i]+=" ";
		VS tmp;
		string tm="";
		
		FOR(j,0,publications[i].size()){
			if(publications[i][j]!=' ')
				tm+=publications[i][j];
			else{
				PB(tmp,tm);
				ch[tm]=false,num[tm]=0;
				tm="";
			}
		}
		PB(pair,tmp);
		tmp.clear();
	}
	ch["ERDOS"]=true;

	VS stac(1,"ERDOS");
	int count=1;
	
	while(stac.size()>0){
		VS que;
		FOR(r,0,pair.size()){
			FOR(c,0,pair[r].size()){
	
				FOR(m,0,stac.size()){
			
					if(pair[r][c]==stac[m]){
						FOR(l,0,pair[r].size()){
							if(l!=c && !ch[pair[r][l]]){
								ch[pair[r][l]]=true;
								PB(que,pair[r][l]);  }
						}
					}
				}
			}
		}
		
		FOR(n,0,que.size())
			num[que[n]]=count;

		stac.clear();
		FOR(n,0,que.size())
			PB(stac,que[n]);

		que.clear();
		++count;
	}
	map<string,int>::iterator it;
	map<string,bool>::iterator itb;
	itb=ch.begin();

	for(it=num.begin();it!=num.end();itb++,it++){
		PB(ret,it->first);
		if(itb->second){
			ret[ret.size()-1]+= ' ';
			ret[ret.size()-1]+= conv(it->second);
		}
	}
	return ret;
}
double test0() {
	string t0[] = {"ERDOS"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ErdosNumber * obj = new ErdosNumber();
	clock_t start = clock();
	vector <string> my_answer = obj->calculateNumbers(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"ERDOS 0" };
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
	string t0[] = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ErdosNumber * obj = new ErdosNumber();
	clock_t start = clock();
	vector <string> my_answer = obj->calculateNumbers(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" };
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
	string t0[] = {"ERDOS A", "A B", "B AA C"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ErdosNumber * obj = new ErdosNumber();
	clock_t start = clock();
	vector <string> my_answer = obj->calculateNumbers(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" };
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
	string t0[] = {"ERDOS B", "A B C", "B A E", "D F"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ErdosNumber * obj = new ErdosNumber();
	clock_t start = clock();
	vector <string> my_answer = obj->calculateNumbers(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" };
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
double test4() {
	string t0[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
 "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ErdosNumber * obj = new ErdosNumber();
	clock_t start = clock();
	vector <string> my_answer = obj->calculateNumbers(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" };
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
