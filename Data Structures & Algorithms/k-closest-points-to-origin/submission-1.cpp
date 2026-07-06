class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<double,int>> pq;
       for(int i = 0; i < points.size(); i++){
            double dist = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            if(pq.size() < k) pq.push({dist,i});
            else if(pq.top().first > dist){
                pq.pop();
                pq.push({dist,i});
            }
       } 
       vector<vector<int>> res;
       while(!pq.empty()){
            pair<double,int> top = pq.top();pq.pop();
            res.push_back(points[top.second]);
       }
       return res;
    }
};
