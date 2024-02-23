#include <iostream>

using namespace std;

class Pessoa {

    protected:
      string m_name, m_phone, m_cpf;

    public:

      Pessoa(string name, string phone, string cpf) {
        m_name = name;
        m_phone = phone;
        m_cpf = cpf;
      }
      void exibir() {
        cout << m_name << " - " << m_phone << " - CPF: " << m_cpf << endl; 
      }
};

class Aluno : public Pessoa {

    private:
      float m_cra;
      int m_semester;

    public:

      Aluno (float cra, int semester, string name, string phone, string cpf) : Pessoa (name, phone, cpf) {
        m_cra = cra;
        m_semester = semester;
        m_name = name;
        m_phone = phone;
        m_cpf = cpf;
      }

      void exibir() {
        Pessoa::exibir();
        cout << "CRA: " << m_cra << " - Semestre: " << m_semester << endl;
      }
};

class Professor : public Pessoa {

    private:
      int m_disciplines_amount;
      string m_department;


    public:

      Professor (int disciplines_amount, string department, string name, string phone, string cpf) : Pessoa (name, phone, cpf) {
        m_disciplines_amount = disciplines_amount;
        m_department = department;
        m_name = name;
        m_phone = phone;
        m_cpf = cpf;
      }

      void exibir() {
          Pessoa::exibir();
          cout << "Qtd: " << m_disciplines_amount << " - " << m_department << endl;
      }
};

int main() {
  int input1;
  float input2;
  string input3, input4, input5, input6;

  getline(cin, input3);
  getline(cin, input4);
  getline(cin, input5);

  Pessoa person = Pessoa(input3, input4, input5);

  getline(cin, input3);
  getline(cin, input4);
  getline(cin, input5);
  cin >> input2;
  cin >> input1;

  Aluno student = Aluno(input2, input1, input3, input4, input5);

  cin.ignore();
  getline(cin, input3);
  getline(cin, input4);
  getline(cin, input5);
  cin >> input1;
  cin.ignore();
  getline(cin, input6);

  Professor teacher = Professor(input1, input6, input3, input4, input5);

  person.exibir();
  student.exibir();
  teacher.exibir();


  return 0;
}
