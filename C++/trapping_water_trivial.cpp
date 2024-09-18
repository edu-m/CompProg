#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(vector<int> &h, int s) {
  vector<int> ret = h;
  for (int i = 0; i < ret.size(); i++)
    ret[i] = h[i] >= s;
  return ret;
}

int findWells(vector<int> &slice) {
  int start;
  int end;
  int sum = 0;
  bool state = 0;
  for (int i = 0; i < slice.size(); i++) {
    if (slice[i] > 0) { // '>' is to avoid bugs, we can't guarantee that caller
                        // passes a boolean array
      if (state == 0) {
        start = i;
        state = 1;
      } else {
        end = i;
        sum += end - start - 1;
        start = i;
      }
    }
  }
  //  cout << start << " " << end << endl;
  return sum;
}

int find_max(vector<int> &height){
  int max = -1;
  for(auto k : height)
    max = k > max ? k : max;
  return max;
}

int trap(vector<int> &height) {
  int sum = 0;
  int max = find_max(height);
  for (int i = 0; i < max; i++) {
    auto temp = slice(height, i+1);
    sum += findWells(temp);
  }

  return sum;
}

int main() {
  vector<int> height = {2,0,2};
  cout << trap(height);
}