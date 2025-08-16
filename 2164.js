const fs = require("fs");
const rawInput = fs.readFileSync("/dev/stdin").toString();

const n = parseInt(rawInput);
const card = [];

for (let i = 0; i < n; i++) {
	card[i] = i + 1;
}

// ** 시간 초과? 왜? shift();가 그렇게 느린가?
// i는 무시. i+1은 뒤에 삽입. 그렇다면 늘 짝수 번째의 값만이 살 것임.

for (let i = 0; i < card.length; i += 2) {
	// i + 1이면 끝부분을 의미.
	if (card[i + 1] === undefined) {
		break;
	}

	card.push(card[i + 1]);
}

console.log(card.pop());

