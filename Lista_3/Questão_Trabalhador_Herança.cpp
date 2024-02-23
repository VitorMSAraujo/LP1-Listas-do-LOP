#include <iostream>
#include <string>

using namespace std;

class Trabalhador {

  protected:
    string m_name;
    float m_salary;

  public:

    Trabalhador() {
      m_salary = 0;
    }

    void setName(string name) {
      m_name = name;
    }

    void setSalary(float salary) {
      m_salary = salary;
    }

    string getName() {
      return m_name;
    }

    float getSalary() {
      return m_salary;
    }

};

class TrabalhadorPorHora : public Trabalhador {

  private:
    float m_hourly_rate;

  public:

    TrabalhadorPorHora(float hourly_rate) : Trabalhador() {
      m_hourly_rate = hourly_rate;
    }

    float calcularPagamentoSemanal(int week_hours) {

      if( week_hours <= 40) {
        m_salary = (m_hourly_rate * week_hours) * 4;
        return m_hourly_rate * week_hours;
      }

      else if(week_hours > 40) {
        m_salary = ((m_hourly_rate * 40) + ((week_hours - 40) * (m_hourly_rate * 1.5))) * 4;
        return ((m_hourly_rate * 40) + ((week_hours - 40) * (m_hourly_rate * 1.5)));
      }
    }

    float getTPHSalary() {
      return m_salary;
    }
};

class TrabalhadorAssalariado : public Trabalhador {

  public:

  TrabalhadorAssalariado(float salary) : Trabalhador()  {
    m_salary = salary;
  }

  float calcularPagamentoSemanal() {
    return m_salary / 4;
  }

};


int main() {

  int worker_num;
  cin >> worker_num;
  int worker_type;
  int input1;
  float input2;
  string input3;

  for(int i = 0; i < worker_num; i++) {
    cin >> worker_type;
    if(worker_type == 1) {
      cin.ignore();
      getline(cin, input3);
      cin >> input2;
      
      TrabalhadorAssalariado worker = TrabalhadorAssalariado(input2);
      worker.setName(input3);
      
      cout << worker.getName() << " - Semanal: R$ " << worker.calcularPagamentoSemanal() << " - Mensal: R$ " << worker.getSalary() << endl;
      
    }
    else if(worker_type == 2) {
        cin.ignore();
        getline(cin, input3);
        cin >> input2;
        cin >> input1;
        
        TrabalhadorPorHora worker = TrabalhadorPorHora(input2);
        worker.setName(input3);
        float week_salary = worker.calcularPagamentoSemanal(input1);

        cout << worker.getName() << " - Semanal: R$ " << week_salary << " - Mensal: R$ " << worker.getTPHSalary() << endl;
        
        
    }
  }
  

  return 0;
}
