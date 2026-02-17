#include <iostream>
#include <string>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	string arr[3] = { a,b,c };

	// 3개 중 하나에 반드시 Fizz가 있을 것.
	// 숫자 하나는 반드시 자연수일 것임.

	int num = 0;
	int index = 0;
	for (int i = 0;i < 3;i++) {
		string e = arr[i];
		if (e != "Fizz" && e != "Buzz" && e != "FizzBuzz") {
			index = i;
			num = stoi(e);
		}
	}

	num = num + (3 - index);

	string result = "";

	if (num % 3 == 0) result += "Fizz";
	if (num % 5 == 0) result += "Buzz";
	if (num % 3 != 0 && num % 5 != 0) result = to_string(num);

	cout << result;
}