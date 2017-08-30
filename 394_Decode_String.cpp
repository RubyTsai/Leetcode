class Solution {
public:
    string decodeString(string s) {
        this->s = s;
        ssize = s.size();
        string ret = "";
        for (int i = 0; i < ssize; i++) {
            if (isalpha(s[i])) ret += s[i];
            else ret += helper(i);
        }
        return ret;
    }
private:
    string s;
    int ssize;
    string helper(int& index) {
        int repeat = getNum(index);
        string tmpStr = "", retStr = "";
        index++; // 吃掉一個 '['
        while (index < ssize && s[index] != ']') {
            if (isalpha(s[index])) tmpStr += s[index];
            else tmpStr += helper(index);
            index++;
        }
        for (int j = 0; j < repeat; j++)
            retStr += tmpStr;
        return retStr;
    }
    int getNum(int& index) {
        int ret = 0;
        while (isdigit(s[index])) {
            ret = ret*10 + (s[index] - '0');
            index++;
        }
        return ret;
    }
};
