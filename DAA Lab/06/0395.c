#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    int numDeliveryFrogs;
    int maxHouses;
} Result;

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false

// bool isTree(int n, const int graph[][n]) {
// 	int v[n];
// 	for(int i=0; i<n; i++)
// 		v[i] = 0;
	
// 	for(int i=0; i<n; i++) {
// 		for(int j=0; j<n; j++) {
// 			if(!v[j] && graph[i][j]) {
// 				v[j]=1;
// 			}
// 			else if(v[j] && graph[i][j])
// 		}
// 	}
// 	return 0;
// }

bool isCyclic(int u, bool visited[], int parent, int n, const int graph[][n]) 
	{
	visited[u] = true;
	for(int v = 0; v<n; v++)
	{
	if(graph[u][v])
	{
	if(!visited[v])
	{
	if(isCyclic(v, visited, u, n, graph))
	{
	return true;
	}
	}
	else if(v != parent)
	{ //when adjacent vertex is visited but not parent
	return true; //there is a cycle
	}
	}
	}
	return false;
	}
	
	bool isTree(int n, const int graph[][n])
	{
	bool visited[n];
	for (int i = 0; i < n; i++)
	visited[i] = false;
	if (isCyclic(0, visited, -1, n, graph))
	return false;
	for (int i = 0; i < n; i++)
	if (!visited[i])
	return false;
	
	return true;
	}

int dfs(int v, int n, const int safeSeq[][n], int *visit) {
	visit[v]=1;
	int hCnt=1;
	for(int i=0; i<n; i++) {
		if (safeSeq[v][i] && (!visit[i])) {
			// printf("v%d i%d cnt%d\n", v, i, hCnt);
			hCnt += dfs(i, n, safeSeq, visit);
		}
	}
	// printf("final v %d cnt %d\n", v, hCnt);
	return hCnt;
}

// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired
//by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find number of delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n]) {
	int visit[n];
	Result t;
	// t = (Result*) malloc(sizeof(Result));
	t.numDeliveryFrogs = 0;
	t.maxHouses=-1;
	int hCnt=0;
	// printf("%d\n", n);
	for(int i=0; i<n; i++)
		visit[i] = 0;

	for(int v=0; v<n; v++) {
		// printf("v %d\n", v);
		if(!visit[v]) {
			// hCnt=1;
			hCnt = dfs(v, n, safeSeq, visit);
			// dfs(v, n, safeSeq, visit, &hCnt);
			// printf("%d\n", hCnt);
			if(hCnt > t.maxHouses)
				t.maxHouses = hCnt;
			t.numDeliveryFrogs++;
		}

	}
	return t;
}

int dfsWithK(int v, int n, const int safeSeq[][n], int *visit) {
	visit[v]=1;
	int hCnt=1;
	for(int i=0; i<n; i++) {
		if (safeSeq[v][i] && (!visit[i]) && (fabs(v-i))) {
			// printf("v%d i%d cnt%d\n", v, i, hCnt);
			hCnt += dfs(i, n, safeSeq, visit);
		}
	}
	// printf("final v %d cnt %d\n", v, hCnt);
	return hCnt;
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k) {
int visit[n];
	Result t;
	// t = (Result*) malloc(sizeof(Result));
	t.numDeliveryFrogs = 0;
	t.maxHouses=-1;
	int hCnt=0;
	// printf("%d\n", n);
	for(int i=0; i<n; i++)
		visit[i] = 0;

	for(int v=0; v<n; v++) {
		// printf("v %d\n", v);
		if(!visit[v]) {
			// hCnt=1;
			hCnt = dfsWithK(v, n, safeSeq, visit);
			// dfs(v, n, safeSeq, visit, &hCnt);
			// printf("%d\n", hCnt);
			if(hCnt > t.maxHouses)
				t.maxHouses = hCnt;
			t.numDeliveryFrogs++;
		}

	}
	return t;
}
