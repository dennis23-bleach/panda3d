// Filename: config_gobj.h
// Created by:  drose (01Oct99)
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

#ifndef CONFIG_GOBJ_H
#define CONFIG_GOBJ_H

#include <pandabase.h>
#include <notifyCategoryProxy.h>

NotifyCategoryDecl(gobj, EXPCL_PANDA, EXPTP_PANDA);

// Configure variables for gobj package.
extern EXPCL_PANDA const int max_texture_dimension;
extern EXPCL_PANDA bool textures_up_power_2;
extern EXPCL_PANDA bool textures_down_power_2;
extern EXPCL_PANDA bool textures_up_square;
extern EXPCL_PANDA bool textures_down_square;

enum BamTextureMode {
  BTM_fullpath,
  BTM_relative,
  BTM_basename
};
extern EXPCL_PANDA BamTextureMode bam_texture_mode;
extern EXPCL_PANDA const string fake_texture_image;

#endif


