//
//  SpidersAndCrows.cpp
//  PipeStuck
//
//
//

#include "SpidersAndCrows.h"
#include "config.h"


	void SpidersAndCrows::update(float delta)
{
			parent = (HelloWorld*)getOwner();
    if 	(parent == NULL) return;

    interval+= delta;
		if (interval >= ktimeToSpidersAndCrows )
    {
        interval = 0;
        parent->addPipe();
		}
}

	SpidersAndCrows::SpidersAndCrows()
		{
			setName("SpidersAndCrows");
    interval = 0;
}

