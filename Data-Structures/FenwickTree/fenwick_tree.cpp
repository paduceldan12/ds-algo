#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
    vector<int> BIT;
    int n;

public:
    FenwickTree(int size) : n(size) {
        BIT.resize(n + 1, 0);
    }

    void update(int index, int value) {
        while (index <= n) {
            BIT[index] += value;
            index += index & -index;
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    FenwickTree ft(10);
    ft.update(3, 5);
    ft.update(5, 7);
    cout << "Range Sum (1-5): " << ft.rangeQuery(1, 5) << endl;
}
