#ifndef __Bomberman_h_
#define __Bomberman_h_

#include "Hero.h"
#include "BaseApplication.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif

class Bomberman : public BaseApplication
{
public:
	static Bomberman* getInstance(void);

	Hero* hero;
protected:
    Bomberman(void);
    virtual ~Bomberman(void);

    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

    // OIS::KeyListener
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
    // OIS::MouseListener
    virtual bool mouseMoved( const OIS::MouseEvent &arg );
    virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
    virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

	static Bomberman* instance;
};

#endif // #ifndef __Bomberman_h_
