#include <iostream>
#include <cstring>

using namespace std;

int strongPassword(char* s){
    int countRepeating = 1, count = 0, minCount = 0;
    char last_char;
    bool hasUpper = false, hasLower = false, hasDigit = false, isRepeating = false;
    int lens = strlen(s);
    
    for(int i=0; i < lens; i ++){
        if(isdigit(s[i])) ///verificam daca avem cifra
            hasDigit = true;
        if(isupper(s[i])) /// verificam daca avem litera mare
            hasUpper = true;
        if(islower(s[i])) /// verificam daca avem litera mica
            hasLower = true;
        if(s[i] == last_char){ ///verificam daca caracterul curent = caracterul anterior
            countRepeating ++; 
            if(countRepeating > 2) /// daca avem 3 caractere care se repeta consecutiv, crestem nr de modificari
                isRepeating = true, count ++;
        }
        else
            countRepeating = 1;
        last_char = s[i];
    }
    
    if(hasDigit && hasUpper && hasLower && !isRepeating && lens >= 6 && lens <= 20)
        return 0;
        
    if(lens >= 6 && lens <=20){
        if(!hasLower)
            count ++;
        if(!hasUpper)
            count ++;
        if(!hasDigit)
            count ++;
    }
    else if(lens < 6)
        count += 6 - lens;
    else if(lens > 20)
        count += lens - 20;
    
    minCount = count; 
    return minCount;
    
}

int main()
{
    char* s = new char [sizeof(char)];
    cin >> s;
    cout << strongPassword(s);
    return 0;
}
