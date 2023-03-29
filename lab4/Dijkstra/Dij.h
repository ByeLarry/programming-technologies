#pragma once
//при явном подключении длл заголовочный файл не нужен
extern "C" {
    __declspec(dllimport) int Mydijkstra(int numA, int numB, int matrix[6][6]);

}
