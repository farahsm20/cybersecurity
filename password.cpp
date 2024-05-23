#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

string generatePassword(int length) {
  const string charset =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*("
      ")";
  string password = "";
  srand(time(0));  // Seed for random number generation

  for (int i = 0; i < length; ++i) {
    int index = rand() % charset.length();
    password += charset[index];
  }

  return password;
}

int main() {
  int length;
  cout << "Please enter the length of the password: ";
  cin >> length;

  string password = generatePassword(length);
  cout << "Your generated password is: " << password << endl;

  return 0;
}
