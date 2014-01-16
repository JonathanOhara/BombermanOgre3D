#include "Bomberman.h"
#include "Cenario.h"
Bomberman* Bomberman::instance = NULL;
//-------------------------------------------------------------------------------------
Bomberman::Bomberman(void){
	hero = NULL;
}
//-------------------------------------------------------------------------------------
Bomberman::~Bomberman(void){
	if( hero != NULL ){
		delete hero ;
	}
}
//-------------------------------------------------------------------------------------
Bomberman* Bomberman::getInstance(void){
	if( instance == NULL){
		instance = new Bomberman();
	}
	return instance;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void Bomberman::createScene(void){
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

	Ogre::LogManager::getSingleton().logMessage(Ogre::LML_NORMAL, "Criando Cena");

	mCamera->setPosition(Ogre::Vector3(6, 11, 5.5f));
	mCamera->pitch( Ogre::Degree( -45 ) );

	// Set ambient light
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.2f, 0.2f, 0.2f));

	// Cria uma Luz
	Ogre::Light* l = mSceneMgr->createLight("Luz");
	l->setType(Ogre::Light::LT_POINT);
	l->setDiffuseColour( 1.0, 1.0, 1.0 );
	l->setSpecularColour( 1.0, 1.0, 1.0 );
	l->setPosition(6, 120, 80);

	Cenario::iniciarCenario();

	hero = Cenario::iniciarHero();
}
//-------------------------------------------------------------------------------------
bool Bomberman::frameRenderingQueued(const Ogre::FrameEvent& evt){
	
	switch( hero->getDirection() ){
		case GameEnums::UP:
			hero->getNode()->translate( 0, 0, evt.timeSinceLastFrame * hero->getMovimentSpeed() * -1 );
		break;
		case GameEnums::DOWN:
			hero->getNode()->translate( 0, 0, evt.timeSinceLastFrame * hero->getMovimentSpeed() );
		break;
		case GameEnums::LEFT:
			hero->getNode()->translate( evt.timeSinceLastFrame * hero->getMovimentSpeed() * -1, 0, 0 );
		break;
		case GameEnums::RIGHT:
			hero->getNode()->translate( evt.timeSinceLastFrame * hero->getMovimentSpeed(), 0, 0 );
		break;
	}

	/*
	if( mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->getEnabled() ){
		mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->addTime(evt.timeSinceLastFrame * 2);
	}
	*/
	return BaseApplication::frameRenderingQueued(evt);
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
bool Bomberman::keyPressed( const OIS::KeyEvent &arg ){

	switch( arg.key ){
	case OIS::KC_UP:
		hero->setDirection( GameEnums::UP );
		break;
	case OIS::KC_DOWN:
		hero->setDirection( GameEnums::DOWN );
		break;
	case OIS::KC_LEFT:
		hero->setDirection( GameEnums::LEFT );
		break;
	case OIS::KC_RIGHT:
		hero->setDirection( GameEnums::RIGHT );
		break;
	}
	return BaseApplication::keyPressed(arg);
}
//-------------------------------------------------------------------------------------
bool Bomberman::keyReleased( const OIS::KeyEvent &arg ){

	switch( arg.key ){
	case OIS::KC_UP:
		if( hero->getDirection() == GameEnums::UP ){
			hero->setDirection( GameEnums::UP );
		}
		break;
	case OIS::KC_DOWN:
		if( hero->getDirection() == GameEnums::DOWN ){
			hero->setDirection( GameEnums::DOWN );
		}
		break;
	case OIS::KC_LEFT:
		if( hero->getDirection() == GameEnums::LEFT ){
			hero->setDirection( GameEnums::LEFT );
		}
		break;
	case OIS::KC_RIGHT:
		if( hero->getDirection() == GameEnums::RIGHT ){
			hero->setDirection( GameEnums::RIGHT );
		}
		break;
	}


	return BaseApplication::keyReleased(arg);
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
bool Bomberman::mouseMoved( const OIS::MouseEvent &arg ){

	return BaseApplication::mouseMoved(arg);
}
//-------------------------------------------------------------------------------------
bool Bomberman::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){

	return BaseApplication::mousePressed(arg, id);
}
//-------------------------------------------------------------------------------------
bool Bomberman::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id ){

	return BaseApplication::mouseReleased(arg, id);
}