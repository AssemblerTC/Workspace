#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#include <climits>

using namespace std;

#define DBG(X) cerr << #X << " = " << X << '\n';
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)

class Embassy {
  public:
    int visaApplication(vector <int> forms, int dayLength, int openTime) {
      int ans = INT_MAX;
      for (int ini = 0; ini < dayLength; ini++) {
        int cur = ini, tiempo = 0;
        for (int i = 0; i < sz(forms); i++) {
          tiempo += forms[i];
          cur += forms[i];
          while (cur >= dayLength) {
            cur -= dayLength;
          }
          if (cur > openTime) {//closed
            int to_wait = dayLength - cur;
            tiempo += to_wait;
            cur += to_wait;
          }
        }    
        ans = min(ans, tiempo);
      }
      return ans;    
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	Embassy *obj;
	int answer;
	obj = new Embassy();
	clock_t startTime = clock();
	answer = obj->visaApplication(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {4,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 24;
	p2 = 8;
	p3 = 12;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {4,4,4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 24;
	p2 = 8;
	p3 = 28;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,2,2,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 24;
	p2 = 1;
	p3 = 73;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {25,500,630,2500,1000,350,22,58,100,400,500,5000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1440;
	p2 = 360;
	p3 = 16945;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// You've just qualified for the on-site round of a major coding tournament! You now need to sort out a visa to allow you to travel to the event. You know that this is likely to be a long process, but are determined to sort it out as quickly as possible, even if it means working day and night. The process involves filling out a series of forms, which then have to be approved by the embassy. When the last form is approved your visa is granted. The approval process is very quick (instantaneous for the purpose of this problem), but there is a catch: each form has to be approved by the embassy before they will give you the next form to fill out. The embassy opens at exactly the same time each day and remains open for openTime time units. By the non-standard embassy clocks, a day is dayLength time units long, so the embassy then remains closed for dayLength - openTime time units before it opens the next day. Forms can be approved at any point in time between the time that the embassy opens and the time it closes, inclusive. However, if you finish filling in a form when the embassy is closed, you have to wait until it opens again before the form can be approved. The length of time it takes you to fill out form i is forms[i] units and the forms must be completed in the order they are given in forms. You already have the first form in your possession and can start filling it out at any time. Return the minimum length of time between starting to fill out the first form and getting your visa granted.
// 
// DEFINITION
// Class:Embassy
// Method:visaApplication
// Parameters:vector <int>, int, int
// Returns:int
// Method signature:int visaApplication(vector <int> forms, int dayLength, int openTime)
// 
// 
// CONSTRAINTS
// -forms will contain between 1 and 50 elements, inclusive.
// -Each element of forms will be between 1 and 1,000,000 (10^6), inclusive.
// -dayLength will be between 1 and 1,000,000 (10^6), inclusive.
// -openTime will be between 1 and dayLength, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {4,4,4}
// 24
// 8
// 
// Returns: 12
// 
// The embassy is open for 8 hours out of a 24 hour day. Each of the three forms takes 4 hours to fill in. If you start filling in the first form 4 hours before the embassy opens, you can get it approved just as the embassy opens. The embassy will still be open 4 hours later to approve the second form and the third form can be approved just as the embassy shuts. Since you never have to wait, the total time is 12 hours.
// 
// 1)
// {4,4,4,4}
// 24
// 8
// 
// Returns: 28
// 
// Now there is an additional form to fill in. You can't complete the process in a single day.
// 
// 2)
// {2,2,2,2}
// 24
// 1
// 
// Returns: 73
// 
// The embassy is only open for one hour each day, so you can only get one form approved per day.
// 
// 3)
// {25,500,630,2500,1000,350,22,58,100,400,500,5000}
// 1440
// 360
// 
// Returns: 16945
// 
// Time is now measured in minutes. It's optimal to start filling in the first form 335 minutes after the embassy first opens.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
