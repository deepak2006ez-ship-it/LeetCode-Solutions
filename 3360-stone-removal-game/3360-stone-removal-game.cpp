class Solution {
public:
    bool canAliceWin(int n) {
        int remove = 10;
        int k=n;
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                if (remove > n) {
                    return false;
                } else {
                    n -= remove;
                }
            } else {
                n -= remove;
                if (n < 0) {
                    break;
                }
    
            }
            remove -= 1;
        }
        return true;
    }
};