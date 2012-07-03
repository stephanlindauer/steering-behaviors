#ifndef NULLOBJECT_H
#define NULLOBJECT_H

#include "object.h"

class NullObject : public Object {

};

const NullObject * NULL_OBJECT = new NullObject();

#endif // NULLOBJECT_H
