#include "Quit.h"
#include <iostream>

Quit::Quit() {

}

Quit::Quit(float width, float height, float x, float y)
 : Bouton(width, height, x, y){
}

void Quit::OnClick(Params* _params)
{
	QuitParams* CastedParams = static_cast<QuitParams*>(_params);
	CastedParams->InternWindow->close();
	std::cout << "Quit";

}
