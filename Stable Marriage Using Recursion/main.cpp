#include <iostream>
using namespace std;


bool ok(int q[], int col){
  static int mp[3][3] = {{0,2,1},
                        {0,2,1},
                        {1,2,0}};
                    
  static int wp[3][3] = {{2,1,0},
                        {0,1,2},
                        {2,0,1}};
                    
    int nm = col;//new man
    int nw = q[col];//new woman
    for(int i = 0; i < col; i ++){
      if(q[col] == q[i]) return false;
      int m = i; // Man
      int w = q[i]; // Woman
      //if the new woman has already been assigned to some man then return false
      if((mp[m][nw]<mp[m][w])&&(wp[nw][m]<wp[nw][nm])) return false;
      if((mp[nm][w]<mp[nm][nw])&&(wp[w][nm]<wp[w][m])) return false;
      
    }
  return true;
  }
void print(int q[]) {
  static int solution = 0;
  cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
  for (int i = 0; i < 3; ++i)
  cout << i << "\t" << q[i] << "\n";
  cout << "\n";
  }
void next(int q[], int c){
     if (c == 3)
      print(q);
   else for (q[c] = 0; q[c] <3 ; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main(){
  int q[3];
  next(q,0);
  return 0;
}