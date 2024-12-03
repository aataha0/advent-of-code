#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>

const char *digits[10] = {"0","1","2","3","4","5","6","7","8","9"};

int main() {
  std::ifstream input("input.txt");
  std::stringstream buffer;
 
  buffer << input.rdbuf();

  std::string content = buffer.str();
  int sum = 0;

  for (unsigned long i = 0; i < content.size(); i++) {
    bool error = false;
    if (content[i] == 'm' && content[i+1] == 'u' && content[i+2] == 'l' && content[i+3] == '(') {
      std::string first_num;
      int index = i+4;
      while (content[index] != ',') {
        char c = content[index];
        if (!(c >= '0' && c <= '9')) {
          // not found
          error = true;
          break;
        }
        first_num += content[index];
        index++;
      }

      std::string second_num;
      int secindex = index+1; // skip the comma
      while (content[secindex] != ')' && secindex - index < 5)  {
        char c = content[secindex];
        if (!(c >= '0' && c <= '9')) {
          // not found
          error = true;
          break;
        }
        second_num += content[secindex];
        secindex++;
      }

      if (!error) {
        std::cout << first_num << ", sec: " << second_num << std::endl;
        sum += (std::stoi(first_num) * std::stoi(second_num));
      }
    }
  }

  std::cout << "sum: " << sum << std::endl;
}
