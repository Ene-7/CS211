#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
// Returns the cost of the shortest path from the left to the square in row i, column j.
int calculateCost(int i, int j) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
// Declare the cost matrix.
   static int memo[NUM_ROWS][NUM_COLS] = {{3,0,0,0,0,0},
                                          {6,0,0,0,0,0},
                                          {5,0,0,0,0,0},
                                          {8,0,0,0,0,0},
                                          {3,0,0,0,0,0}};
   // If the cost has already been calculated, return it.
   
   // Check for the base case.
   if (j == 0){
      return memo[i][0];
   }
   if(memo[i][j]!=0){
      return memo[i][j];
   }
   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int up = weight[i][j] + calculateCost(i,j-1); 
   int left = weight[i][j] + calculateCost((i+4)%5,j-1);
   int down = weight[i][j] + calculateCost((i+1)%5,j-1);
   // Find the minimum of the 3 costs.
   int minCost = left;
    if (up < minCost)
        minCost = up; 
    if (down < minCost)
        minCost = down; 
   return memo[i][j] = minCost;
}
int main() {
 int expense[NUM_COLS];
 int minRow;
 for (int i = 0; i < NUM_ROWS; i++){
   expense[i] = calculateCost(i,NUM_COLS-1);
 }
  int min= expense[0];
    for (int i=1; i<NUM_ROWS; i++)
        if (expense[i] < min){
            min = expense[i];
            minRow = i;}    
    cout<<"The Shortest Path Is: "<<min<<endl;
  return 0;
 }
 