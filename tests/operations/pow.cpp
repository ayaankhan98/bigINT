#include <stdio.h>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
#include "../bigint.hpp"


int multiply(int x, int res[], int res_size) {
        int carry = 0;
    
        for (int i = 0; i < res_size; i++) {
            int prod = res[i] * x + carry;    
            res[i] = prod % 10;
            carry = prod / 10;
        }
    
        while (carry) {
            res[res_size] = carry % 10;
            carry = carry / 10;
            res_size++;
        }
        return res_size;
    }
    
    
largeInt* pow(int a, int b) 
    {
        if(b == 0 ){ 
            cout<< "1";
            return NULL;
        }
    
    
        int res[100000];
        int res_size = 0;
        int temp = a;
    
        while (temp != 0) {
            res[res_size++] = temp % 10;
            temp = temp / 10;
        }
        
        for (int i = 2; i <= b; i++)
            res_size = multiply(a, res, res_size);
        
        cout << a << "^" << b << " = ";
        string str;
        int flag=0;
        if(res[res_size - 1]<0){
                flag=1;
        }
                
        for (int i = res_size - 1; i >= 0; i--){
            int a=res[i];
            if(a<0){
                a=-a;
            }
            char ch='0'+a;


            str=str+ch;
        }


        if(flag==1){
            str='-'+str;
        }
        
        
        largeInt * tempo=new largeInt(str);
        return tempo;

}




int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    largeInt *obj=pow(3,21);
    //3 to the power 21 is stored in object whose reference is obj pointer
}