#include "Square.h"
#include "Bomberman.h"
//-------------------------------------------------------------------------------------
Square::Square(){
	x = y = 0;
}
//-------------------------------------------------------------------------------------
Square::Square(Ogre::Real _x, Ogre::Real _y){
	x = _x;
	y = _y;

}
//-------------------------------------------------------------------------------------
Square::~Square(void){
}
//-------------------------------------------------------------------------------------
void Square::criarNomeDeEntidadesNos(Ogre::String* sceneNodeName, Ogre::String* entityName) const{
	*sceneNodeName = "cenario_node_";
	*entityName = "cenario_entidade_";

	const Ogre::String strPosicaoX = Ogre::StringConverter::toString(x);
	const Ogre::String strPosicaoY = Ogre::StringConverter::toString(y);
 
	(*sceneNodeName).append( strPosicaoY );
	(*sceneNodeName).append( "_" );
	(*sceneNodeName).append( strPosicaoX );
 
	(*entityName).append( strPosicaoY );
	(*entityName).append( "_" );
	(*entityName).append( strPosicaoX );
}
//-------------------------------------------------------------------------------------
Ogre::Real Square::getX(){
	return x;
}
//-------------------------------------------------------------------------------------
void Square::setX( Ogre::Real _x ){
	x = _x;
}
//-------------------------------------------------------------------------------------
Ogre::Real Square::getY(){
	return y;
}
//-------------------------------------------------------------------------------------
void Square::setY( Ogre::Real _y ){
	y = _y;
}
//-------------------------------------------------------------------------------------