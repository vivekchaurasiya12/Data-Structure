class Solution {
public:
     struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, k;
    vector<Node> tree;

    Node mergeNode(const Node& a, const Node& b) {
        Node res;

        // Product of complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] = a.cnt[r];
        }

        // Prefixes = whole left + prefix of right
        for (int r = 0; r < k; r++) {
            if (b.cnt[r]) {
                int nr = (a.prod * r) % k;
                res.cnt[nr] += b.cnt[r];
            }
        }

        return res;
    }

    Node makeNode(int value) {
        Node res;

        res.prod = value % k;
        res.cnt[res.prod] = 1;

        return res;
    }

    void update(int pos, int value) {
        pos += n;

        tree[pos] = makeNode(value);

        for (pos >>= 1; pos; pos >>= 1) {
            tree[pos] = mergeNode(tree[pos << 1],
                                   tree[pos << 1 | 1]);
        }
    }

    // Query [l, r]
    Node query(int l, int r) {
        l += n;
        r += n;

        Node leftRes;
        Node rightRes;

        while (l <= r) {
            if (l & 1) {
                leftRes = mergeNode(leftRes, tree[l]);
                l++;
            }

            if (!(r & 1)) {
                rightRes = mergeNode(tree[r], rightRes);
                r--;
            }

            l >>= 1;
            r >>= 1;
        }

        return mergeNode(leftRes, rightRes);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;
        this->n = nums.size();

        tree.resize(2 * n);

        // Build leaves
        for (int i = 0; i < n; i++) {
            tree[n + i] = makeNode(nums[i]);
        }

        // Build tree
        for (int i = n - 1; i >= 1; i--) {
            tree[i] = mergeNode(tree[i << 1],
                                tree[i << 1 | 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(index, value);

            // All possible remaining arrays are
            // non-empty prefixes of [start ... n-1]
            Node res = query(start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};