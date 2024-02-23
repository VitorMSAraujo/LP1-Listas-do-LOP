#include <iostream>
#include <string>

using namespace std;

class Imovel {

  protected:
    int m_type;
    float m_value;
    string m_disponibility;

  public:

    Imovel(int type) {
      m_type = type;
    }

    Imovel() {

    }

    void setValor(float value) {
      m_value = value;
    }

    void setDisponibility(string disponibility) {
      m_disponibility = disponibility;
    }

    float getValor() {
      return m_value;
    }

    string getDisponibility() {
      return m_disponibility;
    }

    string getNome() {
      switch(m_type) {
        case 0:
          break;
        case 1:
          return "Casa";
          break;
        case 2:
          return "Apartamento";
          break;
        case 3:
          return "Terreno";
          break;
      }
    }

    void lerAtributos() {

    }

    void exibirAtributos () {

    }
};

class Casa : public Imovel {

  private:
    int m_pav_amount, m_rooms_amount;
    float m_land_area, m_building_area;


  public:


    Casa() : Imovel(1) {

    }

    void setNumPav(int pav_amount) {
      m_pav_amount = pav_amount;
    }

    void setNumQuartos(int rooms_amount) {
      m_rooms_amount = rooms_amount;
    }

    void setTerrenoArea(float land_area) {
      m_land_area = land_area;
    }

    void setAreaConstruida(float building_area) {
      m_building_area = building_area;
    }

    int getNumPav() {
      return m_pav_amount;
    }

    int getNumQuartos() {
      return m_rooms_amount;
    }

    float getTerrenoArea() {
      return m_land_area;
    }

    float getAreaConstruida() {
      return m_building_area;
    }

    void lerAtributos(float value, string disponibility, int pav_amount, int rooms_amount, float land_area, float building_area) {

      setValor(value);
      setDisponibility(disponibility);
      setNumPav(pav_amount);
      setNumQuartos(rooms_amount);
      setTerrenoArea(land_area);
      setAreaConstruida(building_area);
    }

    void exibirAtributos() {

      cout << getNome() << " para " << getDisponibility() << ", R$ " << getValor() << ". " << getNumPav() << " pavimentos, " << getNumQuartos() << " quartos, " << getTerrenoArea() << "m2 de área de terreno e " << getAreaConstruida() << "m2 de área construída." << endl;
    }
};

class Apartamento : public Imovel {

  private:
    int m_rooms_amount, m_floor, m_garage_amount;
    float m_area, m_condo_value;

  public:

    Apartamento() : Imovel(2) {

    }

    void setPisos(int floor) {
      m_floor = floor;
    }

    void setNumQuartos(int rooms_amount) {
      m_rooms_amount = rooms_amount;
    }

    void setNumGaragens(int garage_amount) {
      m_garage_amount = garage_amount;
    }

    void setArea(float area) {
      m_area = area;
    }

    void setValorCondominio(float condo_value) {
      m_condo_value = condo_value;
    }

    int getPisos() {
      return m_floor;
    }

    int getNumQuartos() {
      return m_rooms_amount;
    }

    int getNumGaragens() {
      return m_garage_amount;
    }

    float getArea() {
      return m_area;
    }

    float getValorCondominio() {
      return m_condo_value;
    }

    void lerAtributos(float value, string disponibility, int floor, int rooms_amount, int garage_amount, float area, float condo_value) {

      setValor(value);
      setDisponibility(disponibility);
      setPisos(floor);
      setNumQuartos(rooms_amount);
      setNumGaragens(garage_amount);
      setArea(area);
      setValorCondominio(condo_value);

    }

    void exibirAtributos() {
      cout << getNome() << " para " << getDisponibility() << ", R$ " << getValor() << ". " << getArea() << "m2 de área, " << getNumQuartos() << " quartos, " << getPisos() << " andar(es), " << getValorCondominio() << " de condomínio, " << getNumGaragens() << " vaga(s) de garagem." << endl;
    }
};

class Terreno : public Imovel {

  private:
    float m_area;

  public:


    Terreno() : Imovel(3) {

    }

    float getArea() {
      return m_area;
    } 

    void setArea(float area) {
      m_area = area;
    } 

    void lerAtributos(float value, string disponibility, float area) {

      setValor(value);
      setDisponibility(disponibility);
      setArea(area);

    }

    void exibirAtributos() {

      cout << getNome() << " para " << getDisponibility() << ", R$ " << getValor() << ". " << getArea() << "m2 de área de terreno." << endl;
    }
};


int main() {

  int num_immobile;
  cin >> num_immobile;
  int input1, input2, input3;
  float input4, input5, input6;
  string input7;

  for(int i = 0; i < num_immobile; i++) {
    int type_immobile;
    cin >> type_immobile;

    if(type_immobile == 1) {
      Casa immobile;

      cin >> input4;
      cin.ignore();
      getline(cin, input7);
      cin >> input1;
      cin >> input2;
      cin >> input5;
      cin >> input6;

      immobile.lerAtributos(input4, input7, input1, input2, input5, input6);
      immobile.exibirAtributos();

    }

    else if(type_immobile == 2) {
      Apartamento immobile;

      cin >> input4;
      cin.ignore();
      getline(cin, input7);
      cin >> input5;
      cin >> input1;
      cin >> input2;
      cin >> input6;
      cin >> input3;

      immobile.lerAtributos(input4, input7, input2, input1, input3, input5, input6);
      immobile.exibirAtributos();
    }

    else if(type_immobile == 3) {
      Terreno immobile;

      cin >> input4;
      cin.ignore();
      getline(cin, input7);
      cin >> input5;

      immobile.lerAtributos(input4, input7, input5);
      immobile.exibirAtributos();

    }
  }





  return 0;
}
