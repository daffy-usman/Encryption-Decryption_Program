# Encryption-Decryption Program

## Overview

This C++ program provides a menu-driven interface for encrypting and decrypting text using three classic ciphers:
- **Caesar Cipher**
- **XOR Cipher**
- **Vigenère Cipher**

The user can select encryption or decryption, choose a cipher, and provide the required keys.

---

## How to Use

1. **Run the Program:**  
   Compile and run the code. You’ll be prompted to choose between encryption and decryption.

2. **Select Cipher:**  
   Choose one of the three supported ciphers.

3. **Input Data:**  
   - Enter the sentence to encrypt or decrypt.
   - Enter the required key (shift for Caesar, integer for XOR, keyword for Vigenère).

4. **View Result:**  
   The program displays the encrypted or decrypted result.

5. **Repeat or Exit:**  
   Choose to run again or exit the program.

---

## Function Documentation

### Caesar Cipher

**Caesar_Cipher_Enc**  
Encrypts a string using the Caesar cipher.
```cpp
string Caesar_Cipher_Enc(string sentence, int shift)
```
- **sentence**: The input text to encrypt.
- **shift**: The integer shift value.
- **Returns**: Encrypted string.

**Caesar_Cipher_Dec**  
Decrypts a string using the Caesar cipher.
```cpp
string Caesar_Cipher_Dec(string sentence, int shift)
```
- **sentence**: The encrypted text.
- **shift**: The integer shift value.
- **Returns**: Decrypted string.

---

### XOR Cipher

**XOR_Cipher**  
Encrypts or decrypts a string using XOR operation (symmetric).
```cpp
string XOR_Cipher(string sentence, int key)
```
- **sentence**: The input text.
- **key**: Integer key value.
- **Returns**: Encrypted or decrypted string.

---

### Vigenère Cipher

**Vigenere_Cipher_Enc**  
Encrypts a string using the Vigenère cipher.
```cpp
string Vigenere_Cipher_Enc(string sentence, string keyword)
```
- **sentence**: The input text to encrypt.
- **keyword**: The keyword used for encryption.
- **Returns**: Encrypted string.

**Vigenere_Cipher_Dec**  
Decrypts a string using the Vigenère cipher.
```cpp
string Vigenere_Cipher_Dec(string sentence, string keyword)
```
- **sentence**: The encrypted text.
- **keyword**: The keyword used for decryption.
- **Returns**: Decrypted string.

---

## Main Menu Flow

- Prompts for encryption or decryption.
- Prompts the user to select one of the three ciphers.
- Requests the sentence and relevant key/keyword.
- Calls the appropriate function and outputs the result.
- Allows the user to run the program again or exit.

---

## Notes

- Only alphabetic characters are ciphered; non-letters are preserved.
- For XOR, encryption and decryption are the same operation.
- Input validation is basic; invalid choices exit the loop or prompt for re-entry.

---

## Example

```
Enter your choice:
1. Encryption
2. Decryption
>> 1

Enter type of Encryption you want:
1. Caesar Cipher
2. XOR Cipher
3. Vigenere Cipher
>> 1

Enter a sentence you want to Encryption : Hello World!
Enter the shift (number): 3

Encrypted Sentence: Khoor Zruog!
