//
//  Collision.cpp
//  PipeStuck
//
//
//

#include "Collision.h"


	CCPoint Collision::getWorldPosition()
{
		return ((CCParallaxNode*)parent->getParent())->convertToWorldSpace(parent->getPosition());
}


bool Collision::isCollision()
{
			CCSize spipe = parent->boundingBox().size;
    CCPoint ppipe = getWorldPosition();

			CCSize sjetpack = jetpack->boundingBox().size;
		CCPoint pjetpack = jetpack->getPosition();

			float d = 6;

			float maxx1 = ppipe.x + spipe.width/2 - d;
    float minx1 = ppipe.x - spipe.width/2 + d;
			float maxy1 = ppipe.y + spipe.height/2 - d;
					float miny1 = ppipe.y - spipe.height/2 + d;

			float maxx2 = pjetpack.x + sjetpack.width/2 - d;
				float minx2 = pjetpack.x - sjetpack.width/2 + d;
    float maxy2 = pjetpack.y + sjetpack.height/2 - d;
			float miny2 = pjetpack.y - sjetpack.height/2 + d;

					return !(maxx1 < minx2 ||
             maxx2 < minx1 ||
             maxy1 < miny2 ||
             maxy2 < miny1);

}


Collision::Collision(JetPack* jetpack, bool getScore)
{
			setName("Collision");

    this->jetpack = jetpack; //attaches the jetpack boy with this data strcuture.
			this->getScore = getScore; // stores the score in getscore variable
}



		void Collision::update(float delta)
{
    parent = (CCNode*)getOwner();
			if (parent == NULL) return;

				if (jetpack->status == isDie) return;

			if (getScore)
    {
        if (getWorldPosition().x <= jetpack->getPosition().x)
				{
					getScore = false;
            jetpack->updateScore(); // each time this function is called, the score is updates by 1 in Collision.cpp
			}
		}

			if (isCollision())
    {
				jetpack->hitMe(); //Function to check whether the collision has occured
		}
}
