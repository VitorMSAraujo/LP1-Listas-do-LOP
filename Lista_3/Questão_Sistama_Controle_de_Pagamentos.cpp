#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Pagamento {

  private:

    float m_payment_amount;
    string m_costumer_name;

  public: 

    Pagamento() {
      m_payment_amount = 0;
    }

    float getPaymentAmount() {
      return m_payment_amount;
    }

    void setPaymentAmount(float payment_amount) {
      m_payment_amount = payment_amount;
    }

    string getCostumerName() {
      return m_costumer_name;
    } 

    void setCostumerName(string costumer_name) {
      m_costumer_name = costumer_name;
    }

};

class ControledePagamentos {
  private:
    Pagamento* pagamentos = new Pagamento[100];

  public:

    ~ControledePagamentos() {
        delete[] pagamentos;
    }

    void setPagamento(Pagamento p, int index) {
      pagamentos[index] = p;
    }

    Pagamento getPagamento(int pos) {
      return pagamentos[pos];
    }

    float calculaTotalDePagamentos() {
      float total_payment = 0;
      for(int i = 0; i < 100; i++) {
        total_payment = total_payment + pagamentos[i].getPaymentAmount();
      }
      return total_payment;
    }

    int getIndexFuncionario (string nome_funcionario) {
      string search = nome_funcionario;
      int find = -1;

      for(int i = 0; i < 100; i++) {
        size_t found = pagamentos[i].getCostumerName().find(search);

        if(found != string::npos) {
          find = i;
        }
      }

      return find;
    }


};


int main() {
  int pay_amount;

  cin >> pay_amount;

  Pagamento payment;
  ControledePagamentos payments;

  string input1;
  float input2;

  for(int i = 0; i < pay_amount; i++) {
    cin >> input2;
    cin.ignore();
    getline(cin, input1);
      payment.setCostumerName(input1);
      payment.setPaymentAmount(input2);
      payments.setPagamento(payment, i);
  }

  string busca;
  int achar;

  cin >> busca;

  achar = payments.getIndexFuncionario(busca);

  if(achar != -1) {
    cout << payments.getPagamento(achar).getCostumerName() << ": R$ " << payments.getPagamento(achar).getPaymentAmount() << endl << "Total: R$ " << payments.calculaTotalDePagamentos();
  }

  else {
    cout << busca << " não encontrado(a)." << endl << "Total: R$ " << payments.calculaTotalDePagamentos() << endl;
  }



  return 0;
}
