#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void update_twos_and_threes(string str, int& twos, int& threes) {
  map<char, int> chars;
  
  for (char& c : str) {
    if (!chars.count(c)) {
      chars[c] = 1;
    } else {
      chars[c]++;
    }
  }
  
  bool has_two = false;
  bool has_three = false;
  
  for (map<char, int>::iterator it=chars.begin(); it != chars.end(); it++) {
    has_two = has_two || it->second == 2;
    has_three = has_three || it->second == 3;
  }
  
  twos += has_two;
  threes += has_three;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "usage: day_2_1 path_to_box_ids" << endl;
    return 1;
  }
  
  int twos = 0;
  int threes = 0;
  
  ifstream is(argv[1]);
  string line;
  
  while (getline(is, line)) {
    update_twos_and_threes(line, twos, threes);
  }
  
  cout << "twos: " << twos << ", threes: " << threes << endl;
  cout << "Checksum: " << twos * threes;
  
  return 0;
}