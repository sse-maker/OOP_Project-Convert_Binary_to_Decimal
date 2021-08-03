//
//  main.cpp
//  Convert_Binary_to_Decimal
//
//  Created by 세광 on 2021/08/03.
//

#include <iostream>
#include <fstream>
#include <memory>
#include <cmath>

#define array_size 1024

using namespace std;

class Convert {
public:
    Convert();
    ~Convert();
    
    bool FileInput();
    void FileOutput();
    void Calculate();
    
private:
    int *bin, *dec;
    int index;
};

int main() {
    Convert *convert = new Convert;
    if (convert->FileInput() == true) {
        convert->Calculate();
        convert->FileOutput();
    }
    delete convert;
}

Convert::Convert() : index(0) {
    bin = new int[array_size];
    dec = new int[array_size];
    memset(dec, 0, array_size);
}

Convert::~Convert() {
    delete bin;
    delete dec;
}

bool Convert::FileInput() {
    ifstream fin("input1.txt");
    if (fin.fail()) {
        cout << "Could not open input.txt file" << endl;
        return false;
    }
    if(fin.is_open()) {
        while (!fin.eof()) {
            fin >> bin[index];
            index++;
        }
    }
    fin.close();
    return true;
}

void Convert::FileOutput() {
   ofstream fout("output.txt");
   for (size_t i = 0; i < index; i++) fout << dec[i] << '\n';
   fout.close();
}

void Convert::Calculate() {
    int j = 0;
    for (int i = 0; i < index; i++) {
        while (bin[i] != 0) {
            if (pow(10, j) <= bin[i] && bin[i] < pow(10, j + 1)) {
                dec[i] += pow(2, j);
                bin[i] -= pow(10, j);
                j = 0;
            } else j++;
        }
    }
}
