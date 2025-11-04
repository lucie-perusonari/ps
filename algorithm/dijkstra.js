class MinHeap {
	constructor() {
		this.arr = [];
	}

	// Bottom-Up
	// 1. 배열 끝 자리에 아무거나 때려 넣는다.
	// 2. (while문 시작) 부모보다 작다면 자리를 교환한다. 
	// 3. 현재 인덱스(curr)가 0이 될 때까지 이걸 반복한다. 
	push(e) {
		const pq = this.arr;
		pq.push(e);

		let curr = pq.length - 1;

		while (curr > 0) {
			let parent = Math.floor((curr - 1) / 2);

			if (pq[curr] >= pq[parent]) break;

			[pq[curr], pq[parent]] = [pq[parent], pq[curr]];

			curr = parent; // Bottom-Up
		}

		return pq.length;
	}

	// Top-Down
	// 1. 루트에서 최소 값을 꺼낸다. 
	// 2. 배열의 마지막 값을 루트(0)에 놓고 curr를 설정한다.
	// 3. (while문 시작) left와 right를 비교해 작은 값을 minChild로 쓴다.
	// 4. 이 때 left와 right가 배열의 범위에 속하는지 확인한다.
	// 5. curr와 minChild의 값을 비교한다. 같다면 정확한 위치에 있는 것이고 아닌 경우 교환한다.
	pop() {
		const pq = this.arr;

		if (pq.length === 0) return;
		if (pq.length === 1) return pq.pop();

		const min = pq[0];
		pq[0] = pq.pop();

		let curr = 0;
		let minChild = 0;

		while (true) {
			let left = curr * 2 + 1;
			let right = curr * 2 + 2;


			// left와 right의 범위 비교에 주의할 것.
			if (left < pq.length && pq[left] < pq[minChild]) {
				minChild = left;
			}

			if (right < pq.length && pq[right] < pq[minChild]) {
				minChild = right;
			}

			if (curr === minChild) break;

			[pq[curr], pq[minChild]] = [pq[minChild], pq[curr]];
			curr = minChild; // Top-Down
		}

		return min;
	}
}


const [S, V] = [0, 10];

// c++에서 pq는 내림차순 정렬임. 그래서 weight 값을 -로 처리해주는 경우도 보임.
const pq = new MinHeap();

// {v: v, w: w} ==> {Vertex, Weight}를 페어로 사용함.
const graph = []; // {v: v, w: w};

// 0 Base를 쓸지, 1 Base를 쓸지에 따라서 V를 다르게 설정해야 함.
const dist = Array(V + 1).fill(Infinity);
const visited = Array(V + 1).fill(false);

dist[S] = 0;

while (pq.length) {
	const curr = pq.pop();

	if (visited[curr.v]) continue;
	visited[curr.v] = true;

	for (const next of graph[curr.v]) {

		// 이 부분의 visited는 성능 향상을 위해서 사용함. 
		if (!visited[next.v] && dist[next.v] > dist[curr.v] + next.w) {
			dist[next.v] = dist[curr.v] + next.w;
			pq.push({ v: next.v, w: dist[next.v] });
		}
	}
}