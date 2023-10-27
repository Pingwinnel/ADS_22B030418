#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//run id:652
bool compareRows(const vector<int>& row1, const vector<int>& row2) {
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < row1.size(); i++) {
        sum1 += row1[i];
        sum2 += row2[i];
    }

    if (sum1 == sum2) {
        for (int i = 0; i < row1.size(); i++) {
            if (row1[i] < row2[i]) {
                return true; 
            } else if (row1[i] > row2[i]) {
                return false; 
            }
        }
        return false;
    } else {
        return sum1 > sum2; 
    }
}

void merge(vector<vector<int>>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<vector<int>> L(n1);
    vector<vector<int>> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compareRows(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<vector<int>>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }
    mergeSort(rows, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << rows[i][j] << " ";
        }
        cout <<endl;
    }
    return 0;
}