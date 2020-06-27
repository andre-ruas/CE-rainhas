#include <time.h>
#include <iostream>

using namespace std;

int main() {
  srand(time(NULL));
  cout << rand() % 2;
}