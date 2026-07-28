#include <gui/screen1_screen/Screen1View.hpp>
uint8_t PositionPressed = 0;
uint8_t HumanMove = 0;
uint8_t STM32Move = 0;

Screen1View::Screen1View()
{

}
void Screen1View::handleTickEvent()
{
	if(HumanMove)
	{
		TicTacToeAddCircle(PositionPressed);
		HumanMove = 0;
		PositionPressed = 0;
	}
	if(STM32Move)
	{
		TicTacToeAddX(PositionPressed);
		STM32Move = 0;
		PositionPressed = 0;
	}
}
void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::TicTacToeAddCircle(uint8_t P)
{
	switch (P)
	{
	case 1:
	    circle11.setVisible(true);
	    circle11.invalidate();
		break;
	case 2:
		circle12.setVisible(true);
		circle12.invalidate();
		break;
	case 3:
		circle13.setVisible(true);
		circle13.invalidate();
		break;
	case 4:
		circle21.setVisible(true);
		circle21.invalidate();
		break;
	case 5:
		circle22.setVisible(true);
		circle22.invalidate();
		break;
	case 6:
		circle23.setVisible(true);
		circle23.invalidate();
		break;
	case 7:
		circle31.setVisible(true);
		circle31.invalidate();
		break;
	case 8:
		circle32.setVisible(true);
		circle32.invalidate();
		break;
	case 9:
		circle33.setVisible(true);
		circle33.invalidate();
		break;
	default:
		break;
	}
}

void Screen1View::TicTacToeAddX(uint8_t P)
{
    switch (P)
    {
    case 0:
        cell11_A.setVisible(true);
        cell11_A.invalidate();
        cell11_B.setVisible(true);
        cell11_B.invalidate();
        break;

    case 1:
        cell12_A.setVisible(true);
        cell12_A.invalidate();
        cell12_B.setVisible(true);
        cell12_B.invalidate();
        break;

    case 2:
        cell13_A.setVisible(true);
        cell13_A.invalidate();
        cell13_B.setVisible(true);
        cell13_B.invalidate();
        break;

    case 3:
        cell21_A.setVisible(true);
        cell21_A.invalidate();
        cell21_B.setVisible(true);
        cell21_B.invalidate();
        break;

    case 4:
        cell22_A.setVisible(true);
        cell22_A.invalidate();
        cell22_B.setVisible(true);
        cell22_B.invalidate();
        break;

    case 5:
        cell23_A.setVisible(true);
        cell23_A.invalidate();
        cell23_B.setVisible(true);
        cell23_B.invalidate();
        break;

    case 6:
        cell31_A.setVisible(true);
        cell31_A.invalidate();
        cell31_B.setVisible(true);
        cell31_B.invalidate();
        break;

    case 7:
        cell32_A.setVisible(true);
        cell32_A.invalidate();
        cell32_B.setVisible(true);
        cell32_B.invalidate();
        break;

    case 8:
        cell33_A.setVisible(true);
        cell33_A.invalidate();
        cell33_B.setVisible(true);
        cell33_B.invalidate();
        break;

    default:
        break;
    }
}
void Screen1View::PlaceX1()
{
	PositionPressed  = 1;
}

void Screen1View::PlaceX2()
{
	PositionPressed  = 2;
}

void Screen1View::PlaceX3()
{
	PositionPressed  = 3;
}

void Screen1View::PlaceX4()
{
	PositionPressed  = 4;
}

void Screen1View::PlaceX5()
{
	PositionPressed  = 5;
}

void Screen1View::PlaceX6()
{
	PositionPressed  = 6;
}

void Screen1View::PlaceX7()
{
	PositionPressed  = 7;
}

void Screen1View::PlaceX8()
{
	PositionPressed  = 8;
}

void Screen1View::PlaceX9()
{
	PositionPressed  = 9;
}
