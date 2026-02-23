#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

vector<int> spis_(int n) {
    vector<int> sp(n, 1);
    return sp;
}

bool find_in_spis(vector<int> vec, int tar) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == tar) {
            return true;
        }
    }
    return false;
}

int measure_time(int n, int tar) {
    auto list = spis_(n);

    auto start_t = chrono::high_resolution_clock::now();
    bool found = find_in_spis(list, tar);
    auto end_t = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end_t - start_t);
    return duration.count();
}

int main() {
    setlocale(LC_ALL, "RU");

    vector<int> sizes = { 10, 100, 1000, 10000, 100000, 500500, 120000, 2000000, 5000000 };


    for (int n : sizes) {

        vector<int> targets = { 1, 67, 999 };

        for (int tar : targets) {
            int duration = measure_time(n, tar);
            cout << n << " " << duration << " мс" << endl;
        }
    }

    return 0;
}
