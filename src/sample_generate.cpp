#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main() {
    ofstream file("../data/sample.csv");

    int rows = 100;
    int cols;
    cout<<"enter the no of columns"<<endl;
    cin>>cols;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            file << dist(gen);

            if(j != cols - 1)
                file << ",";
        }
        file << "\n";
    }

    file.close();

    cout << "pixel values generated successfully!" << endl;
}