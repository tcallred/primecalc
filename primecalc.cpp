#include <iostream>
#include <vector>
using namespace std;

class PrimeCalc
{
public:
    bool isPrime(int x){
        if(x == 1) return true;
        if(x == 2) return true;
        for(int i = 2; i < x; i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
    
    void breakdown(int x){
        if(isPrime(x)){
            numberlist.push_back(x);
            return;
        }
        else{
            for(int i = x; i > 1; i-- ){
                if(isPrime(i) && (x % i == 0)){
                    breakdown(i);
                    breakdown(x / i);
                    break;
                }
            }
        }
    }
    
    vector<int> givelist(int x){
        if(!isPrime(x)){
            breakdown(x);
        }        
        else{
            numberlist.push_back(x);
        }
        return numberlist;
    }
private:
    vector<int> numberlist;
    
};
