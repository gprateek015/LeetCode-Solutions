class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1) {
            if (n==1) {
                return flowerbed[0]==0;
            } else if(n==0)
                return true;
            return false;
        }
        for(int i=0; i<flowerbed.size(); i++) {
            if(flowerbed[i]==0) {
                if(i!=0 && i<flowerbed.size()-1 && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
                    flowerbed[i]=1;
                    n--;
                } else if (i==0 && flowerbed[i+1]==0) {
                    flowerbed[i]=1;
                    n--;
                } else if (i==flowerbed.size()-1 && flowerbed[i-1]==0) {
                    flowerbed[i]=1;
                    n--;
                }
            }
        }
        return n<=0;
    }
};