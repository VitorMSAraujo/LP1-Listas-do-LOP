#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Endereco {

  private:
    string m_rua, m_numero, m_bairro, m_cidade, m_estado, m_cep;

  public:
    Endereco() {

    }

    Endereco(string rua, string numero, string bairro, string cidade, string estado, string cep) {
      m_rua = rua;
      m_numero = numero;
      m_bairro = bairro;
      m_cidade = cidade;
      m_estado = estado;
      m_cep = cep;
    }

    void setRua(string rua) {
      m_rua = rua;
    }

    void setNumero(string numero) {
      m_numero = numero;
    }

    void setBairro(string bairro) {
      m_bairro = bairro;
    }

    void setCidade(string cidade) {
      m_cidade = cidade;
    }

    void setEstado(string estado) {
      m_estado = estado;
    }

    void setCEP(string cep) {
      m_cep = cep;
    }

    string toString() {
      string frase = m_rua;
      frase += ", ";
      frase += m_numero;
      frase += ", ";
      frase += m_bairro;
      frase += ". ";
      frase += m_cidade;
      frase += " - ";
      frase += m_estado;
      frase += ". CEP: ";
      frase += m_cep;

      return frase;
    }
};

class Pessoa {

  private:

    string m_name, m_phone;
    Endereco m_adress;


  public:

    Pessoa() {
      
    }

    Pessoa (string name, string phone, Endereco adress) {
      m_name = name;
      m_phone = phone;
      m_adress = adress;
    }

    Pessoa (string name) {
      m_name = name;
    }

    void setName(string name) {
      m_name = name;
    }
    void setPhone(string phone) {
      m_phone = phone;
    }
    void setAdress(Endereco adress) {
      m_adress = adress;
    }

    string getName() {
      return m_name;
    }

    string getPhone() {
      return m_phone;
    }

    Endereco getAdress() {
      return m_adress;
    }

    string toString() {
      string frase = m_name;
      frase += ", ";
      frase += m_phone;
      frase += "\n";
      frase += m_adress.toString();
      frase += "\n";
      return frase;
    }
};


int main() {

  int qtd_people;
  string input;

  cin >> qtd_people;

  Pessoa people_amount[qtd_people];
  Endereco adress_amount[qtd_people];

  cin.ignore();

  for(int i = 0; i < qtd_people; i++) {
    getline(cin, input);
    people_amount[i].setName(input);
    getline(cin, input);
    people_amount[i].setPhone(input);
    getline(cin, input);
    adress_amount[i].setRua(input);
    getline(cin, input);
    adress_amount[i].setNumero(input);
    getline(cin, input);
    adress_amount[i].setBairro(input);
    getline(cin, input);
    adress_amount[i].setCidade(input);
    getline(cin, input);
    adress_amount[i].setEstado(input);
    getline(cin, input);
    adress_amount[i].setCEP(input);
    people_amount[i].setAdress(adress_amount[i]);
  }

  string exibir;
  
  for(int i = 0; i < qtd_people; i++) {
    exibir = people_amount[i].toString();
    cout << exibir << endl;
  }
    
  return 0;
}
