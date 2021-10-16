# base-converter
Każdą liczbę całkowitą nieujemną n możemy przedstawić w systemie pozycyjnym jednorodnym o podstawie r jako ciąg cyfr 0 ≤ di < r, o wartości:
```
n = d 0  + r * d1  + r2 * d2  + r3 * d3  + ...
```
Zadaniem skryptu jest dokonać konwersji podanej liczby w systemie o podstawie r do liczby w systemie o podstawie s, na przykład: liczba 
dziesiętna 231 ma reprezentację binarną 11100111. Zakładać będziemy, że r ≤ 36 oraz cyfry są postaci 
```
0,1,2,3,4,5,6,7,8,9, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
```
### wejście
```
n r s [n ≤ 101000, r,s ≤ 36]
```
### wyjście
```
n [reprezentacja liczby n w systemie o podstawie s]
```
### exit
```
(input) number to convert [number, start-system, end-system]: exit
```
### przykład
```
(input) number to convert [number, start-system, end-system]: 123 10 16
(output) converted: 7B

(input) number to convert [number, start-system, end-system]: 4563 7 11
(output) converted: 1281
```
