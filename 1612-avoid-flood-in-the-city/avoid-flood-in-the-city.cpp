class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> mp;
        set<int> st;

        for (int i = 0; i < n; i++) {
            int x = rains[i];

            if (x == 0) {
                st.insert(i);
            } else {
                ans[i] = -1;
                if (mp.count(x)) {
                    auto it = st.lower_bound(mp[x]);
                    if (it == st.end()) return {};
                    ans[*it] = x;
                    st.erase(it);
                }
                mp[x] = i;
            }
        }
        return ans;
    }
};
