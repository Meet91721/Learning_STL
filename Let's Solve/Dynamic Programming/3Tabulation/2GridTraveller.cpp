// Say that you are a traveller on a 2 grid. You begin in the
// top-left corner and your goal is to travel to the bottom right
// corner. You may only move down or right.

// In how many ways can you travel to the goal
// if you have a grid with dimensions m * n?

#include <bits/stdc++.h>
using namespace std;

const int N = 100;
long long int arr[N + 1][N + 1];

void gridTraveller()
{
    arr[1][1] = 1;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            // cout << i << " " << j << '\n';
            if (i != N)
                arr[i + 1][j] += arr[i][j];
            if (j != N)
                arr[i][j + 1] += arr[i][j];
        }
    }
}

int main()
{
    cout << arr[1][1];
    gridTraveller();
    cout << "Enter the number of queries: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter the vertices: ";
        cin >> a >> b;
        cout << arr[a][b] << '\n';
    }
}