#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <algorithm>
using namespace std;

int comparisons;

struct SearchResult {
    string name;
    int comparisonCount;
    double duration;
    int result; 
};

void WW() {
    comparisons = 0;
}

int AA(const vector<int>& arr, int target) {
    WWW();
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == target) return i;
    }
    return -1;
}

int BB(const vector<int>& arr, int target, int left = 0, int right = -1, bool reset = true) {
    if (arr.empty()) return -1;
    if (right == -1) right = static_cast<int>(arr.size()) - 1;  
    if (reset) WW();

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int CC(const vector<int>& arr, int target) {
    WWW();
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev] < target) {
        comparisons++;
        prev++;
        if (prev == min(step, n)) return -1;
    }

    comparisons++;
    prev++;
    if (arr[prev] == target) return prev;
    return -1;
}

int DDHelper (const vector<int>& arr, int target, int left, int right) {
    if (left > right) return -1;

    comparisons++;
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target) return mid1;
    if (arr[mid2] == target) return mid2;

    if (target < arr[mid1]) {
        return DDHelper(arr, target, left, mid1 - 1);
    } else if (target > arr[mid2]) 
        return DDHelper(arr, target, mid2 + 1, right);
    } else {
        return DDHelper(arr, target, mid1 + 1, mid2 - 1);
    }
}

int DD(const vector<int>& arr, int target) {
    WWW();
    return DDHelper(arr, target, 0, arr.size() - 1);
}

int EE(const vector<int>& arr, int target) {
    WW();
    int n = arr.size();
    int fib2 = 0, fib1 = 1, fib = fib2 + fib1;
    
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = - 1;
    while (fib > 1) {
    comparisons++;
    int i = min(offset + fib2, n - 1);
    if (arr[i] < target) {
        fib = fib1;
        fib1 = fib2;
        fib2 = fib - fib1;
        offset = i;
    } else if (arr[i] > target) {
        fib = fib2;
        fib1 = fib1 - fib2;
        fib2 = fib - fib1;
    } else {
        return i;
    }
}
    comparisons++;
    if (fib1 && offset + 1 < n && arr[offset + 1] == target) {
        return offset + 1;
    }
    return -1;  
}

int FF(const vector<int>& arr, int target) {
    WW();
    int left = 0, right = arr.size() - 1;

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        comparisons++;
        int pos = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == target) return pos;
        else if (arr[pos] < target) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

int GG(const vector<int>& arr, int target) {
    WW();
    if (arr.empty()) return -1;
    if (arr[0] == target) return 0;

    int n = static_cast<int>(arr.size());
    int i = 1;
    while (i < n && arr[i] < target) {
        comparisons++;
        i *= 2;
    }

    int left = i / 2;
    int right = min(i, n - 1);
    return BB(arr, target, left, right, false);
}

SearchResult II(const string& name, const function<int()>& algo) {
    auto start = chrono::high_resolution_clock::now();
    int result = algo();
    auto end = chrono::high_resolution_clock::now();
    double duration = chrono::duration<double, micro>(end - start).count();
    return {name, comparisons, duration, result};
}

void HH(int rank, const string& algoName, int result, int comparisonCount, double duration) {
    cout << rank << ". " << algoName << " - ";
    if (result != - 1) {
        cout << "Found at index " << result;
    } else {
        cout << "Not found" ;
    }
    cout << " (Comparisons: " << comparisonCount << ", Time: " << duration << " us)" << endl;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int target = 56;

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\nSearching for: " << target << "\n\n";

    vector<SearchResult> results;

    vector<pair<string, function<int()>>> algorithms = {
        {"AA", [&]() { return AA(arr, target); }},
        {"BB", [&]() { return BB(arr, target); }},
        {"CC", [&]() { return CC(arr, target); }},
        {"DD", [&]() { return DD(arr, target); }},
        {"EE", [&]() { return EE(arr, target); }},
        {"FF", [&]() { return FF(arr, target); }},
        {"GG", [&]() { return GG(arr, target); }}
    };

    for (auto& algo : algorithms) {
        results.push_back(II(algo.first, algo.second));
    }

    sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.duration < b.duration;
    });

    cout << "\n --- Ranking by Time --- \n";
    for (int i = 0; i < results.size(); i++) {
        HH(
            i + 1, 
            results[i].name, 
            results[i].result, 
            results[i].comparisonCount, 
            results[i].duration
        );
    }
    return 0;
}

