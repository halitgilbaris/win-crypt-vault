# Windows DPAPI C++ Cryptor

A simple and lightweight C++ terminal application that securely encrypts and decrypts user messages locally using the Windows Data Protection API (DPAPI) and stores them in a binary file.

## 🚀 Features
- **Local Encryption:** Uses Windows `CryptProtectData` to secure text.
- **Secure Storage:** Saves encrypted data in a binary format (`data.txt`).
- **Self-Contained:** Designed to run with all dependencies static-linked.

## 🛠️ How to Compile (Derleme Komutu)

To build a standalone executable with all libraries included, open your terminal (CMD/PowerShell) and run:

```bash
g++ -static -static-libgcc -static-libstdc++ main.cpp -o program.exe -lcrypt32
```

## 📝 License
This project is licensed under the [MIT License](LICENSE).
