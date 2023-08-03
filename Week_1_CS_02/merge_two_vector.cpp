#include<bits/stdc++.h>
using namespace std;
vector<int> mergeSortedVectors(const vector<int>& vec1, const vector<int>& vec2) {
    vector<int> mergedVec;
    int i = 0; // Index for vec1
    int j = 0; // Index for vec2

    // Merge the two vectors while both have elements
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            mergedVec.push_back(vec1[i]);
            i++;
        } else {
            mergedVec.push_back(vec2[j]);
            j++;
        }
    }

    // If there are remaining elements in vec1 or vec2, add them to the merged vector
    while (i < vec1.size()) {
        mergedVec.push_back(vec1[i]);
        i++;
    }

    while (j < vec2.size()) {
        mergedVec.push_back(vec2[j]);
        j++;
    }

    return mergedVec;
}

int main() {
    vector<int> vec1 = {1, 3, 5, 7, 9};
    vector<int> vec2 = {2, 4, 6, 8, 10};

    vector<int> mergedVec = mergeSortedVectors(vec1, vec2);

    // Print the merged vector
    for (int num : mergedVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
