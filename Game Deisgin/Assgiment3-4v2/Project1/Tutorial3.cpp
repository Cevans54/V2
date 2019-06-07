#include "Tutorial3.h"
#define ROWS 5
#define COLOMS 5
#define CUBE_WITH 40
#define VOL 20
#define STARTING_X 2000


/*

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
		// TODO **** XXX need to fix this up such that it renders properly since this doesnt know the scale of the node
		// also the getCube function returns a cube that isnt centered on Z
		mVisibleobj->setPosition(pos.x(), pos.y() + 5, pos.z() - 5);
	}
protected:
	Ogre::SceneNode *mVisibleobj;
	btTransform mPos1;
};

*/

 
TutorialApplication::TutorialApplication()
  : mTerrainGroup(0),
    mTerrainGlobals(0),
    mInfoLabel(0)
{
	//init globals from defines
	NumRows = ROWS;
	NumCols = COLOMS;
	Cube_size = CUBE_WITH;
	Velocity_magnitude = VOL;
}
 
TutorialApplication::~TutorialApplication()
{
}
 //set up like the cube production but adding a class pointer to point to
//a class that stroes all of the nessay information about the
//Object 
/*
//Hadler ofr colliosion
class GameObject {
public:
	Ogre::Entity* EntityObject;
	Ogre::SceneNode* SceneNodeObject;
	MyMotionState* MyMotionStateObject;
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
};*/


//this wont due to some error
//used string off of a sugestion form another student
/*
void TutorialApplication::createShpere(const btVector3 &Position, btScalar Mass,const btVector3 &scale,std::string name ) {
// this is a combonation of Astroids and BulltOgre look there for the code refraces 
//Epty Vectors size and postion 
	Ogre::Vector3 size = Ogre::Vector3::ZERO;
	Ogre::Vector3 pos = Ogre::Vector3::ZERO;

	Ptr2O = new GameObject;
	//Converstion is the sae as in cude 
	pos.x = Position.getX();
	pos.y = Position.getY();
	pos.z = Position.getZ();
	//now nstead of pionting to all like in cube you now point them to EntityObject in the last class 
	//box node replaceed woth Ptr To Ogre node 
	//EntityObject
	Ptr2O->EntityObject = mSceneMgr->createEntity(name,"sphere.mesh");
	Ptr2O->EntityObject -> setCastShadows(true);
	//just using the way we attache thing in the past cople asiment 
	Ptr2O -> SceneNodeObject = mSceneMgr->getRootSceneNode()->createChildSceneNode(name);
	Ptr2O -> SceneNodeObject -> attachObject(Ptr2O->EntityObject);
	//makeing life easier to pass things 
	// Didint work :( Ogre::Vector3 Passer((scale.getX(), scale.getY(), scale.getZ()));
	Ptr2O->SceneNodeObject->scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	//phyicis stuff in donet really under stand i just copied form Create cube 

	Ogre::AxisAlignedBox boundingB = Ptr2O->EntityObject->getBoundingBox();
	boundingB.scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	size = boundingB.getSize()*0.95f;
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(Position);
	Ptr2O-> MyMotionStateObject = new MyMotionState(Transform, Ptr2O->SceneNodeObject) ;
	 
	
	
	btScalar HalfExtents(size.x);
	Ptr2O->BtCollisionShapeObject = new btSphereShape(HalfExtents);
	btVector3 LocalInertia;
	Ptr2O->BtCollisionShapeObject->calculateLocalInertia(Mass, LocalInertia);
	//temps store object so funtion will work
	MyMotionState* temp1= Ptr2O->MyMotionStateObject;
	btCollisionObject * temp2= Ptr2O->BtCollisionObjectObject;
	
	Ptr2O->BtRigidBodyObject= new btRigidBody(Mass, temp1, Ptr2O->BtCollisionShapeObject, LocalInertia);

	Ptr2O ->BtRigidBodyObject ->setUserPointer((void*)(Ptr2O));
	//Seting node data in the spheres thats shot
	Ptr2O->BtCollisionObjectObject= Ptr2O->BtRigidBodyObject;
	Ptr2O->DeleteThis = false;
	Ptr2O->ObjectType = name;
	Ptr2O->TimeAlive = 0 ;
	Ptr2Os.push_back(Ptr2O);	
	dynamicsWorld->addRigidBody(Ptr2O->BtRigidBodyObject);
	collisionShapes.push_back(Ptr2O->BtCollisionShapeObject);
	//foreing the Sphere 
	//Get Camera direction
	Ogre::Vector3 CamraDir = mCamera->getDirection();
	//convert
	btVector3 FireV = btVector3(CamraDir.x, CamraDir.y, CamraDir.z);
	//Aagiment frieing the ball
	FireV.normalize();
	FireV *= (VOL*100);

	//Now we fire are 
	Ptr2O->BtRigidBodyObject->setLinearVelocity(FireV * 1);


}
*/


//The only chages are we have to change it to fit how the above code works 
//also makeing usre that it is bulit in a way to alo it to work how the asigment wantti to 
/*
void TutorialApplication::CreateCube(const btVector3 &Position, btScalar Mass, const btVector3 &scale, std::string name){
	// empty ogre vectors for the cubes size and position
	
	
	
	
	Ogre::Vector3 size = Ogre::Vector3::ZERO;
	Ogre::Vector3 pos = Ogre::Vector3::ZERO;
	Ptr2O = new GameObject;
	
	// Convert the bullet physics vector to the ogre vector
	

	pos.x = Position.getX();
	pos.y = Position.getY();
	pos.z = Position.getZ();
	
	Ptr2O->EntityObject = mSceneMgr->createEntity(name, "cube.mesh");
	//boxentity->setScale(Vector3(scale.x,scale.y,scale.z));	
	Ptr2O->EntityObject->setCastShadows(true);
	//Error catching here for Error 0 
	
	
	
	if(Ptr2O->SceneNodeObject=mSceneMgr->getSceneNode(name))
		Ptr2O->SceneNodeObject = mSceneMgr->getSceneNode(name);
	else { Ptr2O->SceneNodeObject = mSceneMgr->getRootSceneNode()->createChildSceneNode(name); }
	
	try{
	
	Ptr2O->SceneNodeObject = mSceneMgr->getSceneNode(name);
	}

	catch(Ogre::Exception& e){
		Ptr2O->SceneNodeObject = mSceneMgr->getRootSceneNode()->createChildSceneNode(name);
	}


	
	Ptr2O->SceneNodeObject->attachObject(Ptr2O->EntityObject);
	Ptr2O->SceneNodeObject->scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	Ptr2O->SceneNodeObject->setScale(Ogre::Vector3(0.1,0.1,0.1));
	Ogre::AxisAlignedBox boundingB = Ptr2O->EntityObject->getBoundingBox();
	//Ogre::AxisAlignedBox boundingB = Ptr2O->SceneNodeObject->_getWorldAABB();
	boundingB.scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	size = boundingB.getSize()*0.95f;
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(Position);
	Ptr2O->MyMotionStateObject = new MyMotionState(Transform, Ptr2O->SceneNodeObject);
	//Give the rigid body half the size
	// of our cube and tell it to create a BoxShape (cube)
	btVector3 HalfExtents(size.x*0.5f, size.y*0.5f, size.z*0.5f);
	Ptr2O->BtCollisionShapeObject = new btBoxShape(HalfExtents);
	btVector3 LocalInertia;
	Ptr2O -> BtCollisionShapeObject ->calculateLocalInertia(Mass, LocalInertia);
	
	MyMotionState*temp1 = Ptr2O->MyMotionStateObject;
	btCollisionShape * temp2 = Ptr2O->BtCollisionShapeObject;
	
	
	Ptr2O->BtCollisionObjectObject = new btRigidBody(Mass, Ptr2O->MyMotionStateObject, Ptr2O->BtCollisionShapeObject, LocalInertia);

	// Store a pointer to the Ogre Node so we can update it later
	//Ptr2O -> BtRigidBodyObject -> setUserPointer((void *)(Ptr2O));//this line is causeing a problem in the bt colltion object

	//Decale and intilize node settings 
	Ptr2O->BtCollisionObjectObject = Ptr2O->BtRigidBodyObject;
	Ptr2O->DeleteThis = false;
	Ptr2O->ObjectType = name;
	Ptr2O->Red= false;		
	Ptr2Os.push_back(Ptr2O);

	// Add it to the physics world
	dynamicsWorld->addRigidBody(Ptr2O->BtRigidBodyObject);
	collisionShapes.push_back(Ptr2O->BtCollisionShapeObject);

}
*/
/*
void TutorialApplication::BuildCubes(int startingX, int rows, int comums, int width) {
	//nested for loops  to build the cube
	int cubeCount = 0;
	for (int i = 0; i < comums; i++) {
		int x = startingX + (width / 2 * (comums*i));
		for (int j = 0; j < rows; j++) {
			std::string name = "Cube" + std::to_string(cubeCount);
			int y = width * (j + 1);
			double cubeDimension = 12.0 / width;
			CreateCube(btVector3(x, y, 1400), 1.0f, btVector3(cubeDimension, cubeDimension, cubeDimension), name);
			cubeCount++;
		}
	}


}
*/
void TutorialApplication::CreateCube(const btVector3 &Position, btScalar Mass, const btVector3 &scale, std::string name) {
	// empty ogre vectors for the cubes size and position
	Ogre::Vector3 size = Ogre::Vector3::ZERO;
	Ogre::Vector3 pos = Ogre::Vector3::ZERO;
	Ogre::SceneNode *boxNode;
	Ogre::Entity *boxentity;
	// Convert the bullet physics vector to the ogre vector
	pos.x = Position.getX();
	pos.y = Position.getY();
	pos.z = Position.getZ();
	boxentity = mSceneMgr->createEntity(name, "cube.mesh");
	//boxentity->setScale(Vector3(scale.x,scale.y,scale.z));
	boxentity->setCastShadows(true);
	boxNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	boxNode->attachObject(boxentity);
	boxNode->scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	//boxNode->setScale(Vector3(0.1,0.1,0.1));
	Ogre::AxisAlignedBox boundingB = boxentity->getBoundingBox();
	//Ogre::AxisAlignedBox boundingB = boxNode->_getWorldAABB();
	boundingB.scale(Ogre::Vector3(scale.getX(), scale.getY(), scale.getZ()));
	size = boundingB.getSize()*0.95f;
	btTransform Transform;
	Transform.setIdentity();
	Transform.setOrigin(Position);
	MyMotionState *MotionState = new MyMotionState(Transform, boxNode);
	//Give the rigid body half the size
	// of our cube and tell it to create a BoxShape (cube)
	btVector3 HalfExtents(size.x*0.5f, size.y*0.5f, size.z*0.5f);
	btCollisionShape *Shape = new btBoxShape(HalfExtents);
	btVector3 LocalInertia;
	Shape->calculateLocalInertia(Mass, LocalInertia);
	btRigidBody *RigidBody = new btRigidBody(Mass, MotionState, Shape, LocalInertia);

	// Store a pointer to the Ogre Node so we can update it later
	RigidBody->setUserPointer((void *)(boxNode));

	// Add it to the physics world
	dynamicsWorld->addRigidBody(RigidBody);
	collisionShapes.push_back(Shape);
}

void TutorialApplication::createBulletSim(void) {
	///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	collisionConfiguration = new btDefaultCollisionConfiguration();

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	dispatcher = new   btCollisionDispatcher(collisionConfiguration);

	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	overlappingPairCache = new btDbvtBroadphase();

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	solver = new btSequentialImpulseConstraintSolver;

	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0, -100, 0));
	{
		///create a few basic rigid bodies
		// start with ground plane, 1500, 1500
		Ogre::Terrain * pTerrain = mTerrainGroup->getTerrain(0, 0);
		float* terrainHeightData = pTerrain->getHeightData();
		Ogre::Vector3 terrainPosition = pTerrain->getPosition();
		float * pDataConvert = new float[pTerrain->getSize() *pTerrain->getSize()];
		for (int i = 0; i<pTerrain->getSize(); i++)
			memcpy(
			pDataConvert + pTerrain->getSize() * i, // source
			terrainHeightData + pTerrain->getSize() * (pTerrain->getSize() - i - 1), // target
			sizeof(float)*(pTerrain->getSize()) // size
			);

		float metersBetweenVertices = pTerrain->getWorldSize() / (pTerrain->getSize() - 1); //edit: fixed 0 -> 1 on 2010-08-13
		btVector3 localScaling(metersBetweenVertices, 1, metersBetweenVertices);

		btHeightfieldTerrainShape* groundShape = new btHeightfieldTerrainShape(
			pTerrain->getSize(),
			pTerrain->getSize(),
			pDataConvert,
			1/*ignore*/,
			pTerrain->getMinHeight(),
			pTerrain->getMaxHeight(),
			1,
			PHY_FLOAT,
			true);

		groundShape->setUseDiamondSubdivision(true);
		groundShape->setLocalScaling(localScaling);

		btRigidBody * mGroundBody = new btRigidBody(0, new btDefaultMotionState(), groundShape);

		mGroundBody->getWorldTransform().setOrigin(
			btVector3(
			terrainPosition.x,
			terrainPosition.y + (pTerrain->getMaxHeight() - pTerrain->getMinHeight()) / 2,
			terrainPosition.z));

		mGroundBody->getWorldTransform().setRotation(
			btQuaternion(
			Ogre::Quaternion::IDENTITY.x,
			Ogre::Quaternion::IDENTITY.y,
			Ogre::Quaternion::IDENTITY.z,
			Ogre::Quaternion::IDENTITY.w));

		dynamicsWorld->addRigidBody(mGroundBody);
		collisionShapes.push_back(groundShape);
		
		//void TutorialApplication::BuildCubes(int start, int rows, int comums, int width);
		CreateCube(btVector3(2623, 500, 750), 1.0f, btVector3(0.3, 0.3, 0.3), "Cube0");
		CreateCube(btVector3(2263, 150, 1200), 1.0f, btVector3(0.2, 0.2, 0.2), "Cube1");
		CreateCube(btVector3(2253, 100, 1210), 1.0f, btVector3(0.2, 0.2, 0.2), "Cube2");
		CreateCube(btVector3(2253, 200, 1210), 1.0f, btVector3(0.2, 0.2, 0.2), "Cube3");
		CreateCube(btVector3(2253, 250, 1210), 1.0f, btVector3(0.2, 0.2, 0.2), "Cube4");		
		
		
		
		
		//CreateCube(btVector3(1963, 150, 1660),1.0f,btVector3(0.2,0.2,0.2),"Cube1");
		
	}
	//BuildCubes(STARTING_X, NumRows, NumCols, Cube_size);

  }
Ogre::ManualObject* TutorialApplication::createCubeMesh(Ogre::String name, Ogre::String matName) {

	Ogre::ManualObject* cube = new Ogre::ManualObject(name);

	cube->begin(matName);

	cube->position(0.5, -0.5, 1.0); cube->normal(0.408248, -0.816497, 0.408248); cube->textureCoord(1, 0);
	cube->position(-0.5, -0.5, 0.0); cube->normal(-0.408248, -0.816497, -0.408248); cube->textureCoord(0, 1);
	cube->position(0.5, -0.5, 0.0); cube->normal(0.666667, -0.333333, -0.666667); cube->textureCoord(1, 1);
	cube->position(-0.5, -0.5, 1.0); cube->normal(-0.666667, -0.333333, 0.666667); cube->textureCoord(0, 0);
	cube->position(0.5, 0.5, 1.0); cube->normal(0.666667, 0.333333, 0.666667); cube->textureCoord(1, 0);
	cube->position(-0.5, -0.5, 1.0); cube->normal(-0.666667, -0.333333, 0.666667); cube->textureCoord(0, 1);
	cube->position(0.5, -0.5, 1.0); cube->normal(0.408248, -0.816497, 0.408248); cube->textureCoord(1, 1);
	cube->position(-0.5, 0.5, 1.0); cube->normal(-0.408248, 0.816497, 0.408248); cube->textureCoord(0, 0);
	cube->position(-0.5, 0.5, 0.0); cube->normal(-0.666667, 0.333333, -0.666667); cube->textureCoord(0, 1);
	cube->position(-0.5, -0.5, 0.0); cube->normal(-0.408248, -0.816497, -0.408248); cube->textureCoord(1, 1);
	cube->position(-0.5, -0.5, 1.0); cube->normal(-0.666667, -0.333333, 0.666667); cube->textureCoord(1, 0);
	cube->position(0.5, -0.5, 0.0); cube->normal(0.666667, -0.333333, -0.666667); cube->textureCoord(0, 1);
	cube->position(0.5, 0.5, 0.0); cube->normal(0.408248, 0.816497, -0.408248); cube->textureCoord(1, 1);
	cube->position(0.5, -0.5, 1.0); cube->normal(0.408248, -0.816497, 0.408248); cube->textureCoord(0, 0);
	cube->position(0.5, -0.5, 0.0); cube->normal(0.666667, -0.333333, -0.666667); cube->textureCoord(1, 0);
	cube->position(-0.5, -0.5, 0.0); cube->normal(-0.408248, -0.816497, -0.408248); cube->textureCoord(0, 0);
	cube->position(-0.5, 0.5, 1.0); cube->normal(-0.408248, 0.816497, 0.408248); cube->textureCoord(1, 0);
	cube->position(0.5, 0.5, 0.0); cube->normal(0.408248, 0.816497, -0.408248); cube->textureCoord(0, 1);
	cube->position(-0.5, 0.5, 0.0); cube->normal(-0.666667, 0.333333, -0.666667); cube->textureCoord(1, 1);
	cube->position(0.5, 0.5, 1.0); cube->normal(0.666667, 0.333333, 0.666667); cube->textureCoord(0, 0);

	cube->triangle(0, 1, 2);      cube->triangle(3, 1, 0);
	cube->triangle(4, 5, 6);      cube->triangle(4, 7, 5);
	cube->triangle(8, 9, 10);      cube->triangle(10, 7, 8);
	cube->triangle(4, 11, 12);   cube->triangle(4, 13, 11);
	cube->triangle(14, 8, 12);   cube->triangle(14, 15, 8);
	cube->triangle(16, 17, 18);   cube->triangle(16, 19, 17);
	cube->end();

	return cube;
}




void TutorialApplication::createScene()
{
  mCamera->setPosition(Ogre::Vector3(1863, 60,1650 ));
  mCamera->lookAt(Ogre::Vector3(2263, 50, 1200));
  mCamera->setNearClipDistance(.1);
 
  bool infiniteClip =
    mRoot->getRenderSystem()->getCapabilities()->hasCapability(
      Ogre::RSC_INFINITE_FAR_PLANE);
 
  if (infiniteClip)
    mCamera->setFarClipDistance(0);
  else
    mCamera->setFarClipDistance(50000);
 
  mSceneMgr->setAmbientLight(Ogre::ColourValue(.2, .2, .2));
 
  Ogre::Vector3 lightDir(.55, -.3, .75);
  lightDir.normalise();
 
  Ogre::Light* light = mSceneMgr->createLight("TestLight");
  light->setType(Ogre::Light::LT_DIRECTIONAL);
  light->setDirection(lightDir);
  light->setDiffuseColour(Ogre::ColourValue::White);
  light->setSpecularColour(Ogre::ColourValue(.4, .4, .4));
 
  // Fog
 Ogre::ColourValue fadeColour(.9, .9, .9);
  mWindow->getViewport(0)->setBackgroundColour(fadeColour);
 
//mSceneMgr->setFog(Ogre::FOG_EXP2, fadeColour, 0.002);
 
  // Terrain
  mTerrainGlobals = OGRE_NEW Ogre::TerrainGlobalOptions();
 
  mTerrainGroup = OGRE_NEW Ogre::TerrainGroup(
    mSceneMgr,
    Ogre::Terrain::ALIGN_X_Z,
    513, 12000.0);
  mTerrainGroup->setFilenameConvention(Ogre::String("terrain"), Ogre::String("dat"));
  mTerrainGroup->setOrigin(Ogre::Vector3::ZERO);
 
  configureTerrainDefaults(light);
 
  for (long x = 0; x <= 0; ++x)
    for (long y = 0; y <= 0; ++y)
      defineTerrain(x, y);
 
  mTerrainGroup->loadAllTerrains(true);
 
  if (mTerrainsImported)
  {
    Ogre::TerrainGroup::TerrainIterator ti = mTerrainGroup->getTerrainIterator();
 
    while (ti.hasMoreElements())
    {
      Ogre::Terrain* t = ti.getNext()->instance;
      initBlendMaps(t);
    }
  }
 
  mTerrainGroup->freeTemporaryResources();
 
  // Sky Techniques
  // mSceneMgr->setSkyBox(true, "Examples/SpaceSkyBox", 300, false);
  mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);
  // Ogre::Plane plane;
  // plane.d = 1000;
  // plane.normal = Ogre::Vector3::NEGATIVE_UNIT_Y;
 
  // mSceneMgr->setSkyPlane(
  //   true, plane, "Examples/SpaceSkyPlane", 1500, 40, true, 1.5, 150, 150);
  createBulletSim();

  mRenderer = &CEGUI::OgreRenderer::bootstrapSystem();
  CEGUI::ImageManager::setImagesetDefaultResourceGroup("Imagesets");
  CEGUI::Font::setDefaultResourceGroup("Fonts");
  CEGUI::Scheme::setDefaultResourceGroup("Schemes");
  CEGUI::WidgetLookManager::setDefaultResourceGroup("LookNFeel");
  CEGUI::WindowManager::setDefaultResourceGroup("Layouts");

  CEGUI::SchemeManager::getSingleton().createFromFile("TaharezLook.scheme");

  CEGUI::WindowManager &wmgr = CEGUI::WindowManager::getSingleton();
  CEGUI::Window *sheet = wmgr.createWindow("DefaultWindow", "CEGUIDemo/Sheet");
  CEGUI::System::getSingleton().getDefaultGUIContext().setRootWindow(sheet);

  CEGUI::System::getSingleton().getDefaultGUIContext().getMouseCursor().setDefaultImage("TaharezLook/MouseArrow");

  //ui inputs
  CEGUI::Window *rowLabel = wmgr.createWindow("TaharezLook/StaticText");
  rowLabel->setText("Rows");
  rowLabel->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  rowLabel->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.05, 0)));

  rows = (CEGUI::DefaultWindow*)wmgr.createWindow("TaharezLook/Editbox");
  rows->setText(std::to_string(NumRows));
  rows->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  rows->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.10, 0)));

  CEGUI::Window *colLabel = wmgr.createWindow("TaharezLook/StaticText");
  colLabel->setText("Columns");
  colLabel->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  colLabel->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.15, 0)));

  columns = (CEGUI::DefaultWindow*)wmgr.createWindow("TaharezLook/Editbox");
  columns->setText(std::to_string(NumCols));
  columns->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  columns->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.20, 0)));

  CEGUI::Window *sizeLabel = wmgr.createWindow("TaharezLook/StaticText");
  sizeLabel->setText("Width (BigNum=Small)");
  sizeLabel->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  sizeLabel->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.25, 0)));

  size = (CEGUI::DefaultWindow*)wmgr.createWindow("TaharezLook/Editbox");
  size->setText(std::to_string(Cube_size));
  size->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  size->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.30, 0)));

  CEGUI::Window *velocityLabel = wmgr.createWindow("TaharezLook/StaticText");
  velocityLabel->setText("Sphere velocity");
  velocityLabel->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  velocityLabel->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.35, 0)));

  velocity = (CEGUI::DefaultWindow*)wmgr.createWindow("TaharezLook/Editbox");
  velocity->setText(std::to_string(Velocity_magnitude));
  velocity->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  velocity->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.40, 0)));
  /*
  CEGUI::Window *Rebuild = wmgr.createWindow("TaharezLook/Button", "Button");
  Rebuild->setText("Y To Restart");
  Rebuild->setSize(CEGUI::USize(CEGUI::UDim(0.15, 0), CEGUI::UDim(0.05, 0)));
  Rebuild->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 0), CEGUI::UDim(0.45, 0)));
  Rebuild->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TutorialApplication::resetButton, this));
  */
  sheet->addChild(rowLabel);
  sheet->addChild(rows);
  sheet->addChild(colLabel);
  sheet->addChild(columns);
  sheet->addChild(sizeLabel);
  sheet->addChild(size);
  sheet->addChild(velocityLabel);
  sheet->addChild(velocity);
 // sheet->addChild(Rebuild);
}

//bool TutorialApplication::resetButton(const CEGUI::EventArgs& args) {
//	resetTargets();
//	return true;}
 
void TutorialApplication::createFrameListener()
{
  BaseApplication::createFrameListener();
 
  mInfoLabel = mTrayMgr->createLabel(OgreBites::TL_TOP, "TerrainInfo", "", 350);
}
 
void TutorialApplication::destroyScene()
{
  OGRE_DELETE mTerrainGroup;
  OGRE_DELETE mTerrainGlobals;
}

bool TutorialApplication::frameStarted(const Ogre::FrameEvent &evt)
{
//	mKeyboard->capture();
//	mMouse->capture();
	// update physics simulation
	//dynamicsWorld->stepSimulation(evt.timeSinceLastFrame,10);
	dynamicsWorld->stepSimulation(evt.timeSinceLastFrame);
	return true;
}


















bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);
 
  if (mTerrainGroup->isDerivedDataUpdateInProgress())
  {
    mTrayMgr->moveWidgetToTray(mInfoLabel, OgreBites::TL_TOP, 0);
    mInfoLabel->show();
 
    if (mTerrainsImported)
      mInfoLabel->setCaption("Building terrain...");
    else
      mInfoLabel->setCaption("Updating textures...");
  }
  else
  {
    mTrayMgr->removeWidgetFromTray(mInfoLabel);
    mInfoLabel->hide();
 
    if (mTerrainsImported)
    {
      mTerrainGroup->saveAllTerrains(true);
      mTerrainsImported = false;
    }
  }
 
  return ret;
}
 
void getTerrainImage(bool flipX, bool flipY, Ogre::Image& img)
{
  img.load("terrain.png", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
 
  if (flipX)
    img.flipAroundY();
  if (flipY)
    img.flipAroundX();
 
}
 
void TutorialApplication::defineTerrain(long x, long y)
{
  Ogre::String filename = mTerrainGroup->generateFilename(x, y);
 
  bool exists =
    Ogre::ResourceGroupManager::getSingleton().resourceExists(
      mTerrainGroup->getResourceGroup(),
      filename);
 
  if (exists)
    mTerrainGroup->defineTerrain(x, y);
  else
  {
    Ogre::Image img;
    getTerrainImage(x % 2 != 0, y % 2 != 0, img);
    mTerrainGroup->defineTerrain(x, y, &img);
 
    mTerrainsImported = true;
  }
}
 
void TutorialApplication::initBlendMaps(Ogre::Terrain* terrain)
{
  Ogre::Real minHeight0 = 70;
  Ogre::Real fadeDist0 = 40;
  Ogre::Real minHeight1 = 70;
  Ogre::Real fadeDist1 = 15;
 
  Ogre::TerrainLayerBlendMap* blendMap0 = terrain->getLayerBlendMap(1);
  Ogre::TerrainLayerBlendMap* blendMap1 = terrain->getLayerBlendMap(2);
 
  float* pBlend0 = blendMap0->getBlendPointer();
  float* pBlend1 = blendMap1->getBlendPointer();
 
  for (Ogre::uint16 y = 0; y < terrain->getLayerBlendMapSize(); ++y)
  {
    for (Ogre::uint16 x = 0; x < terrain->getLayerBlendMapSize(); ++x)
    {
      Ogre::Real tx, ty;
 
      blendMap0->convertImageToTerrainSpace(x, y, &tx, &ty);
      Ogre::Real height = terrain->getHeightAtTerrainPosition(tx, ty);
      Ogre::Real val = (height - minHeight0) / fadeDist0;
      val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
      *pBlend0++ = val;
 
      val = (height - minHeight1) / fadeDist1;
      val = Ogre::Math::Clamp(val, (Ogre::Real)0, (Ogre::Real)1);
      *pBlend1++ = val;
    }
  }
 
  blendMap0->dirty();
  blendMap1->dirty();
  blendMap0->update();
  blendMap1->update();
 
}
 
void TutorialApplication::configureTerrainDefaults(Ogre::Light* light)
{
  mTerrainGlobals->setMaxPixelError(8);
  mTerrainGlobals->setCompositeMapDistance(3000);
 
  mTerrainGlobals->setLightMapDirection(light->getDerivedDirection());
  mTerrainGlobals->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
  mTerrainGlobals->setCompositeMapDiffuse(light->getDiffuseColour());
 
  Ogre::Terrain::ImportData& importData = mTerrainGroup->getDefaultImportSettings();
  importData.terrainSize = 513;
  importData.worldSize = 12000.0;
  importData.inputScale = 600;
  importData.minBatchSize = 33;
  importData.maxBatchSize = 65;
 
  importData.layerList.resize(3);
  importData.layerList[0].worldSize = 100;
  importData.layerList[0].textureNames.push_back(
    "dirt_grayrocky_diffusespecular.dds");
  importData.layerList[0].textureNames.push_back(
    "dirt_grayrocky_normalheight.dds");
  importData.layerList[1].worldSize = 30;
  importData.layerList[1].textureNames.push_back(
    "grass_green-01_diffusespecular.dds");
  importData.layerList[1].textureNames.push_back(
    "grass_green-01_normalheight.dds");
  importData.layerList[2].worldSize = 200;
  importData.layerList[2].textureNames.push_back(
    "growth_weirdfungus-03_diffusespecular.dds");
  importData.layerList[2].textureNames.push_back(
    "growth_weirdfungus-03_normalheight.dds");
 
}
 
 
#if Ogre_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif
 
#ifdef __cplusplus
extern "C" {
#endif
 
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
  int main(int argc, char *argv[])
#endif
  {
    // Create application object
    TutorialApplication app;
 
    try {
      app.go();
    } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      std::cerr << "An exception has occured: " <<
	e.getFullDescription().c_str() << std::endl;
#endif
    }
 
    return 0;
  }
 
#ifdef __cplusplus
}
#endif