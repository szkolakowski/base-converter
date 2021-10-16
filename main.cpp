#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

std::string n;
int r, s;
char numbers[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// odwrocenie ciagu znakow
std::string reverseString(std::string n){
    reverse(n.begin(), n.end());
    return n;
}

// przeliczenie liczby z dowolnego systemu na dziesiętny
int countDecimal(std::string n, int r){
    int decimal = 0;
    for (int a=0; a < n.length(); a++){
        for (int b=0; b < 36; b++){
            if (n[a] == numbers[b]){
                decimal += b * pow(r, a);
            }
        }
    }
    //std::cout << "(output) converted to decimal: " << decimal << std::endl;
    return decimal;
}

// znalezc pierwsza potege s ktora bedzie wieksza od decimala
int findFirstHigher(int decimal, int s){
    int slider = 0;
    while (1>0){
        if (pow(s, slider) > decimal){
            //std::cout << "(output) first higher power: " << s << "^" << slider << "=" << pow(s, slider) << std::endl;
            break;
        }
        slider++;
    }
    return slider;
}

// konwersja z dziesietnego do bazy s
std::string convertToNewBase(int slider, int decimal, int s){
    std::string converted = "";
    for (int c=slider-1; c>=0; c--){
        for (int d=s-1; d>=0; d--){
            if(d*pow(s, c) <= decimal){
                converted += numbers[d];
                decimal -= d*pow(s, c);
                break;
            }
        }
    }
    return converted;
}

int main()
{
    while (true){
        // pobranie zestawu danych
        std::cout << "(input) number to convert [number, start-system, end-system]: ";
        std::cin >> n;
        if (n == "exit"){
            break;
        }
        std::cin >> r >> s;

        n = reverseString(n);
        int decimal = countDecimal(n, r);
        int slider = findFirstHigher(decimal, s);
        std::string converted = convertToNewBase(slider, decimal, s);

        std::cout << "(output) converted: " << converted << std::endl << std::endl;
    }
    return 0;
}
