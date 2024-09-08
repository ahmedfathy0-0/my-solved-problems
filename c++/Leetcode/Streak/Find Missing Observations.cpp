class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalSum = mean * (rolls.size() + n);
        int sumRolls = 0;
        for (int i = 0; i < rolls.size(); i++) {
            sumRolls += rolls[i];
        }
        
        int neededSum = totalSum - sumRolls;
        
        if (neededSum < n || neededSum > 6 * n) {
            return {}; 
        }
        
        vector<int> ans(n, neededSum / n);  
        int remainder = neededSum % n;     
        
        for (int i = 0; i < remainder; i++) {
            ans[i]++;
        }
        
        return ans;
    }
};
