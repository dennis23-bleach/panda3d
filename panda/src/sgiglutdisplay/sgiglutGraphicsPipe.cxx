// Filename: sgiglutGraphicsPipe.cxx
// Created by:  mike (09Jan97)
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
#include "sgiglutGraphicsPipe.h"
#include "config_sgiglutdisplay.h"

////////////////////////////////////////////////////////////////////
// Static variables
////////////////////////////////////////////////////////////////////
TypeHandle sgiglutGraphicsPipe::_type_handle;

sgiglutGraphicsPipe::sgiglutGraphicsPipe(const PipeSpecifier& spec)
  : sgiGraphicsPipe(spec) {}

////////////////////////////////////////////////////////////////////
//     Function: sgiglutGraphicsPipe::get_window_type
//       Access: Public, Virtual
//  Description: Returns the TypeHandle of the kind of window
//               preferred by this kind of pipe.
////////////////////////////////////////////////////////////////////
TypeHandle sgiglutGraphicsPipe::
get_window_type() const {
  return glutGraphicsWindow::get_class_type();
}

GraphicsPipe *sgiglutGraphicsPipe::
make_sgiglutGraphicsPipe(const FactoryParams &params) {
  GraphicsPipe::PipeSpec *pipe_param;
  if (!get_param_into(pipe_param, params)) {
    return new sgiglutGraphicsPipe(PipeSpecifier());
  } else {
    return new sgiglutGraphicsPipe(pipe_param->get_specifier());
  }
}

TypeHandle sgiglutGraphicsPipe::get_class_type(void) {
  return _type_handle;
}

void sgiglutGraphicsPipe::init_type(void) {
  sgiGraphicsPipe::init_type();
  register_type(_type_handle, "sgiglutGraphicsPipe",
                sgiGraphicsPipe::get_class_type());
}

TypeHandle sgiglutGraphicsPipe::get_type(void) const {
  return get_class_type();
}
