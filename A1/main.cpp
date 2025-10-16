//Assignment 1
#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

//---Problem 1 Start---
//Bubble Sort Function
void bubbleSort(vector<int> &arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Switch arr[j] and arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
// Function to print vector
void printVector(const vector<int> &arr) {
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;
}
void Problem1()
{
    vector<int> numbers;

    for (;;)
    {
        cout << "Enter one of your integers: ";
        int number{};

        if (!(cin >> number))
        {
            cout << "Invalid input! Please enter an integer." << endl;

            // Clear the error state and ignore the rest of the line
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // go back to the top of the loop
        }

        numbers.push_back(number);
        cout << "\nEnter more? [y/n]: ";
        char ans{};
        cin >> ans;
        cout << "\n";
        if (ans == 'n' || ans == 'N')
            break;
    }

    cout << "Unsorted numbers: ";
    printVector(numbers);

    // Sort
    bubbleSort(numbers);

    cout << "Sorted numbers: ";
    printVector(numbers);
}
//---Problem 1 End---

//---Problem 2 Start---
double compareHistograms(const vector<int>& hist1, const vector<int>& hist2) {
	double sum = 0.0, euclidianDistance;
	for (size_t i = 0; i < hist1.size(); i++) {
		double diff = hist1[i] - hist2[i];
		sum += diff * diff;
	}
	euclidianDistance=sqrt(sum);
	return euclidianDistance;
}
vector<double> normalizedHistogram(const vector<int>& hist) {
	vector<double> normalized(hist.size());
	int total = 0;
	//Find total
	for (int i : hist) total += i;
	if (total == 0) return normalized;
	for (size_t i = 0; i < hist.size(); i++) {
		normalized[i] = static_cast<double>(hist[i]) / total;
	}
	return normalized;
}
double compareNormalizedHistograms(const vector<int>& hist1, const vector<int>& hist2) {
	auto normalizedHistogram1=normalizedHistogram(hist1);
	auto normalizedHistogram2=normalizedHistogram(hist2);
	double sum = 0.0, euclidianDistance;
	for (size_t i = 0; i < normalizedHistogram1.size(); i++) {
		double diff = normalizedHistogram1[i] - normalizedHistogram2[i];
		sum += diff * diff;
	}
	euclidianDistance=sqrt(sum);
	return euclidianDistance;
}
void Problem2()
{
    // Read and print files
    string f1text, f2text;
    ifstream f1("f1.txt"), f2("f2.txt");
    cout << "File 1: ";
	
    while (getline(f1, f1text))
    {
        cout << f1text << endl;
    }
    cout << "File 2: ";
    while (getline(f2, f2text))
    {
        cout << f2text << endl;
    }

    // Make 2 histograms with size 26 and Initial value 0
    vector histogram1('z' - 'a' + 1, 0);
    vector histogram2('z' - 'a' + 1, 0);
    for (auto c : f1text)                        // c takes on successive letters from in str
        if (isalpha(c))                     // isalpha (c) returns true if c is alphanumeric
            ++histogram1[tolower(c) - 'a']; // ++ adds 1 to the letter position
    for (auto c : f2text)                        
        if (isalpha(c))
            ++histogram2[tolower(c) - 'a'];

    cout << endl
         << "Num of: ";

    // Print letters 'a' to 'z'
    for (auto c{'a'}; c <= 'z'; ++c)
        cout << c << " ";

    cout << endl
         << "File 1: ";
    for (auto h : histogram1) // h is successive values of the histogram
        cout << h << " ";     // Print histogram values
    cout << endl
         << "File 2: ";
    for (auto h : histogram2)
        cout << h << " ";     

    cout << "\n\nEuclidean distance (not normalized): "
         << compareHistograms(histogram1, histogram2) << endl;
    cout << "Euclidean distance (normalized): "
         << compareNormalizedHistograms(histogram1, histogram2) << endl;
}
//---Problem 2 End---

//---Problem 3 Start---
bool isANumber(const string& s) {
    if (s.empty()) return false;
    for (char ch : s) {
        if (!isdigit(ch)) return false;
    }
    return !s.empty();
}
int Problem3(){
	cout << "Enter an addition expression (Ex: 1 + 2, 1+ 2): ";
    //Collect Input
    string input, removedSpacesInput;
    getline(cin, input);

    // Remove spaces
    for (char ch : input) {
        //If not space add to string
        if (!isspace(ch)) {
            removedSpacesInput+=ch;
        }
    }
    //Get position of '+'
    size_t plusPos = removedSpacesInput.find('+'); 
    // If no '+' character
    if (plusPos == string::npos) {
        cout << "Error: Expression must contain a '+' sign." << endl;
        return 1;
    }

    // Extract numbers
    string left = removedSpacesInput.substr(0, plusPos);
    string right = removedSpacesInput.substr(plusPos + 1);
    // Check if both sides are valid integers
    if (!isANumber(left) || !isANumber(right)) {
        cerr  << "Error: Both numbers must be positive integers." << endl;
        return 1;
    }

    // Convert to integers
    int num1 = stoi(left), num2 = stoi(right);

    // Print sum
    cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
	return 0;
}
//---Problem 3 End---

int main(int argc, char* argv[]) {

    Problem1();
    // Problem2();
	// Problem3();
    return 0;
}

