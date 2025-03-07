class MovingAverage {
public:
    int size = 0;
    queue<int> q;
    double sum = 0;
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if(q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        sum += val;
        
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */