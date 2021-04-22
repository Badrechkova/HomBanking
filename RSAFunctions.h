#pragma once
#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<sstream>
#include<random>

//------------------------------------------FOR THE BANK -------------------------------------------------------------------|
//---------------------Function generates big numbers--------------------                                                   |
double big_random_number() {                                                                                              //|     
    /* Seed */                                                                                                            //|  
    std::random_device rd;                                                                                                //|  
                                                                                                                          //|        
    /* Random number generator */                                                                                         //|  
    std::default_random_engine generator(rd());                                                                           //|    
                                                                                                                          //|    
    /* Distribution on which to apply the generator */                                                                    //|   
    std::uniform_int_distribution<long long unsigned> distribution(0, 0xFFFFFFFFFFFFFFFF);                                //|            
                                                                                                                          //|  
    return  distribution(generator);                                                                                      //|  
}                                                                                                                         //|            
                                                                                                                          //|        
                                                                                                                          //|                     
bool isPrime(int number)                                                                                                  //|        
{                                                                                                                         //|     
    // 0 and 1 are not prime numbers                                                                                      //|    
    if (number == 0 || number == 1) {                                                                                     //|    
        return false;                                                                                                     //|    
    }                                                                                                                     //|    
    else {                                                                                                                //|    
        for (int a = 2; a < number / 2; a++) {                                                                            //|  
            if (number % a == 0) {                                                                                        //|    
                return false;                                                                                             //|    
            }                                                                                                             //|    
        }                                                                                                                 //|    
    }                                                                                                                     //|                    
    return true;                                                                                                          //|    
}                                                                                                                         //|    
                                                                                                                          //|    
double big_prime(double big_num) {                                                                                        //|    
    double y;                                                                                                             //|    
    if (isPrime(big_num) == true)                                                                                         //|    
    {                                                                                                                     //|            
        y = big_num;                                                                                                      //|                                                                                                        //|    
    }                                                                                                                     //|  
    return y;                                                                                                             //|    
}                                                                                                                         //|                
                                                                                                                          //|    
//------------------------Variables--------------------                                                                   //|                
//double p = big_random_number();                                                                                         //|             
double p = big_prime(big_random_number());                                                                                //|         
//double q = big_random_number();                                                                                         //|    
double q = big_prime(big_random_number());                                                                                //|    
double n = p * q;                                                                                                         //|        
double phi = (p - 1) * (q - 1);                                                                                           //|    
                                                                                                                          //|                     
//---------------------Functions-----------------------------                                                             //|            
// //GCD---------------------------------------------------------                                                         //|        
int gcd(int a, int b) {                                                                                                   //|        
    int t;                                                                                                                //|    
    while (1) {                                                                                                           //|        
        t = a % b;                                                                                                        //|                                
        if (t == 0)                                                                                                       //|    
            return b;                                                                                                     //|    
        a = b;                                                                                                            //|            
        b = t;                                                                                                            //|                
    }                                                                                                                     //|    
}                                                                                                                         //|    
//Generates e---------------------------------------------------                                                          //|        
double Gen_e(double phi) {                                                                                                //|    
    double track;                                                                                                         //|    
    double e = 17;                                                                                                        //|    
    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.                            //|                
    while (e < phi) {                                                                                                     //|    
        track = gcd(e, phi);                                                                                              //|    
        //std::cout << track << std::endl;                                                                                //|        
        if (track == 1)                                                                                                   //|    
            break;                                                                                                        //|        
        else                                                                                                              //|                                                                                                                    //|        
            e++;                                                                                                          //|                
    }                                                                                                                     //|           
    return e;                                                                                                             //|   
}                                                                                                                         //|   
                                                                                                                          //|   
//----------------Inverse variable----------------------------------                                                      //|         
double e = Gen_e(phi);                                                                                                    //|   
//double d1=1/e;                                                                                                          //|   
double d = fmod(1 / e, phi);                                                                                              //|                   
//------------------------------------------FOR THE BANK -------------------------------------------------------------------|



//----------------------FOR EVOOQ'S CLOUD--------------------------------------------|
//Encryption function using the PUBLIC KEY (e,n)----------------------------         |   
double Enc_RSA(double age) {                                                       //|        
    double cryptAge;                                                               //| 
    cryptAge = pow(age, e);                                                        //|     
    // std::cout << "encrypted message " << cryptAge << std::endl;                 //|     
    cryptAge = fmod(cryptAge, n);                                                  //| 
    //std::cout << "encrypted message modulo n: " << cryptAge << std::endl;        //|     
    return cryptAge;                                                               //| 
}                                                                                  //| 
//----------------------FOR EVOOQ'S CLOUD--------------------------------------------|


//------------------FOR EVOOQ'S CLOUD AND THE BANK-----------------------------------|
//Decryption function--------------------------------------                          |   
double Dec_RSA(double cipher) {                                                    //|
    double decryptCipher;                                                          //|
    decryptCipher = pow(cipher, d);                                                //|
    //std::cout << "decrypted message " << decryptCipher << std::endl;             //|
    decryptCipher = fmod(decryptCipher, n);                                        //|
    // std::cout << "decrypted message modulo n: " << decryptCipher << std::endl;  //|
    return decryptCipher;                                                          //|
}                                                                                  //|
//------------------FOR EVOOQ'S CLOUD AND THE BANK-----------------------------------|

//----------------------FOR EVOOQ'S CLOUD---------------------------------------------|
double Enc_RSA_Cloud(double l, double exposant_cloud) {                             //|
    double val;                                                                     //|        
    val = Enc_RSA(l, exposant_cloud);                                               //| 
    return val;                                                                     //|     
}                                                                                   //| 
//----------------------FOR EVOOQ'S CLOUD---------------------------------------------|
