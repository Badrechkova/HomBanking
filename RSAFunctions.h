#pragma once
#include<iostream>
#include<math.h>
#include<fstream>
#include<string>
#include<sstream>

//---------------------Function generates big numbers--------------------
double big_random_number() {
double x;
x = rand() % 1000000000000000000 + 1000000000000000000;
return x;
}

//------------------------Variables--------------------
double p = big_random_number();
double q = big_random_number();
double n = p * q;
double phi = (p - 1) * (q - 1);

//---------------------Functions-----------------------------
// //GCD---------------------------------------------------------
int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}
//Generates e---------------------------------------------------
double Gen_e(double phi) {
    double track;
    double e = 11;
    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while (e < phi) {
        track = gcd(e, phi);
        //std::cout << track << std::endl;
        if (track == 1)
            break;
        else
            e++;
    }
    return e;
}

//----------------Inverse variable----------------------------------
double e = Gen_e(phi);
//double d1=1/e;
double d = fmod(1 / e, phi);

//Encryption and Decryption functions--------------------------------------
double Enc_RSA(double age) {
    double cryptAge;
    cryptAge = pow(age, e);
   // std::cout << "encrypted message " << cryptAge << std::endl;
    cryptAge=fmod(cryptAge,n);
    //std::cout << "encrypted message modulo n: " << cryptAge << std::endl;
    return cryptAge;
}
double Dec_RSA(double cipher) {
    double decryptCipher;
    decryptCipher = pow(cipher, d);
    //std::cout << "decrypted message " << decryptCipher << std::endl;
    decryptCipher = fmod(decryptCipher,n);
   // std::cout << "decrypted message modulo n: " << decryptCipher << std::endl;
    return decryptCipher;
}
