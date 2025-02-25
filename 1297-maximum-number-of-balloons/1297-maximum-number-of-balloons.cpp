class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> balloon(5,0);
        for (int i = 0;i<text.size();i++){
            switch (text[i]){
                case 'b':
                    balloon[0]++;
                    break;
                case 'a':
                    balloon[1]++;
                    break;
                case 'l':
                    balloon[2]++;
                    break;
                case 'o':
                    balloon[3]++;
                    break;
                case 'n':
                    balloon[4]++;
                    break;    
            }
        }
        balloon[2] /= 2;
        balloon[3] /= 2;
        return *min_element(balloon.begin(), balloon.end());
    }
};