class Solution {
    struct IntervalData {
        int end, start, weight, originalIndex;

        bool operator<(const IntervalData& other) const {
            return end < other.end;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<IntervalData> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

      
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(
                5,
                {0LL, {}}
            )
        );

        for (int i = 0; i < n; i++) {

            int start = a[i].start;

           
            int k = lower_bound(
                a.begin(),
                a.begin() + i,
                IntervalData{start, 0, 0, 0}
            ) - a.begin();

            for (int j = 0; j <= 4; j++) {

                // Skip current interval
                dp[i + 1][j] = dp[i][j];

                if (j == 0)
                    continue;

                // Take current interval
                long long score =
                    dp[k][j - 1].first - a[i].weight;

                vector<int> indices =
                    dp[k][j - 1].second;

                indices.push_back(a[i].originalIndex);

                sort(indices.begin(), indices.end());

                pair<long long, vector<int>> take = {
                    score,
                    indices
                };

                dp[i + 1][j] =
                    min(dp[i + 1][j], take);
            }
        }

       
        pair<long long, vector<int>> answer = dp[n][0];

        for (int j = 1; j <= 4; j++) {
            answer = min(answer, dp[n][j]);
        }

        return answer.second;
    }
};