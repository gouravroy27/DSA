class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.empty()) return "";
        
        vector<string> tokens;
        int count = 0;
        int start = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            count += (s[i] == '1') ? 1 : -1;
            
            if (count == 0) {
                string inside = s.substr(start + 1, i - start - 1);
                tokens.push_back("1" + makeLargestSpecial(inside) + "0");
                
                start = i + 1;
            }
        }
        
        sort(tokens.begin(), tokens.end(), greater<string>());
        
        string result = "";
        for (const string& token : tokens) {
            result += token;
        }
        
        return result;
    }
};