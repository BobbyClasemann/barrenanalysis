#include "BarrenLand.h"
#include <gtest/gtest.h>

class BarrenLandTest : public ::testing::Test {
protected:
	unordered_map<pair<int, int>, int, pair_hash> map;
	unordered_map<pair<int, int>, int, pair_hash> allCoords;
	pair<int, int> p;
	BarrenLand land;
	vector<string> coordinates;
};

TEST(BarrenLandTest, ExtractInputIntoMap) {
	vector<string> coordinates = {"0 2 1 3"};
	p.first = 0, p.second = 2;
	map[p] = 1;
	p.second = 3;
	map[p] = 1;
	p.first = 1, p.second = 2;
	map[p] = 1;
	p.second = 3;
	map[p] = 1;
	EXPECT_EQ(map, land.extractInput(coordinates, allCoords));
}
