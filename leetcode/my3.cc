#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<3){
        cout<< -1<<endl;
    }
    
    else{
        vector<vector<int>> matrix;
        vector<int> odd;
        vector<int> eve;
        for(int i=1;i<n+1;i++){
            if(i%2==1) odd.push_back(i);
            else eve.push_back(i);
        }
        for(int i=0;i<n;i++){
            vector<int> v;
            if(i==0){
                for(int j=0;j<(n/2);j++){
                    v.push_back(odd[j]);
                }
                for(int j=0;j<(n/2);j++){
                    v.push_back(eve[j]);
                }  
            }
            if(i==1){
                v.push_back(matrix[0][0]+n*i);
                //默认奇数
                for(int j=1;j<n;j++){
                    if((matrix[0][j-1]+matrix[0][j]+matrix[i][j-1])%2==0){
                        //需要奇数
                        v.push_back(odd[j+1/2]);
                    }
                    else{
                        //需要偶数
                        v.push_back(eve[j/2]);
                    }
                }   
            }
            matrix.push_back(v);
            if((i>1)&&(i%2==0)){
                for(int j=0;j<n;j++){
                    if(matrix[i-2][j]%2==0){
                        v.push_back(odd[j/2]);
                    }
                    else{
                        v.push_back(eve[j/2]);
                    }
                }
            }
            else{
                for(int j=0;j<n;j++){
                    if(matrix[i-2][j]%2==0){
                        v.push_back(odd[j/2]);
                    }
                    else{
                        v.push_back(eve[j/2]);
                    }
                }
                return matrix;
            }
        }
        
    }
}