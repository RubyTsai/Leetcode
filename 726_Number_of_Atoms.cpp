class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> m;
        int size = formula.size();
        char c; int num = -1;
        string atom;
        for (int i = 0; i < size; i++) {
            parse(formula, i, m, num, atom);
        }
        if (num != -1) m[atom] += num? num: 1;
        string ans;
        for (auto& kv: m) {
            ans += kv.first;
            if (kv.second > 1)
                ans += to_string(kv.second);
        }
        return ans;
    }
private:
    map<string, int> helper(string f, int& i) {        
        map<string, int> m;
        char c; int num = -1;
        string atom;
        for (; f[i] != ')'; i++) {
            parse(f, i, m, num, atom);
        }
        if (num != -1) { m[atom] += num? num: 1; }
        num = 0;
        while (++i < f.size() && isdigit(f[i])) num = num*10 + f[i] - '0';
        i--;
        for (auto& kv: m)
            kv.second *= num;
        return m;
    }
    void parse(string f, int& i, map<string, int>& m, int& num, string& atom) {
        char c = f[i];
        if (c == '(') {
            if (num != -1) m[atom] += num? num: 1;                   
            
            map<string, int> tmp = helper(f, ++i);
            for (auto& kv: tmp)
                m[kv.first] += kv.second;
            num = -1;
        }
        else if (isupper(c)) {
            if (num != -1) {
                m[atom] += num? num: 1;
                atom.clear();
            }
            num = 0;
            atom = move(string(1, c));
        }
        else if (islower(c)) { atom += c;}
        else if (isdigit(c)) { num = num*10 + c - '0'; }
    }
}; 
//--------------------------------------------------------------------------
// 以下為原本的想法，上面的是把 loop body 拉出來成為一個 function
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> m;
        int size = formula.size();
        char c; int num = -1;
        string atom;
        for (int i = 0; i < size; i++) {
            c = formula[i];
            if (c == '(') {
                if (num != -1) {
                    m[atom] += num? num: 1;                   
                }
                map<string, int> tmp = helper(formula, ++i);
                for (auto& kv: tmp)
                    m[kv.first] += kv.second;
                num = -1;
            }
            else if (isupper(c)) {
                if (num != -1) {
                    m[atom] += num? num: 1;
                    atom.clear();
                }
                num = 0;
                atom = move(string(1, c));
            }
            else if (islower(c)) { atom += c;}
            else if (isdigit(c)) { num = num*10 + c - '0'; }
        }
        if (num != -1) m[atom] += num? num: 1;
        string ans;
        for (auto& kv: m) {
            ans += kv.first;
            if (kv.second > 1)
                ans += to_string(kv.second);
        }
        return ans;
    }
private:
    map<string, int> helper(string f, int& i) {        
        map<string, int> m;
        char c; int num = -1;
        string atom;
        for (; f[i] != ')'; i++) {
            c = f[i];
            if (c == '(') {
                if (num != -1) {
                    m[atom] += num? num: 1;                    
                }
                map<string, int> tmp = helper(f, ++i);
                for (auto& kv: tmp)
                    m[kv.first] += kv.second;
                num = -1;
            }
            else if (isupper(c)) {
                if (num != -1) {
                    m[atom] += num? num: 1; 
                    atom.clear();                    
                }
                num = 0;
                atom = move(string(1, c));
            }
            else if (islower(c)) { atom += c;}
            else if (isdigit(c)) { num = num*10 + c - '0'; }
        }
        if (num != -1) { m[atom] += num? num: 1; }
        num = 0;
        i++;
        while (i < f.size() && isdigit(f[i])) num = num*10 + f[i++] - '0';
        i--;
        for (auto& kv: m)
            kv.second *= num;
        return m;
    }
};
