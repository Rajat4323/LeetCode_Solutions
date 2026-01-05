class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count = {0,0};
        for(int i=0; i<students.size(); i++){
            count[students[i]]++;
        }
        for(int ch:sandwiches){
            if(count[ch] == 0) break;
            count[ch]--;
        }
        return count[0]+count[1];
    }
};