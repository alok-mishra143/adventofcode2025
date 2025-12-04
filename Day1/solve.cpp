#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputfile("input.txt");
    if (!inputfile.is_open()) {
        cerr << "Error while opening the file\n";
        return 1;
    }

    int pos = 50;      
    long long cnt = 0; 

    string line;
    while (getline(inputfile, line)) {
        if (line.empty()) continue; 

        char dir = line[0];
        int value = stoi(line.substr(1));

        if (dir == 'L') {
            pos = (pos - value) % 100;
            if (pos < 0) pos += 100; 
        } else if (dir == 'R') {
            pos = (pos + value) % 100;
        } else {
            cerr << "Invalid direction in line: " << line << "\n";
            return 1;
        }

        if (pos == 0) {
            cnt++;
        }
    }

    cout << cnt << endl;  
    return 0;
}
