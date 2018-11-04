#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <utility>
#include <math.h>
using namespace std;

//Iterative Function to calculate (x^y)%p
int power(int x, unsigned int y, int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 

//find d values for alice's decryption
int decrypt(int a){
	long int d = pow(((a+1)/4), 6);
	d = d % (a - 1);
	//cout << d << endl;
	return d;
}
//function to handle when modulus base is negative
int modulo(int a, int b){
	int fin = a % b + (a % b < 0 ? b : 0);
	return fin;
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

//function to convert decimal to binary
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

//alice
int main(int argc, char* argv[]){
	int p = 499;
	int q = 547;
	int n = p * q;
	int a = -57;
	int b = 52;

	int d1 = decrypt(p);
	int d2 = decrypt(q);

	//given by Bob
	int i6 =  139680;
	string cipher = "00100000110011100100";

	unsigned long long int u = power(i6,d1,p);
	unsigned long long int v = power(i6, d2 ,q);

	int vap = v*a*p;
	int ubq = u*b*q;
	long int xi = modulo((vap+ubq),n);
	
	string final_m = "";
	string temp = "";

	long int x_first = (xi * xi) % n;

	for(int i = 0; i < cipher.length()/4; i++){
		
		bitset<4> tmp_bit = bitset<4>(x_first);
		temp = cipher.substr(i*4, 4);
		bitset<4> tmp_bit2 = bitset<4>(temp);
		tmp_bit ^= tmp_bit2;
		final_m.append(tmp_bit.to_string());
		x_first = (x_first * x_first) % n;
	}
	cout << final_m << endl;
}