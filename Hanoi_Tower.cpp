#include <iostream>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c) {
    if (n == 1) {
        // Trường hợp cơ sở: chỉ có một đĩa, chuyển trực tiếp từ cột nguồn sang cột đích
        cout << "Move disk 1 from " << a << " to " << b << endl;
        return;
    }
    // Chuyển n-1 đĩa từ cột nguồn sang cột phụ, sử dụng cột đích làm trung gian
    towerOfHanoi(n - 1, a, c, b);
    // Chuyển đĩa lớn nhất từ cột nguồn sang cột đích
    cout << "Move disk " << n << " from " << a << " to " << b << endl;
    // Chuyển n-1 đĩa từ cột phụ sang cột đích, sử dụng cột nguồn làm trung gian
    towerOfHanoi(n - 1, c, b, a);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    // Gọi hàm giải bài toán tháp Hà Nội
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
