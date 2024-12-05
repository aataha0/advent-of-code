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

      // horizontal
      if (j < (row_length - 3) && rows[i][j] == 'X' && rows[i][j+1] == 'M' && rows[i][j+2] == 'A' && rows[i][j+3] == 'S')
      {
        occurences++;
      }

      if (j < (row_length - 3) && rows[i][j+3] == 'X' && rows[i][j+2] == 'M' && rows[i][j+1] == 'A' && rows[i][j] == 'S')
      {
        occurences++;
      }

      // vertical
      if (i < (col_length - 3) && rows[i][j] == 'X' && rows[i+1][j] == 'M' && rows[i+2][j] == 'A' && rows[i+3][j] == 'S')
      {
        occurences++;
      }

      if (i < (col_length - 3) && rows[i+3][j] == 'X' && rows[i+2][j] == 'M' && rows[i+1][j] == 'A' && rows[i][j] == 'S')
      {
        occurences++;
      }

      // diagonal down
      if (j < (row_length - 3) && i < (col_length - 3) && rows[i][j] == 'X' && rows[i+1][j+1] == 'M' && rows[i+2][j+2] == 'A' && rows[i+3][j+3] == 'S')
      {
        occurences++;
      }

      if (j < (row_length - 3) && i < (col_length - 3) && rows[i+3][j+3] == 'X' && rows[i+2][j+2] == 'M' && rows[i+1][j+1] == 'A' && rows[i][j] == 'S')
      {
        occurences++;
      }

      // diagonal up
      if (j < (row_length - 3) && i > 2 && rows[i][j] == 'X' && rows[i-1][j+1] == 'M' && rows[i-2][j+2] == 'A' && rows[i-3][j+3] == 'S')
      {
        occurences++;
      }

      if (j < (row_length - 3) && i > 2 && rows[i-3][j+3] == 'X' && rows[i-2][j+2] == 'M' && rows[i-1][j+1] == 'A' && rows[i][j] == 'S')
      {
        occurences++;
      }
    }  
  }

  cout << "occurences: " << occurences << endl;
}
