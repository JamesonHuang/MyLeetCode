/*************************************************************************
	> File Name:        Solution.h
	> Description:      
	> Conclusion:          
	> Author:           rh_Jameson
	> Created Time:     2014年12月07日 星期日 17时10分20秒
 ************************************************************************/
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        int p = 0; q = p;
       
        while(q < len){
            if(s[p] == ' '){
                p++;
                q = p;
                continue;
            }
            if(s[q] != ' '){
                q++;
            }
            else{
                reverse(p, q - 1, s);
                p = q;
            }
        }
        reverse(0, len - 1, s);
    }
    
    void reverse(int p, int q, string& s){
        char tmp;
        while(p < q){
            tmp = s[p];
            s[p++] = s[q];
            s[q--] = tmp;
        }
    }
};
