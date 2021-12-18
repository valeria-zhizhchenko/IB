#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

using binType = vector<unsigned char>;

binType generateKey(size_t len);
pair<binType, binType> encrypt(binType p1, binType p2, binType k);
binType decrypt(binType c1, binType c2, binType p1);

int main() {
  char str1[] = {"Как ваши дела?"};
  char str2[] = {"Как вас зовут?"};

  binType p1(str1, str1 + sizeof(str1));
  binType p2(str2, str2 + sizeof(str2));

  auto key = generateKey(p1.size());
  auto encr = encrypt(p1, p2, key);
  auto decrP2 = decrypt(encr.first, encr.second, p1);

  cout << "P1: ";

  for (auto i: p1) {
    cout << i;
  }

  cout << endl << "P2: ";

  for (auto i: p2) {
    cout << i;
  }

  cout << endl << "C1: ";

  for (auto i: encr.first) {
    cout << i;
  }

  cout << endl << "C2: ";

  for (auto i: encr.second) {
    cout << i;
  }

  int count = 0;

  cout << endl << endl << "C1 hex:" << endl;

  for (auto i: encr.first) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }

  count = 0;

  cout << endl << "C2 hex:" << endl;

  for (auto i: encr.second) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }

  count = 0;

  cout << endl << endl << "Key: " << endl;

  for (auto i: key) {
    printf("%#x\t", i);

    if (count++ >= 4) {
      count = 0;
      cout << endl;
    }
  }

  cout << endl << endl << "Decrypted P2: ";
  
  for (auto i: decrP2) {
    cout << i;
  }
  
  cout << endl;

  return 0;
}

binType generateKey(size_t len) {
  binType out;

  srand(time(nullptr));

  for (int i = 0; i < len; i++) {
    out.push_back(rand() % (1 << 8 * sizeof(unsigned char)));
  }

  return out;
}

pair<binType, binType> encrypt(binType p1, binType p2, binType k) {
  binType c1;
  binType c2;

  for (int i = 0; i < k.size(); i++) {
    c1.push_back(p1[i] ^ k[i]);
    c2.push_back(p2[i] ^ k[i]);
  }

  return make_pair(c1, c2);
}

binType decrypt(binType c1, binType c2, binType p1) {
  binType out;

  for (int i = 0; i < p1.size(); i++) {
    out.push_back(c1[i] ^ c2[i] ^ p1[i]);
  }

  return out;
}
