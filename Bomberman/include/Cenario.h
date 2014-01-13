#ifndef __CENARIO_h_
#define __CENARIO_h_

#include <Ogre.h>
#include "Square.h"
#include "Hero.h"

#define LINHAS 13
#define COLUNAS 15

class Cenario{
	private:
		static Square cenarioSquare[LINHAS][COLUNAS];
		static char cenario[LINHAS][COLUNAS];
		static Ogre::SceneNode* cenarioNode;

		static Square criarSquare(Ogre::Real x, Ogre::Real y, Ogre::String* sceneNodeName, Ogre::String* entityName);

	public:
		static void iniciarCenario();
		static Hero* iniciarHero();
};

#endif // #ifndef __CENARIO_h_