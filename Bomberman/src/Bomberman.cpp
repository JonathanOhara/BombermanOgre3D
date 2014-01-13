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

	if( mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->getEnabled() ){
		mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->addTime(evt.timeSinceLastFrame * 2);
	}

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
		hero->setDirection( GameEnums::LEFT );
		break;
	}

	/*
	if (arg.key == OIS::KC_C) {
		mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->setEnabled( true );
		mSceneMgr->getEntity("Bomb")->getAnimationState("walk")->setTimePosition(0);

	}else if (arg.key == OIS::KC_V) {
		mSceneMgr->getSceneNode("campo")->yaw( Ogre::Degree( 90 ) );
	}else if (arg.key == OIS::KC_B) {
		mSceneMgr->getSceneNode("campo")->pitch( Ogre::Degree( 90 ) );
	}else if (arg.key == OIS::KC_N) {
		mSceneMgr->getSceneNode("campo")->roll( Ogre::Degree( 90 ) );	
	}else if (arg.key == OIS::KC_UP) {
		mCamera->setPosition( Ogre::Vector3(6, 11, mCamera->getPosition().z - 1) );
	}else if (arg.key == OIS::KC_DOWN) {
		mCamera->setPosition( Ogre::Vector3(6, 11, mCamera->getPosition().z + 1) );
	}
	*/

	return BaseApplication::keyPressed(arg);
}
//-------------------------------------------------------------------------------------
bool Bomberman::keyReleased( const OIS::KeyEvent &arg ){

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