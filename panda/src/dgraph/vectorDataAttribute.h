// Filename: vectorDataAttribute.h
// Created by:  drose (27Mar00)
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

#ifndef VECTORDATAATTRIBUTE_H
#define VECTORDATAATTRIBUTE_H

#include <pandabase.h>

#include <nodeAttribute.h>
#include <indent.h>

template<class VecType, class MatType>
class VectorDataTransition;

////////////////////////////////////////////////////////////////////
//       Class : VectorDataAttribute
// Description :
////////////////////////////////////////////////////////////////////
template<class VecType, class MatType>
class VectorDataAttribute : public NodeAttribute {
public:
  INLINE VectorDataAttribute();
  INLINE VectorDataAttribute(const VecType &value);
  INLINE VectorDataAttribute(const VectorDataAttribute<VecType, MatType> &copy);
  INLINE void operator = (const VectorDataAttribute<VecType, MatType> &copy);

public:
  INLINE void set_value(const VecType &value);
  INLINE const VecType &get_value() const;

  virtual TypeHandle get_handle() const;

  virtual void output(ostream &out) const;
  virtual void write(ostream &out, int indent_level = 0) const;

protected:
  virtual int internal_compare_to(const NodeAttribute *other) const;

private:
  VecType _value;

public:
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}
  static TypeHandle get_class_type() {
    return _type_handle;
  }
  static void init_type() {
    NodeAttribute::init_type();
    register_type(_type_handle,
                  string("VectorDataAttribute<") +
                  get_type_handle(VecType).get_name() + "," +
                  get_type_handle(MatType).get_name() + ">",
                  NodeAttribute::get_class_type());
  }

private:
  static TypeHandle _type_handle;
friend class VectorDataTransition<VecType, MatType>;
};

#include "vectorDataAttribute.I"

#endif
