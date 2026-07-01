class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> isThere;

        for (auto &it : wordList)
            isThere[it] = true;

        if (!isThere[endWord]) return 0;

        queue<string> q;
        q.push(beginWord);

        int ans = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string node = q.front();
                q.pop();

                if (node == endWord)
                    return ans;

                for (int i = 0; i < node.length(); i++) {
                    char ogChar = node[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == ogChar) continue;

                        node[i] = ch;

                        if (isThere[node]) {
                            q.push(node);
                            isThere[node] = false;   // mark visited
                        }
                    }

                    node[i] = ogChar;
                }
            }

            ans++;
        }

        return 0;
    }
};