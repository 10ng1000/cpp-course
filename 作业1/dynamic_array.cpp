#include <iostream>
using namespace std;

int main(){
  int m, n;
  cin >> m >> n;
  //m = 3, n = 5;
  int **p = new int*[m];
  for (int i = 0; i < m; i++){
    p[i] = new int[n];
  }
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> p[i][j];
    }
  }
  int sum = 0;
  int max = p[0][0];
  int min = p[0][0];
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      sum += p[i][j];
      if (p[i][j] > max){
        max = p[i][j];
      }
      if (p[i][j] < min){
        min = p[i][j];
      }
    }
  }
  cout << "sum: " << sum << endl;
  cout << "max: " << max << endl;
  cout << "min: " << min << endl;
  for (int i = 0; i < m; i++){
    delete [] p[i];
  }
  delete [] p;
  return 0;
}