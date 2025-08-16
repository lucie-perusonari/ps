const fs = require("fs");
const lines = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 최대 1000000임.
// 재수가 없으면 500000 * 500000이 될 수도 있음.
const [s, p] = lines.shift().split(" ").map(Number);
const str = lines.shift();
const [a, c, g, t] = lines.shift().split(" ").map(Number);

// 부분 문자열에서 a,c,g,t를 찾는 과정 자체는 O(n^2)임.
// 그러나 앞 글자가 사라지고, 뒷 글자가 생기는 식이니까. 먼저 구해놓고 접근하면 될 듯?
let answer = 0;

let tempStr = str.substring(0, p);
let tempA = 0, tempC = 0, tempG = 0, tempT = 0; // 정직하게 현재 문자열의 값을 모두 반영하자.

for (let j = 0; j < tempStr.length; j++) {
	if (tempStr[j] === 'A') {
		tempA++;
	} else if (tempStr[j] === 'C') {
		tempC++;
	} else if (tempStr[j] === 'G') {
		tempG++;
	} else if (tempStr[j] === 'T') {
		tempT++;
	}
}

if (tempA >= a && tempC >= c && tempG >= g && tempT >= t) {
	answer++;
}

for (let i = 1; i + p - 1 < str.length; i++) {
	const front = str[i - 1];
	const back = str[i + p - 1];

	if (front === 'A') {
		tempA--;
	} else if (front === 'C') {
		tempC--;
	} else if (front === 'G') {
		tempG--;
	} else if (front === 'T') {
		tempT--;
	}

	if (back === 'A') {
		tempA++;
	} else if (back === 'C') {
		tempC++;
	} else if (back === 'G') {
		tempG++;
	} else if (back === 'T') {
		tempT++;
	}

	if (tempA >= a && tempC >= c && tempG >= g && tempT >= t) {
		answer++;
	}
}

console.log(answer);
