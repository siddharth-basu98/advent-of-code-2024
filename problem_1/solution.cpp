#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string FILE_NAME = "numbers.txt";

void splitStringToTwoIntegers(const string str, const string delimiter, int& num1, int& num2) {
    stringstream ss(str);
    string temp; 
    
    getline(ss, temp, delimiter.front());
    num1 = stoi(temp);

    getline(ss, temp);
    num2 = stoi(temp);
}

void constructVectors(vector<int>& location_1, vector<int>& location_2) {
    ifstream input_file(FILE_NAME);
    const string delimiter = "   ";

    if(input_file.is_open()) {
        string number_pair;
        while(getline(input_file, number_pair)) {
            int num1, num2;
            splitStringToTwoIntegers(number_pair, delimiter, num1, num2);
            location_1.push_back(num1);
            location_2.push_back(num2);
        }
    }
    else {
        cout << "ERROR: file could not be found";
    }
}

[[nodiscard]]
long long computeDistance(vector<int>& location_1, vector<int>& location_2) {
    sort(location_1.begin(), location_1.end());
    sort(location_2.begin(), location_2.end());

    long long distance = 0;

    for (int i = 0 ; i < location_1.size() ; i++) {
        distance += abs(location_1[i] - location_2[i]);
    }

    return distance;
}

int main() {
    vector<int> location_1;
    vector<int> location_2;

    constructVectors(location_1, location_2);

    cout << "Distance between the locations = " << computeDistance(location_1, location_2);
    return 0; 
}