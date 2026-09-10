#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

int main(){

    std::string secret_text;
    std::cout << "Enter the secret message: ";
    std::getline(std::cin, secret_text);

    DATA_BLOB box;

    box.pbData = (BYTE*)secret_text.c_str();
    box.cbData = secret_text.length() + 1;

    DATA_BLOB encrypted_box;

    BOOL encryption = CryptProtectData(
        &box,
        NULL,
        NULL, NULL, NULL, 0,
        &encrypted_box
    );

    std::ofstream file_write("data.txt", std::ios::binary);

    if(file_write.is_open()){
        file_write << encrypted_box.pbData;
        std::cout << "writing successful\n";
        file_write.close();
    }
    else{
        std::cout << "Operation failed\n";
    }


    DATA_BLOB decrypted_box;

    std::ifstream file_read("data.txt", std::ios::binary);
    
    std::string final_decrypted_text = ""; 

    if(file_read.is_open()){
        std::string line;

        while(std::getline(file_read, line)){

            decrypted_box.pbData = (BYTE*)line.c_str();
            decrypted_box.cbData = line.length() + 1;

            BOOL decryption = CryptUnprotectData(
                &encrypted_box,
                NULL,
                NULL, NULL, NULL, 0,
                &decrypted_box
            );

            if(decryption){
                std::cout << "Decrypted successfully\n";
                final_decrypted_text = (char*)decrypted_box.pbData;
            }

        }
        file_read.close();
    }

    std::ofstream decrypted_file_write("data.txt", std::ios::binary | std::ios::app);

    if(decrypted_file_write.is_open()){
        decrypted_file_write << "\n" << final_decrypted_text;
        std::cout << "Text written!\n";
        decrypted_file_write.close();
    }


    std::cout << "\nThe program will close in 3 seconds..." << std::endl;
    Sleep(3000); 

    return 0;
}
