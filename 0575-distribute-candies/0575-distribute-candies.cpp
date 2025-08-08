class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin(),candyType.end());
  int n=candyType.size(),count=1;
  for(int i=1;i<n;i++){
    if(candyType[i-1]!=candyType[i]){
        count++;
    }
  }      int temp= min(count,n/2);
  return temp;
    }
};