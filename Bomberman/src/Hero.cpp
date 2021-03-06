#include "Hero.h"
#include "Cenario.h"
//-------------------------------------------------------------------------------------
Hero::Hero(){
	direction = GameEnums::STAND;

	movimentSpeed = 1;
}
//-------------------------------------------------------------------------------------
Hero::~Hero(void){
}
//-------------------------------------------------------------------------------------
GameEnums::Direction Hero::getDirection(){
	return direction;
}
//-------------------------------------------------------------------------------------
void Hero::setDirection(GameEnums::Direction _direction){
	direction = _direction;
}
//-------------------------------------------------------------------------------------
Ogre::SceneNode* Hero::getNode(){
	return node;
}
//-------------------------------------------------------------------------------------
void Hero::setNode(Ogre::SceneNode* _node){
	node = _node;
}
//-------------------------------------------------------------------------------------
Ogre::Entity* Hero::getEntity(){
	return entity;
}
//-------------------------------------------------------------------------------------
void Hero::setEntity(Ogre::Entity* _entity){
	entity = _entity;
}
//-------------------------------------------------------------------------------------
Ogre::Real Hero::getMovimentSpeed(){
	return movimentSpeed;
}
//-------------------------------------------------------------------------------------
void Hero::setMovimentSpeed(Ogre::Real _movimentSpeed){
	movimentSpeed = _movimentSpeed;
}
//-------------------------------------------------------------------------------------

