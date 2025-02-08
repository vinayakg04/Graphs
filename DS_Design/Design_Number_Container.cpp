class NumberContainers {
public:
    unordered_map<int,int> mp;
    unordered_map<int,set<int>> s;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(mp.count(index)){
        int prevNum=mp[index];
        s[prevNum].erase(index);
        
        if(s[prevNum].empty()){
            s.erase(prevNum);
        }
       }

       mp[index]=number;
       s[number].insert(index);
    }
    
    int find(int number) {
        if(s.count(number)){
            return *s[number].begin();
        }

        return -1;
    }
};
