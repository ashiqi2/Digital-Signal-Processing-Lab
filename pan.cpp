#include <bits/stdc++.h>

using namespace std;


vector<int> flip(vector<int>& pancakes, int i) {
    vector<int> flipped_pancake = pancakes;
    reverse(pancakes.begin(), pancakes.begin() + i + 1);
    return flipped_pancake;
}

bool is_sorted(const vector<int>& pancakes) {
    for (int i = 0; i < pancakes.size() - 1; ++i) {
        if (pancakes[i] > pancakes[i + 1])
            return false;
    }
    return true;
}

pair<vector<int>, int> pancake_sort(vector<int>& pancakes) {
    set<vector<int>> visited;
    queue<pair<vector<int>, int>> q;
    q.push({pancakes, 0});

    while (!q.empty()) {
        auto [current_pancakes, flips] = q.front();
        q.pop();

        if (is_sorted(current_pancakes)) {
            return {current_pancakes, flips};
        }
        vector<int> new_state;
        for (int i = 1; i <= current_pancakes.size(); ++i) {
            new_state = flip(current_pancakes, i);
            if (visited.find(new_state) == visited.end()) {
                visited.insert(new_state);
                q.push({new_state, flips + 1});
            }
        }
        cout << "After flip " << flips + 1 << ": ";
        for (int pancake : new_state) {
            cout << pancake << " ";
        }
        cout << endl;
        new_state.clear();
    }

    return {vector<int>(), -1};
}

int main() {
    vector<int> initial_pancakes = {1, 10, 9, 2, 6, 5, 3, 5};
    auto [sorted_pancakes, flips_needed] = pancake_sort(initial_pancakes);

    cout << "Initial Pancakes: ";
    for (int pancake : initial_pancakes)
        cout << pancake << " ";
    cout << endl;

    cout << "Sorted Pancakes: ";
    for (int pancake : sorted_pancakes)
        cout << pancake << " ";
    cout << endl;

    cout << "Flips Needed: " << flips_needed << endl;

    return 0;
}
