class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto& word : words) {
            freq[word]++;
        }

        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second; // smaller word first
            return a.first < b.first; // higher frequency first
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        for (auto& [word, count] : freq) {
            pq.push({count, word});
        }

        vector<string> res;
        while (k-- && !pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
