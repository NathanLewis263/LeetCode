class SmallestInfiniteSet {
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> addedIntegers;
    int currentInteger;
public:
    SmallestInfiniteSet() {
        currentInteger = 1;
    }
    
    int popSmallest() {
        if (!isPresent.empty()){
            int ans = addedIntegers.top();
            addedIntegers.pop();
            isPresent.erase(ans);
            return ans;
        } else {
            currentInteger++;
            return currentInteger-1;
        }
    }
    
    void addBack(int num) {
        if (currentInteger>num && isPresent.count(num) == 0){
            addedIntegers.push(num);
            isPresent.insert(num);
        } else {
            return;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */