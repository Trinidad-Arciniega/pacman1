#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    std::string yupii = "¡Yupii!";
   
    int frame = 0;
    const int max_frame = 25;
  
    while (true)
    {
        int x = frame ;
        int y = x/2;

        auto can = Canvas(200,200);
        //can.DrawPointCircle(10,10,10);
       //horizontal
        can.DrawBlockLine(10,30,90,30);
        can.DrawBlockLine(20,80,80,80);
       //vertical
        can.DrawBlockLine(20,80,20,30);
        can.DrawBlockLine(80,80,80,30);
       //techo
        can.DrawBlockLine(10,30,50,1);
        can.DrawBlockLine(90,30,50,1);
        //puerta
        can.DrawBlockLine(30,80,30,50);
        can.DrawBlockLine(50,80,50,50);
        can.DrawBlockLine(30,50,50,50);
        can.DrawBlockCircle(35,65,2);
        //sol
        can.DrawBlockCircle(110+frame,15-frame,10);
        //monocabeza
        can.DrawBlockCircle(115,50,5);
        //cuerpo
        can.DrawBlockLine(115,55,115,70);
        //manos
        can.DrawBlockLine(115,60,125,65-y);
        can.DrawBlockLine(115,60,107,65-y);
        //piernas
        can.DrawBlockLine(115,70,120,70);
        can.DrawBlockLine(120,70,125,75);
        can.DrawBlockLine(115,71,113,70);
        can.DrawBlockLine(113,70,107,75);

        can.DrawText(130,50-y,yupii);

        


        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::LightPink1, canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
        if (frame > max_frame) {
            frame = 0;
        }
    }

    return 0;
}
