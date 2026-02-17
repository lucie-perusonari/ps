#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int check = 0;

	int w = 1;

	for (int i = 0;i < 12;i++) {
		if (str[i] == '*') {
			if (i % 2 == 1) {
				w = 3;
			}
			continue;
		}

		if (i % 2 == 0) {
			check += str[i] - '0';
		} else {
			check += (str[i] - '0') * 3;
		}
	}

	int m = str[12] - '0';

	for (int i = 0; i < 10;i++) {
		if ((check + i * w + m) % 10 == 0) {
			cout << i;
			break;
		}
	}
}