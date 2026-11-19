class SmallestInfiniteSet {
public:
    int currentsmallest = 1;
    unordered_set<int> popped;
    SmallestInfiniteSet() {
        
    }
    int popSmallest() {
        while(popped.count(currentsmallest)){
            currentsmallest++;
        }
        int smallest = currentsmallest;
        popped.insert(currentsmallest);
        currentsmallest++;
        return smallest;
    }
    
    void addBack(int num) {
        popped.erase(num);
        if(num < currentsmallest){
            currentsmallest = min(currentsmallest, num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
