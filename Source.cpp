#include <iostream>
#include <vector>
using namespace std;
int const m = 10;
// Задание 1 : Рекурсивный вариант поиска максимума массива с выводом массива в консоль
int findMax(int arr[], int size) {
    if (size == 1)
        return arr[0];

    int max = findMax(arr, size - 1);
    if (arr[size - 1] > max)
        return arr[size - 1];
    else
        return max;
}
// Задание 2 : Программная реализация "ханойских башен"

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
// Задание 3 : Алгоритм "Ход коня"

// Размеры доски
int rows, cols;
// Начальное положение коня
int startRow, startCol;

// Функция для проверки, что ячейка с координатами (row, col) находится в пределах доски
bool isValid(int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// Функция для поиска возможных ходов коня из текущей позиции
std::vector<std::pair<int, int>> findKnightMoves(int row, int col) {
    std::vector<std::pair<int, int>> moves;

    // Все возможные варианты перемещения коня
    int moveOffsets[8][2] = {
        {-2, -1}, {-1, -2},
        {1, -2}, {2, -1},
        {2, 1}, {1, 2},
        {-1, 2}, {-2, 1}
    };

    // Проверяем каждый вариант перемещения и добавляем его к списку, если он корректный
    for (int i = 0; i < 8; i++) {
        int newRow = row + moveOffsets[i][0];
        int newCol = col + moveOffsets[i][1];
        if (isValid(newRow, newCol)) {
            moves.push_back(std::make_pair(newRow, newCol));
        }
    }

    return moves;
}
// Задание 4  реализации алгоритма "Расстановка ферзей"
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
        // Проверяем конфликт с другими ферзями по вертикали и диагонали
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n) {
    if (row == n) {
        // Все ферзи успешно размещены
        printBoard(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; // Размещаем ферзя на текущую позицию
            solveNQueens(board, row + 1, n); // Рекурсивно размещаем остальных ферзей
        }
    }
}

void nQueens(int n) {
    vector<int> board(n, -1); // Инициализируем доску, -1 означает пустую ячейку
    solveNQueens(board, 0, n);
}




int main() {
    setlocale(LC_ALL, "Russian");
    int q;
    cout << "write 1 or 2 or 3 or 4 " << endl;
    cin >> q;

    if (q == 1) {
        // Задание 1 : Рекурсивный вариант поиска максимума массива с выводом массива в консоль

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
        // Задание 2 : Программная реализация "ханойских башен"


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
        // Задание 3 : Алгоритм "Ход коня"

       // Ввод размеров доски и начального положения коня
        cout << "Введите количество строк доски: ";
        cin >> rows;
        cout << "Введите количество столбцов доски: ";
        cin >> cols;
        cout << "Введите номер строки начального положения коня: ";
        cin >> startRow;
        cout << "Введите номер столбца начального положения коня: ";
        cin >> startCol;

        // Создание матрицы номеров ходов коня, заполненной нулями
        vector<vector<int>> board(rows, vector<int>(cols, 0));

        // Очередь для обхода в ширину
        vector<pair<int, int>> queue;
        // Добавляем начальное положение коня в очередь
        queue.push_back(std::make_pair(startRow, startCol));

        // Номер текущего хода
        int moveNumber = 1;

        while (!queue.empty()) {
            // Получаем координаты следующей позиции из очереди
            int row = queue.front().first;
            int col = queue.front().second;
            queue.erase(queue.begin());

            // Если данная ячейка не была посещена ранее
            if (board[row][col] == 0) {
                // Записываем номер хода в данную ячейку
                board[row][col] = moveNumber;

                // Ищем возможные ходы коня из текущей позиции
                vector<std::pair<int, int>> moves = findKnightMoves(row, col);

                // Добавляем найденные ходы в очередь
                for (const auto& move : moves) {
                    queue.push_back(move);
                }

                // Увеличиваем номер текущего хода
                moveNumber++;
            }
        }

        // Вывод матрицы номеров ходов коня
        cout << "Матрица номеров ходов коня:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << board[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        return main();
    }
    if (q == 4) {
        // Задание 4 : Алгоритм "Расстановка ферзей"
        int n;
        cout << "Введите количество строк (столбцов) доски: ";
        cin >> n;
        cout << endl;

        nQueens(n);
    }


    return main();
}