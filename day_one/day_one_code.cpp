#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

int getValues(string input);

string digits[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  
// Driver Code 
int main() 
{ 
    string fileName = "day_one_input.txt";

    ifstream inputFile(fileName);

    string input;

    int sum = 0;

    while(getline(inputFile, input)) {
        sum += getValues(input);
    }
    cout << sum;
    return sum; 
} 

int getValues(string input) {
    int stringLength = input.length();
    int firstValue = -1;
    int lastValue = 0;

    for (int i = 0; i < stringLength; i++)
    {
        int tempValue = input[i] - '0';

        for (int j = 0; j < 10; j++)
        {
            int digitLength = digits[j].length();
            if (i >= (digitLength - 1)) {
                string possibleDigit = input.substr(i - (digitLength - 1), digitLength);
                if (possibleDigit == digits[j]) {
                    tempValue = j;
                    break;
                }
            }
        }

        if (0 <= tempValue && tempValue <= 9) {
            cout << tempValue;
            if (firstValue < 0) {
                firstValue = tempValue;
            } 
            lastValue = tempValue;
        }
    }
    cout << '\n';
    return firstValue * 10 + lastValue;
}