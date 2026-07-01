class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> isThere;
        for(auto it: wordList){
            isThere[it] = true;
        }
        if(!isThere[endWord]) return 0;
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int size = q.size();
            string node = q.front();
            q.pop();
            if(node == endWord) return ans - 1;
            while(size--){
                for(int i = 0; i < node.length(); i++){
                    int ogChar = node[i];
                    for(int j = 0; j < 26; j++){
                        if(ogChar == 'a' + j) continue;
                        node[i] = 'a' + j;
                        if(isThere[node]) q.push(node);
                    }
                    node[i] = ogChar;
                }
            }
            ans++;
        }
        return 0;
    }
};
