class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> myStack;
        for (int& asteroid : asteroids){
            while (!myStack.empty() && asteroid < 0 && myStack.top() > 0){
                if (asteroid+myStack.top()<0){
                    myStack.pop(); 
                } else if (asteroid+myStack.top() > 0) {
                    asteroid = 0;
                } else {
                    myStack.pop();
                    asteroid = 0;
                }
            }
            if (asteroid){
                myStack.push(asteroid);
            }
        }
   
         
        vector<int> output(myStack.size());
        for (int i = output.size()-1; i>-1;i--){
            output[i] = myStack.top();
            myStack.pop();
        }
        return output;
    }
};