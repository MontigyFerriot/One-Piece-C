#ifndef OBJECT_H
#define OBJECT_H

#include "Object_base.hpp"

class Object : public Object_base
{
  public:
    Object(Resource_manager& resource_manager, std::string texture_name);

  private:
    // Defining virtual void set_up_animations() from Object_base
    void set_up_animations();
    
    // Defining virtual void unique_set_up() from Object_base
    void unique_set_up(Resource_manager& resource_manager); 
};

#endif // OBJECT_H