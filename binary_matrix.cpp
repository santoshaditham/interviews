/* find if a binary matrix (all 0s and 1s) has a rectangle with corners as 1s */

#include <iostream>
#include <vector>
using namespace std;

bool match(vector<int>& r1positions, vector<int>& r2positions){
    int count=0;
    for(int i=0; i<r1positions.size(); i++){
        if(r1positions[i] == r2positions[i] == 1){
            count++;
        }
    }
    if(count>1) return true;
    else return false;
}

//step1: at least 2 rows should have 2 or more 1s
//step2: positions of 1s should match
bool isThereRect(vector<vector<int>> matrix, int row, int col){
    bool r1 = false, r2 = false;
    vector<int> r1positions, r2positions;
    for(int c=0; c<col; c++){
        vector<int> positions;
        for(int r=0; r<row; r++){
            if(matrix[r][c]==1){
                positions.push_back(r);
            }
        }
        if(positions.size()>1){
            if(!r1){ 
                r1=true;
                r1positions = positions;
            }
            else{
                if(match(positions, r1positions)){
                    r2=true;
                    r2positions = positions;
                }
            }
        }
    }
    return (r1 && r2);
}

//given a binary matrix, find if there is rectangle with corners as 1
int main()
{
    int r=4, c=4;
    vector<vector<int>> matrix = {{1,0,0,1},{0,1,1,0},{1,0,1,1},{0,1,0,0}};
    if(isThereRect(matrix,r,c))
        cout << "yay" << endl;
    return 0;
}
