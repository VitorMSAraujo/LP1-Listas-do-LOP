#include <iostream>
#include <string>

using namespace std;

class FiguraGeometrica {

  protected:
    int m_tipo;

  public:

    FiguraGeometrica() {

    }

    FiguraGeometrica(int tipo) {
      m_tipo = tipo;
    }

    float calculaArea() {
    }

    void lerAtributosArea() {

    }

    string getName() {

      switch(m_tipo) {
        case 0:
          return "Indefinido";
          break;
        case 1:
          return "Quadrado";
          break;
        case 2:
          return "Retângulo";
          break;
        case 3:
          return "Triângulo";
          break;
        case 4:
          return "Círculo";
          break;
      }

    }
};


class Squad : public FiguraGeometrica {

  private:
    float side;

  public:

    Squad() : FiguraGeometrica(1) {

    }

    float calculaArea() {
      return side*side;
    }

    void lerAtributosArea() {
      cin >> side;
    }

};

class Retangle : public FiguraGeometrica {

  private:
    float base;
    float hight;

  public:

    Retangle() : FiguraGeometrica(2) {

    }

    float calculaArea() {
      return base*hight;
    }

    void lerAtributosArea() {
      cin >> base;
      cin >> hight;
    }

};

class Triangle : public FiguraGeometrica {

  private:
    float base;
    float hight;

  public:

    Triangle() : FiguraGeometrica(3) {

    }

    float calculaArea() {
      return (base*hight)/2;
    }

    void lerAtributosArea() {
      cin >> base;
      cin >> hight;
    }

};

class Circle : public FiguraGeometrica {

  private:
    float ray;
    float pi = 3.14;

  public:

    Circle() : FiguraGeometrica(4) {

    }

    float calculaArea() {
      return pi*(ray*ray);
    }

    void lerAtributosArea() {
      cin >> ray;
    }

};


int main() {

  FiguraGeometrica figure;
  Squad quadrado;
  Triangle triangulo;
  Retangle retangulo;
  Circle circulo;

  int type = -1;
  float input2;

  while(type != 0) {
    cin >> type;

    switch(type) {
      case 0:
        break;
      case 1:
        quadrado.lerAtributosArea();
        cout << quadrado.getName() << " de área " << quadrado.calculaArea() << endl;
        break;
      case 2:
        retangulo.lerAtributosArea();
        cout << retangulo.getName() << " de área " << retangulo.calculaArea() << endl;
        break;
      case 3:
        triangulo.lerAtributosArea();
        cout << triangulo.getName() << " de área " << triangulo.calculaArea() << endl;
        break;
      case 4:
        circulo.lerAtributosArea();
        cout << circulo.getName() << " de área " << circulo.calculaArea() << endl;
        break;
    }
  }









  return 0;
}
