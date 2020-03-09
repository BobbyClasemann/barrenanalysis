#include <unordered_map>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>
#include <functional>
#include <queue>

using namespace std;

const int ROW = 600;
const int COL = 400;

struct pair_hash {
	template <class T1, class T2>
	size_t operator () (const pair<T1, T2> &p) const {
		T1 h1 = hash<T1>()(p.first);
		T2 h2 = hash<T2>()(p.second);
		return h1 ^ h2;
	}
};

void extractInput(vector<string> coordinates, unordered_map<pair<int, int>, int, pair_hash>& allCoordCount) {
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
}

void setBarrenLand(unordered_map<pair<int, int>, int, pair_hash>& allCoordCount, 
	vector<vector<bool> >& field, vector<vector<bool> >& visited) {
		for (auto it = allCoordCount.begin(); it != allCoordCount.end(); it++){
		int x = it->first.first;
		int y = it->first.second;
		field[y][x] = false;
		visited[y][x] = true;
	}
}

void searchForFertileLand(vector<vector<bool> >& field, vector<vector<bool> >& visited,
	vector<int>& fertileAreas) {
	int fertileLandArea = 0;
	queue<pair<int, int> > queue;

	for (int i = 0; i < field.size(); i++) {
		for (int j = 0; j < field[i].size(); j++) {
			if (field[i][j] && !visited[i][j]) {
				pair<int, int> p;
				p.first = i;
				p.second = j;
				queue.push(p);
				while (!queue.empty()) {
					int n = queue.size();
					for (int k = 0; k < n; k++) {
						pair<int, int> point;
						int x = queue.front().first;
						int y = queue.front().second;
						queue.pop();
						if (x < 0 || x >= field.size() || y < 0 || y >= field[0].size() || visited[x][y])
							continue;
						visited[x][y] = true;
						if (field[x][y])
							fertileLandArea++;
						point.first = x+1, point.second = y;
						queue.push(point);
						point.first = x-1, point.second = y;
						queue.push(point);
						point.first = x, point.second = y+1;
						queue.push(point);
						point.first = x, point.second = y-1;
						queue.push(point);
					}
				}
				fertileAreas.push_back(fertileLandArea);
				fertileLandArea = 0;
			}
		}
	}
}

int main() {
	unordered_map<pair<int, int>, int, pair_hash> allCoordCount;
	vector<vector<bool> > field(ROW, vector<bool>(COL, true));
	vector<vector<bool> > visited(ROW, vector<bool>(COL, false));
	vector<string> coordinates;
	char coords[256];
	queue<pair<int, int> > queue;
	vector<int> fertileAreas;

	// get user input coordiantes
	cout << "Enter coordinates (e to end): ";
	while (cin.getline (coords, 256)) {
		if (coords[0] == 'e')
			break;
		coordinates.push_back(coords);
	}

	extractInput(coordinates, allCoordCount);
	
	setBarrenLand(allCoordCount, field, visited);

	searchForFertileLand(field, visited, fertileAreas);

	sort(fertileAreas.begin(), fertileAreas.end());

	for (auto a : fertileAreas)
		cout << a << " ";
	cout << endl;

	return 0;
}