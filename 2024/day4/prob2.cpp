#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> split(string s, const string& delimiter) {
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);

    return tokens;
}

int main() {
  ifstream input("input.txt");
  stringstream buffer;
  buffer << input.rdbuf();
  string content = buffer.str();
  vector<string> rows = split(content, "\n");

  int occurences = 0;

  unsigned long col_length = rows.size();
  for (unsigned long i = 0; i < col_length; i++) {

    unsigned long row_length = rows[i].size();
    for (unsigned long j = 0; j < row_length; j++) {
      // M M
      //  A
      // S S
      if (j < (row_length - 2) && i < (col_length - 2) && rows[i][j] == 'M' && rows[i][j+2] == 'M' && rows[i+1][j+1] == 'A' && rows[i+2][j] == 'S' && rows[i+2][j+2] == 'S')
      {
        occurences++;
      }

      // S S
      //  A
      // M M
      if (j < (row_length - 2) && i < (col_length - 2) && rows[i][j] == 'S' && rows[i][j+2] == 'S' && rows[i+1][j+1] == 'A' && rows[i+2][j] == 'M' && rows[i+2][j+2] == 'M')
      {
        occurences++;
      }

      // M S
      //  A
      // M S
      if (j < (row_length - 2) && i < (col_length - 2) && rows[i][j] == 'M' && rows[i][j+2] == 'S' && rows[i+1][j+1] == 'A' && rows[i+2][j] == 'M' && rows[i+2][j+2] == 'S')
      {
        occurences++;
      }

      // S M
      //  A
      // S M
      if (j < (row_length - 2) && i < (col_length - 2) && rows[i][j] == 'S' && rows[i][j+2] == 'M' && rows[i+1][j+1] == 'A' && rows[i+2][j] == 'S' && rows[i+2][j+2] == 'M')
      {
        occurences++;
      }
    }  
  }

  cout << "occurences: " << occurences << endl;
}
