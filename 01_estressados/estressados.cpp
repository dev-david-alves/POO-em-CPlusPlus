#include <bits/stdc++.h>

using namespace std;

// Funções de Busca

bool existe_valor_x(vector<int> stress) {
    int valor = 0;

    cout << "Digite o valor que deseja procurar na fila: ";
    cin >> valor;

    if(valor >= -99 && valor <= 99) {
        if(find(stress.begin(), stress.end(), valor) != stress.end()) {
            cout << "Existe esse valor na fila." << "\n";
        } else {
            cout << "Nao existe esse valor na fila." << "\n";
        }

        return true;
    } else {
        cout << "Digite um valor entre -99 e 99." << "\n";
    }

    return false;
}

bool contar_x(vector<int> stress) {
    int valor = 0;

    cout << "Digite o valor que deseja contar na fila: ";
    cin >> valor;

    if(valor >= -99 && valor <= 99) {
        int counter = count(stress.begin(), stress.end(), valor);
        cout << "O valor " << valor << " aparece " << counter << (counter > 1? " vezes" : " vez") << " na fila." << "\n";

        return true;
    } else {
        cout << "Digite um valor entre -99 e 99." << "\n";
    }

    return false;
}

bool procurar_valor_x(vector<int> stress, int pos) { // Também será usada para procurar_valor_x_apos
    int valor = 0;

    cout << "Digite o valor que deseja procurar a posicao na fila: ";
    cin >> valor;

    if(valor >= -99 && valor <= 99) {
        auto bg = stress.begin();
        advance (bg, pos);
        auto itr = find(bg, stress.end(), valor);

        if (itr != stress.end()) {
            cout << "Valor " << valor << " foi encontrado na posicao " << (itr - stress.begin() + 1) << " da fila." << "\n";
        } else {
            cout << "Valor nao foi encontrado na fila." << "\n";
        }

        return true;
    } else {
        cout << "Digite um valor entre -99 e 99." << "\n";
    }

    return false;
}

// Funções de Melhor Caso

bool procurar_menor_maior(vector<int> stress, char caso) { // caso m = menor, caso M = maior
    int maior = -99999;
    int menor = 99999;
    
    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        if(stress[i] > maior) maior = stress[i];
        if(stress[i] < menor) menor = stress[i];
    }

    if(caso == 'm') cout << "O menor valor encontrado na fila foi " << menor << "\n";
    else cout << "O maior valor encontrado na fila foi " << maior << "\n";

    return true;
}

bool procurar_menor_pos(vector<int> stress, int pos) { // Serve para o procurar_menor_pos_apos também
    int menor = 99999;
    int menor_index = 0;
    
    int sz = (int) stress.size();

    for(int i = pos; i < sz; i++) {
        if(stress[i] < menor) {
            menor = stress[i];
            menor_index = i;
        }
    }

    if(pos == 0) {
        cout << "A posicao do menor valor da fila e " << menor_index + 1 << "\n";
    } else {
        cout << "A posicao do menor valor da fila apos " << pos << " e " << menor_index + 1<< "\n";
    }

    return true;
}

bool procurar_melhor_se(vector<int> stress) {
    int menor = 99999;
    int menor_index = 0;
    
    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        if(stress[i] < menor && stress[i] > 0) {
            menor = stress[i];
            menor_index = i;
        }
    }

    cout << "A posicao do homem mais calmo e " << menor_index + 1 << "\n";

    return true;
}

// Funções de Contagem

bool calcular_stress_medio(vector<int> stress) {
    double stress_medio = 0;

    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        stress_medio += abs(stress[i]);
    }

    stress_medio /= (double) sz;

    cout << "A media de stress da fila e: " << stress_medio << "\n";

    return true;
}

bool mais_homens_ou_mulheres(vector<int> stress) {
    int homens = 0;
    int mulheres = 0;

    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        if(stress[i] > 0) {
            homens++;
        } else {
            mulheres++;
        }
    }

    if(homens > mulheres) {
        cout << "Ha mais homens do que mulheres na fila." << "\n";
    } else if(homens < mulheres) {
        cout << "Ha mais mulheres do que homens na fila." << "\n";
    } else {
        cout << "Quantidade de homens e mulheres na fila igual." << "\n";
    }

    return true;
}

bool qual_metade_e_mais_estressada(vector<int> stress) {
    int primeira = 0;
    int segunda = 0;

    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        if(i < sz / 2) {
            primeira += abs(stress[i]);
        } else {
            segunda += abs(stress[i]);
        }
    }

    if(primeira > segunda) {
        cout << "O nivel de stress da primeira parte e maior que o da segunda parte da fila." << "\n";
    } else if(primeira < segunda) {
        cout << "O nivel de stress da segunda parte e maior que o da primeira parte da fila." << "\n";
    } else {
        cout << "Nivel de stress da duas partes da fila e igual." << "\n";
    }

    return true;
}

bool homens_sao_mais_estressados_que_mulheres(vector<int> stress) {
    double stress_homens = 0;
    double stress_mulheres = 0;

    double homens_qntd = 0;
    double mulheres_qntd = 0;

    int sz = (int) stress.size();

    for(int i = 0; i < sz; i++) {
        if(stress[i] > 0) {
            stress_homens += abs(stress[i]);
            homens_qntd++;
        } else {
            stress_mulheres += abs(stress[i]);
            mulheres_qntd++;
        }
    }

    if(homens_qntd > 0) {
        stress_homens /= homens_qntd;
    } 
    
    if(mulheres_qntd > 0) {
        stress_mulheres /= mulheres_qntd;
    }

    if(stress_homens > stress_mulheres) {
        cout << "O nivel de stress dos homens e maior que o das mulheres na fila." << "\n";
    } else if(stress_homens < stress_mulheres) {
        cout << "O nivel de stress das mulheres e maior que o dos homens da fila." << "\n";
    } else {
        cout << "O nivel de stress dos homens e das mulheres e igual." << "\n";
    }

    return true;
}

// Selecionar função do item

bool selecionar_item(char item, vector<int> stress) {
    int pos = 0;

    switch (item) {
    case 'a':
        return existe_valor_x(stress);
        break;
    case 'b':
        return contar_x(stress);
        break;
    case 'c':
        return procurar_valor_x(stress, 0);
        break;
    case 'd':
        cout << "Digite a posicao que deseja comecar a busca: ";
        cin >> pos;

        if(pos < 0 || pos > (int) stress.size()) {
            cout << "Digite um valor valido." << "\n";
            return false;
        }

        return procurar_valor_x(stress, pos);
        break;
    case 'e':
        return procurar_menor_maior(stress, 'm');
        break;
    case 'f':
        return procurar_menor_maior(stress, 'M');
        break;
    case 'g':
        return procurar_menor_pos(stress, 0);
        break;
    case 'h':
        cout << "Digite a posicao que deseja comecar a busca: ";
        cin >> pos;

        if(pos < 0 || pos > (int) stress.size()) {
            cout << "Digite um valor valido." << "\n";
            return false;
        }

        return procurar_menor_pos(stress, pos);
        break;
    case 'i':
        return procurar_melhor_se(stress);
        break;
    case 'j':
        return calcular_stress_medio(stress);
        break;
    case 'k':
        return mais_homens_ou_mulheres(stress);
        break;
    case 'l':
        return qual_metade_e_mais_estressada(stress);
        break;
    case 'm':
        return homens_sao_mais_estressados_que_mulheres(stress);
        break;
    default:
        break;
    }

    return false;
}

int main() {

    char resposta;
    char item;

    vector<char> items{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
    vector<int> stress{-11, 99, 39, -99, 85, 57, -99, -33, -22, -34};

    cout << "Deseja coletar informacoes sobre a fila? Digite a letra 's' ou 'S' para continuar." << "\n";
    cin >> resposta;

    while(resposta == 's' || resposta == 'S') {
        cout << "Selecione um item entre as perguntas ------------->" << "\n";

        while(true) { 
            cout << "Busca ---------------->" << "\n";
            cout << "(a) Alguem com o valor X esta na fila?" << "\n";
            cout << "(b) Quantas vezes o valor X apareceu na fila?" << "\n";
            cout << "(c) Em que posicao da fila aparece X pela primeira vez?" << "\n";
            cout << "(d) Dada a posicao para iniciar a busca, qual a proxima posicao em que aparece X?" << "\n";

            cout << "Melhor caso ---------->" << "\n";
            cout << "(e) Qual o menor valor da lista?" << "\n";
            cout << "(f) Qual o maior valor da lista?" << "\n";
            cout << "(g) Qual a posicao do menor valor da lista?" << "\n";
            cout << "(h) Qual a posicao do menor valor da lista depois da posicao P?" << "\n";
            cout << "(i) Qual a posicao do HOMEM mais calmo? (menor valor maior que 0)" << "\n";

            cout << "Contagem ------------->" << "\n";
            cout << "(j) Qual a media de stress da fila? (abs)" << "\n";
            cout << "(k) Na fila existem mais homens ou mulheres?" << "\n";
            cout << "(l) O nivel de stress somado de todas as pessoas da primeira metade e maior que o nivel de stress somado das pessoas da segunda metade da fila? (abs)" << "\n";
            cout << "(m) A media do stress dos homens e maior que a das mulheres?" << "\n";

            cout << "Item: ";
            cin >> item;

            if(find(items.begin(), items.end(), item) != items.end()) {
                if(selecionar_item(item, stress)) break;
            } else {     
                cout << "Selecione um item existente na lista." << "\n";
            }
        }

        cout << "Deseja continuar coletando informacoes sobre a fila? Digite a letra 's' ou 'S' para continuar." << "\n";
        cin >> resposta;
    }

    cout << "Encerrando...";

    return 0;
}