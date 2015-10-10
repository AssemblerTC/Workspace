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

class RestaurantManager {
  public:
    int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures) {
      int n = sz(groupSizes);
      vector<int> usado(sz(tables), -1);
      sort(all(tables));
      int ans = 0;
      for (int i = 0; i < n; i++) {
        int tam = groupSizes[i];
        bool ok = false;
        for (int j = 0; j < sz(tables); j++) {
          if (tables[j] >= tam && (usado[j] == -1 || departures[usado[j]] <= arrivals[i])) {
            usado[j] = i;
            ok = true;
            break;
          }
        }
        if (!ok) {
          ans += tam;
        }
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p3[i];
	}
	cout << "}";
	cout << "]" << endl;
	RestaurantManager *obj;
	int answer;
	obj = new RestaurantManager();
	clock_t startTime = clock();
	answer = obj->allocateTables(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	int p4;
	
	{
	// ----- test 0 -----
	int t0[] = {4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 14;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {4,4};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 8;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {4,8};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {4,8,4,2,2,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,10,12,16,18,26};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {10,20,18,26,36,28};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 2;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {10,8,11,16};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {14,1,15,1,19,15,9,15,20,2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {4,5,7,18,21,25,29,31,46,49};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {8,37,11,36,36,46,40,42,47,50};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 69;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {18,15,2,6};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {7,9,16,3,10,3,2,10,16,16};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {10,15,19,20,21,22,27,35,37,43};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {13,24,22,32,32,32,35,48,41,44};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 10;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {13,9,6,1,9,8,6,2,8,20};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {20,10,11,10,1,5,16,2,9,17};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {12,14,64,78,100,121,151,155,162,164};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	int t3[] = {19,26,159,96,155,134,169,199,169,174};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	p4 = 17;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
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
// You are the manager in charge of service at a restaurant.  Over the course of an evening, groups of customers arrive and you need to allocate tables to them.  The restaurant has tables of various sizes in order to cope with different sized groups.  The tables are allocated as follows:
// 
// When a group of customers arrives, it is allocated the smallest unallocated table that is at least as big as the group.  Apart from their sizes, tables are otherwise the same, so if there are multiple appropriate tables, one is allocated arbitrarily.  If there is no appropriate table available when the group arrives, the group is immediately turned away, and it will not return again that evening.  When a group finishes eating and leaves, its table becomes available again to be allocated to a new group of customers.
// 
// You want to know how many customers will be turned away using this method of allocating tables.
// 
// The sizes of the tables in the restaurant are given in a vector <int> tables, in which each element gives the size of a single table.  The size, arrival time and departure time of group i will be represented by groupSizes[i], arrivals[i] and departures[i], respectively.  The groups will be listed in the order that they arrive at the restaurant, and no two groups will arrive at the same time.  If a group arrives at exactly the same time another group departs, the table of the departing group will be available to be allocated to the arriving group (see example 0).  Return the number of customers who are turned away.
// 
// DEFINITION
// Class:RestaurantManager
// Method:allocateTables
// Parameters:vector <int>, vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int allocateTables(vector <int> tables, vector <int> groupSizes, vector <int> arrivals, vector <int> departures)
// 
// 
// CONSTRAINTS
// -tables will contain between 1 and 50 elements, inclusive.
// -Each element of tables will be between 1 and 20, inclusive.
// -groupSizes, arrivals and departures will each contain between 1 and 50 elements, inclusive.
// -groupSizes, arrivals and departures will each contain the same number of elements.
// -Each element of groupSizes will be between 1 and 20, inclusive.
// -Each element of arrivals and departures will be between 0 and 200, inclusive.
// -Element i of arrivals will be strictly less than element i of departures.
// -The elements of arrivals will be distinct and in increasing order.
// 
// 
// EXAMPLES
// 
// 0)
// {4}
// {4,8,4,2,2,4}
// {0,10,12,16,18,26}
// {10,20,18,26,36,28}
// 
// Returns: 14
// 
// This restaurant only has a single table that will seat 4 people. The first group of 4 arrives at time 0 and leaves at time 10. The next group also arrives at time 10, so the table is available, but the group is too big for the table so they are turned away. Another group of 4 then turns up at time 12 and is allocated the table until time 18. The group of 2 that turns up at time 16 is therefore turned away. Another group of 2 comes along at time 18, just as the table becomes available. They are still sitting as the final group comes along, so this group is also turned away. The total number of customers turned away is 8 + 2 + 4 = 14.
// 
// 1)
// {4,4}
// {4,8,4,2,2,4}
// {0,10,12,16,18,26}
// {10,20,18,26,36,28}
// 
// Returns: 8
// 
// With 2 tables, the only group turned away is the group of size 8, which is too big for either table.
// 
// 2)
// {4,8}
// {4,8,4,2,2,4}
// {0,10,12,16,18,26}
// {10,20,18,26,36,28}
// 
// Returns: 2
// 
// Now the restaurant has a table big enough for the group of size 8. A different group of size 2 is turned away later on because a table isn't available when they turn up.
// 
// 3)
// {10,8,11,16}
// {14,1,15,1,19,15,9,15,20,2}
// {4,5,7,18,21,25,29,31,46,49}
// {8,37,11,36,36,46,40,42,47,50}
// 
// Returns: 69
// 
// 4)
// {18,15,2,6}
// {7,9,16,3,10,3,2,10,16,16}
// {10,15,19,20,21,22,27,35,37,43}
// {13,24,22,32,32,32,35,48,41,44}
// 
// Returns: 10
// 
// 5)
// {13,9,6,1,9,8,6,2,8,20}
// {20,10,11,10,1,5,16,2,9,17}
// {12,14,64,78,100,121,151,155,162,164}
// {19,26,159,96,155,134,169,199,169,174}
// 
// Returns: 17
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
