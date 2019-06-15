# C++ Windows KeyLogger by Fibek


# Build options

    g++ main.cpp KeyLogger.cpp CClip.cpp -Wall -Wextra -std=c++11 -D_WIN32_WINNT=0x0501 -w -o msvsysapp.exe

| Build option            | Meaning                                                |    
| :---------------------: | :-----------------------------------------------------: |
| '-Wall'                 | required to working multithreading with MinGW compiler |
| '-Wextra'               | required to working multithreading with MinGW compiler |
| '-D_WIN32_WINNT=0x0501' | required to working multithreading with MinGW compiler |
| '-w'                    | skipp all warnings                                     |
| '-o msvsysapp.exe'      | ouput = msvsysapp.exe                                  |
