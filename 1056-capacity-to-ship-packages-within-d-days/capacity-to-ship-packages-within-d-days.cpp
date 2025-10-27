class Solution {
public:
    int DayReq(vector<int>& weights, int cap){
        int days=1,load=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(load+weights[i]>cap){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int req=DayReq(weights,mid);
            if(req<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};