// The MIT License(MIT)
// Copyright © 2024 Case Technologies

#include "Common.hpp"

namespace CUtils
{
    enum class Alg 
    { 
       Caesar, 
       Vigenere, 
       XOR, 
       Substitution, 
       Transposition 
    };

    class Encryption 
    {
    public:
       Encryption(Alg algorithm, const std::string& key = "");

       std::string Encrypt(const std::string& plaintext);
       std::string Decrypt(const std::string& ciphertext);

    private:
       Alg algorithm;
       std::string key;
    };
}
