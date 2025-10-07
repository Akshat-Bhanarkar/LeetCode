class Solution {
    public boolean isSubsequence(String s, String t) {
        int count=0,i=0,j=0;
       while(i<s.length() && j<t.length()){
            
                if(s.charAt(i)==t.charAt(j)){
                    count++;
                    i++;
                }
                j++;
            }
            if(count==s.length()){
                return true;
            }
        return false;
        
    }
}