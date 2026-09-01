class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ew=0;
        int prev=-1e9;
        for(int price: prices){
            ew=max(ew,prev+price-fee);
            prev=max(prev,ew-price);
        }
        return ew;
    }
};