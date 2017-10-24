class RangeModule {
public:
   
    void addRange(int left, int right) {
        auto litup = m.upper_bound(left);
        auto ritup = m.upper_bound(right);        
        if (litup != m.begin()) {
            if ((--litup)->second >= left)
                left = litup->first;
            litup++;
        }
        if (ritup != m.begin()) { 
            if ((--ritup)->second > right)
                right = ritup->second;
            ritup++;
            m.erase(litup, ritup);
        }
        m[left] = right;
    }     
    bool queryRange(int left, int right) {
        auto litup = m.upper_bound(left);
        if (litup == m.begin() || (--litup)->second < right) return false;                
        return true;
    }
    void removeRange(int left, int right) {
        auto litup = m.upper_bound(left);
        auto ritup = m.upper_bound(right);    
        if (litup != m.begin()) {
            if ((--litup)->second > left) {
                if (litup->second > right) {
                    m[right] = litup->second;
                    litup->second = left;
                    return;
                }
                else litup->second = left;
            }
            litup++;
        }
        if (ritup != m.begin()) { 
            int newEnd = -1;
            if ((--ritup)->second > right) 
                newEnd = ritup->second;
            m.erase(litup, ++ritup);
            if (newEnd != -1) m[right] = newEnd;
        }
    }
private:
    map<int, int> m;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
