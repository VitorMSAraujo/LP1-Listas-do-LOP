#include <iostream>
#include <string>

using namespace std;


class FiguraGeometrica {

  protected:
    int m_type;

  public: 


    FiguraGeometrica(int type) {
      m_type = type;
    }

    virtual ~FiguraGeometrica() {

    };

    virtual float calcularArea() = 0;

    virtual void lerAtributos() = 0;

    string getName() {

        if(m_type == 1) {
          return "Quadrado";
        }

        else if(m_type == 2) {
          return "Retângulo";
        }

        else if(m_type == 3) {
          return "Triângulo";
        }

        else if(m_type == 4) {
          return "Círculo";
        }

        else {
          return "";
        }
    }

};

class Square : public FiguraGeometrica {

  private:
    float side;

  public:

    Square() : FiguraGeometrica(1) {

    }

    ~Square() override {};

    float calcularArea() override {
      return side*side;
    }

    void lerAtributos() override {
      cin >> side;
    }

};

class Rectangle : public FiguraGeometrica {

  private:
    float base;
    float hight;

  public:

    Rectangle() : FiguraGeometrica(2) {

    }

    ~Rectangle() override {};

    float calcularArea() override {
      return base*hight;
    }

    void lerAtributos() override {
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

    ~Triangle() override {};

    float calcularArea() override {
      return (base*hight)/2;
    }

    void lerAtributos() override {
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

    ~Circle() override {};

    float calcularArea() override {
      return pi*(ray*ray);
    }

    void lerAtributos() override {
      cin >> ray;
    }

};


int main() {

  FiguraGeometrica* figure;
  int type = -1;

  while(type != 0) {
    cin >> type;

    switch(type) {
      case 1:
        figure = new Square();
        figure->lerAtributos();
        cout << figure->getName() << " polimórfico de área " << figure->calcularArea() << endl;
        delete figure;
        break;



      case 2:
        figure = new Rectangle();
        figure->lerAtributos();
        cout << figure->getName() << " polimórfico de área " << figure->calcularArea() << endl;
        delete figure;
        break;



      case 3:
        figure = new Triangle();
        figure->lerAtributos();
        cout << figure->getName() << " polimórfico de área " << figure->calcularArea() << endl;
        delete figure;
        break;



      case 4:
        figure = new Circle();
        figure->lerAtributos();
        cout << figure->getName() << " polimórfico de área " << figure->calcularArea() << endl;
        delete figure;
        break;


    }
  }








  return 0;
}
