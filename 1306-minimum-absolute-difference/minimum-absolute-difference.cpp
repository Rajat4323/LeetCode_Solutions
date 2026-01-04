class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mini = INT_MAX;
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1; i++){
             if(mini > arr[i+1]-arr[i]){
                res.clear();
                res.push_back({arr[i],arr[i+1]}); 
                mini = arr[i+1]-arr[i];
             }
             else if(mini == arr[i+1]-arr[i]){
                res.push_back({arr[i],arr[i+1]});
             }
        }
        return res;
    }
};