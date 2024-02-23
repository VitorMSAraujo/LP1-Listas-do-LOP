#include <iostream>
#include <string>

using namespace std;

class Pedido {

  private:
    int m_numb, m_amount;
    float m_price;
    string m_description;

  public:

    Pedido() {

    }

    Pedido(int numb, int amount, float price, string description) {
      m_numb = numb;
      m_amount = amount;
      m_price = price;
      m_description = description;
    }

    void setAmount(int amount) {
      m_amount = amount;
    }

    void setNumb(int numb) {
      m_numb = numb;
    }

    void setPrice(float price) {
      m_price = price;
    }

    void setDescription(string description) {
      m_description = description;
    }

    int getNumb() {
      return m_numb;
    }

    int getAmount() {
      return m_amount;
    }

    float getPrice() {
      return m_price;
    }

    string getDescription() {
      return m_description;
    }

    float getTotal() {
      return m_price * m_amount;
    }
};

class MesadeRestaurante{

  private:
    Pedido m_orders[50];

  public:

    int order_position = 0;

    Pedido getPedidoMesa() {
      return m_orders[0];
    }


    void adicionarPedido(Pedido order) {

      bool equal = false;
      int equal_position;

      for (int i = 0; i < 50; i++) {
          if (m_orders[i].getDescription() == order.getDescription()) {
              equal = true;
              equal_position = i;
              break; 
          }
      }

      if (!equal) {
          m_orders[order_position] = order;
          order_position++;
      } 

      else {
          m_orders[equal_position].setAmount(m_orders[equal_position].getAmount() + order.getAmount());
      }
    }

    void zerarPedidos() {
      for(int i = 0; i < 50; i++) {
        m_orders[i].setAmount(0);
      }
    }

    float calculaTotal() {
      float total = 0;
      for(int i = 0; i < 50; i++) {
        total = total + m_orders[i].getTotal();
      }
      return total;
    }

    void exibeConta() {

      for(int i = 0; i < 50; i++) {
        if(m_orders[i].getNumb() == 0) {
          break;
        }
        cout << m_orders[i].getNumb() << " - " << m_orders[i].getDescription() << " - " << m_orders[i].getAmount() << " - " << m_orders[i].getPrice() << " - R$ " << m_orders[i].getTotal() << endl;
      }

      cout << "Total: R$ " << calculaTotal() << endl << endl;
    }
};

class Restaurante {

  private:
    MesadeRestaurante m_tables[50];

  public:


    void adicionarPedido(Pedido order, int table) {
      m_tables[table].adicionarPedido(order);
    }

    float calculaTotalRestaurante() {
      float total = 0;

      for(int i = 0; i < 50; i++) {

        if(m_tables[i].getPedidoMesa().getNumb() != 0)
          total = total + m_tables[i].calculaTotal();
      }
      return total;
    }

    MesadeRestaurante getTable(int table) {
      return m_tables[table];
    }
};


int main() {

  int count = 0;
  int input1, input2, input3;
  float input4;
  string input5;
  Pedido pedido;

  Restaurante restaurant;

  while(true) {
    cin >> input1;
    if(input1 == -1) {
      break;
    }
    cin.ignore();
    getline(cin, input5);
    cin >> input2;
    cin >> input4;
    cin >> input3;
    count = input3;

    pedido.setNumb(input1);
    pedido.setDescription(input5);
    pedido.setAmount(input2);
    pedido.setPrice(input4);

    restaurant.adicionarPedido(pedido, input3-1);
  }

  for(int i = 0; i < count; i++) {

    if(restaurant.getTable(i).calculaTotal() != 0){
      cout << "Mesa " << i+1 << endl;

      restaurant.getTable(i).exibeConta();
    }
  }

  cout << "Total Restaurante: R$ " << restaurant.calculaTotalRestaurante();



  return 0;
}
