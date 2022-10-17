#include<bits/stdc++.h>
class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for(int i=0; i<sentence.length(); i++){
            s.insert(sentence[i]);
        }
        int count = 0;
        set<char>::iterator it;
        for(it = s.begin(); it!=s.end(); it++) {
            count++;
            if(count == 26) {
                return true;
            }
        }
        
        return false;
    }
};