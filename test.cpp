#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 특정 범위를 뒤집기 위해 반복자(iterator)를 사용합니다.
    auto start = vec.begin() + 2;  // 3번째 요소부터
    auto end = vec.begin() + 7;    // 8번째 요소 전까지

    std::reverse(start, end);

    // 결과 확인
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}