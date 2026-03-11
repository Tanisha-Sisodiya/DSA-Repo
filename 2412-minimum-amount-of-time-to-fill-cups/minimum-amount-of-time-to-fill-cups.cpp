class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i = 0; i< amount.size(); i++){
            if(amount[i]>0){
            pq.push(amount[i]);
            }
        }
        int seconds = 0; 
        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            y--;
            int x = pq.top();
            pq.pop();
            x--;
            seconds++;
            if(y > 0) pq.push(y);
            if(x > 0) pq.push(x);
        }
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            x--;
            seconds++;
            if(x > 0) pq.push(x);
        }
        return seconds;
    }
};