max min using divide and conquer


#include<iostream>
#include<climits>
using namespace std;

void findMinMax(int arr[], int left, int right, int &minValue, int &maxValue) {
    if (left == right) {
        // If there is only one element
        minValue = arr[left];
        maxValue = arr[right];
    } else if (right == left + 1) {
        // If there are two elements
        minValue = min(arr[left], arr[right]);
        maxValue = max(arr[left], arr[right]);
    } else {
        // Divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively find min and max in the left and right halves
        int leftMin, leftMax, rightMin, rightMax;
        findMinMax(arr, left, mid, leftMin, leftMax);
        findMinMax(arr, mid + 1, right, rightMin, rightMax);

        // Combine the results
        minValue = min(leftMin, rightMin);
        maxValue = max(leftMax, rightMax);
    }
}

int main() {
    int arr[5] = {7, 2, 4, 9, 7};

    int minValue, maxValue;
    findMinMax(arr, 0, 4, minValue, maxValue);

    cout << "Minimum value: " << minValue << endl;
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
