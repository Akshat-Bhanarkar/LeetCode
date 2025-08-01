class Solution {
public:
    int numRookCaptures(vector<vector<char>>& b) {
        int r = b.size(), c = b[0].size(), i=0, j=0, ans=0, f=0;
        // Find
        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                if(b[i][j]=='R') {
                    f=1;
                    break;
                }
            }
            if(f) break;
        }

        // Bottom
        for(int x=i+1; x<r; x++){
            if(b[x][j] =='p'){
                ans++;
                break;
            }
            else if(b[x][j] =='B')  break;
        }

        // Right
        for(int x=j+1; x<c; x++){
            if(b[i][x] =='p'){
                ans++;
                break;
            }
            else if(b[i][x] =='B')  break;
        }

        //Left
        for(int x=j-1; x>=0; x--){
            if(b[i][x] =='p'){
                ans++;
                break;
            }
            else if(b[i][x] =='B')  break;
        }

        //Top
        for(int x=i-1; x>=0; x--){
            if(b[x][j] =='p'){
                ans++;
                break;
            }
            else if(b[x][j] =='B')  break;
        }
        return ans;
    }
};