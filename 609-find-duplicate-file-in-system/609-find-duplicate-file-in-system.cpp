class Solution {
public:
    vector<vector<string> > findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > res;
        for(int i=0; i<paths.size(); i++) {
            string str = paths[i];
            stringstream X(str);
            string s;
            vector<string> ss;
            while(X>>s) {
                ss.push_back(s);
            }
            string dir = ss[0];
            for(int i=1; i<ss.size(); i++) {
                int n = ss[i].find(".txt", 0);
                res[ss[i].substr(n+3)].push_back(dir+"/"+ss[i].substr(0, n+4));
            }
        }
        
        unordered_map<string, vector<string> > :: iterator it;
        vector<vector<string> > ans;
        for(it=res.begin(); it!=res.end(); it++) {
            if((it->second).size() > 1) {
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};