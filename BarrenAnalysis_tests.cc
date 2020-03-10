#define CATCH_CONFIG_MAIN
#include "BarrenLand.h"
#include <catch2/catch.hpp>

SCENARIO("Small Grid", "[vector]") {
	GIVEN("A vector with coordinates") {
		vector<vector<bool> > field(4, vector<bool>(4, true));
		vector<vector<bool> > field_test = {{1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}};
		vector<vector<bool> > visited(4, vector<bool>(4, false));
		vector<vector<bool> > visited_test = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}};
		vector<int> field_area_test = {12};
		vector<string> coordinates = {"0 2 1 3"};
		BarrenLand land;	
		unordered_map<pair<int, int>, int, pair_hash> map;
		pair<int, int> p;
		p.first = 0, p.second = 2;
		map[p] = 1;
		p.second = 3;
		map[p] = 1;
		p.first = 1, p.second = 2;
		map[p] = 1;
		p.second = 3;
		map[p] = 1;
		REQUIRE(map == land.extractInput(coordinates));

		land.setBarrenLand(map, field, visited);

		REQUIRE(field_test == field);
		REQUIRE(visited_test == visited);
		REQUIRE(field_area_test[0] == land.searchForFertileLand(field_test, visited_test)[0]);
	}
}