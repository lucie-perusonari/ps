const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n").slice(1);

let p = parseInt(input.pop());

// 이진 트리인지 확실하지 않음. 불균형 트리일 수 있음.
const nodes = input.pop().split(" ").map(e => parseInt(e));

const queue = [];

const root = nodes.indexOf(-1);

queue.push(root);
let count = 0;
while (queue.length) {
	let curr = queue.shift();
	if (curr === p) break;


	const tmp = [];
	for (let i = 0; i < nodes.length; i++) {
		if (i === p) continue;

		if (nodes[i] === curr) {
			tmp.push(i);
		}
	}

	if (tmp.length === 0) {
		count++;
	}

	queue.push(...tmp);
}

console.log(count);
