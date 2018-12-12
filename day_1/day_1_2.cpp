#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  // The current frequency - a sum of all the previous changes
  int freq = 0;	
  // A vector containing the vector changes, read from the input file
  vector<int> changes;
  // A set with all the past frequencies, used to look for the first
  //	frequency to occur twice
  set<int> prev_freqs;
  
  // The current line read from the changes file
  string line;
  
  ifstream infile("/tmp/changes.txt");
  
  if (!infile.is_open()) {
    cout << "Unable to open file" << endl;
    return 1;
  }
  
  // Read all the changes, while logging the frequencies and changes
  while (getline(infile, line)) {
    int change = atoi(line.c_str());
    freq += change;
    changes.push_back(change);
    prev_freqs.insert(freq);
  }
  infile.close();
  
  // Repeatedly apply the changes, in order, until a frequency appears twice for the first time
  while (true) {
    for (vector<int>::iterator it = changes.begin(); it < changes.end(); freq += *it++) {
      if (prev_freqs.count(freq)) {
        cout << "First frequency to re-occur " << freq << endl;
        return 0;
      }
      prev_freqs.insert(freq);
    }
  }
  
  // Should never reach here
}
