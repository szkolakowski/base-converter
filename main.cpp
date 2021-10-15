#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>

char numbers[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    //wczytanie liczby iteracji
    std::cout << "(input) number of conversions: ";
    int iterations;
    std::cin >> iterations;
    std::cout << std::endl;

    for(int i=0; i <= iterations; i++){
        // pobieranie zestawow danych i ich porzadkowanie
        std::cout << "(input) number to convert [number, start-system, end-system]: ";
        std::string n = "";
        int r = 0;
        int s = 0;
        std::cin >> n >> r >> s;
        // odwrocenie ciagu znakow
        reverse(n.begin(), n.end());

        // przeliczenie liczby z dowolnego systemu na dziesiętny
        int decimal = 0;
        for (int a=0; a < n.length(); a++){
            for (int b=0; b < 36; b++){
                if (n[a] == numbers[b]){
                    decimal += b * pow(r, a);
                }
            }
        }
        std::cout << "(output) converted to decimal: " << decimal << std::endl;

        // znalezc pierwsza potege s ktora bedzie wieksza od decimala
        int slider = 0;
        while (1>0){
            if (pow(s, slider) > decimal){
                std::cout << "(output) first higher power: " << s << "^" << slider << "=" << pow(s, slider) << std::endl;
                break;
            }
            slider++;
        }

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
        std::cout << "(output) converted: " << converted << std::endl << std::endl;
    }
}
