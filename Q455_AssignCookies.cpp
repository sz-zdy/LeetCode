class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //g : gread factor ; s : cookie size
        if(g.empty() || s.empty()) return 0;

        int result = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        auto it_g = g.begin();
        auto it_s = s.begin();
        for(;it_g != g.end(); it_g++){
            it_s = find_if(it_s, s.end(), [it_g](int size)->bool{return (*it_g <= size);});
            if(it_s != s.end()){
                result ++;
                it_s++;
            }
            else
                return result;
        }

        return result;
    }
};

int main(){
    vector<int> g={};
    vector<int> s={};

}