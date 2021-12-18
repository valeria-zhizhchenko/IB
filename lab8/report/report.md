---
# Front matter
lang: ru-RU
title: "Отчёт по лабораторной работе №8"
subtitle: "Элементы криптографии. Шифрование (кодирование) различных исходных текстов одним ключом"
author: "Жижченко Валерия Викторовна"

# Formatting
toc-title: "Содержание"
toc: true # Table of contents
toc_depth: 2
lof: true # List of figures
fontsize: 12pt
linestretch: 1.5
papersize: a4paper
documentclass: scrreprt
polyglossia-lang: russian
polyglossia-otherlangs: english
mainfont: PT Serif
romanfont: PT Serif
sansfont: PT Sans
monofont: PT Mono
mainfontoptions: Ligatures=TeX
romanfontoptions: Ligatures=TeX
sansfontoptions: Ligatures=TeX,Scale=MatchLowercase
monofontoptions: Scale=MatchLowercase
indent: true
pdf-engine: lualatex
header-includes:
  - \linepenalty=10 # the penalty added to the badness of each line within a paragraph (no associated penalty node) Increasing the value makes tex try to have fewer lines in the paragraph.
  - \interlinepenalty=0 # value of the penalty (node) added after each line of a paragraph.
  - \hyphenpenalty=50 # the penalty for line breaking at an automatically inserted hyphen
  - \exhyphenpenalty=50 # the penalty for line breaking at an explicit hyphen
  - \binoppenalty=700 # the penalty for breaking a line at a binary operator
  - \relpenalty=500 # the penalty for breaking a line at a relation
  - \clubpenalty=150 # extra penalty for breaking after first line of a paragraph
  - \widowpenalty=150 # extra penalty for breaking before last line of a paragraph
  - \displaywidowpenalty=50 # extra penalty for breaking before last line before a display math
  - \brokenpenalty=100 # extra penalty for page breaking after a hyphenated line
  - \predisplaypenalty=10000 # penalty for breaking before a display
  - \postdisplaypenalty=0 # penalty for breaking after a display
  - \floatingpenalty = 20000 # penalty for splitting an insertion (can only be split footnote in standard LaTeX)
  - \raggedbottom # or \flushbottom
  - \usepackage{float} # keep figures where there are in the text
  - \floatplacement{figure}{H} # keep figures where there are in the text
---

# Цель работы

Освоить на практике применение режима однократного гаммирования
на примере кодирования различных исходных текстов одним ключом.

# Выполнение работы

Разработали приложение, позволяющее шифровать и дешифровать тексты $P_1$ и $P_2$ в режиме однократного гаммирования.
Приложение определяет вид шифротекстов $C_1$ и $C_2$ обоих текстов $P_1$ и $P_2$ при известном ключе:

```C++
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
```

1. Вывод работы программы:

![Вывод программы](../image/fig01.png){ #fig:001 width=70% }

# Ответы на контрольные вопросы

1. Как, зная один из текстов ($P_1$ или $P_2$), определить другой, не зная при этом ключа?

Необходимо воспользоваться формулой:

$C_1\oplus C_2\oplus P_1=P_1\oplus P_2\oplus P_1=P_2$,

где $C_1$ и $C_2$ – шифротексты.

2. Что будет при повторном использовании ключа при шифровании текста?

Тогда мы получим исходное сообщение.

3. Как реализуется режим шифрования однократного гаммирования одним ключом двух открытых текстов?

Режим шифрования однократного гаммирования одним ключом двух открытых текстов реализуется по следующей формуле:

$C_1=P_1\oplus K$

$C_2=P_2\oplus K$,

где $C_i$ – шифротексты, $P_i$ – открытые тексты, $K$ – ключ шифрования.

4. Перечислите недостатки шифрования одним ключом двух открытых текстов.

* Во-первых, имея на руках одно из сообщений в открытом виде и оба шифротекста, злоумышленник способен расшифровать каждое сообщение, не зная ключа.

* Во-вторых, зная шаблон сообщений, злоумышленник получает возможность определить те символы сообщения $P_2$, которые находятся на позициях известного шаблона сообщения $P_1$.

* В соответствии с логикой сообщения $P_2$, злоумышленник имеет реальный шанс узнать ещё некоторое количество символов сообщения $P_2$. Таким образом, применяя формулу из п. 1, с подстановкой вместо $P_1$ полученных на предыдущем шаге новых символов сообщения $P_2$ злоумышленник если не прочитает оба сообщения, то значительно уменьшит пространство их поиска. Наконец, зная ключ, злоумышленник смоет расшифровать все сообщения, которые были закодированы при его помощи.

5. Перечислите преимущества шифрования одним ключом двух открытых текстов.

Такой подход помогает упростить процесс шифрования и дешифровки. Также, при отправке сообщений между 2-я компьютерами, удобнее пользоваться одним общим ключом для передаваемых данных.

# Вывод

Освоили на практике применение режима однократного гаммирования на примере кодирования различных исходных текстов одним ключом.
