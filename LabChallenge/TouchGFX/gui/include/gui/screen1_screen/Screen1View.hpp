#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void PlaceX1();
    virtual void PlaceX2();
    virtual void PlaceX3();
    virtual void PlaceX4();
    virtual void PlaceX5();
    virtual void PlaceX6();
    virtual void PlaceX7();
    virtual void PlaceX8();
    virtual void PlaceX9();
    virtual void TicTacToeAddCircle(uint8_t P);
    virtual void TicTacToeAddX(uint8_t P);
    void handleTickEvent();
protected:
};

#endif // SCREEN1VIEW_HPP
