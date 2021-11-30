#include <iostream>
#include <fstream>
int main(){

    std::ifstream input("input.txt"); // opening the input file

    const int processes =(input.get()-48);
    input.get();

    const int resources =input.get()-48;
    input.get(); input.get();

    int allocation[processes][resources];
    int max[processes][resources];
    int available[resources];
    int need[processes][resources];
    
    //initializes allocation
    for (int i = 0; i < processes; i++){
        for (int j = 0; j < resources; j++){
            allocation[i][j]=(input.get()-48);
            input.get();
        }
    }
    input.get();
    
    //initializes max
    for (int i = 0; i < processes; i++){    
        for (int j = 0; j < resources; j++){
            max[i][j]=(input.get()-48);
            input.get();
        }
    }
    input.get();

    //initializes available
    for (int i =0; i<resources; i++){
        available[i]=(input.get()-48);
        input.get();
    }

    //initializes need
    for (int i = 0; i < processes; i++){    
        for (int j = 0; j < resources; j++){
            need[i][j]=max[i][j] - allocation[i][j];
            input.get();
        }
    }
    //initializes finish
    bool finish[processes];
    for(int i =0; i<processes; i++){
        finish[i]=false;
    }
    //declares safe sequence array and counter
    int safe[processes];
    int safeCount=0;
    
    //safety algorithm implementation
    for (int i =0; i<processes; i++){
        for (int j =0; j<processes; j++){
            if(finish[j]==false){
                int x=0;
                for(int k=0; k<resources; k++){
                    if(need[j][k]>available[k]){
                        x=1;
                        break;
                    }
                }
                if(x==0){
                    safe[safeCount++]=j;
                    for(int k =0; k<resources; k++){
                        available[k]+=allocation[j][k];
                    }
                    finish[j]=true;
                }
            }
        }
    }

    //outputting the safe sequence
    std::cout<<"Safe sequence is:";
    for(int i =0; i<processes; i++){
        std::cout<<safe[i]<<" ";
    }

    input.close();
}