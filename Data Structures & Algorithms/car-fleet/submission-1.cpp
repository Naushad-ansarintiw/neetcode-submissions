class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vec; 
        int n = position.size(); 
        for(int i=0; i<n; i++) {
            vec.push_back({position[i], speed[i]});
        }
        sort(vec.begin(), vec.end()); 
        int ans = 0; 
        float maxi = -1; 
        for(int i=n-1; i>=0; i--) {
            int pos = vec[i].first; 
            int sp = vec[i].second; 
            float tim = (float)(target-pos) / sp;
            // cout<<tim<<" "<<maxi<<endl;
            if(tim>maxi) {
                ans += 1; 
                maxi = tim;
            }
        }
        return ans;
    }
};
