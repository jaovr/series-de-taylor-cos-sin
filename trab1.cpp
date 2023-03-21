#include <iostream>
#include <cmath>
using namespace std;

//função para calcular as operações de fatorial dentro da série de taylor para seno e cosseno.

long double fatorial(int n) {
    long double multiplicaçãodetermos = 1;

    for(int i = 1; i <= n; i++) {
        multiplicaçãodetermos *= i;
    }
    return multiplicaçãodetermos;
}


int main(){

// declaração de váriaveis e seus respectivos tipos.

double graus = 0, valorabsoluto3termoscosseno = 0, valorabsoluto3termosseno = 0, valorabsoluto40termoscosseno = 0, valorabsoluto40termosseno = 0;
long double radianos = 0, soma3termosparacosseno = 0, soma3termosparaseno = 0, soma40termosparacosseno = 0, soma40termosparaseno = 0;

// Recebe o valor do angulo em graus pelo usuário.

cout << "Insira o valor do angulo em graus: " << endl;
cin >> graus;

cout << endl;

// Converte o valor do angulo em graus para radianos.

radianos = (graus * 3.14159265358979323846) / 180.0;

// Loop para somar o valor da substituição de cada termo dentro da série de taylor até atingir o limite de i = 2 (para 3 termos).
// Função padrão da biblioteca <cmath> => pow(): Realiza a operação de potenciação entre uma base e um expoente.
// Função fatorial(): Calcula o fatorial da expressão dentro dos parenteses.

for (int i = 0; i < 3; i++){

soma3termosparacosseno += (pow(-1, i) * pow(radianos, 2 * i)) / fatorial(2 * i);

}

for (int i = 0; i < 3; i++){

soma3termosparaseno += (pow(-1, i) * pow(radianos, 2 * i + 1)) / fatorial(2 * i + 1);

}

// Imprime os resultados do seno e cosseno para a somatória de 3 termos na série de taylor.

cout << "=================================================================================" << endl << endl;
cout <<"O cosseno de " << graus << " graus para 3 termos eh: " << soma3termosparacosseno << endl;
cout <<"O seno de " << graus << " graus para 3 termos eh: " << soma3termosparaseno << endl << endl;

//Utilizando 40 termos para calcular o seno e o cosseno do angulo.

for (int i = 0; i < 40; i++){

soma40termosparacosseno += (pow(-1, i) * pow(radianos, 2 * i)) / fatorial(2 * i);

}

for (int i = 0; i < 40; i++){

soma40termosparaseno += (pow(-1, i) * pow(radianos, 2 * i + 1)) / fatorial(2 * i + 1);

}

valorabsoluto3termoscosseno = abs(soma3termosparacosseno - cos(radianos));
valorabsoluto3termosseno =  abs(soma3termosparaseno - sin(radianos));
valorabsoluto40termoscosseno =  abs(soma40termosparacosseno - cos(radianos));
valorabsoluto40termoscosseno = abs(soma40termosparaseno - sin(radianos));

cout << "=================================================================================" << endl;
cout << "=================================================================================" << endl << endl;
cout << "O cosseno de " << graus << " graus para 40 termos eh: " << soma40termosparacosseno << endl;
cout << "O seno de " << graus << " graus para 40 termos eh: " << soma40termosparaseno << endl << endl;

cout << "=================================================================================" << endl;
cout << "=================================================================================" << endl << endl;
cout << "Imprimindo o valor para o angulo inserido nas funcoes padroes da biblioteca <cmath>" << endl << endl;
cout << "Valor para o cosseno na funcao padrao: " << cos(radianos) << endl;
cout << "Valor para o seno na funcao padrao: " << sin(radianos) << endl << endl;

cout << "=================================================================================" << endl;
cout << "=================================================================================" << endl << endl;
cout << "Calculando os valores dos erros em numeros absolutos entre seno e cosseno para 3 termos e as funcoes padroes" << endl << endl;
cout << "Valor Absoluto entre o cosseno de 3 termos para a funcao padrao eh: " << valorabsoluto3termoscosseno << endl;
cout << "Valor Absoluto entre o seno de 3 termos para a funcao padrao eh: " << valorabsoluto3termosseno << endl << endl;
cout << "Calculando os valores dos erros em numeros absolutos entre seno e cosseno para 40 termos e as funcoes padroes" << endl << endl;
cout << "Valor Absoluto entre o cosseno de 40 termos para a funcao padrao eh: " << valorabsoluto40termoscosseno << endl;
cout << "Valor Absoluto entre o seno de 40 termos para a funcao padrao eh: " << valorabsoluto3termosseno << endl << endl;

cout << "=================================================================================" << endl;
cout << "=================================================================================" << endl << endl;
cout << "Calculando o valor do erro em porcentagem para 3 termos" << endl << endl;
cout << "A porcentagem de erro para o cosseno para 3 termos eh: " << valorabsoluto3termoscosseno * 100 / cos(radianos) << "%" << endl;
cout << "A porcentagem de erro para o seno para 3 termos eh: " << valorabsoluto3termosseno * 100 / sin(radianos) << "%" << endl << endl;
cout << "Calculando o valor do erro em porcentagem para 40 termos" << endl << endl;
cout << "A porcentagem de erro para o cosseno para 40 termos eh: " << valorabsoluto40termoscosseno * 100 / cos(radianos) << "%" << endl;
cout << "A porcentagem de erro para o seno para 40 termos eh: " << valorabsoluto40termosseno * 100 / sin(radianos) << "%" << endl << endl << endl;

return 0;

}