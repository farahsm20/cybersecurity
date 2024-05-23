#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void encryptFile(string filename, int shift) {
  ifstream inputFile(filename);
  ofstream outputFile(filename + ".enc");

  if (!inputFile) {
    cout << "Error: Unable to open input file." << endl;
    return;
  }

  char ch;
  while (inputFile.get(ch)) {
    ch = ch + shift;  // Simple encryption algorithm
    outputFile << ch;
  }

  inputFile.close();
  outputFile.close();

  cout << "Encryption successful. Encrypted file saved as " << filename + ".enc"
       << endl;
}

void decryptFile(string filename, int shift) {
  ifstream inputFile(filename);
  ofstream outputFile("decrypted_" + filename);

  if (!inputFile) {
    cout << "Error: Unable to open input file." << endl;
    return;
  }

  char ch;
  while (inputFile.get(ch)) {
    ch = ch - shift;  // Simple decryption algorithm
    outputFile << ch;
  }

  inputFile.close();
  outputFile.close();

  cout << "Decryption successful. Decrypted file saved as decrypted_"
       << filename << endl;
}

int main() {
  string filename;
  int choice, shift;

  cout << "Enter the file name: ";
  cin >> filename;

  cout << "Choose an option:" << endl;
  cout << "1. Encrypt" << endl;
  cout << "2. Decrypt" << endl;
  cin >> choice;

  cout << "Enter the shift value: ";
  cin >> shift;

  switch (choice) {
    case 1:
      encryptFile(filename, shift);
      break;
    case 2:
      decryptFile(filename, shift);
      break;
    default:
      cout << "Invalid choice" << endl;
      break;
  }

  return 0;
}
