class Solution {
public:

    void ptrswap(vector<string>::iterator &str1, vector<string>::iterator  &str2){
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
    return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0]; 
        }
        vector<string>::iterator p = strs.begin();
        // use quicksort
   for(;p!=strs.end();++p){
     for(vector<string>::iterator x=std::next(p,1);x!=strs.end() ;++x){
         if (*x < *p){
          ptrswap(x,p);
         }
     }
   }
   
   int i=0;
   string ans="";
   (strs[strs.size()-1]==ans)?i=1:i=0;
   if(i==1){
       return ans;
   }
    while(strs[0][i]==strs[strs.size()-1][i]&& i<strs[strs.size()-1].size()){
           ans+=strs[0][i];
   i++;
    }
       return ans;
}
};
