#include <unordered_map>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <functional>

using namespace std;

struct pair_hash {
	template <class T1, class T2>
	size_t operator () (const pair<T1, T2> &p) const {
		T1 h1 = hash<T1>()(p.first);
		T2 h2 = hash<T2>()(p.second);
		return h1 ^ h2;
	}
};

int main() {
	unordered_map<pair<int, int>, int, pair_hash> allCoordCount;
	unordered_map<pair<int, int>, int, pair_hash> perimeterCoordCount;
	vector<string> coordinates;
	char coords[256];
	cout << "Enter coordinates (e to end): ";
	while (cin.getline (coords, 256)) {
		if (coords[0] == 'e')
			break;
		coordinates.push_back(coords);
	}

	for (int i = 0; i < coordinates.size(); i++) {
		stringstream ss(coordinates[i]);
		int x1, y1, x2, y2;
		ss >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++) {
			for (int k = y1; k <= y2; k++) {
				pair<int, int> p;
				p.first = j;
				p.second = k;
				if (allCoordCount.find(p) == allCoordCount.end()) {
					allCoordCount[p] = 1;
				} else {
					allCoordCount[p]++;
				}
			}
		}
	}

	for (auto it = allCoordCount.begin(); it != allCoordCount.end(); it++){
		int x = it->first.first;
		int y = it->first.second;
	}



	int area = 0;

	return area;
}