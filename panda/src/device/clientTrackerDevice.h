// Filename: clientTrackerDevice.h
// Created by:  drose (25Jan01)
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

#ifndef CLIENTTRACKERDEVICE_H
#define CLIENTTRACKERDEVICE_H

#include <pandabase.h>

#include "clientDevice.h"
#include "trackerData.h"

////////////////////////////////////////////////////////////////////
//       Class : ClientTrackerDevice
// Description : A device, attached to the ClientBase by a
//               TrackerNode, that records the data from a single
//               tracker device.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA ClientTrackerDevice : public ClientDevice {
protected:
  INLINE ClientTrackerDevice(ClientBase *client, const string &device_name);

public:
  INLINE const TrackerData &get_data() const;

protected:
  TrackerData _data;

public:
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    ClientDevice::init_type();
    register_type(_type_handle, "ClientTrackerDevice",
                  ClientDevice::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "clientTrackerDevice.I"

#endif
