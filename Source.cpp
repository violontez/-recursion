#include <iostream>
#include <vector>
using namespace std;
int const m = 10;
// ������� 1 : ����������� ������� ������ ��������� ������� � ������� ������� � �������
int findMax(int arr[], int size) {
    if (size == 1)
        return arr[0];

    int max = findMax(arr, size - 1);
    if (arr[size - 1] > max)
        return arr[size - 1];
    else
        return max;
}
// ������� 2 : ����������� ���������� "��������� �����"

void moveDisk(int disk, int source, int destination) {
    std::cout << "Move disk " << disk << " from tower " << source << " to tower " << destination << std::endl;
}

void hanoiTower(int disks, int source, int auxiliary, int destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
        return;
    }

    hanoiTower(disks - 1, source, destination, auxiliary);
    moveDisk(disks, source, destination);
    hanoiTower(disks - 1, auxiliary, source, destination);
}
// ������� 3 : �������� "��� ����"

// ������� �����
int rows, cols;
// ��������� ��������� ����
int startRow, startCol;

// ������� ��� ��������, ��� ������ � ������������ (row, col) ��������� � �������� �����
bool isValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// ������� ��� ������ ��������� ����� ���� �� ������� �������
std::vector<std::pair<int, int>> findKnightMoves(int row, int col) {
    std::vector<std::pair<int, int>> moves;

    // ��� ��������� �������� ����������� ����
    int moveOffsets[8][2] = {
        {-2, -1}, {-1, -2},
        {1, -2}, {2, -1},
        {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}
    };

    // ��������� ������ ������� ����������� � ��������� ��� � ������, ���� �� ����������
    for (int i = 0; i < 8; i++) {
        int newRow = row + moveOffsets[i][0];
        int newCol = col + moveOffsets[i][1];
        if (isValid(newRow, newCol)) {
            moves.push_back(std::make_pair(newRow, newCol));
        }
    }

    return moves;
}
// ������� 4  ���������� ��������� "����������� ������"
void printBoard(vector<int>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        // ��������� �������� � ������� ������� �� ��������� � ���������
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        // ��� ����� ������� ���������
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // ��������� ����� �� ������� �������
            solveNQueens(board, row + 1, n); // ���������� ��������� ��������� ������
        }
    }
}

void nQueens(int n) {
    vector<int> board(n, -1); // �������������� �����, -1 �������� ������ ������
    solveNQueens(board, 0, n);
}




int main() {
    setlocale(LC_ALL, "Russian");
    int q;
    cout << "write 1 or 2 or 3 or 4 " << endl;
    cin >> q;

    if (q == 1) {
        // ������� 1 : ����������� ������� ������ ��������� ������� � ������� ������� � �������

        int arr[m];

        int size = sizeof(arr) / sizeof(arr[0]);

        std::cout << "Array: ";
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 15;
            cout << arr[i] << " ";
        }
        cout << endl;

        int max = findMax(arr, size);

        cout << "Maximum element: " << max << endl;
        cout << endl;
        return main();
    }
    if (q == 2) {
        // ������� 2 : ����������� ���������� "��������� �����"


        int numTowers;
        std::cout << "Enter the number of towers: ";
        std::cin >> numTowers;

        // Check for valid input
        if (numTowers < 3) {
            std::cout << "Invalid number of towers. Minimum required is 3." << std::endl;
            return 1;
        }

        int numDisks;
        std::cout << "Enter the number of disks: ";
        std::cin >> numDisks;

        // Check for valid input
        if (numDisks < 1) {
            std::cout << "Invalid number of disks. Minimum required is 1." << std::endl;
            return 1;
        }

        hanoiTower(numDisks, 1, 2, numTowers);

        return main();
    }
    if (q == 3) {
        // ������� 3 : �������� "��� ����"

       // ���� �������� ����� � ���������� ��������� ����
        cout << "������� ���������� ����� �����: ";
        cin >> rows;
        cout << "������� ���������� �������� �����: ";
        cin >> cols;
        cout << "������� ����� ������ ���������� ��������� ����: ";
        cin >> startRow;
        cout << "������� ����� ������� ���������� ��������� ����: ";
        cin >> startCol;

        // �������� ������� ������� ����� ����, ����������� ������
        vector<vector<int>> board(rows, vector<int>(cols, 0));

        // ������� ��� ������ � ������
        vector<pair<int, int>> queue;
        // ��������� ��������� ��������� ���� � �������
        queue.push_back(std::make_pair(startRow, startCol));

        // ����� �������� ����
        int moveNumber = 1;

        while (!queue.empty()) {
            // �������� ���������� ��������� ������� �� �������
            int row = queue.front().first;
            int col = queue.front().second;
            queue.erase(queue.begin());

            // ���� ������ ������ �� ���� �������� �����
            if (board[row][col] == 0) {
                // ���������� ����� ���� � ������ ������
                board[row][col] = moveNumber;

                // ���� ��������� ���� ���� �� ������� �������
                vector<std::pair<int, int>> moves = findKnightMoves(row, col);

                // ��������� ��������� ���� � �������
                for (const auto& move : moves) {
                    queue.push_back(move);
                }

                // ����������� ����� �������� ����
                moveNumber++;
            }
        }

        // ����� ������� ������� ����� ����
        cout << "������� ������� ����� ����:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << board[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        return main();
    }
    if (q == 4) {
        // ������� 4 : �������� "����������� ������"
        int n;
        cout << "������� ���������� ����� (��������) �����: ";
        cin >> n;
        cout << endl;

        nQueens(n);
    }


    return main();
}