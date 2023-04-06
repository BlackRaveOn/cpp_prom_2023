#include <iostream>
#include <vector>
#include "modifications.hpp"

using namespace std;

int main() {
    // Create a vector representing the sequence 1, 2, 3, 4, 5
    vector<int> v_1 = {1, 2, 3, 4, 5, 1, 10, 20, 1, 3, 5, 9, 10};
    vector<int> v_2 = v_1;
    vector<int> v_3 = v_1;
    vector<int> v_4 = v_1;
    vector<int> v_5 = v_1;
    vector<int> v_6 = v_1;
    vector<int> v_7 = v_1;
    vector<int> v_8 = v_1;

    srand(time(NULL));

    cout << "Original sequence:" << endl;
    for (int num : v_1) {
        cout << num << " ";
    }
    cout << endl;

    fill_seq(v_1.begin(), v_1.end(), 0);

    cout << "Fill zeros:" << endl;
    for (int num : v_1) {
        cout << num << " ";
    }
    cout << endl;

    mt19937 rng(random_device{}());
    uniform_int_distribution<int> dist(0, 4);

    // Generate a sequence of random integers and store them in the vector
    generate_seq(v_1.begin(), v_1.end(), [&]() { return dist(rng); });

    cout << "Generate from 0 to 4" << endl;
    for (int num : v_2) {
        cout << num << " ";
    }
    cout << endl;

    iter_swap_seq(v_3.begin(), v_3.end());
    cout << "Swap iter" << endl;
    for (int num : v_3) {
        cout << num << " ";
    }
    cout << endl;

    partition_seq(v_4.begin(), v_4.end(), [](int i){return i % 2 == 0;});
    cout << "Partition" << endl;
    for (int num : v_4) {
        cout << num << " ";
    }
    cout << endl;

    shuffle_seq(v_5.begin(), v_5.end(), rng);
    cout << "Shuffle" << endl;
    for (int num : v_5) {
        cout << num << " ";
    }
    cout << endl;

    remove_seq(v_6.begin(), v_6.end(), 3);
    cout << "Remove" << endl;
    for (int num : v_6) {
        cout << num << " ";
    }
    cout << endl;

    replace_seq(v_7.begin(), v_7.end(), 1, 300);
    cout << "Replace" << endl;
    for (int num : v_7) {
        cout << num << " ";
    }
    cout << endl;

    unique_seq(v_8.begin(), v_8.end());
    cout << "Unique" << endl;
    for (int num : v_8) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}