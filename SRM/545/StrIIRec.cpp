#include <vector>
#include <string>
#include <numeric>
using namespace std;

class StrIIRec {
public:
  int num_smaller(char c, vector<bool>& used) {
    int count = 0;
    for (int i = 0; i < c - 'a'; i++) {
      if (!used[i]) count++;
    }
    return count;
  }

  char find_kth_char(int k, vector<bool>& used) {
    int count = 0;
    for (int i = 0; i < used.size(); i++) {
      if (!used[i]) {
        if (count == k) return 'a' + i;
        else count++;
      }
    }
    return ' ';
  }

  string recover(vector<int>& inv_count) {
    string res = "";
    vector<bool> used(inv_count.size());
    for (int i = 0; i < inv_count.size(); i++) {
      char c = find_kth_char(inv_count[i], used);
      res += c;
      used[c - 'a'] = true;
    }
    return res;
  }

  string recovstr(int n, int minInv, string minStr) {
    // inv_count[i]: the number of chars smaller than i-th char after i-th
    // inv_couht = {2,0,1,0} <=> "cadb"
    vector<int> inv_count(n, 0);

    // calc assured inversions by minStr
    vector<bool> used(n, false);
    for (int i = 0; i < minStr.size(); i++) {
      char c = minStr[i];
      used[c-'a'] = true;
      inv_count[i] = num_smaller(c, used);
    }
    int inversion = accumulate(inv_count.begin(), inv_count.end(), 0);

    // determine inversion count for each characters from the tail
    for (int i = n-1; i >= 0; i--) {
      if (inversion < minInv) {
        int can_add = n-1 - i - inv_count[i];
        if (minInv - inversion >= can_add) {
          inv_count[i] += can_add;
          inversion += can_add;
        } else {
          inv_count[i] += minInv - inversion;
          inversion = minInv;
        }
      }
    }
    
    if (inversion >= minInv) {
      return recover(inv_count);
    } else {
      return "";
    }
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
