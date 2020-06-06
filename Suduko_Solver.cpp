#include<iostream>
#include<cmath>
using namespace std;
bool are_we_put_right_place(int mat[][9],int i,int j,int num,int n){
    for(int a=0;a<n;a++){
        if(mat[i][a]==num||mat[a][j]==num){
            return false;
        }
    }
    n=sqrt(n);
    int row=(i/n)*n;
    int col=(j/n)*n;
    for(i=row;i<row+n;i++){
        for(j=col;j<col+n;j++){
            if(mat[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool SudokoSolver(int mat[][9],int i,int j,int n){
	if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++){
                cout<<mat[k][l]<<" ";
            }
            cout<<endl;
        }
		return true;
	}
	if(j==n){
		return SudokoSolver(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		return SudokoSolver(mat,i,j+1,n);
	}
    for(int num=1;num<=n;num++){
        if(are_we_put_right_place(mat,i,j,num,n)==true){
            mat[i][j]=num;
            bool check_for_remain=SudokoSolver(mat,i,j+1,n);
            if(check_for_remain==true){
                return true;
            }
            mat[i][j]=0;
        }
    }
    
    return false;
}
int main(){
	int mat[][9]={
	 {5,3,0,0,7,0,0,0,0},
	 {6,0,0,1,9,5,0,0,0},
     {0,9,8,0,0,0,0,6,0},
	 {8,0,0,0,6,0,0,0,3},
	 {4,0,0,8,0,3,0,0,1},
	 {7,0,0,0,2,0,0,0,6},
	 {0,6,0,0,0,0,2,8,0},
	 {0,0,0,4,1,9,0,0,5},
	 {0,0,0,0,8,0,0,7,9}
	};
	SudokoSolver(mat,0,0,9);
    return 0;
}
