HOW TO MODULARISE CODE
1. Identify user defined datatypes such as 'class's and 'struct's.
2. Create separate '*.h' (header/interface) and corresponding '*.cpp'
   (implementation) files.
3. Copy/Paste the user defined datatypes into their respective header/interface
   files.
4. Separate the method definitions of the class methods into their respective
   implementation files.
5. Follow the rules of the language to identify the methods with their respective
   class'.

BUG FIX!
- Open "car.h" and look for "!FIX". The explanation is given there together
  with the wrong way that was used before ("!WRONG").

COMPILATION COMMAND
g++ main.cpp driver.cpp car.cpp -o car.exe

HOW TO RUN UNDER TERMINAL
$ ./car.exe
