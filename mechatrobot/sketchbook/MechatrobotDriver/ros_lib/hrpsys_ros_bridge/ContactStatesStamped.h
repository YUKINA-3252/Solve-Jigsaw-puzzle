#ifndef _ROS_hrpsys_ros_bridge_ContactStatesStamped_h
#define _ROS_hrpsys_ros_bridge_ContactStatesStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "hrpsys_ros_bridge/ContactStateStamped.h"

namespace hrpsys_ros_bridge
{

  class ContactStatesStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t states_length;
      typedef hrpsys_ros_bridge::ContactStateStamped _states_type;
      _states_type st_states;
      _states_type * states;

    ContactStatesStamped():
      header(),
      states_length(0), states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (hrpsys_ros_bridge::ContactStateStamped*)realloc(this->states, states_lengthT * sizeof(hrpsys_ros_bridge::ContactStateStamped));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(hrpsys_ros_bridge::ContactStateStamped));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/ContactStatesStamped"; };
    const char * getMD5(){ return "b6742b9b07d60b922dd6c77d76e65fc7"; };

  };

}
#endif
