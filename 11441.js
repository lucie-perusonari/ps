const fs = require("fs");
let rawData = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// shift가 너무 느림.
rawData.reverse();
rawData.pop();

const arr = rawData.pop().split(" ").map(e => parseInt(e));

// 최악의 경우 10^10.

const accArr = [];

// 앞에서 뒤의 합.
let accA = 0;
for (let i = 0; i < arr.length; i++) {
	accA += arr[i];
	accArr.push(accA);
}


let result = "";

let n = parseInt(rawData.pop());
while (n--) {

	let [i, j] = rawData.pop().split(" ").map(e => parseInt(e));

	// j까지의 합에서 i-1까지의 합을 뺌.
	let sum = accArr[j - 1];
	if (i - 2 >= 0) {
		sum -= accArr[i - 2];
	}

	result += sum + "\n";
}

console.log(result);
