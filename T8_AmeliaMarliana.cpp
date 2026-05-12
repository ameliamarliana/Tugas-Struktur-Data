#include <iostream>
#include <iomanip>

using namespace std;

#define MAX 10

int cost[MAX][MAX] = {
    {0, 4, 1, 3},
    {4, 0, 2, 1},
    {1, 2, 0, 5},
    {3, 1, 5, 0}
};

int visited[MAX];
int path[MAX];
int bestPath[MAX];

int minimumCost = 9999;
int n = 4;

// Fungsi mencari jalur minimum
void tsp(int current, int count, int totalCost) {

    // Jika semua simpul sudah dikunjungi
    if(count == n) {

        totalCost = totalCost + cost[current][0];

        if(totalCost < minimumCost) {

            minimumCost = totalCost;

            for(int i = 0; i < n; i++) {

                bestPath[i] = path[i];

            }

            bestPath[n] = 0;
        }

        return;
    }

    // Mencari kemungkinan jalur
    for(int i = 0; i < n; i++) {

        if(visited[i] == 0 && cost[current][i] != 0) {

            visited[i] = 1;
            path[count] = i;

            tsp(i, count + 1,
                totalCost + cost[current][i]);

            visited[i] = 0;
        }
    }
}

int main() {

    // Inisialisasi visited
    for(int i = 0; i < n; i++) {

        visited[i] = 0;

    }

    // Mulai dari node 1
    visited[0] = 1;
    path[0] = 0;

    tsp(0, 1, 0);

    cout << "Cost List : " << endl << endl;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            cout << setw(4) << cost[i][j];

        }

        cout << endl;
    }

    cout << endl;

    cout << "Jalur Terpendek : " << endl;

    for(int i = 0; i <= n; i++) {

        cout << bestPath[i] + 1;

        if(i < n) {

            cout << " ----> ";

        }
    }

    cout << endl << endl;

    cout << "Minimum Cost : "
         << minimumCost << endl;

    return 0;
}
