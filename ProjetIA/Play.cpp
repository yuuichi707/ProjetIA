#include "Play.h"
#include <iostream>



Play::Play(float width, float height, float x, float y)
: Bouton(width, height, x, y){
}

void Play::OnClick(Params* _params)
{
	PlayParams* CastedParams = static_cast<PlayParams*>(_params);
	CastedParams->InternWindow->display();
	std::cout << "Play";
}
