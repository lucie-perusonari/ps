// const fs = require("fs");

// // const inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n"); //d
// const inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n");


// inputs.pop();

let result = [];
const rl = require("readline").createInterface({
	input: process.stdin,
	output: process.stdout
});

rl.on("line", (str) => {
	if (str === ".") {
		rl.close();
	}

	const brackets = [];
	let answer = "yes";

	for (const c of str) {
		if (c === "(" || c === "[") {
			brackets.push(c);
			continue;
		}

		if (c === ")") {
			if (brackets.pop() !== "(") {
				answer = "no";
				break;
			}
		}

		if (c === "]") {
			if (brackets.pop() !== "[") {
				answer = "no";
				break;
			}
		}
	}

	if (brackets.length > 0) {
		answer = "no";
	}

	result.push(answer);
})

rl.on("close", () => {
	console.log(result.join("\n"));
})




// let result = [];

// for (const str of inputs) {
// 	const brackets = [];
// 	let answer = "yes";

// 	for (const c of str) {
// 		if (c === "(" || c === "[") {
// 			brackets.push(c);
// 			continue;
// 		}

// 		if (c === ")") {
// 			if (brackets.pop() !== "(") {
// 				answer = "no";
// 				break;
// 			}
// 		}

// 		if (c === "]") {
// 			if (brackets.pop() !== "[") {
// 				answer = "no";
// 				break;
// 			}
// 		}
// 	}

// 	if (brackets.length > 0) {
// 		answer = "no";
// 	}

// 	result.push(answer);
// }

// console.log(result.join("\n"))