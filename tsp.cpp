tsp
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_CITIES = 20; // Maximum number of cities (adjust as needed)

int tsp(int mask, int currentCity, int distance[MAX_CITIES][MAX_CITIES], int memo[1 << MAX_CITIES][MAX_CITIES]) {
    int numCities = __builtin_popcount(mask); // Count the number of set bits in the mask

    // If all cities have been visited, return the cost of returning to the starting city
    if (numCities == 1) {
        return distance[currentCity][0];
    }

    // If the result is already memoized, return it
    if (memo[mask][currentCity] != -1) {
        return memo[mask][currentCity];
    }

    int minCost = INT_MAX;

    // Try to visit each unvisited city
    for (int nextCity = 0; nextCity < MAX_CITIES; ++nextCity) {
        if ((mask & (1 << nextCity)) == 0) {
            int newMask = mask | (1 << nextCity);
            int cost = distance[currentCity][nextCity] + tsp(newMask, nextCity, distance, memo);
            minCost = min(minCost, cost);
        }
    }

    // Memoize the result
    memo[mask][currentCity] = minCost;

    return minCost;
}

int main() {
    // Example: Distance matrix between cities
    int distance[MAX_CITIES][MAX_CITIES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Memoization table
    int memo[1 << MAX_CITIES][MAX_CITIES];
    fill_n(&memo[0][0], (1 << MAX_CITIES) * MAX_CITIES, -1);

    // Start the TSP from city 0 with the initial mask representing only city 0 as visited
    int minTourCost = tsp(1, 0, distance, memo);

    cout << "Minimum Tour Cost: " << minTourCost << endl;

    return 0;
}
