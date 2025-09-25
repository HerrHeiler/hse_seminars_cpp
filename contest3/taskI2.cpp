#include <iostream>

int find(int arr[], int len, int el) {
    for (int i = len - 1; i >= 0; --i)
    {
        if (arr[i] == el) return i;
    }
    return -1;
}

int main() {
    int n, temp;
    std::cin >> n;
    int numbers[] = {};
    int count[] = {};
    int threes[] = {};
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        int t = find(numbers, i, temp);
        numbers[i] = temp;
        if (t != -1) {
            count[i] = count[t] + 1;
            if (count[i] == 3) threes[i] = temp;
        } else {
            count[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (find(threes, sizeof(threes), numbers[i]) == -1) {
            std::cout << '\n' << numbers[i] << " " << count[i] << '\n';
            //break;
        }
        std::cout << numbers[i] << ' ' << count[i] << ' ' << i;
    }
    return 0;
}