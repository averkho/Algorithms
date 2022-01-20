#include <iostream>
#include <vector>

void print(std::vector <std::vector<int>> &A, int n, int m){

    for (int i=0; i<=n; ++i){
        for (int j=0; j<=m; ++j){

            std::cout << A[i][j] << '\t';
        }
        std::cout << std::endl;
    }

};

std::vector<std::vector<int>> knapsack_optimization(std::vector<int> &values, std::vector<int> &weights, int W, int n){

    
    std::vector<std::vector<int>> K(n+1,std::vector<int>(W+1));

      

    for (int i=1; i<=n; ++i){

        for (int w=1; w<=W; ++w){

             if (i==0 || w==0){
                 K[i][w]=0;
             }         
            else if (weights[i-1]<=w){
                K[i][w]=std::max(values[i-1]+K[i-1][w-weights[i-1]],K[i-1][w]);
            } else{
                K[i][w]=K[i-1][w];
            }



        }
    }

     
    return K;
}



int main(){

    int W;
    int n;
    
    std::cout << "Enter the maximum size of knapsack ";
    std::cin >> W;

    std::cout << "Enter the number of available items ";
    std::cin >> n;
    std::vector <int> values(n);
    std::vector <int> weights(n);
    std::cout << "Enter the weights and values of items " << std::endl;

    for (int i=0; i<n; ++i){
        std::cout << "The weight of item " << i+1 << " is ";
        std::cin >> weights[i];
        std::cout << " and the value of it is ";
        std::cin >> values[i];
    }

    std::vector<std::vector<int>> Knapsack_result=knapsack_optimization(values,weights,W,n);
    std::cout << "The maximum value of the knapsack is";
    std::cout << Knapsack_result[n][W] << std::endl;
    std::cout << "The knapsack optimization " << std::endl;
    print(Knapsack_result,n,W);

    return 0;
}