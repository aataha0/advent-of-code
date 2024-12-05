#include <bits/stdc++.h>

using namespace std;

// code hallucinogene fait a 1 heur du matin, je m'excuse d'avance.
// hallucinogenic-fueled 1-am code, i apologize in advance

bool check_compliance(const vector<int>& test_case, const map<int, vector<int>>& rules) {
  for (size_t i=0; i<test_case.size(); i++) {
    int number = test_case[i];
    auto it = rules.find(number);
    if (it != rules.end()) {
      const vector<int>& rule_nums = it->second;
      for (int rule : rule_nums) {
        auto rule_exists_find = find(test_case.begin(), test_case.end(), rule);
        if (rule_exists_find != test_case.end() && i > distance(test_case.begin(), rule_exists_find)) {
          // not anymore
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);

  map<int, vector<int>> rules;
  int sum = 0;

  string x;
  while (cin >> x) {
    auto col = x.find('|');
    if (col != string::npos) {
      // rule learning
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
      // rule applying
      // number, rule, sorting key
      vector<int> test_case = {};

      // fill the test_case vector with ints
      size_t start = 0;
      size_t end = x.find(",");
      while (end != string::npos) {
        test_case.push_back(stoi(x.substr(start, end - start)));
        start = end + 1;
        end = x.find(",", start);
      }
      test_case.push_back(stoi(x.substr(start)));

      bool early_compliance = check_compliance(test_case, rules);
      if (early_compliance) {
        // we only want the ones that don't comply, so bye
        continue;
      }

      // go over every number to check for its rule compliance
      // this code is brought to you by caffeine, 3am and anthropic claude-assisted chaos
      while (!check_compliance(test_case, rules)) {
        for (unsigned long i=0; i<test_case.size(); i++) {
          int number = test_case[i];
          if (rules.count(number)) {
            for (int rule : rules[number]) {
              auto rule_exists_find = find(test_case.begin(), test_case.end(), rule);
              size_t rule_index = distance(test_case.begin(), rule_exists_find);

              if (rule_exists_find != test_case.end() && i > rule_index) {
                  test_case.erase(rule_exists_find);
                  // since rule_index is before number_index (test_case.begin()+i), and we erase the former, we don't need to add one since the list shifts by one to the left
                  test_case.insert(test_case.begin()+i, rule);
              }
            }
          }
        }
      }

      bool respecting_rules = check_compliance(test_case, rules);
      // cout << "respecting " << respecting_rules << endl;
    
      if (respecting_rules) {
        size_t middle_i = test_case.size() / 2;
        sum += test_case[middle_i];
      }
    }
  }

  cout << "sum: " << sum << endl;

  return 0;
}
