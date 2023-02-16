#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Record {
  string name;
  int score;
};

bool compareRecords(const Record &a, const Record &b) {
  return a.score > b.score;
}

int main() {
  cout << "Welcome to the High Scores Tracker!" << endl;
  cout << "===============================" << endl;

  // Read records from the file
  vector<Record> records;
  ifstream inputFile("records.txt");
  if (inputFile.is_open()) {
    string name;
    int score;
    while (inputFile >> name >> score) {
      records.push_back({name, score});
    }
    inputFile.close();
  }

  // Get new record from the user
  cout << "Enter your name: ";
  string name;
  cin >> name;
  cout << "Enter your score: ";
  int score;
  cin >> score;
  records.push_back({name, score});

  // Sort records in descending order of scores
  sort(records.begin(), records.end(), compareRecords);

  // Write records to the file
  ofstream outputFile("records.txt");
  if (outputFile.is_open()) {
    for (const auto &record : records) {
      outputFile << record.name << " " << record.score << endl;
    }
    outputFile.close();
  }

  // Display records on the screen
  cout << "High Scores:" << endl;
  for (const auto &record : records) {
    cout << record.name << ": " << record.score << endl;
  }

  return 0;
}
