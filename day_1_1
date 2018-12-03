#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	int freq = 0;
	string line;
	ifstream infile("/tmp/changes.txt");
	
	if (infile.is_open()) {
		while (getline(infile, line)) {
			freq += atoi(line.c_str());
		}
		infile.close();
	} else {
		cout << "Unable to open file" << endl;
	}
	
	cout << "Resulting Frequency is: " << freq << endl;
}
