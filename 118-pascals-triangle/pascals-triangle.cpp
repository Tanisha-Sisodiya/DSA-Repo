class Solution {
public: 
    void getpasTriangle(vector<vector<int>>& arr, int nR){
        for(int i = 0; i<nR; i++){
            arr.push_back(vector<int>(i + 1));
            for(int j = 0; j<=i; j++){
                if(j==0 || j==i){
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                }

            }
        }
    }

    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> arr;
    getpasTriangle(arr, numRows);   
    return arr;
    }
};