
#ifndef MOVABLE_TEXT_EXAMPLE_DISPLAY_H_
#define MOVABLE_TEXT_EXAMPLE_DISPLAY_H_

#include <OGRE/OgreBillboard.h>
#include <OGRE/OgreBillboardSet.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreSceneNode.h>
#include <rviz/display.h>
#include <rviz/display_context.h>
#include <rviz/ogre_helpers/movable_text.h>
#include <rviz/properties/float_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/string_property.h>

class MovableTextExampleDisplay : public rviz::Display {
  Q_OBJECT
 public:
  MovableTextExampleDisplay();
  ~MovableTextExampleDisplay();

 protected:
  /// @brief Overrides of rviz methods.
  void onInitialize();
  void onEnable();
  void onDisable();
 private Q_SLOTS:
  void UpdateParameters();

 private:
  rviz::BoolProperty *display_BB_;
  rviz::StringProperty *text_;
  rviz::IntProperty *v_pos_;
  rviz::IntProperty *h_pos_;
  rviz::FloatProperty *line_space_;
  rviz::MovableText text_obj_;
  Ogre::BillboardSet *background_;
  Ogre::SceneNode *display_node_;
};

#endif  // MOVABLE_TEXT_EXAMPLE_DISPLAY_H_
