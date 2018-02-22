#include "rviz_movable_text_test/movable_text_example_display.h"

MovableTextExampleDisplay::MovableTextExampleDisplay()
    : text_obj_("Hello There!") {
  display_BB_ = new rviz::BoolProperty("display background", true, "", this,
                                       SLOT(UpdateParameters()));
  text_ = new rviz::StringProperty("Text", "Sample Text", "", this,
                                   SLOT(UpdateParameters()));
  v_pos_ = new rviz::IntProperty("Vertical Position", 0, "", this,
                                 SLOT(UpdateParameters()));
  v_pos_->setMin(0);
  v_pos_->setMax(2);
  h_pos_ = new rviz::IntProperty("Horizontal Position", 0, "", this,
                                 SLOT(UpdateParameters()));
  h_pos_->setMin(0);
  h_pos_->setMax(1);
  line_space_ = new rviz::FloatProperty("Line Spacing", 0.5, "", this,
                                        SLOT(UpdateParameters()));
}

MovableTextExampleDisplay::~MovableTextExampleDisplay() {
  display_node_->detachAllObjects();
  context_->getSceneManager()->destroySceneNode(display_node_);
}

void MovableTextExampleDisplay::onInitialize() {
  display_node_ =
      context_->getSceneManager()->getRootSceneNode()->createChildSceneNode();
  display_node_->attachObject(&text_obj_);
  background_ = context_->getSceneManager()->createBillboardSet();
  background_->createBillboard(0, 0, 0, Ogre::ColourValue::Black);
  background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_TOP_LEFT);
  background_->setDefaultDimensions(text_obj_.GetAABB().getHalfSize().x,
                                    text_obj_.GetAABB().getHalfSize().y);
  display_node_->attachObject(background_);
  UpdateParameters();
}
void MovableTextExampleDisplay::onEnable() { display_node_->setVisible(true); }

void MovableTextExampleDisplay::onDisable() {
  display_node_->setVisible(false);
}

void MovableTextExampleDisplay::UpdateParameters() {
  text_obj_.setTextAlignment(
      (rviz::MovableText::HorizontalAlignment)h_pos_->getInt(),
      (rviz::MovableText::VerticalAlignment)v_pos_->getInt());
  text_obj_.setCaption(text_->getStdString());
  text_obj_.setLineSpacing(line_space_->getFloat());
  background_->setVisible(display_BB_->getBool());
  background_->setDefaultDimensions(text_obj_.GetAABB().getHalfSize().x,
                                    text_obj_.GetAABB().getHalfSize().y);
  switch (v_pos_->getInt()) {
    case 0:
      if (h_pos_->getInt() == 0)
        background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_TOP_LEFT);
      else
        background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_TOP_CENTER);
      break;
    case 1:
      if (h_pos_->getInt() == 0)
        background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_BOTTOM_LEFT);
      else
        background_->setBillboardOrigin(
            Ogre::BillboardOrigin::BBO_BOTTOM_CENTER);
      break;
    case 2:
      if (h_pos_->getInt() == 0)
        background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_CENTER_LEFT);
      else
        background_->setBillboardOrigin(Ogre::BillboardOrigin::BBO_CENTER);
      break;
  }
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(MovableTextExampleDisplay, rviz::Display)
