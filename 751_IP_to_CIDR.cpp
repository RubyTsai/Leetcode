class Solution {
public:
    vector<string> ipToCIDR(string ip, int range) {
        parse(ip);
        vector<string> ans;
        while (range > 0) {            
            if (ipn[3] % 2) {
                ans.emplace_back(genStr());
                range--;
                
                if (++ipn[3] == 256) {
                    ipn[3] = 0;
                    if (++ipn[2] == 256) {
                        ipn[2] = 0;
                        if (++ipn[1] == 256) {
                            ipn[1] = 0;
                            ip[0]++;
                        }
                    }
                }
            }
            else {
                jump = 1; bool cont = true;
                for (int j = 3; j >= 0 && cont; j--) {
                    int n = ipn[j];
                    int pow = 1;
                    for (int i = 0; i < 8; i++) {
                        if (n % 2 == 1) {
                            if (range >= jump) {
                                ans.emplace_back(genStr());                     
                                ipn[j] -= pow;
                                ipn[j] += pow*2;
                                for (; j >=0; j--) {
                                    if (ipn[j] > 255) {
                                        ipn[j-1] += ipn[j]/256;
                                        ipn[j] %= 256;
                                    }
                                    else break;
                                }
                            }
                            else {
                                ans.emplace_back(genStr(range));
                                ipn[3] += jump;
                                for (j = 3; j >= 0; j--) {
                                    if (ipn[j] > 255) {
                                        ipn[j-1] += ipn[j]/256;
                                        ipn[j] %= 256;
                                    }
                                    else break;
                                }
                            }
                            range -= jump;
                            cont = false;
                            break;
                        }
                        jump *= 2;
                        pow *= 2;
                        n >>= 1;
                    }
                }
            }
        }
        return ans;
    }
private:
    int ipn[4], jump;
    string genStr() { 
        string str;
        for (int i = 0; i < 3; i++)
            str += to_string(ipn[i]) + ".";
        str += to_string(ipn[3]);
        int fixed = 32;
        for (int j = 3; j >= 0; j--) {
            int n = ipn[j];
            for (int i = 0; i < 8; i++) {
                if (n % 2 == 1) {
                    str += "/" + to_string(fixed);   
                    return str;
                }
                n >>= 1; fixed--;
            }
        }
        str += "/" + to_string(0);
        return str;
    }
    string genStr(int range) { 
        string str;
        for (int i = 0; i < 3; i++)
            str += to_string(ipn[i]) + ".";
        str += to_string(ipn[3]);
        int fixed = 32;
        while (range > 1) {
            range >>= 1;
            fixed--;
        }
        str += "/" + to_string(fixed);
        jump = pow(2, 32 - fixed);
        return str;
    }
    void parse(string ip) {
        int n = 0, i = 0;
        for (auto& c: ip) {
            if (c == '.') {
                ipn[i++] = n;
                n = 0;
            }
            else {
                n *= 10;
                n += c - '0';
            }
        }
        ipn[3] = n;        
    }
};
