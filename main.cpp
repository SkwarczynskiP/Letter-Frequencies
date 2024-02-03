#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void getFile();
void readFile();
void sortFile();

ifstream myFile;
unsigned int countAlphabet[26];
char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                   'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                   'V', 'W', 'X', 'Y', 'Z'};

int main() {
    int x;

    getFile();
    readFile();

    cout << "Alphabetized Frequency Counts: (Letters with count 0 are not printed)" << endl;
    cout << "Letter:" << "\tNumber:" << endl;

    for(x = 0; x < 26; x++) {
        if(countAlphabet[x] != 0) {
            cout << alphabet[x] << "\t" << countAlphabet[x] << endl;
        }
    }

    sortFile();

    cout << "Frequency Counts in Ascending Order: (Letters with count 0 are not printed)" << endl;
    cout << "Letter:" << "\tNumber:" << endl;

    for(x = 0; x < 26; x++) {
        if(countAlphabet[x] != 0) {
            cout << alphabet[x] << "\t" << countAlphabet[x] << endl;
        }
    }

    return 0;
}

void getFile() {
    string name;
    bool validFile = false;

    while(!validFile) {
        cout << "Please enter the name of a text file (including .txt): ";
        cin >> name;
        myFile.open(name);

        if (myFile.is_open()) {
            validFile = true;
        } else {
            cout << "Invalid File. Please try again." << endl;
        }
    }
}

void readFile() {
    char c;

    while(myFile.get(c)) {
        if(isalpha(c)) {
            for(int i = 0; i < 26; i++) {
                if (alphabet[i] == toupper(c)) {
                    countAlphabet[i]++;
                }
            }
        }
    }
    myFile.close();
}

void sortFile() {
    for(int i = 0; i < 26 - 1; i++) {
        for(int j = 0; j < 26 - i - 1; j++) {
            if(countAlphabet[j] > countAlphabet[j+1]) {
                swap(countAlphabet[j], countAlphabet[j+1]);
                swap(alphabet[j], alphabet[j+1]);
            }
        }
    }
}