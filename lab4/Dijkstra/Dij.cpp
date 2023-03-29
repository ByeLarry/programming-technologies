#include "pch.h" 
#include <string> 
#define DLL_EXPORT __declspec(dllexport)

//определение функции 
extern "C" {
    DLL_EXPORT std::string Mydijkstra(int numA, int numB, int matrix[6][6]) {
		std::string path;
		int start = numA;
		int end = numB;
		int dist[6];
		bool visited[6];
		for (int i = 0; i < 6; i++) {
			dist[i] = 999999;
			visited[i] = false;
		}
		dist[start] = 0;

		for (int i = 0; i < 6 - 1; i++) {
			int u = -1;
			for (int j = 0; j < 6; j++) {
				if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
					u = j;
				}
			}
			visited[u] = true;
			for (int v = 0; v < 6; v++) {
				if (matrix[u][v] > 0) {
					int alt = dist[u] + matrix[u][v];
					if (alt < dist[v]) {
						dist[v] = alt;
					}
				}
			}
		}

		if (dist[end] == 999999) {
			path = "No way!";
		}
		else {
			path = std::to_string(end + 1) + "\nCount steps: " + std::to_string(dist[end]) + "\n";
			int curend = end;
			while (curend != start) {
				for (int i = 0; i < 6; i++) {
					if (matrix[i][curend] > 0 && dist[i] + matrix[i][curend] == dist[curend]) {
						path = std::to_string(i + 1) + " -> " + path;
						curend = i;
						break;
					}
				}
			}
		}
		return path;

    }
}
