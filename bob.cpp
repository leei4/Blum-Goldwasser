#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <utility>

using namespace std;

//find LSB at n
bool LSB(int num, int K) 
{ 
    return (num & (1 << (K-1))); 
}
//pad binary value with extra 0's if needed
string pad(string s){
    string new_string = string(4 - s.length(), '0') + s;
    return new_string;
}
// Function to convert binary to decimal 
int b_d(int n) 
{ 
    int num = n; 
    int dec_value = 0; 
      
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
      
    int temp = num; 
    while (temp) 
    { 
        int last_digit = temp % 10; 
        temp = temp/10; 
          
        dec_value += last_digit*base; 
          
        base = base*2; 
    } 
      
    return dec_value; 
}

//Function to convert from decimal to binary
string d_b(int n) 
{   
    string bin = "";
    // array to store binary number 
    int binaryNum[1000]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--){
        bin += to_string(binaryNum[j]); 
    }
    return bin;
} 

//Bob
int main(int argc, char* argv[]){

    //1001 1100 0001 0000 1100
    string message = "10011100000100001100";
    int messageb [5] = {9, 12, 1, 0, 12};

    //given by Alice
	//request public key N
    int n = 272953;
    long int qr = 159201;

    int ci = 0;
    string p = "";
    string final_cipher = "";

    long int temp = (qr * qr) % n;
    
    for( int t = 0; t < 5; t++){
        p = "";
        for(int i = 4; i > 0; i--){
            p += to_string(LSB(temp, i));
    }
    ci = b_d(stoi(p)) ^ messageb[t];
    final_cipher += pad(d_b(ci));

    temp = (temp * temp) % n; //adjust to exponentiate
    }

    //Ciphertext
    pair<string, int> cipher_pair;
    cipher_pair.first = final_cipher;
    cipher_pair.second = temp;
    //c = 134372
    //i6 = 139680
    cout << cipher_pair.first << " " << cipher_pair.second << endl;

}