#ifndef __HERO_h_
#define __HERO_h_

#include <Ogre.h>
#include "GameEnums.h"

class Hero{
public:
	Hero();
	virtual ~Hero(void);

	GameEnums::Direction getDirection();
	void setDirection( GameEnums::Direction _direction );

	Ogre::SceneNode* getNode();
	void setNode( Ogre::SceneNode* _node );

	Ogre::Entity* getEntity();
	void setEntity( Ogre::Entity* _entity );

private:
	GameEnums::Direction direction;
	Ogre::SceneNode* node;
	Ogre::Entity* entity;
};
#endif // #ifndef __HERO_h_