class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

    const int INF = 1e9;
    vector<int> best(n, INF);

    int left = 0;
    int sum = 0;
    int answer = INF;

    for (int right = 0; right < n; right++) {

        sum += arr[right];

        while (sum > target) {
            sum -= arr[left];
            left++;
        }

        // Current window has sum == target
        if (sum == target) {
            int currentLength = right - left + 1;

            // Previous non-overlapping subarray
            if (left > 0 && best[left - 1] != INF) {
                answer = min(answer,
                             currentLength + best[left - 1]);
            }

            // This is the shortest valid subarray
            // ending at or before right
            if (right == 0) {
                best[right] = currentLength;
            } else {
                best[right] = min(best[right - 1], currentLength);
            }
        } 
        else {
            // No new valid subarray ending at right
            if (right > 0) {
                best[right] = best[right - 1];
            }
        }
    }

    return answer == INF ? -1 : answer;
    }
};