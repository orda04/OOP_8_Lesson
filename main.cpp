
//**********  Eight task on  OOPcourse                                         ****
//**********  Filename >main.cpp                                               ****
//**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
//**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
//**********  Date 08.08.2021                                                  ****


// •••Done 1. Написать шаблонную функцию div, которая должна вычислять результат деления двух параметров и запускать исключение DivisionByZero,
// •••        если второй параметр равен 0. В функции main выводить результат вызова функции div в консоль, а также ловить исключения.
// •••Done 2. Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу, инициализирующий x значением параметра.
// •••        Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем)
// •••        и имеющий метод set с единственным вещественным параметром a. Если y + a > 100, возбуждается исключение типа Ex с данными a*y,
// •••        иначе в y заносится значение a. В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
// •••        Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
// •••        В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.
// •••Done 3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у которого есть метод,
// •••        означающий задание переместиться на соседнюю позицию. Эти методы должны запускать классы-исключения OffTheField,
// •••        если робот должен уйти с сетки, и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
// •••        Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
// •••        Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
// •••        а также выводящую подробную информацию о всех возникающих ошибках.

#include <iostream>
#include <string>
#define  X_FIELD 15
#define  Y_FIELD 15
using namespace std;


template < typename T,typename A >
T my_div ( T &numerator , A & denominator )
{
   if (denominator ==0.0)
   {
    throw"Sorry,but we cannot divide on 0";
   }
  return numerator/denominator;
}
class Ex
{
    public:
    double x;
    Ex(const double &m_x):x(m_x){}
    ~Ex(){}
};


class Bar
{
    private:
    double y;

    public:
    Bar()
    {
        y=0;
    }
    ~Bar()
    {}
    void set(const double &a)
    {
        if(y+a>100)
        {
          throw Ex(y*a);

        }
        else
        {
          y=a;
        }
    }

};

//-------------------------------------------------------
//-------------ROBOT T-1000------------------------------
class OffTheField
{
private:
    string m_error;
public:
    OffTheField(string error):m_error(error)
    {}
    const char* getError()
    {
        return m_error.c_str();
    }
};
class IllegalCommand
{
private:
    string m_error;
public:
    IllegalCommand(string error):m_error(error)
    {}
    const char* getError()
    {
        return m_error.c_str();
    }
};
class Robot
{
private :
    int field [X_FIELD][Y_FIELD]={0};
    int coord_X=0;
    int coord_Y=0;
public:
void set(int pos_a,int pos_b)   //задаем начальные координаты робота
{
    coord_X=pos_a;
    coord_Y=pos_b;
}
void printcoord()
{
    cout<<"\n";
    cout<<"coord_x: "<<coord_X<<" coord_Y: "<<coord_Y<<endl;
}
void move(int pos_x, int pos_y)
{
  if(!((pos_x==1&&pos_y==0)||(pos_x==0&&pos_y==1)||(pos_x==0&&pos_y==0)||(pos_x==-1&&pos_y==0)||(pos_x==0&&pos_y==-1)))
  {
      throw IllegalCommand("\nSorry you can move only on 1 step at one direction\nYour comand were to move on\nX:" + to_string(pos_x)+"\nY:"+to_string(pos_y) );
  }
  else
   {
      if(coord_X+pos_x>X_FIELD-1||coord_Y+pos_y>Y_FIELD-1)
      {
       throw OffTheField(" \nOut of field: Basics coordinates is \nX:"+
                         to_string(coord_X)+" You want to move on :"+to_string(coord_X+pos_x)+"\nY:"+
                         to_string(coord_Y)+" You want to move on :"+to_string(coord_Y+pos_y));
      }
      else
      {
      coord_X=coord_X+pos_x;
      coord_Y=coord_Y+pos_y;
      }
  }
}

void print_field()
{
   for(int i=0;i<X_FIELD;++i)
   {
   cout<<" _";
   }
   cout<<"\n";
   for(int i=0;i<X_FIELD;++i)
   {
       cout<<"|";
       for(int y=0;y<Y_FIELD;++y)
       {
        if(i==coord_X&&y==coord_Y)
           {
            cout<<"R"<<"|";

           }
        else
           {
            cout<<"_"<<"|";
           }

        }

       cout<<endl;
   }
cout<<"************************************"<<endl;
}
};

//-------------ROBOT T-1000------------------------------
//-------------------------------------------------------
int main()
{


    double num;
     int   den;
    cout<<"Dividing be careful... \nPlease Enter Numerator: ";
    cin>>num;
    cout<<"How about denominator? : ";
    cin>>den;
    try
    {
      cout<<my_div(num,den)<<endl;
    }
    catch (const char* exception)
    {
       cerr << "Error: " << exception << endl;
    }

//----------------------------------------------------------------------
//-------------second part

    Bar read;
    int x;
    cout<<"please enter digits,... \nthat will work until: \na+y <=100 or ..... you will not enter 0"<<endl;
    while(cin>>x && x!=0){

        try
        {
            read.set(x);
        }
        catch(Ex &err)
        {
            cerr<<"Exception: ay "<<err.x<<endl;
        }
    }

//-------------------------------------------------------------------------
//------------------third
Robot R;
int a;
int b;
char choice='Y';
bool run=true;
R.print_field();
R.set(8,8);
R.print_field();

   cout<<"Введите коориднаты для движения.\nДвижение разрешено только на одну клетку по вертикали или горизонтали"<<endl;
 while(run)
  {
   cout<<"X: ";
   cin>>a;
   cout<<"Y: ";
   cin>>b;

   try
    {
     R.move(a,b);
     }
   catch (IllegalCommand &exception)
    {
      cerr << "\n***ERROR: Robot moving illegal command detected***"<<exception.getError()<<"\n";
    }
   catch (OffTheField &exception)
     {
       cerr << "\n***ERROR: Robot moving out of field detected***"<<exception.getError()<<"\n";
     }

  R.printcoord();
  cout<<"\n Next move? (only Key 'N' or 'n' will stop moving Robot)";
  cin>>choice;
  if(choice =='N'||choice =='n')
  {
              run = false;  // or we can just put here break;
  }
 }
 R.print_field();

 cout<<"\n\n\n ***all tasks done ***\n\n\n";


    return 0;
}











