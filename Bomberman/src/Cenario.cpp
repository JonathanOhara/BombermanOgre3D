#include "Cenario.h"
#include "Bomberman.h"
//-------------------------------------------------------------------------------------
Square Cenario::cenarioSquare[LINHAS][COLUNAS];
Ogre::SceneNode* Cenario::cenarioNode;

char Cenario::cenario[LINHAS][COLUNAS] = {
{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
{'X','H','.','.','B','B','B','B','B','B','B','.','.','.','X'},
{'X','.','X','B','X','B','X','B','X','B','X','B','X','.','X'},
{'X','.','B','B','B','B','B','B','B','B','B','B','B','B','X'},
{'X','B','X','B','X','B','X','.','X','B','X','B','X','B','X'},
{'X','B','B','B','B','B','B','.','B','B','.','B','B','B','X'},
{'X','B','X','B','X','B','X','.','X','.','X','B','X','B','X'},
{'X','B','B','B','B','B','B','.','B','B','.','B','.','B','X'},
{'X','B','X','B','X','B','X','B','X','B','X','B','X','.','X'},
{'X','.','B','B','B','B','B','B','.','B','.','B','B','.','X'},
{'X','.','X','B','X','B','X','B','X','B','X','B','X','.','X'},
{'X','.','.','.','B','B','.','B','B','B','B','.','.','.','X'},
{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
};
//-------------------------------------------------------------------------------------
void Cenario::iniciarCenario(){

	// Crio um nó filho do nó raiz na hierarquia de cena
	Cenario::cenarioNode = Bomberman::getInstance()->mSceneMgr->getRootSceneNode()->createChildSceneNode("cenarioNode");

	//Posiciona o Nó
	Cenario::cenarioNode->setPosition( Ogre::Vector3(0,0,0) );

	Ogre::Entity* campoEntity = Bomberman::getInstance()->mSceneMgr->createEntity("cenario", "scenario_green.mesh");

    Ogre::SceneNode * campo = Bomberman::getInstance()->mSceneMgr->getRootSceneNode()->createChildSceneNode( "campo" );
    campo->attachObject(campoEntity);
	campo->setPosition(6,-0.5f,-7);
	campo->setScale( 10.0f, 10.0f, 10.0f );
	campo->pitch( Ogre::Degree( -90 ) );


	Ogre::SceneNode* elementoNode;
	Ogre::Entity* elementoEntidade;

	for( int i = 0; i < LINHAS; i++ ){
		for( int j = 0; j < COLUNAS; j++){
			Ogre::String nomeEntidade, nomeCenarioNode;

			Square square = Cenario::criarSquare( i, j, &nomeCenarioNode, &nomeEntidade );

			switch( Cenario::cenario[i][j] ){
			case 'X':
				elementoNode = Cenario::cenarioNode->createChildSceneNode( nomeCenarioNode );

				elementoEntidade = Bomberman::getInstance()->mSceneMgr->createEntity( nomeEntidade, "block_hard.mesh" );
				elementoEntidade->setCastShadows(true);
				
				elementoNode->setPosition( Ogre::Vector3( i, 0, j * - 1 ) );
				elementoNode->attachObject( elementoEntidade );
				elementoNode->setScale( 0.5f, 0.5f, 0.5f );
				break;
			case 'B':
				elementoNode = Cenario::cenarioNode->createChildSceneNode( nomeCenarioNode );

				elementoEntidade = Bomberman::getInstance()->mSceneMgr->createEntity( nomeEntidade, "block_normal.mesh" );
				elementoEntidade->setCastShadows(true);
				
				elementoNode->setPosition( Ogre::Vector3( i, 0, j * - 1 ) );
				elementoNode->attachObject( elementoEntidade );
				elementoNode->setScale( 0.5f, 0.5f, 0.5f );
				

				break;
			case 'H':
				elementoNode = Cenario::cenarioNode->createChildSceneNode( "bomberman_node" );

				elementoEntidade = Bomberman::getInstance()->mSceneMgr->createEntity( "bomberman", "bomberman.mesh" );
				elementoEntidade->setCastShadows(true);

				elementoNode->setPosition( Ogre::Vector3( i, 0.5f, j * - 1 ) );
				elementoNode->attachObject( elementoEntidade );
				elementoNode->setScale( 0.3f, 0.3f, 0.3f );
				elementoNode->yaw( Ogre::Degree( 180 ) );

				break;
			}

			Cenario::cenarioSquare[i][j] = square;
		}
	}

}
//-------------------------------------------------------------------------------------
Square Cenario::criarSquare(Ogre::Real x, Ogre::Real y, Ogre::String* sceneNodeName, Ogre::String* entityName){
	Square square(x, y);

	square.criarNomeDeEntidadesNos( sceneNodeName, entityName );

	return square;
}
//-------------------------------------------------------------------------------------
Hero* Cenario::iniciarHero(){
	Hero* hero = new Hero();

	hero->setNode( Bomberman::getInstance()->mSceneMgr->getSceneNode( "bomberman_node" ) );
	hero->setEntity( Bomberman::getInstance()->mSceneMgr->getEntity( "bomberman" ) );

	return hero;
}
//-------------------------------------------------------------------------------------