#include <iostream>
using namespace std;




class Solution {
public:

    void ptrswap(vector<string>::iterator str1, vector<string>::iterator  str2){
    string temp = *str1;
    *str1 = *str2;
    *str2 = temp;
    return;
    }
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::iterator p = strs.begin();
        // use quicksort
   for(;p!=strs.end();++p){
     for(vector<string>::iterator x=p;x!=strs.end();++x){
         if (*x < *p){
          ptrswap(x,p);
         }
     }
   }
   int i=0;
   string ans="";
    while(strs[0][i]==strs[strs.size()-1][i]){
           ans+=strs[0][i];
   i++;
    }
       return ans;
}
};
