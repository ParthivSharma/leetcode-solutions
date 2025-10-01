class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for(int d : digits) freq[d]++;
        
        vector<int> result;
         
        for(int h = 1; h <= 9; h++) {
            if(freq[h] == 0) continue;
            freq[h]--;
            for(int t = 0; t <= 9; t++) {
                if(freq[t] == 0) continue;
                freq[t]--;
                for(int u = 0; u <= 8; u += 2) {  
                    if(freq[u] == 0) continue;
                    result.push_back(h*100 + t*10 + u);
                }
                freq[t]++;
            }
            freq[h]++;
        }
        
        sort(result.begin(), result.end());
        return result;
    }
};
