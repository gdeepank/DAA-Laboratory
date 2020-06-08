#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int numDeliveryFrogs;
    int maxHouses;
} Result;

bool isCyclic(int w, bool visited[], int parent, int n, const int graph[][n]){
	visited[w] = true;
	for(int v = 0; v < n; ++v)
	if(graph[w][v]){
		if(!visited[v]){
			if(isCyclic(v, visited, w, n, graph))
				return true;
			else if(v != parent) 
				return true;
		}
	}
	return false;
}
	
bool isTree(int n, const int graph[][n]){
	bool visited[n];
	for(int i = 0; i < n; i++)
	visited[i] = false;
	if(isCyclic(0, visited, -1, n, graph))
		return false;
	for(int i = 0; i < n; i++)
	if (!visited[i])
		return false;	
	return true;
}

int dfs(int v, int n, const int safe[][n], int *visit) {
	visit[v] = 1;
	int count = 1;
	for(int i = 0; i < n; ++i)
	if (safe[v][i] && (!visit[i]))
		count += dfs(i, n, safe, visit);
	return count;
}

Result pepesAnswers(int n, const int safeSeq[][n]){
	int visit[n];
	Result t;
	t.numDeliveryFrogs = 0;
	t.maxHouses = -1;
	int count = 0;
	for(int i = 0; i < n; ++i)
	visit[i] = 0;
	for(int v = 0; v < n; ++v)
	if(!visit[v]){
		count = dfs(v, n, safeSeq, visit);
		if(count > t.maxHouses)
			t.maxHouses = count;
		t.numDeliveryFrogs++;
	}
	return t;	
}

int dfsWithK(int v, int n, const int safe[][n], int *visit) {
	visit[v] = 1;
	int count = 1;
	for(int i = 0; i < n; ++i)
	if(safe[v][i] && (!visit[i]) && (fabs(v-i)))
		count += dfs(i, n, safe, visit);
	return count;
}

Result pepesAnswersWithK(int n, const int safeSeq[][n], int k){
	int visit[n];
	Result t;
	t.numDeliveryFrogs = 0;
	t.maxHouses = -1;
	int count = 0;
	for(int i = 0; i < n; ++i)
	visit[i] = 0;
	for(int v = 0; v < n; ++v)
	if(!visit[v]){
		count = dfsWithK(v, n, safeSeq, visit);
		if(count > t.maxHouses)
			t.maxHouses = count;
		t.numDeliveryFrogs++;
	}
	return t;	
}


