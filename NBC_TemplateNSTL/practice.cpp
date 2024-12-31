#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	vector<int> vec = { 10, 20, 30, 40, 50 };
	map<string, int> mp = {
		{"Alice", 90},
		{"Bob", 85},
		{"Charlie", 95}
	};

	vector<int> vec2(vec.rbegin(), vec.rend()-2);

	return 0;
}