#include <bits/stdc++.h>

using namespace std;

// code hallucinogene fait a 1 heur du matin, je m'excuse d'avance.
// hallucinogenic-fueled 1-am code, i apologize in advance


int main() {
  freopen("input.txt", "r", stdin);

  map<int, vector<int>> rules;
  int sum = 0;

  string x;
  while (cin >> x) {
    auto col = x.find('|');
    if (col != string::npos) {
      int num1 = stoi(x.substr(0, col));
      int num2 = stoi(x.substr(col+1, x.size()));

      auto numsThatNum1IsSmallerThan = rules.find(num1);
      if (numsThatNum1IsSmallerThan != rules.end()) {
        rules[num1].push_back(num2);
      }
      else {
        rules[num1] = {num2};
      }
    }
    else {
      bool respecting_rules = true;
      vector<int> test_case = {};
      size_t start = 0;
      size_t end = x.find(",");

      while (end != string::npos) {
        test_case.push_back(stoi(x.substr(start, end - start)));
        start = end + 1;
        end = x.find(",", start);
      }
      test_case.push_back(stoi(x.substr(start))); // add the last one, oops

      for (unsigned long i=0; i<test_case.size(); i++) {
        int number = test_case[i];
        vector<int> rule_nums = rules[number];
        for (int rule : rule_nums) {
          auto rule_exists_find = find(test_case.begin(), test_case.end(), rule);
          if (rule_exists_find != test_case.end() && i > distance(test_case.begin(), rule_exists_find) && respecting_rules) {
            // not anymore
            respecting_rules = false;
            break;
          }
        }
        if (!respecting_rules) {
          break; // janky way to break out twice
        }
      }

      if (respecting_rules) {
        // find the item at the middle
        size_t middle_i = test_case.size()/2;
        sum += test_case[middle_i];
      }
    }
  }

  cout << "sum: " << sum << endl;

  return 0;
}
