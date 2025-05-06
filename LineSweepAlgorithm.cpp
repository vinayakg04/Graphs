class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    //Double booking not allowed here
    //Use map because sweep line algorithm works on sorted keys
    map<int,int> mp;
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;

        int totalCount=0;
        for(auto p: mp){
            totalCount+=p.second;

            if(totalCount>1){
                mp[startTime]-=1;
                mp[endTime]+=1;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
