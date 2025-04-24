#include <iostream>
#include <fstream> // For file I/O
using namespace std;

int main() {
    // Open input and output files
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    // Input variables
    int bronze_before, bronze_after;
    int silver_before, silver_after;
    int gold_before, gold_after;
    int platinum_before, platinum_after;

    // Read inputs from the file
    fin >> bronze_before >> bronze_after;
    fin >> silver_before >> silver_after;
    fin >> gold_before >> gold_after;
    fin >> platinum_before >> platinum_after;

    // Calculate promotions
    int gold_to_platinum = platinum_after - platinum_before;
    int silver_to_gold = (gold_after - gold_before) + gold_to_platinum;
    int bronze_to_silver = (silver_after - silver_before) + silver_to_gold;

    // Write results to the file
    fout << bronze_to_silver << endl;
    fout << silver_to_gold << endl;
    fout << gold_to_platinum << endl;

    // Close the files
    fin.close();
    fout.close();

    return 0;
}
