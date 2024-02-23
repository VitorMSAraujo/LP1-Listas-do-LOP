#include <iostream>
#include <string>

using namespace std;

class Funcionario {

  protected:
    int m_registration;
    string m_name;
    float m_salary;

  public:

    Funcionario() {

    }

    void setRegistration(int registration) {
      m_registration = registration;
    }

    void setName(string name) {
      m_name = name;
    }

    void setSalary(float salary) {
      m_salary = salary;
    }

    int getRegistration() {
      return m_registration;
    }

    string getName() {
      return m_name;
    }

    float getSalary() {
      return m_salary;
    }
};

class Consultor : public Funcionario {

  public:

    float getSalary() {
      return m_salary + (m_salary * 0.1);
    }

    float getSalary(float percentual) {
      return m_salary + (m_salary * ( 0.1 * percentual));
    }
};



int main() {

  Funcionario worker;
  Consultor consulter;
  int input1;
  string input2;
  float input3;

  cin >> input1;
  cin.ignore();
  getline(cin, input2);
  cin >> input3;

  worker.setRegistration(input1);
  worker.setName(input2);
  worker.setSalary(input3);

  cin >> input1;
  cin.ignore();
  getline(cin, input2);
  cin >> input3;

  consulter.setRegistration(input1);
  consulter.setName(input2);
  consulter.setSalary(input3);

  cout << worker.getRegistration() << " - " << worker.getName() << " - R$ " << worker.getSalary() << endl;
  cout << consulter.getRegistration() << " - " << consulter.getName() << " - R$ " << consulter.getSalary();



  return 0;
}
