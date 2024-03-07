#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    char* nome_num(int n) {
    char* nomes[] = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove", "dez",
"onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
    return nomes[n];
}
    char* nome_dez(int n) {
    char* nomes[] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta",
"noventa"};
    return nomes[n/10 - 2];
}
    char* nome_cen(int n) {
    char* nomes[] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos",
"setecentos", "oitocentos", "novecentos"};
    return nomes[n/100 - 1];
}
void escrever_extenso(int n) {
    if (n == 0) {
    printf("%s\n", nome_num(n));
    return;
 }
    if (n == 100) {
    printf("cem\n");
    return;
 }
    int c = n / 100;
    int d = (n % 100) / 10;
    int u = n % 10;
    if (c > 0) {
    printf("%s ", nome_cen(c * 100));
    if (d > 0 || u > 0) {
    printf("e ");
 }
 }
    if (d > 0) {
    if (d == 1) {
    printf("%s\n", nome_num(d * 10 + u));
    return;

 } else {
    printf("%s ", nome_dez(d * 10));
    if (u > 0) {
    printf("e ");
 }
 }
 }
    if (u > 0) {
    printf("%s\n", nome_num(u));
 }
}
    void escrever_extenso_6(int n) {
    if (n == 0) {
    printf("%s\n", nome_num(n));
    return;
 }
    int m = n / 1000;
    int c = n % 1000;
    if (m > 0) {
    escrever_extenso(m);
    if (m == 1) {
    printf("mil ");

 } else {
    printf("mil e ");
 }
 }
    if (c > 0) {
    escrever_extenso(c);
 }
}
    int main() {
    int n;
    printf("Digite um número de até seis dígitos: ");
    scanf("%d", &n);
    if (n < 0 || n > 999999) {
    printf("Número inválido.\n");
    return -1;
 }
    escrever_extenso_6(n);
    return 0;
}