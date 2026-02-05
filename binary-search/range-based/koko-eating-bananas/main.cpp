class Solution {
public:
   int sz;


   bool canKokoEat(vector<int>&piles, int h, int speed) {
       int time = 0;


       for (int i=0; i<sz; ++i) {
           int hoursNeeded = piles[i] / speed;


           if ((piles[i] % speed) > 0) {
               ++hoursNeeded;
           }


           time += hoursNeeded;
       }


       return (time <= h) ? 1 : 0;
   }


   int minEatingSpeed(vector<int>& piles, int h) {
       int l = 1;
       int r = INT_MAX;
       int ans = -1;
       sz = piles.size();


       while (l <= r) {
           int m = l + ((r-l) >> 1);
           bool canEat = canKokoEat(piles, h, m);


           if (canEat) {
               ans = m;
               r = m-1;
           } else {
               l = m+1;
           }
       }


       return ans;
   }
};
