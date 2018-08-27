#include "Objects/Object.hpp"

Object::Object(Resource_manager& resource_manager,std::string texture_name)
        :Object_base{resource_manager,texture_name}
{
}

void Object::set_up_animations()
{
}

void Object::unique_set_up(Resource_manager& resource_manager) 
{
}

