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

const int ROW = 6;
const int COL = 4;

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
	vector<vector<bool> > field(ROW, vector<bool>(COL, true));
	vector<vector<bool> > visited(ROW, vector<bool>(COL, false));
	vector<string> coordinates;
	char coords[256];
	int totalLandArea = ROW * COL;
	int fertileLandArea = 0;
	int barrenLandArea = 0;
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
				allCoordCount[p] = 1;
			}
		}
	}

	for (auto it = allCoordCount.begin(); it != allCoordCount.end(); it++){
		int x = it->first.first;
		int y = it->first.second;
		field[x][y] = false;
	}

	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j])
				fertileLandArea++;
			else
				barrenLandArea++;
		}
	}

	cout << "fertile: " << fertileLandArea << endl;
	cout << "barren: " << barrenLandArea << endl;


	return 0;
}