#include "Tutorial3.h"
 
TutorialApplication::TutorialApplication()
  : mTerrainGroup(0),
    mTerrainGlobals(0),
    mInfoLabel(0)
{
}
 
TutorialApplication::~TutorialApplication()
{
}
 
void TutorialApplication::createScene()
{
  mCamera->setPosition(Ogre::Vector3(1683, 50, 2116));
  mCamera->lookAt(Ogre::Vector3(1963, 50, 1660));
  mCamera->setNearClipDistance(.1);
 
//stuff i added

  Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
  Ogre::SceneNode* ninjaNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);

  
  
/* 
  Ogre::Entity* ninjaEntiy2 = mSceneMgr->createEntity("ninja.mesh");
  Ogre::SceneNode* node2 = ninjaNode ->createChildSceneNode(Ogre::Vector3(1750,150,750));
  node2->attachObject(ninjaEntiy2);
  
  Ogre::Entity*ogreEnity = mSceneMgr->createEntity("ogrehead.mesh");
 
  // Ogre::SceneNode* orgreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(Ogre::Vector3(0,100,0) );
  
  Ogre::SceneNode* node3 = ninjaNode->createChildSceneNode(Ogre::Vector3(1850,250,750));
  node2->yaw(Ogre::Degree(180));
  //orgreNode->setPosition(0, 100, 0);
  node3->attachObject(ogreEnity);
  
  Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
  spotLight->setDiffuseColour(0, 0, 1.0);
  spotLight->setSpecularColour(0,0,1.0);

  spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
  spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));
  
  spotLight->setPosition(Ogre::Vector3(1850,250,750));
  
  
  Ogre::Light* spotLight2 = mSceneMgr->createLight("SpotLight2");
  spotLight2->setDiffuseColour(0, 1.0, 0.0);
  spotLight2->setSpecularColour(0, 1.0, 0.0);

  spotLight2->setType(Ogre::Light::LT_SPOTLIGHT);
  spotLight2->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

  spotLight2->setPosition(Ogre::Vector3(1850, 250, 750));
  */
  
  
  
  
  
  /*
  Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
  directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
  //Now we'll set the diffuse and specular colors to a dark red.
  directionalLight->setDiffuseColour(Ogre::ColourValue(0.4, 0, 0));
  directionalLight->setSpecularColour(Ogre::ColourValue(0.4, 0, 0));
  
  directionalLight->setDirection(Ogre::Vector3::NEGATIVE_UNIT_Z);
  Ogre::SceneNode* directionalLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  directionalLightNode->attachObject(directionalLight);
  directionalLightNode->setDirection(Ogre::Vector3(0, -1, 1));
  */
  
  /*
  Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
  directionalLight->setType(Ogre::Light::LT_DIRECTIONAL); 
  directionalLight->setDiffuseColour(Ogre::ColourValue(0.4, 0, 0));
  directionalLight->setSpecularColour(Ogre::ColourValue(0.4, 0, 0));
  
  Ogre::SceneNode* directionalLightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  directionalLightNode->attachObject(directionalLight);
  directionalLightNode->setDirection(Ogre::Vector3(0, -1, -1));
  */
  
  
  
  
  Ogre::Light*pointlight = mSceneMgr->createLight("PointLight");
  pointlight->setType(Ogre::Light::LT_POINT);
  pointlight->setDiffuseColour(0.7,0.0,0.0);
  pointlight->setSpecularColour(0.7,0.0,0.0);

  Ogre::SceneNode* pointlightNode = ninjaNode-> createChildSceneNode(Ogre::Vector3(1750,200,700));
  pointlightNode->attachObject(pointlight);


  
  
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
 




  /*

  // Fog
 Ogre::ColourValue fadeColour(.9, .9, .9);
  mWindow->getViewport(0)->setBackgroundColour(fadeColour);
 
mSceneMgr->setFog(Ogre::FOG_EXP2, fadeColour, 0.002);
 */
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
 
}
 
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
      MessageBoxA( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
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