class Solution {
public:
    bool isValidRadius(int radius,vector<int>houses,vector<int>heaters){
        int i=0;
        int j=0;
        while(i<houses.size() && j<heaters.size()){
            if(abs(heaters[j]-houses[i])<=radius) i++;
            else j++;
        }
        return i==houses.size();
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int left=0;
        int right=1*1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int radius=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValidRadius(mid,houses,heaters)){
                radius=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return radius;
    }
};