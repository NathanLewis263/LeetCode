class Solution {
public:
    string predictPartyVictory(string& senate) {
        queue<int> R;
        queue<int> D;
        
        for (int i = 0;i<senate.size();i++){
            if (senate[i] == 'R'){
                R.push(i);
            } else {
                D.push(i);
            }
        }
        while (!R.empty() && !D.empty()){
            int rTurn = R.front();
            R.pop();
            int dTurn = D.front();
            D.pop();
            if (dTurn < rTurn){
                D.push(dTurn+senate.size());
            } else {
                R.push(rTurn+senate.size());
            }
        }
        return R.empty() ? "Dire" : "Radiant";
    }
};