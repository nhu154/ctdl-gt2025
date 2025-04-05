#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

// Kiểm tra xem một ô có hợp lệ hay không
bool isValid(int x, int y, int N, int M, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y] == 0 && !visited[x][y]);
}

// BFS - tìm đường đi ngắn nhất
bool bfs(int N, int M, int startX, int startY, int endX, int endY, vector<vector<int>>& maze) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    // Các hướng di chuyển (trái, phải, lên, xuống)
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Nếu đã tới đích
        if (x == endX && y == endY) {
            cout << "Đã tìm thấy đường đi (BFS)" << endl;
            return true;
        }

        // Kiểm tra bốn hướng
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, N, M, maze, visited)) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    cout << "Không tìm thấy đường đi (BFS)" << endl;
    return false;
}

// DFS - tìm đường đi
bool dfs(int N, int M, int x, int y, int endX, int endY, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    // Nếu đã tới đích
    if (x == endX && y == endY) {
        cout << "Đã tìm thấy đường đi (DFS)" << endl;
        return true;
    }

    visited[x][y] = true;

    // Các hướng di chuyển (trái, phải, lên, xuống)
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };

    // Kiểm tra bốn hướng
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, N, M, maze, visited)) {
            if (dfs(N, M, nx, ny, endX, endY, maze, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Kích thước của mê cung
    int N = 5, M = 5;
    vector<vector<int>> maze = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0}
    };

    // Điểm xuất phát và đích
    int startX = 0, startY = 0, endX = 4, endY = 4;

    // BFS
    bfs(N, M, startX, startY, endX, endY, maze);

    // DFS
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // Khởi tạo lại visited cho DFS
    dfs(N, M, startX, startY, endX, endY, maze, visited);

    return 0;
}
