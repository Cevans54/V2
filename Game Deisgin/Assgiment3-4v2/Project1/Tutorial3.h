#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include "OgreManualObject.h"
#include "btBulletDynamicsCommon.h"
#include "btHeightfieldTerrainShape.h"
#include "BaseApplication.h"
#include <CEGUI/CEGUI.h>
#include <CEGUI/RendererModules/Ogre/Renderer.h>
#include <OgreException.h>
//stuff to help with the ptroblems 
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>


class MyMotionState : public btMotionState {
public:
	MyMotionState(const btTransform &initialpos, Ogre::SceneNode *node) {
		mVisibleobj = node;
		mPos1 = initialpos;
	}
	virtual ~MyMotionState() {    }
	void setNode(Ogre::SceneNode *node) {
		mVisibleobj = node;
	}
	virtual void getWorldTransform(btTransform &worldTrans) const {
		worldTrans = mPos1;
	}
	virtual void setWorldTransform(const btTransform &worldTrans) {
		if (NULL == mVisibleobj) return; // silently return before we set a node
		btQuaternion rot = worldTrans.getRotation();
		mVisibleobj->setOrientation(rot.w(), rot.x(), rot.y(), rot.z());
		btVector3 pos = worldTrans.getOrigin();

		mVisibleobj->setPosition(pos.x(), pos.y() + 5, pos.z() - 5);
	}
protected:
	Ogre::SceneNode *mVisibleobj;
	btTransform mPos1;
};





struct GameObject {
	Ogre::Entity* EntityObject;
	Ogre::SceneNode* SceneNodeObject;
	MyMotionState* MyMotionStateObject;

	//Keep it simple in nameing so i dont acdently dealre an objcet some ware
	btCollisionShape* BtCollisionShapeObject;
	btRigidBody* BtRigidBodyObject;
	btCollisionObject* BtCollisionObjectObject;
	std::string ObjectType;
	Ogre::Vector3 ObjectPosition;
	bool DeleteThis;

	bool BounceOnce = false;

	double TimeAlive = 0;
	bool Red;
	std::vector<GameObject *> ObjectCollisions;
};





class TutorialApplication : public BaseApplication
{
public:
  TutorialApplication();
  virtual ~TutorialApplication();
 
protected:
  virtual void createScene();
  virtual void createFrameListener();
  virtual void destroyScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
  bool frameStarted(const Ogre::FrameEvent &evt);
  void createShpere(const btVector3 &Position, btScalar Mass, const btVector3 &scale, std::string name);
  void CreateCube(const btVector3 &Position, btScalar Mass, const btVector3 &scale, std::string name);
  void TutorialApplication::BuildCubes(int start, int rows, int comums, int width);
  Ogre::ManualObject *createCubeMesh(Ogre::String name, Ogre::String matName);
 
private:
  void defineTerrain(long x, long y);
  void initBlendMaps(Ogre::Terrain* terrain);
  void configureTerrainDefaults(Ogre::Light* light);
  void createBulletSim(void);
  bool mTerrainsImported;
  Ogre::TerrainGroup* mTerrainGroup;
  Ogre::TerrainGlobalOptions* mTerrainGlobals;
  GameObject* Ptr2O;
  std::vector<GameObject *> Ptr2Os;
  OgreBites::Label* mInfoLabel;
  btDefaultCollisionConfiguration* collisionConfiguration;
  btCollisionDispatcher* dispatcher;
  btBroadphaseInterface* overlappingPairCache;
  btSequentialImpulseConstraintSolver* solver;
  btDiscreteDynamicsWorld* dynamicsWorld;
  btCollisionShape* groundShape;
  btAlignedObjectArray<btCollisionShape*> collisionShapes;
  int NumRows;
  int NumCols;
  int Cube_size;
  int Velocity_magnitude;
  

  //CGUI vars 
  CEGUI::OgreRenderer* mRenderer;
  CEGUI::DefaultWindow *rows;
  CEGUI::DefaultWindow *columns;
  CEGUI::DefaultWindow *size;
  CEGUI::DefaultWindow *velocity;
};
 




//Hadler ofr colliosion



