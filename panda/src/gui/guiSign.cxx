// Filename: guiSign.cxx
// Created by:  cary (06Nov00)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://www.panda3d.org/license.txt .
//
// To contact the maintainers of this program write to
// panda3d@yahoogroups.com .
//
////////////////////////////////////////////////////////////////////

#include "guiSign.h"
#include "config_gui.h"

TypeHandle GuiSign::_type_handle;

void GuiSign::recompute_frame(void) {
  GuiItem::recompute_frame();
  _sign->recompute();
  _sign->get_extents(_left, _right, _bottom, _top);
  this->adjust_region();
}

void GuiSign::set_priority(GuiLabel* l, const GuiItem::Priority p) {
  _sign->set_priority(l, ((p==P_Low)?GuiLabel::P_LOWER:GuiLabel::P_HIGHER));
  GuiItem::set_priority(l, p);
}

GuiSign::GuiSign(const string& name, GuiLabel* sign)
  : GuiItem(name), _sign(sign), _sign_scale(sign->get_scale()) {
  _sign->get_extents(_left, _right, _bottom, _top);
}

GuiSign::~GuiSign(void) {
  this->unmanage();
}

void GuiSign::manage(GuiManager* mgr, EventHandler& eh) {
  if (_mgr == (GuiManager*)0L) {
    mgr->add_label(_sign);
    GuiItem::manage(mgr, eh);
  } else
    gui_cat->warning() << "tried to manage sign (0x" << (void*)this
                       << ") that is already managed" << endl;
}

void GuiSign::manage(GuiManager* mgr, EventHandler& eh, Node* n) {
  if (_mgr == (GuiManager*)0L) {
    mgr->add_label(_sign, n);
    GuiItem::manage(mgr, eh, n);
  } else
    gui_cat->warning() << "tried to manage sign (0x" << (void*)this
                       << ") that is already managed" << endl;
}

void GuiSign::unmanage(void) {
  if (_mgr != (GuiManager*)0L)
    _mgr->remove_label(_sign);
  GuiItem::unmanage();
}

int GuiSign::freeze() {
  return _sign->freeze();
}

int GuiSign::thaw() {
  return _sign->thaw();
}

void GuiSign::set_scale(float f) {
  _sign->set_scale(f * _sign_scale);
  GuiItem::set_scale(f);
  recompute_frame();
}

void GuiSign::set_scale(float x, float y, float z) {
  _sign->set_scale(x, y, z);
  GuiItem::set_scale(x, y, z);
  recompute_frame();
}

void GuiSign::set_pos(const LVector3f& p) {
  _sign->set_pos(p);
  GuiItem::set_pos(p);
  recompute_frame();
}

void GuiSign::set_priority(GuiItem* i, const GuiItem::Priority p) {
  if (p == P_Highest)
    _sign->set_priority(_sign, GuiLabel::P_HIGHEST);
  else if (p == P_Lowest)
    _sign->set_priority(_sign, GuiLabel::P_LOWEST);
  else
    i->set_priority(_sign, ((p==P_Low)?P_High:P_Low));
  GuiItem::set_priority(i, p);
}

int GuiSign::set_draw_order(int v) {
  int o = _sign->set_draw_order(v);
  return GuiItem::set_draw_order(o);
}

void GuiSign::output(ostream& os) const {
  GuiItem::output(os);
  os << "  Sign data:" << endl;
  os << "    sign - 0x" << (void*)_sign << endl;
}
