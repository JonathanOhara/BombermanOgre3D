#ifndef __SQUARE_h_
#define __SQUARE_h_

#include <Ogre.h>

class Square{
public:
	Square();
	Square(Ogre::Real _x, Ogre::Real _y);
	virtual ~Square(void);

	void criarNomeDeEntidadesNos(Ogre::String* sceneNodeName, Ogre::String* entityName) const;

	//getters e setters
	Ogre::Real getX();
	void setX( Ogre::Real _x );

	Ogre::Real getY();
	void setY( Ogre::Real _y );

private:
	Ogre::Real x, y;

};
#endif // #ifndef __SQUARE_h_