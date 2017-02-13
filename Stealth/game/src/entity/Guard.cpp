//
//  Guard.cpp
//  Stealth
//
//  Created by L Nguyen Huu on 13/02/27 H.
//  Copyright (c) 27 Heisei L Nguyen Huu. All rights reserved.
//


#include "entity/AICharacter.h"

#include "entity/Guard.h"

using namespace std;


Guard::Guard() : AICharacter()
{
}

Guard::~Guard()
{
}

void Guard::updateIntention()
{
	moveHorizontal(1.0f);
}
