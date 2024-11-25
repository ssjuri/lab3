#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;

    // 행렬의 크기 입력
    cout << "행렬의 행과 열의 크기를 입력하세요 (예: 2 3): ";
    cin >> rows >> cols;

    // 두 개의 행렬을 위한 vector 선언
    vector<vector<int>> matrix1(rows, vector<int>(cols));
    vector<vector<int>> matrix2(rows, vector<int>(cols));
    vector<vector<int>> result(rows, vector<int>(cols));

    // 첫 번째 행렬의 요소 입력
    cout << "첫 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix1[" << i << "][" << j << "]: ";
            cin >> matrix1[i][j];
        }
    }

    // 두 번째 행렬의 요소 입력
    cout << "두 번째 행렬의 요소를 입력하세요:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix2[" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

    // 행렬 더하기
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // 결과 출력
    cout << "두 행렬의 합:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

