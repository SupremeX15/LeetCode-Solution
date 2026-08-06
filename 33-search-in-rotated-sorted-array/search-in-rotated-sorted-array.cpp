class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Found the target
            if (arr[mid] == target) return mid;

            // Left side is sorted
            if (arr[start] <= arr[mid]) {
                if (target >= arr[start] && target < arr[mid]) {
                    end = mid - 1; 
                } else {
                    start = mid + 1; 
                }
            }
            // Right side is sorted
            else {
                if (target > arr[mid] && target <= arr[end]) {
                    start = mid + 1; 
                } else {
                    end = mid - 1; 
                }
            }
        }

        return -1; // target not found
    }
};
