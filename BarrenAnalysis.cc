#include "BarrenLand.h"

using namespace std;

const int ROW = 600;
const int COL = 400;

int main() {
	BarrenLand barrenLand;
	unordered_map<pair<int, int>, int, pair_hash> allCoordCount;
	vector<vector<bool> > field(ROW, vector<bool>(COL, true));
	vector<vector<bool> > visited(ROW, vector<bool>(COL, false));
	vector<string> coordinates;
	char coords[256];
	queue<pair<int, int> > queue;
	vector<int> fertileAreas;

	// get user input coordinates
	cout << "Enter coordinates (e to end): ";
	while (cin.getline (coords, 256)) {
		if (coords[0] == 'e')
			break;
		coordinates.push_back(coords);
	}

	barrenLand.extractInput(coordinates, allCoordCount);
	barrenLand.setBarrenLand(allCoordCount, field, visited);
	barrenLand.searchForFertileLand(field, visited, fertileAreas);
	sort(fertileAreas.begin(), fertileAreas.end());

	for (auto a : fertileAreas)
		cout << a << " ";
	cout << endl;

	return 0;
}