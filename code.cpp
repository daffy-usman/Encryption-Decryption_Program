#include <iostream>
#include <string>

using namespace std;

// Caesar Cipher (Encryption)
string Caesar_Cipher_Enc(string sentence, int shift)
{
    string result;

    for (char c : sentence)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((c - base) + shift + 26) % 26 + base);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

// Caesar Cipher (Decription)
string Caesar_Cipher_Dec(string sentence, int shift)
{
    string result;

    for (char c : sentence)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            result += char(((c - base) - shift + 26) % 26 + base);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

// XOR Cipher (Encryption/Decription)
string XOR_Cipher(string sentence, int key)
{
    string result = sentence;
    for (char &c : result)
    {
        c = c ^ key;
    }
    return result;
}

// Vigenère cipher (Encryption)
string Vigenere_Cipher_Enc(string sentence, string keyword)
{
    string result;
    int index = 0;
    int keyLen = keyword.length();

    for (char c : sentence)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char keyChar = toupper(keyword[index % keyLen]) - 'A';
            result += char(((c - base) + keyChar + 26) % 26 + base);
            index++;
        }
        else
        {
            result += c;
        }
    }
    return result;
}

// Vigenère Cipher (Decription)
string Vigenere_Cipher_Dec(string sentence, string keyword)
{
    string result;
    int index = 0;
    int keyLen = keyword.length();

    for (char c : sentence)
    {
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char keyChar = toupper(keyword[index % keyLen]) - 'A';
            result += char(((c - base) - keyChar + 26) % 26 + base);
            index++;
        }
        else
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    bool flag = true;
    do
    {
        int choice_1;
        int choice_2;
        int choice_3;
        string sentence;
        int key;
        string keyword;
        string result;

        // Ask Encryption or Decryption
        cout << "Enter your choice:" << endl;
        cout << "1. Encryption" << endl;
        cout << "2. Decryption" << endl;
        cout << ">> ";
        cin >> choice_1;

        // Validate Encryption/Decryption choice
        if (choice_1 != 1 && choice_1 != 2)
        {
            cout << "Invalid choice. Exiting" << endl;
            continue;
        }

        // Determining type
        string choice_type = (choice_1 == 1) ? "Encryption" : "Decryption";

        // 2) Ask which cipher
        cout << "\nEnter type of " << choice_type << " you want:" << endl;
        cout << "1. Caesar Cipher" << endl;
        cout << "2. XOR Cipher" << endl;
        cout << "3. Vigenere Cipher" << endl;
        cout << ">> ";
        cin >> choice_2;

        // Validate cipher type
        if (choice_2 < 1 || choice_2 > 3)
        {
            cout << "Invalid cipher choice. Exiting" << endl;
            continue;
        }

        // Getting the sentence
        cin.ignore();
        cout << "Enter a sentence you want to " << choice_type << " : ";
        getline(cin, sentence);

        // Process based on cipher & encryption/decryption
        switch (choice_2)
        {
        case 1: // Caesar Cipher
            cout << "\nYou chose Caesar Cipher (" << choice_type << ")" << endl;
            cout << "Enter the shift (number): ";
            cin >> key;

            if (choice_1 == 1)
            {
                // Encryption
                result = Caesar_Cipher_Enc(sentence, key);
                cout << "\nEncrypted Sentence: " << result << "\n";
            }
            else
            {
                // Decryption
                result = Caesar_Cipher_Dec(sentence, key);
                cout << "\nDecrypted Sentence: " << result << "\n";
            }
            break;

        case 2: // XOR Cipher
            cout << "\nYou chose XOR Cipher (" << choice_type << ").\n";
            cout << "Enter the key (number): ";
            cin >> key;

            // XOR is symmetric: call the same function to encrypt/decrypt
            result = XOR_Cipher(sentence, key);
            if (choice_1 == 1)
            {
                cout << "\nEncrypted Sentence: " << result << "\n";
            }
            else
            {
                cout << "\nDecrypted Sentence: " << result << "\n";
            }
            break;

        case 3: // Vigenere Cipher
            cout << "\nYou chose Vigenere Cipher (" << choice_type << ").\n";
            cout << "Enter the keyword (letters only): ";
            getline(cin, keyword);

            if (choice_1 == 1)
            {
                // Encryption
                result = Vigenere_Cipher_Enc(sentence, keyword);
                cout << "\nEncrypted Sentence: " << result << "\n";
            }
            else
            {
                // Decryption
                result = Vigenere_Cipher_Dec(sentence, keyword);
                cout << "\nDecrypted Sentence: " << result << "\n";
            }
            break;

        default:
            // Should never reach here because we validated choice_2
            cout << "\nYou entered a wrong choice!\n";
            break;
        }
        while (true)
        {
            cout << "Do you want to run the program Again...!" << endl;
            cout << "1. Yes\n";
            cout << "2. No\n";
            cout << ">> ";
            cin >> choice_3;

            if (choice_3 == 1)
            {
                cout << "Starting Again\n";
                cout << "-------------------------------------------\n";
                break;
            }
            else if (choice_3 == 2)
            {
                cout << "Ending Program\n";
                cout << "-------------------------------------------\n";
                flag = false;
                break;
            }
            else
            {
                cout << "Invalid Choice, Try Again\n";
                cout << "-------------------------------------------\n";
                continue;
            }
        }
    } while (flag == true);
    return 0;
}