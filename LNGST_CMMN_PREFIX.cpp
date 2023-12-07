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







// str2
//
// LNGST_CMMN_PREF
// class Solution {
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
   }  char *cp = &strs[0][0]; const char* endp1=&strs[0][strs[0].size()-1];
    char*cp2 = &strs[strs.size()-1][0]; const char* endp2= &strs[strs.size()-1][strs[strs.size()-1].size()-1];
   string ans="";
    while(*cp==*cp2&& cp != endp1 && cp2!=endp2){
           ans+= *cp;
   ++cp; ++cp2;
    }
       return ans;
}
};
