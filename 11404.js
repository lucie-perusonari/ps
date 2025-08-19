const input = require("fs").readFileSync("/dev/stdin").toString().trim().split("\n");

const n = parseInt(input.shift());
const m = parseInt(input.shift());

const cost = input.map(e => e.split(" ").map(c => parseInt(c)));

const graph = Array.from({ length: n }, () => Array(n).fill(Infinity));
graph.forEach((_, i) => graph[i][i] = 0);

// 최소 값만 그래프에 반영해야 함.
cost.forEach(([a, b, c]) => { if (graph[a - 1][b - 1] > c) { graph[a - 1][b - 1] = c } });


for (let m = 0; m < n; m++)
	for (let s = 0; s < n; s++)
		for (let e = 0; e < n; e++)
			if (graph[s][e] > graph[s][m] + graph[m][e])
				graph[s][e] = graph[s][m] + graph[m][e]

console.log(graph.map(e => e.map((d) => { return d === Infinity ? 0 : d }).join(" ")).join("\n"));

