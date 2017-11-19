class MyCalendar {
public:
    MyCalendar() { }
    
    bool book(int start, int end) {
        auto it0 = c.lower_bound(start);      
        auto itb = it0;
        if (it0 != c.begin()) {
            itb--;
            if (itb->second > start) return false;
        }
        auto ita = c.lower_bound(end);
        
        for (auto it = it0; it != ita; it++) {
            if (it->first >= start) return false;
        }
        if (itb->second == start) itb->second = end;
        else if (ita->first == end) {
            c[start] = it0->second;
            c.erase(ita);
        }    
        else c[start] = end;
        return true;
    }
private:
    map<int, int> c;
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
