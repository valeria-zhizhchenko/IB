#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<unsigned char> generateKey(size_t len);
vector<unsigned char> arrXOR(vector<unsigned char> msg1, vector<unsigned char> msg2);

int main() {
  unsigned char str[] = {"С Новым Годом, Друзья!"};
  vector<unsigned char> message(str, str + sizeof(str));

  auto key = generateKey(message.size());
  auto encrMessage = arrXOR(message, key);
  auto key2 = arrXOR(message, encrMessage);

  cout << "Message: ";

  for (auto i: message) {
    cout << i;
  }

  cout << endl << "Encrypted Message: ";

  for (auto i: encrMessage) {
    cout << i;
  }

  int count = 0;

  cout << endl << endl << "Message hex:" << endl;

  for (auto i: message) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }

  count = 0;

	cout << endl << "Encrypted Message hex:" << endl;

  for (auto i: encrMessage) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }
  
  count = 0;

  cout << endl << endl << "Key1:" << endl;

  for (auto i: key) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }

  count = 0;

  cout << endl << "Key2:" << endl;

  for (auto i: key) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    } 
  }

  return 0;
}

vector<unsigned char> generateKey(size_t len) {
  vector<unsigned char> out;

  srand(time(nullptr));

  for (int i = 0; i < len; i++) {
    out.push_back(rand() % (1 << 8 * sizeof(unsigned char)));
  }

  return out;
}

vector<unsigned char> arrXOR(vector<unsigned char> msg1, vector<unsigned char> msg2) {
  vector<unsigned char> out;

  for (int i = 0; i < msg1.size(); i++) {
    out.push_back(msg1[i] ^ msg2[i]);
  }

  return out;
}

